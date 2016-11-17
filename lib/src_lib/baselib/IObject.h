/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_IOBJECT_H_
#define BASELIB_IOBJECT_H_


namespace alinous {
class ThreadContext;
class SysSpinMutex;
}

namespace java {
namespace lang {

using namespace alinous;
using alinous::MemoryInterface;

class UnicodeString;


class IObject : public GCObject {
public:


#ifdef COUNT_IOBJECT
	static int newCtr;
	static bool startCtr;
#endif

	const static wchar_t* currentClass;
	//SysSpinMutex* spin;

	inline IObject() throw() : GCObject(true, false) {}

	inline IObject(ThreadContext* ctx) throw() : GCObject(ctx == nullptr, false)
	{
		if(__builtin_expect(ctx != nullptr, 1)){
			#ifdef __DEBUG__
			RawArray<StackFrame>* stackTrace = 0;
			BinEngine* engine = BinEngine::getInstance();
			if(engine != nullptr){
				stackTrace = engine->stackTrace(3);
				engine->log(GC_THREAD_LOG_TYPE::VIRTUAL_REGISTER ,this, __FILEW__, __LINE__, L"IOBJECT", stackTrace, nullptr);
			}
			#endif



#ifdef __TRACE_NEW
			if(::dotrace > 0){
				static int done = -1;
				if(done < 0){
					const char* prog = "./Debug/Alinous-NativeDebug";
					::__init_trace_new(prog);
					done = 1;
				}

				int ignoreDepth = 0;

				const static ssize_t trace_frames_max = 100;
				void* trace_frames[trace_frames_max] = {};
				int size = ::backtrace(trace_frames, trace_frames_max);

				for(int i = ignoreDepth; i != size; i++){
					void* address = trace_frames[i];

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
						this->file_name = file_name;
						this->function_name = function_name;
						this->lineno = lineno;
					}
				}
			}
#endif


			//ctx->registerObject(this, ctx, __FILEW__, __LINE__, L"IObject");

			ctx->notifiers->peekNoCheck()->list.addElement(this);

			// peek->registerObject(this, ctx);

			ctx->pLogger->gcEngine->registerObject(this);

			//GCUtils<java::lang::IObject>::alloc(this, ctx, __FILEW__, __LINE__, L"IObject");
		}


	#ifdef COUNT_IOBJECT
		if(IObject::startCtr){
			newCtr++;
		}
	#endif

	}

	virtual ~IObject() throw() {}

	virtual bool equals(IObject* obj, ThreadContext* ctx){
		return this == obj;
	}
	virtual UnicodeString* toString(ThreadContext* ctx) ;
	virtual int hashCode(ThreadContext* ctx){
		u_int64_t uptr = (u_int64_t)this;
		return (int)uptr;
	}

	class ValueCompare {
	public:
		int operator() (const IObject* const a, const IObject* const b, const ThreadContext* const ctx) const throw() {
			if(a == b){
				return 0;
			}

			return a > b ? 1 : -1;
		}
	};
	class Hash {
	public:
		u_int64_t operator() (const IObject* const a) const throw() {
			return (u_int64_t)a;
		}
	};
};

using Object = IObject;


}} /* namespace alinous */




#endif /* BASELIB_IOBJECT_H_ */
