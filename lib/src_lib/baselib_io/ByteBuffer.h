/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_BYTEBUFFER_H_
#define BASELIB_IO_BYTEBUFFER_H_


namespace java{
namespace nio {

using namespace alinous;

class ByteBuffer : public virtual IObject {
public:
	inline ByteBuffer(const char* buffer, int length, ThreadContext* ctx) throw() : IObject(ctx) {
		data = new(ctx) RawArrayPrimitive<char>(128);
		wrapper = new(ctx) ArrayObjectPrimitive<char>(data, nullptr);


		this->wrapped = false;

		this->lim = length;
		this->cap = length;
		this->pos = 0;

		const int maxLoop = length;
		for(int i = 0; i != maxLoop; ++i){
			data->addElement(buffer[i]);
		}
	}

	inline ByteBuffer(int length, ThreadContext* ctx) throw() : IObject(ctx) {
		wrapper = __GC_INS(this, new(ctx) ArrayObjectPrimitive<char>(length, ctx), IArrayObjectPrimitive<char>);
		data = wrapper->raw;

		this->wrapped = true;

		this->lim = length;
		this->cap = length;
		this->pos = 0;
	}

	inline ByteBuffer(ThreadContext* ctx) throw() : IObject(ctx) {
		data = new(ctx) RawArrayPrimitive<char>(128);
		wrapper = new(ctx) ArrayObjectPrimitive<char>(data, nullptr);

		this->wrapped = false;

		this->lim = 0;
		this->pos = 0;
		this->cap = 0;
	}

	inline ByteBuffer(IArrayObjectPrimitive<char>* array, ThreadContext* ctx) throw() : IObject(ctx) {
		data = array->raw;
		data->numArray = array->length;
		wrapper = __GC_INS(this, array, IArrayObjectPrimitive<char>);

		this->wrapped = true;

		this->lim = array->length;
		this->pos = 0;
		this->cap = array->length;
	}

	virtual ~ByteBuffer(){
		ThreadContext* ctx = ThreadContext::getCurentContext();
		__releaseRegerences(false, ctx);
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(!wrapped && this->data != nullptr){
			delete this->data;
			this->data = nullptr;
		}
		if(!wrapped && this->wrapper != nullptr){
			delete this->wrapper;
			this->wrapper = nullptr;
		}

		if(wrapped && this->wrapper != nullptr){
			__GC_DEC(this, this->wrapper, IArrayObjectPrimitive<char>);
			this->wrapper = nullptr;
			this->data = nullptr;
		}

	}

	inline static ByteBuffer* wrap(IArrayObjectPrimitive<char>* buffer, ThreadContext* ctx) throw() {
		return wrap(buffer, 0, buffer->length, ctx);
	}

	inline static ByteBuffer* wrap(IArrayObjectPrimitive<char>* buffer, int begin, int count, ThreadContext* ctx) throw() {
		ByteBuffer* newBuffer = new(ctx) ByteBuffer(buffer, ctx);

		return newBuffer;
	}

	inline ByteBuffer* clear(ThreadContext* ctx) throw() {
		this->lim = this->cap;
		this->pos = 0;
		return this;
	}



	inline char* rawPtr() throw() {
		return this->data->root;
	}

	inline bool hasArray(ThreadContext* ctx) throw() {
		return true;
	}

	inline int arrayOffset(ThreadContext* ctx) throw() {
		return 0;
	}

	inline IArrayObjectPrimitive<char>* array(ThreadContext* ctx) throw() {
		this->wrapper->length = this->lim;
		return this->wrapper;
	}

	inline static ByteBuffer* allocate(int capacity, ThreadContext* ctx) throw() {
		IArrayObjectPrimitive<char>* array = new(ctx) ArrayObjectPrimitive<char>(capacity, ctx);

		ByteBuffer* buff = new(ctx) ByteBuffer(array ,ctx);

		return buff;
	}

	inline bool hasRemaining(ThreadContext* ctx) throw() {
    	return (pos < lim);
    }

