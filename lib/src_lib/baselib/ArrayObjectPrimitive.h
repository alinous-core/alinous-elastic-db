/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ARRAYOBJECTPRIMITIVE_H_
#define BASELIB_ARRAYOBJECTPRIMITIVE_H_


namespace java { namespace lang{
class IObject;
}}

namespace alinous {

using namespace java::lang;
using namespace alinous;

class ThreadContext;
template <typename T> class RawArrayPrimitive;

template <typename T>
class IArrayObjectPrimitive : public IObject, public IArrayObjectBase {
public:
	IArrayObjectPrimitive(ThreadContext* ctx) throw() : IObject(ctx), IArrayObjectBase(ctx) {}
	IArrayObjectPrimitive(int length, ThreadContext* ctx) throw() : IObject(ctx), IArrayObjectBase(ctx), length(length) {}
	void arraycopy(int srcPos, IArrayObjectBase* dest, int destPos, int length, ThreadContext* ctx) throw() {
		copy(srcPos, (IArrayObjectPrimitive<T>*)dest, destPos, length, ctx);
	}
	void copy(int srcPos, IArrayObjectPrimitive<T>* dest, int destPos, int length, ThreadContext* ctx) throw() {
		for(int i = 0; i < length; i++){
			int s = srcPos + i;
			int d = destPos + i;

			dest->set(this->get(s, ctx), d, ctx);
		}
	}
	inline void set(T v, int index, const ThreadContext* const ctx) throw()
	{
		this->raw->set(index, v);
	}

	inline T get(const int n) const throw()
	{
		return raw->get(n);
	}
	inline T get(const int n, const ThreadContext* const ctx) const throw()
	{
		return raw->get(n);
	}

	virtual IArrayObjectPrimitive<T>* clone(ThreadContext* ctx) = 0;


	inline T* rawPtr() const throw() {
		return this->raw->root;
	}

	void prefetch() throw() {
		if(this->raw == 0){
			return;
		}
		int maxLoop = raw->currentSize >> 4;
		if(maxLoop > 256){
			maxLoop = 256;
		}
		for(int i = 0; i != maxLoop; ++i){
			__builtin_prefetch(this->raw->root + (i * 32));
		}

	}

	int length;
	RawArrayPrimitive<T> *raw;
};


template <typename T>
class ArrayObjectPrimitive : public IArrayObjectPrimitive<T> {
public:
	ArrayObjectPrimitive(ArrayObjectPrimitive<T> &base) = default;

	ArrayObjectPrimitive(ThreadContext* ctx) throw() :  IArrayObjectPrimitive<T>(ctx){
		if(ctx == nullptr){
			this->raw = nullptr;
			this->length = 0;
			return;
		}
		this->raw = new(ctx) RawArrayPrimitive<T>(ctx);
		this->length = 0;
		this->wrap = false;
	}
	ArrayObjectPrimitive(int length) throw() :  IArrayObjectPrimitive<T>(nullptr){
		this->raw = new RawArrayPrimitive<T>(length);
		this->raw->numArray = length;
		this->length = length;
		this->wrap = false;
	}
	ArrayObjectPrimitive(int length, ThreadContext* ctx)  throw() :  IArrayObjectPrimitive<T>(ctx){
		if(ctx == nullptr){
			this->raw = nullptr;
			this->length = length;
			return;
		}
		this->raw = new(ctx) RawArrayPrimitive<T>(length, ctx);
		this->length = length;
		this->wrap = false;
	}
	ArrayObjectPrimitive(IArrayObjectPrimitive<T>* ptr, ThreadContext* ctx) throw() : IArrayObjectPrimitive<T>(ctx) {
		this->length = ptr->length;
		this->raw = new(ctx) RawArrayPrimitive<T>(this->length, ctx);

		const int maxLoop =ptr->length;
		for(int i = 0; i < maxLoop; ++i){
			T val = ptr->get(i);
			this->raw->addElement(val);
		}
		this->wrap = false;
	}

	ArrayObjectPrimitive(int length, int nullpadding, ThreadContext* ctx) throw() : IArrayObjectPrimitive<T>(ctx)
	{
		this->raw = new(ctx) RawArrayPrimitive<T>(length, ctx);
		this->length = length;
		for(int i = 0; i < nullpadding; i++){
			this->raw->addElement(0);
		}
		this->wrap = false;
	}
	ArrayObjectPrimitive(T* array, int length, ThreadContext* ctx) throw() : IArrayObjectPrimitive<T>(ctx)
	{
		this->raw = new(ctx) RawArrayPrimitive<T>(length, ctx);
		this->length = length;

		//this->raw->mapElement(array, length);
		for(int i = 0; i < length; i++){
			this->raw->addElement(array[i]);
		}

		delete [] array;

		this->wrap = false;
	}
	ArrayObjectPrimitive(std::initializer_list<T> init, ThreadContext* ctx) throw() : IArrayObjectPrimitive<T>(ctx)
	{
		this->raw = new(ctx) RawArrayPrimitive<T>(ctx);
		this->length = 0;

		for ( auto iter = init.begin() ; iter != init.end() ; ++iter ){
			T val = *iter;
			this->raw->addElement(val);
			this->length++;
		}
		this->wrap = false;
	}
	ArrayObjectPrimitive(std::initializer_list<T> init) throw() : IArrayObjectPrimitive<T>(0)
	{
		this->raw = new RawArrayPrimitive<T>();
		this->length = 0;

		for ( auto iter = init.begin() ; iter != init.end() ; ++iter ){
			T val = *iter;
			this->raw->addElement(val);
			this->length++;
		}
		this->wrap = false;
	}
	ArrayObjectPrimitive(RawArrayPrimitive<T>* wrapped, ThreadContext* ctx) throw() :  IArrayObjectPrimitive<T>(ctx) {
		this->wrap = true;
		this->raw = wrapped;
		this->length = this->raw->size();
	}
	ArrayObjectPrimitive(const ArrayObjectPrimitive<T>& wrapped) throw() :  IArrayObjectPrimitive<T>(nullptr) {
		this->wrap = false;
		this->raw = new RawArrayPrimitive<T>();

		int maxLoop =wrapped.length;
		for(int i = 0; i != maxLoop; ++i){
			T val = wrapped.get(i);
			this->raw->addElement(val);
		}

		this->length = this->raw->size();
	}
	virtual ~ArrayObjectPrimitive() throw() {
		__releaseRegerences(false, nullptr);
	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(!this->wrap && this->raw != nullptr){
			delete this->raw;
			this->raw = nullptr;
		}
	}
	void append(const T val) throw() {
		this->raw->addElement(val);
		this->length++;
	}

	IArrayObjectPrimitive<T>* clone(ThreadContext* ctx) throw() {
		ArrayObjectPrimitive<T>* cloned = new(ctx) ArrayObjectPrimitive<T>(this, ctx);

		return cloned;
	}
	IArrayObjectPrimitive<T>* clone() throw() {
		ArrayObjectPrimitive<T>* cloned = new ArrayObjectPrimitive<T>(this, nullptr);

		return cloned;
	}
private:
	bool wrap;
};

} /* namespace alinous */

#endif /* BASELIB_ARRAYOBJECTPRIMITIVE_H_ */
