/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_GCOBJECT_H_
#define GC_GCOBJECT_H_

namespace alinous {

class GCObject {
public:
	inline void* operator new(size_t size) throw() {
      	return SysThread::getMalloc()->allocate(size);
    }

	inline void* operator new(size_t size, MemoryInterface* ctx) throw() {
      	return ctx->alloc->allocate(size);
    }
	inline void operator delete(void* p, size_t size) throw() {
    	SysThread::getMalloc()->freeMemory((char*)p, size);
    }

	constexpr GCObject(bool staticInst, bool released) throw() __attribute__((always_inline)) : staticInst(staticInst), released(released)
#ifdef __TRACE_NEW
		, file_name(nullptr), function_name(nullptr), lineno(0)
#endif

			{}

	virtual ~GCObject() throw() {}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() = 0;

	bool staticInst;
	bool released;

#ifdef __TRACE_NEW
	const char *file_name;
	const char *function_name;
	unsigned int lineno;
#endif
};

}



#endif /* GC_GCOBJECT_H_ */