	inline int remaining(ThreadContext* ctx) throw()
	{
		 return this->lim - this->pos;
	}
	inline int position(ThreadContext* ctx) throw()
	{
		return this->pos;
	}
	inline ByteBuffer* position(int newPosition, ThreadContext* ctx) throw()
	{
		this->pos = newPosition;
		return this;
	}
	inline int limit(ThreadContext* ctx) throw()
	{
		return this->lim;
	}
	inline ByteBuffer* limit(int limit, ThreadContext* ctx) throw()
	{
		this->lim = limit;
		return this;
	}

	inline int capacity(ThreadContext* ctx) throw() {
		return this->cap;
	}

	inline char get(ThreadContext* ctx) throw() {
		return data->get(this->pos++);
	}

	inline char get(int index, ThreadContext* ctx) throw() {
		return data->get(index);
	}

	inline ByteBuffer* get(IArrayObjectPrimitive<char>* dest, ThreadContext* ctx) {
		return get(dest, 0, dest->length, ctx);
	}


	inline ByteBuffer* get(IArrayObjectPrimitive<char>* dest, int off, int len, ThreadContext* ctx)  {
	    int length = dest->length;
	    if (__builtin_expect((off < 0) || (len < 0) || (long) off + (long) len > length, 0)) {
	        throw new IndexOutOfBoundsException(ctx);
	    }

	    if (__builtin_expect(len > remaining(ctx), 0)) {
	        throw new BufferUnderflowException(ctx);
	    }

	    FastCopy::copy(dest->raw->root + off, &data->root[this->pos], len);
	    this->pos += len;
/*
	    for (int i = off; i < off + len; i++) {
	    	dest->set(get(ctx), i, ctx);
	    }
*/
	    return this;
	}


	inline ByteBuffer* put(char b, ThreadContext* ctx) throw() {
		data->set(this->pos++, b);
		return this;
	}

	inline ByteBuffer* put(int index, char b, ThreadContext* ctx) throw() {
		data->set(index, b);
		return this;
	}

	inline ByteBuffer* put(IArrayObjectPrimitive<char>* src, ThreadContext* ctx) throw() {
	    return put(src, 0, src->length, ctx);
	}

	inline ByteBuffer* put(IArrayObjectPrimitive<char>* src, int off, int len, ThreadContext* ctx) {
        int length = src->length;
        if ((off < 0) || (len < 0) || off + len > length) {
            throw new IndexOutOfBoundsException(ctx);
        }

        if (len > remaining(ctx)) {
            throw new BufferOverflowException(ctx);
        }

        FastCopy::copy(&data->root[this->pos], src->raw->root + off, len);
        this->pos += len;

        return this;
    }

	inline ByteBuffer* put(ByteBuffer* src, ThreadContext* ctx) throw() {
    	int maxLoop = src->lim;

    	FastCopy::copy(&data->root[this->pos], src->data->root, maxLoop);
    	this->pos += maxLoop;

    	return this;
    }

	inline ByteBuffer* putChar(wchar_t value, ThreadContext* ctx) throw() {
		//data->set(this->pos++, value & 0xFF);
		//data->set(this->pos++, (value >> 1) & 0xFF);

		u_short sh = (short)value;
    	char* bytes = (char*)&sh;

    	data->set(this->pos++, bytes[0]);
    	data->set(this->pos++, bytes[1]);

    	return this;
    }

	inline ByteBuffer* putShort(short value, ThreadContext* ctx) throw() {
    	char* bytes = (char*)&value;

    	data->set(this->pos++, bytes[0]);
    	data->set(this->pos++, bytes[1]);

    	return this;
    }

	inline ByteBuffer* putInt(int32_t value, ThreadContext* ctx) throw() {
		int32_t* ptr = (int32_t*)(data->root + this->pos);
		*ptr = value;

		this->pos += 4;

/*
    	char* bytes = (char*)&value;

    	char* dest = data->root;

    	dest[this->pos++] = bytes[0];
    	dest[this->pos++] = bytes[1];
    	dest[this->pos++] = bytes[2];
    	dest[this->pos++] = bytes[3];
*/
    	return this;
    }

