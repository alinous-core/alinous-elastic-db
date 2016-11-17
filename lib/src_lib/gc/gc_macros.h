/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_GC_MACROS_H_
#define GC_GC_MACROS_H_

#ifdef __DEBUG__
#include <bfd.h>
#include <libgen.h>
#endif

namespace alinous {

#ifdef __DEBUG__

class MemoryGCLogElement {
public:
	MemoryGCLogElement(GC_THREAD_LOG_TYPE logType, const wchar_t* filePath, int line,
			const wchar_t* classOrFunc, RawArray<StackFrame>* stackTrace, IObject* owner){
		this->logType = logType;
		this->filePath = filePath;
		this->line = line;
		this->classOrFunc = classOrFunc;
		this->stackTrace = stackTrace;
		this->owner = owner;
	}
	~MemoryGCLogElement(){
		if(this->stackTrace != nullptr){
			auto it = this->stackTrace->iterator();
			while(it.hasNext()){
				StackFrame* frm = it.next();
				delete frm;
			}

			delete this->stackTrace;
			this->stackTrace = nullptr;
		}
	}

	void showDetail(int indent, bool stackTrace) {
		indentSpace(indent);

		const wchar_t* logT;
		switch(this->logType){
		case GC_THREAD_LOG_TYPE::REGISTER:
			logT = L"REGISTER"; break;
		case GC_THREAD_LOG_TYPE::INC:
			logT = L"INC"; break;
		case GC_THREAD_LOG_TYPE::DEC:
			logT =  L"DEC"; break;
		case GC_THREAD_LOG_TYPE::VIRTUAL_REGISTER:
			logT =  L"VIRTUAL_REGISTER"; break;
		case GC_THREAD_LOG_TYPE::DELETE_LOCAL:
			logT =  L"DELETE_LOCAL"; break;
		case GC_THREAD_LOG_TYPE::DELETE_BY_GC:
			logT =  L"DELETE_BY_GC"; break;
		default:
			break;
		}

		if(this->owner == nullptr){
			wprintf(L"%S at %S : %d [%S]\n", logT, this->filePath, line, this->classOrFunc);
		}
		else{
			wprintf(L"%S by %llx at %S : %d [%S]\n", logT, this->owner, this->filePath, line, this->classOrFunc);
		}

		if(stackTrace){
			printStackTrace(this->stackTrace, 1, 4, indent + 2);
		}
	}

	void printStackTrace(RawArray<StackFrame>* stackTrace, int start, int count, int indent){
		int cnt  = 0;
		auto it = stackTrace->iterator();
		while(it.hasNext()){
			StackFrame* frame = it.next();

			if(cnt >= start){
				indentSpace(indent);
				wprintf(L"%s : %d [%s]\n", frame->fileName, frame->lineNo, frame->functionName);
			}
			cnt++;
			if(cnt == count){
				break;
			}
		}
	}

	void indentSpace(const int indent){
		for(int i = 0; i != indent; i++){
			wprintf(L" ");
		}
	}

	GC_THREAD_LOG_TYPE logType;
	IObject* owner;
	const wchar_t* filePath;
	int line;
	const wchar_t* classOrFunc;
	RawArray<StackFrame>* stackTrace;
};

class IObjectLogger {
public:
	IObjectLogger(const IObject *ptr) : ptr(ptr), logs(new RawArray<MemoryGCLogElement>(8)) {

	}
	~IObjectLogger(){
		const int maxLoop = this->logs->size();
		for(int i = 0; i != maxLoop; i++){
			MemoryGCLogElement *element =  this->logs->get(i);
			delete element;
		}

		delete logs;
	}

	void showDetail(int indent, bool stackTrace){
		auto it = this->logs->iterator();
		while(it.hasNext()){
			MemoryGCLogElement *element = it.next();
			element->showDetail(indent, stackTrace);
		}
	}

	void log(const GC_THREAD_LOG_TYPE logType, const wchar_t* filePath, int line, const wchar_t* classOrFunc
			, RawArray<StackFrame>* stackTrace, IObject* owner) {
		MemoryGCLogElement* newElement = new MemoryGCLogElement(logType, filePath, line, classOrFunc, stackTrace, owner);

		logs->addElement(newElement);
	}

