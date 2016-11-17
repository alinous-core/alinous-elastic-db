/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_CHARBUFFER_H_
#define BASELIB_IO_CHARBUFFER_H_

namespace java {
namespace nio {

using namespace alinous;

class CharBuffer : public virtual IObject {
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

	CharBuffer(const wchar_t* buffer, int length, ThreadContext* ctx);
	CharBuffer(int size, ThreadContext* ctx);
	virtual ~CharBuffer();
	void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() ;

	static CharBuffer* allocate(int capacity, ThreadContext* ctx);
	CharBuffer* clear(ThreadContext* ctx);
	RawArrayPrimitive<wchar_t>* move(ThreadContext* ctx);
	bool hasArray(ThreadContext* ctx);
	int arrayOffset(ThreadContext* ctx);
	IArrayObjectPrimitive<wchar_t>* array(ThreadContext* ctx);
    bool hasRemaining(ThreadContext* ctx);
    int length(ThreadContext* ctx);
	int remaining(ThreadContext* ctx);
	int position(ThreadContext* ctx);
	CharBuffer* position(int newPosition, ThreadContext* ctx);
	int limit(ThreadContext* ctx);
	CharBuffer* limit(int limit, ThreadContext* ctx);
	wchar_t get(ThreadContext* ctx);
	wchar_t get(int index, ThreadContext* ctx);
	CharBuffer* get(IArrayObjectPrimitive<wchar_t>* dest, ThreadContext* ctx);
	CharBuffer* get(IArrayObjectPrimitive<wchar_t>* dest, int off, int len, ThreadContext* ctx);
	CharBuffer* put(wchar_t ch, ThreadContext* ctx);
	CharBuffer* put(int index, wchar_t ch, ThreadContext* ctx);
	CharBuffer* put(UnicodeString* str, ThreadContext* ctx);
	CharBuffer* put(IArrayObjectPrimitive<wchar_t>* src, ThreadContext* ctx);
    CharBuffer* put(IArrayObjectPrimitive<wchar_t>* src, int off, int len, ThreadContext* ctx);
	wchar_t* rawArray();
	static CharBuffer* wrap(IArrayObjectPrimitive<wchar_t>* buffer, int begin, int count, ThreadContext* ctx);
	static CharBuffer* wrap(UnicodeString* str, ThreadContext* ctx);
	static CharBuffer* wrap(UnicodeString* str, int begin, int count, ThreadContext* ctx);

// private:
    int pos;
    int lim;
    int cap;
    RawArrayPrimitive<wchar_t>* data;
    ArrayObjectPrimitive<wchar_t>* wrapper;

public:
    static void __cleanUp(ThreadContext* ctx)
	{
	}
};

}} /* namespace alinous */

#endif /* BASELIB_IO_CHARBUFFER_H_ */