	inline ByteBuffer* putInt(int32_t position, int value, ThreadContext* ctx) throw() {
    	char* bytes = (char*)&value;

    	int pos = position;
    	data->set(pos++, bytes[0]);
    	data->set(pos++, bytes[1]);
    	data->set(pos++, bytes[2]);
    	data->set(pos++, bytes[3]);

    	return this;
    }

	inline ByteBuffer* putLong(int64_t value, ThreadContext* ctx) throw() {
		char* bytes = (char*)&value;


		FastCopy::copy(&data->root[this->pos], bytes, sizeof(int64_t));

		this->pos += sizeof(int64_t);

		return this;
	}

	inline ByteBuffer* putFloat(double value, ThreadContext* ctx) throw() {
		char* bytes = (char*)&value;

		data->set(this->pos++, bytes[0]);
		data->set(this->pos++, bytes[1]);
		data->set(this->pos++, bytes[2]);
		data->set(this->pos++, bytes[3]);

		return this;
	}

	inline ByteBuffer* putDouble(double value, ThreadContext* ctx) throw() {
		char* bytes = (char*)&value;

		data->set(this->pos++, bytes[0]);
		data->set(this->pos++, bytes[1]);
		data->set(this->pos++, bytes[2]);
		data->set(this->pos++, bytes[3]);
		data->set(this->pos++, bytes[4]);
		data->set(this->pos++, bytes[5]);
		data->set(this->pos++, bytes[6]);
		data->set(this->pos++, bytes[7]);

		return this;
	}

	inline long long getLong(ThreadContext* ctx) throw() {
		long long val = *((long long*)(this->data->root + this->pos));
		this->pos += sizeof(int64_t);

		return val;
	}

	inline long long getLong(int position, ThreadContext* ctx) throw() {
		long long val = *((long long*)(this->data->root + position));

		return val;
	}

	inline double getDouble(ThreadContext* ctx) throw() {
		double val = *((double*)(this->data->root + this->pos));
		this->pos += sizeof(double);

		return val;
	}

	inline double getDouble(int position, ThreadContext* ctx) throw() {
		double val = *((double*)(this->data->root + position));

		return val;
	}

	inline float getFloat(ThreadContext* ctx) throw() {
		float val = *((float*)(this->data->root + this->pos));
		this->pos += sizeof(float);

		return val;
	}

	inline float getFloat(int position, ThreadContext* ctx) throw() {
		float val = *((float*)(this->data->root + position));

		return val;
	}

	inline int32_t getInt(ThreadContext* ctx) throw() {
		int32_t val = *((int32_t*)(this->data->root + this->pos));
		this->pos += sizeof(int32_t);

		return val;
	}

	inline int32_t getInt(int position, ThreadContext* ctx) throw() {
		int32_t val = *((int32_t*)(this->data->root + position));

		return val;
	}

	inline wchar_t getChar(ThreadContext* ctx) throw() {
		wchar_t val = *((short*)(this->data->root + this->pos));



		this->pos += sizeof(int16_t);

		return (wchar_t)val;
	}

	inline wchar_t getChar(int position, ThreadContext* ctx) throw() {
		int16_t val = *((int16_t*)(this->data->root + position));

		return (wchar_t)val;
	}

	inline int16_t getShort(ThreadContext* ctx) throw() {
		int16_t val = *((int16_t*)(this->data->root + this->pos));
		this->pos += sizeof(int16_t);

		return val;
	}

	inline int16_t getShort(int position, ThreadContext* ctx) throw() {
		int16_t val = *((int16_t*)(this->data->root + position));

		return val;
	}


	RawArrayPrimitive<char>* data;
	IArrayObjectPrimitive<char>* wrapper;
	bool wrapped;
private:
    int pos;
    int lim;
    int cap;


public:
    static void __cleanUp(ThreadContext* ctx)
	{
	}
};

}} /* namespace alinous */

#endif /* BASELIB_IO_BYTEBUFFER_H_ */