	MemoryGCLogElement* getFirstlog(){
		return this->logs->get(0);
	}

	class ValueCompare {
	public:
		int operator() (const IObjectLogger* const _this, const IObjectLogger* const object, const ThreadContext* const ctx) const
		{
			if(_this->ptr == object->ptr){
				return 0;
			}

			return _this->ptr > object->ptr ? 1 : -1;
		}
	};
	class H {
	public:
		u_int64_t operator() (const IObjectLogger* const a) const {
			return (u_int64_t)a->ptr;
		}
	};
	const IObject *ptr;
private:

	RawArray<MemoryGCLogElement> *logs;
};

class BinEngine {
private:
	BinEngine(const char* prog, bool ignoreDetectDelete){
	    abfd = bfd_openr(prog, NULL);
	    assert(abfd != NULL);
	    bfd_check_format(abfd, bfd_object);

	    int size = bfd_get_symtab_upper_bound(abfd);
	    assert(size > 0);
	    symbols = (asymbol**)malloc(size);
	    assert(symbols != NULL);
	    nsymbols = bfd_canonicalize_symtab(abfd, symbols);

	    logs = new HashedRawArray<IObjectLogger, IObjectLogger::H, typename IObjectLogger::ValueCompare>();
	    objectOrder = new RawArray<IObject>(256);

	    this->ignoreDetectDelete = ignoreDetectDelete;
	}

public:
	~BinEngine(){
		bfd_close(abfd);
		free(symbols);

		HashedRawArray<IObjectLogger, IObjectLogger::H, typename IObjectLogger::ValueCompare>::Iterator it = logs->iterator();
		while(it.hasNext()){
			IObjectLogger* objLogger = it.next();
			delete objLogger;
		}

		delete logs;
		delete objectOrder;
	}

	static BinEngine* getInstance(){
		return instance;
	}


	void showLogDetail(IObject* ptr, int indent){
		IObjectLogger tmp(ptr);
		IObjectLogger *logger = logs->search(&tmp);

		if(logger == nullptr){
			wprintf(L"    static variable\n");
			return;
		}

		logger->showDetail(indent, true);
	}

	void log(GC_THREAD_LOG_TYPE logType, IObject* ptr, const wchar_t* filePath, const int line, const wchar_t* classOrFunc, RawArray<StackFrame>* stackTrace, IObject* owner){
		if(ptr == nullptr){
			delete stackTrace;
			return;
		}

		IObjectLogger tmp(ptr);
		IObjectLogger *logger = logs->search(&tmp);
		if(logger == nullptr){
			logger = new IObjectLogger(ptr);
			this->logs->addElement(logger);
		}

		logger->log(logType, filePath, line, classOrFunc, stackTrace, owner);

		IObject* registered = objectOrder->search(ptr);
		if(registered == nullptr){
			objectOrder->addElement(ptr);
		}
	}

	void objectInfo(IObject* ptr, bool stackTrace){
		IObjectLogger tmp(ptr);
		IObjectLogger *logger = logs->search(&tmp);
		if(logger == nullptr){
			return;
		}

		logger->showDetail(0, stackTrace);
	}

	void detectDelete(IObject* ptr) {
		if(this->ignoreDetectDelete){
			return; // do nothing
		}

		IObjectLogger tmp(ptr);
		IObjectLogger *logger = logs->search(&tmp);
		if(logger == nullptr){
			return;
		}

		assert(logger->ptr == ptr);

		logs->removeByObj(logger);
		delete logger;

		auto it = objectOrder->iterator();
		while(it.hasNext()){
			IObject* p = it.next();
			if(p == ptr){
				it.remove();
			}
		}
	}

	RawArray<StackFrame>* stackTrace() {
		return stackTrace(2);
	}

