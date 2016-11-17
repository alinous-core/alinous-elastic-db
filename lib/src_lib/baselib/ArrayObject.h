/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ARRAYOBJECT_H_
#define BASELIB_ARRAYOBJECT_H_


//#define AL_ARRAY_DEBUG

namespace java { namespace lang{
class IObject;
}}

namespace alinous {

using namespace java::lang;



class ThreadContext;
template <typename T, typename C> class RawArray;

template <typename T>
class IArrayObject : public IObject, public IArrayObjectBase {
public:
	IArrayObject() = default;
	IArrayObject(IArrayObject &base) = default;
	inline IArrayObject(ThreadContext* ctx) throw() : IObject(ctx), IArrayObjectBase(ctx) {}
	inline IArrayObject(int length, ThreadContext* ctx) throw() : IObject(ctx), IArrayObjectBase(ctx), length(length) {}
	inline IArrayObject(int length, RawArray<T>* raw, ThreadContext* ctx) throw() : IObject(ctx), IArrayObjectBase(ctx), length(length), raw(raw) {}
	inline IArrayObject(std::initializer_list<T*> init, ThreadContext* ctx) throw() : IObject(ctx), IArrayObjectBase(ctx),
			length(0), raw(new(ctx) RawArray<T>(ctx))
	{
		for ( auto iter = init.begin() ; iter != init.end() ; ++iter ){
			T* ptr = *iter;
			this->raw->addElement(ptr);
			this->length++;

			__GC_INS(this, ptr, T);
		}
	}

	virtual ~IArrayObject() throw(){
		ThreadContext *ctx = ThreadContext::getCurentContext();
		__releaseRegerences(false, ctx);
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(this->raw != nullptr){
			#ifdef AL_ARRAY_DEBUG
			printDebug();
			#endif

			auto it = this->raw->iterator();
			while(it.hasNext()){
				T* element = it.next();
				__GC_DEC(this, element, T);
			}

			delete this->raw;
			this->raw = nullptr;
		}
	}
	inline void remove(int i, ThreadContext* ctx) throw(){
		T* ptr = this->raw->get(i);
		__GC_DEC(this, ptr, T);

		this->raw->remove(i);
	}
	inline void append(T* ptr, ThreadContext* ctx) throw(){
		__GC_INS(this, ptr, T);

		this->raw->addElement(ptr);
		this->length++;
	}
	inline T* get(int n) throw() {
		return this->raw->get(n);
	}
	inline int size() throw() {
		return this->raw->size();
	}
	inline void set(T* ptr, int n, ThreadContext* ctx) throw() {
		__GC_INS(this, ptr, T);

		T* last = this->raw->get(n);
		if(last != 0){
			__GC_DEC(this, last, T);
		}

		this->raw->set(n, ptr);

	#ifdef AL_ARRAY_DEBUG
		printDebug();
	#endif

	}
	inline void arraycopy(int srcPos, IArrayObjectBase* dest, int destPos, int length, ThreadContext* ctx) throw() {
		copy(srcPos, (IArrayObject<T>*)dest, destPos, length, ctx);
	};
	inline void copy(int srcPos, IArrayObject<T>* dest, int destPos, int length, ThreadContext* ctx) throw() {
		for(int i = 0; i < length; i++){
			int s = srcPos + i;
			int d = destPos + i;

			dest->set(this->get(s), d, ctx);
		}
	};

	void prefetch(){
		int maxLoop = raw->currentSize >> 4;
		if(maxLoop > 256){
			maxLoop = 256;
		}
		for(int i = 0; i != maxLoop; ++i){
			__builtin_prefetch(this->raw->root + (i * 32));
		}

	}

	int length;
	RawArray<T>* raw;
};

template <typename T>
class ArrayObject : public IArrayObject<T> {
public:
	ArrayObject() = default;

	inline ArrayObject(IArrayObject<T>& base) throw()
	{
		base.copy(0, this, 0, base.length, nullptr);
	}

	inline ArrayObject(ThreadContext* ctx) throw(): IArrayObject<T>(0, ctx != nullptr ? new(ctx) RawArray<T>(ctx) : nullptr, ctx)
	{

	}
	inline ArrayObject(int length, ThreadContext* ctx) throw()
	: IArrayObject<T>(ctx != nullptr ? 0 : length, ctx != nullptr ? new(ctx) RawArray<T>(ctx) : nullptr, ctx)
	{
		/*if(ctx == nullptr){
			this->raw = nullptr;
			this->length = length;
			return;
		}
		this->raw = new(ctx) RawArray<T>();
		this->length = 0;*/
	}
	inline ArrayObject(std::initializer_list<T*> init, ThreadContext* ctx) throw() : IArrayObject<T>(0, new(ctx) RawArray<T>(ctx), ctx)
	{
		for ( auto iter = init.begin() ; iter != init.end() ; ++iter ){
			T* ptr = *iter;
			this->raw->addElement(ptr);
			this->length++;

			__GC_INS(this, ptr, T);
		}
	}
	inline ArrayObject(int size, int paddnull, ThreadContext* ctx) throw() : IArrayObject<T>(size, new(ctx) RawArray<T>(size, ctx), ctx)
	{
		RawArray<T>* raw = this->raw;

		T** ptrptr = raw->root;
		raw->numArray = paddnull;
		raw->cursor = this->raw->root + paddnull;
		::memset(ptrptr, 0, paddnull * sizeof(T*));

		/*
		for(int i = 0; i < paddnull; i++){
			this->raw->addElement(nullptr);
		}*/
	}

	inline ArrayObject(T** array, int size, ThreadContext* ctx) throw() : IArrayObject<T>(size, new(ctx) RawArray<T>(ctx), ctx)
	{
		for(int i = 0; i < size; i++){
			this->raw->addElement(array[i]);
			if(array[i] != 0){
				__GC_INS(this, array[i], T);
			}
		}

		delete [] array;
	}

	inline ArrayObject(ArrayObject<T>* array, ThreadContext* ctx) throw() : IArrayObject<T>(array->length, new(ctx) RawArray<T>(ctx), ctx)
	{
		for(int i = 0; i < this->length; i++){
			T* p = array->get(i);
			this->raw->addElement(p);

			__GC_INS(this, p, T);
		}
	}

	inline ArrayObject(IArrayObject<T>* array, ThreadContext* ctx) throw() : IArrayObject<T>(array->length, new(ctx) RawArray<T>(ctx), ctx)
	{
		for(int i = 0; i < this->length; i++){
			this->raw->addElement(array->get(i));

			__GC_INS(this, array->get(i), T);
		}
	}
	virtual ~ArrayObject() throw() {}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		IArrayObject<T>::__releaseRegerences(prepare, ctx);
	}

#ifdef AL_ARRAY_DEBUG
	void printDebug(){
		int size = this->raw->size();
		for(int i = 0; i < size; i++){
			T* element = this->raw->get(i);
			wprintf(L"element [%d] -> %LX\n", i, (unsigned long long int)element);
		}
	}
#endif


private:

};

} /* namespace alinous */



#endif /* BASELIB_ARRAYOBJECT_H_ */
