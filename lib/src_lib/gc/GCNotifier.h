/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_GCNOTIFIER_H_
#define GC_GCNOTIFIER_H_

namespace alinous {

class ThreadContext;

class GCNotifierRegisterRecord{
public:
	GCObject* obj;
	const wchar_t* file;
	const wchar_t* clsstr;
	int line;


	GCNotifierRegisterRecord(GCObject* obj, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw()
		: obj(obj), file(filePath), clsstr(classOrFunc), line(line)
	{}

    void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }
    void* operator new(size_t size, MemoryInterface* ctx) throw(){
    	return ctx->alloc->allocate(size);
    }
    void operator delete(void* p, size_t size) throw(){
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }

};

class GCNotifier {
public:
	class RegisterRecordCompare {
	public:
		int operator() (const GCNotifierRegisterRecord* const a, const GCNotifierRegisterRecord* const b, const ThreadContext* const ctx) const throw() {
			if(a->obj == b->obj){
				return 0;
			}

			return a->obj > b->obj ? 1 : -1;
		}
	};


    void* operator new(size_t size) throw(){
      	return SysThread::getMalloc()->allocate(size);
    }
    void* operator new(size_t size, MemoryInterface* ctx) throw(){
    	return ctx->alloc->allocate(size);
    }
    void operator delete(void* p, size_t size) throw(){
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }


	GCNotifier(ThreadContext* ctx, const wchar_t* file, int line, const wchar_t* clsstr, const wchar_t* funcstr) throw();

	~GCNotifier() throw();

	void notifyResigter() throw();

	void setNitified(bool val) throw(){
		this->notified = val;
	}

	void moveInto(GCObject* record) throw(){
		#ifdef __DEBUG__
		assert(ctx != nullptr);
		#endif

		//this->list.addElementWithSorted(record);
		this->list.addElement(record);
	}

	void protectMoveDecreased(GCObject* obj, ThreadContext* ctx, const wchar_t* filePath, int line, const wchar_t* classOrFunc) throw();
	bool hasObject(GCObject* obj) throw();


	void registerObject(GCObject* obj, MemoryInterface* ctx) throw() {
		#ifdef __DEBUG__
		assert(ctx != nullptr);
		#endif

		this->list.addElement(obj);
	}

private:
	bool notified;
	ThreadContext* ctx;
	const wchar_t* file;
	const wchar_t* clsstr;
	const wchar_t* funcstr;
	int line;
public:
	//RawArray<GCNotifierRegisterRecord, RegisterRecordCompare> list;
	RawArray<GCObject> list;
};

} /* namespace alinous */

#endif /* GC_GCNOTIFIER_H_ */