	RawArray<StackFrame>* stackTrace(int ignoreDepth) {
		RawArray<StackFrame>* stackTrace = new RawArray<StackFrame>(32);

		const static ssize_t trace_frames_max = 100;
		void* trace_frames[trace_frames_max] = {};
		int size = ::backtrace(trace_frames, trace_frames_max);

		assert(size > ignoreDepth);
		for(int i = ignoreDepth; i != size; i++){
			void* address = trace_frames[i];
			StackFrame* frame = resolve(address);
			if(frame != nullptr){
				stackTrace->addElement(frame);
			}
		}

		return stackTrace;
	}

	StackFrame* const resolve(void *address){
		bfd_vma offset = (bfd_vma)address;

		asection *section = ::bfd_get_section_by_name(abfd, ".debug_info");
		assert(section != nullptr);

		const char *file_name;
		const char *function_name;
		unsigned int lineno;
		int found = bfd_find_nearest_line(
									abfd,
									section,
									symbols,
									offset,
									&file_name,
									&function_name,
									&lineno);
		if(found > 0){
			StackFrame* frame = new StackFrame();
			frame->fileName = file_name;
			frame->lineNo = lineno;
			frame->functionName = function_name;

			return frame;
		}

		return nullptr;
	}

	void showOrder(){
		auto it = objectOrder->iterator();
		while(it.hasNext()){
			IObject* p = it.next();

			IObjectLogger tmp(p);
			IObjectLogger *logger = logs->search(&tmp);
			MemoryGCLogElement *first = logger->getFirstlog();

			wprintf(L"%llx %S\n", (long long)p, first->classOrFunc);
			logger->showDetail(4, true);

		}
	}
	static void init(const char* prog, bool ignoreDetectDelete) {
		instance = new BinEngine(prog, ignoreDetectDelete);
	}

	static void finish(){
		instance->showOrder();
		delete instance;
		instance = nullptr;
	}

public: // flags
	bool ignoreDetectDelete;

private:
	static BinEngine* instance;
	bfd *abfd;
	asymbol **symbols;
	int nsymbols;


	HashedRawArray<IObjectLogger, IObjectLogger::H, typename IObjectLogger::ValueCompare> *logs;
	RawArray<IObject> *objectOrder;
};

#endif

template <typename T>
class GCUtils {
public:
	friend class ThreadContext;

	inline static T* alloc(T* obj, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw() {
		#ifdef __DEBUG__
		RawArray<StackFrame>* stackTrace = 0;
		BinEngine* engine = BinEngine::getInstance();
		if(engine != nullptr){
			stackTrace = engine->stackTrace();
			engine->log(GC_THREAD_LOG_TYPE::REGISTER ,obj, filePath, line, classOrFunc, stackTrace, nullptr);
		}
		#endif

		return obj;
	}
	inline static T* ins(IObject* owner, T* obj, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw() {
		if(obj == nullptr || obj->staticInst){
			return obj;
		}
		#ifdef __DEBUG__
		RawArray<StackFrame>* stackTrace = 0;
		BinEngine* engine = BinEngine::getInstance();
		if(engine != nullptr){
			if(obj != nullptr){
				stackTrace = engine->stackTrace();
				engine->log(GC_THREAD_LOG_TYPE::INC ,obj, filePath, line, classOrFunc, stackTrace, owner);
			}
		}

		#endif

		return ins(owner, obj, ctx);
	}

	inline static T* ins(IObject* owner, T* obj, ThreadContext* ctx) throw(){
		if(obj == nullptr || obj->staticInst){
			return obj;
		}
		ctx->ins(owner, obj);

		return obj;
	}


	inline static T* mv(IObject* owner, T** pprev, T* next, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw() {
		#ifdef __DEBUG__
		RawArray<StackFrame>* stackTrace = 0;
		BinEngine* engine = BinEngine::getInstance();
		if(engine != nullptr){
			if(prev != nullptr && !prev->staticInst){
				stackTrace = engine->stackTrace();
				engine->log(GC_THREAD_LOG_TYPE::DEC ,prev, filePath, line, classOrFunc, stackTrace, owner);
			}
			if(next != nullptr && !next->staticInst){
				stackTrace = engine->stackTrace(); // again
				engine->log(GC_THREAD_LOG_TYPE::INC ,next, filePath, line, classOrFunc, stackTrace, owner);
			}
		}

		#endif

		return mv(owner, pprev, next, ctx);
	}

	inline static T* mv(IObject* owner, T** pprev, T* next, ThreadContext* ctx) throw() {
		T* prev = *pprev;
		*pprev = next;
		if(ctx == nullptr){
			return next;
		}


		//ctx->mv(owner, prev, next);
		GCLogCollector* pLogger = ctx->pLogger;
		if(prev != nullptr && !prev->staticInst){
			//pLogger->logDec(owner, prev);

			pLogger->decLog->addElement(prev);
			pLogger->decOwnerLog->addElement(owner);
		}
		if(next != nullptr && !next->staticInst){
			//pLogger->logInc(owner, next);

			pLogger->gcEngine->incStatus(owner, next);
		}


		return next;
	}



	inline static void dec(IObject* owner, T* obj, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw() {
		if(obj == nullptr || obj->staticInst || ctx == nullptr){
			return;
		}
		#ifdef __DEBUG__
		RawArray<StackFrame>* stackTrace = 0;
		BinEngine* engine = BinEngine::getInstance();
		if(engine != nullptr){
			if(obj != nullptr){
				stackTrace = engine->stackTrace();
				engine->log(GC_THREAD_LOG_TYPE::DEC ,obj, filePath, line, classOrFunc, stackTrace, owner);
			}
		}
		#endif

		dec(owner, obj, ctx);
	}

	inline static void dec(IObject* owner, T* obj, ThreadContext* ctx){
		if(obj == nullptr || obj->staticInst || ctx == nullptr){
			return;
		}
		ctx->dec(owner, obj);

		//GCLogCollector* pLogger = ctx->pLogger;

		//pLogger->decLog->addElement(obj);
		//pLogger->decOwnerLog->addElement(owner);
	}

	inline static T* global(T* obj, ThreadContext* ctx, const wchar_t* filePath, int line) throw() {
		if(obj == nullptr || obj->staticInst){
			return obj;
		}
		ctx->global(obj);

		return obj;
	}

	inline static T* gcReturn(T* obj, ThreadContext* ctx, const wchar_t* filePath, int line) throw() {
		return obj;
	}
};
}

#define __CLS_STR(str) L##str
#define GC_CLS_STR(str) __CLS_STR(#str)

#define __GC_ALLOC(next, T) GCUtils<T>::alloc(next, ctx, __FILEW__, __LINE__, GC_CLS_STR(T))

// #define __GC_MV(owner,prev, next, T) GCUtils<T>::mv(owner, prev, next, ctx, __FILEW__, __LINE__, GC_CLS_STR(T))
#define __GC_MV(owner,prev, next, T) GCUtils<T>::mv(owner, prev, next, ctx)

// #define __GC_INS(owner, next, T) GCUtils<T>::ins(owner, next, ctx, __FILEW__, __LINE__, GC_CLS_STR(T))
#define __GC_INS(owner, next, T) GCUtils<T>::ins(owner, next, ctx)

// #define __GC_DEC(owner, next, T) GCUtils<T>::dec(owner, next, ctx, __FILEW__, __LINE__, GC_CLS_STR(T))
#define __GC_DEC(owner, next, T) GCUtils<T>::dec(owner, next, ctx);

#define __GC_ST(next, T) GCUtils<T>::global(next, ctx, __FILEW__, __LINE__)

//#define __GC_RT(next, T) GCUtils<T>::gcReturn(next, ctx, __FILEW__, __LINE__)
#define __GC_RT(next, T) next

#define __GC_ALLOC_ST(ptr, T) ( dynamic_cast<T*>(StaticInitializer::reg(ptr)) )
#define __GC_INS_ST(ptr, T) (dynamic_cast<T*>(StaticInitializer::inc((T*)ptr) ) )


#endif /* GC_GC_MACROS_H_ */

#undef TRUE
#undef FALSE

