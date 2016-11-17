/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ARRAYLISTITERATOR_H_
#define BASELIB_ARRAYLISTITERATOR_H_

namespace alinous {

template <typename T, typename C> class RawArray;
template <typename T, typename C> class RawArrayIterator;

}

namespace java{
namespace util {

template <typename T> class Iterator;

template <typename T>
class ArrayListIterator final : public Iterator<T> {
public:
	ArrayListIterator(ThreadContext* ctx) : IObject(ctx),  Iterator<T>(ctx), baseIt(0)
	{

	}
	virtual ~ArrayListIterator(){
		__releaseRegerences(false, nullptr);
	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(this->baseIt != nullptr){
			delete this->baseIt;
			this->baseIt = nullptr;
		}
	}
	void init(RawArray<T>* ptr, ThreadContext* ctx){
		this->baseIt = new RawArrayIterator<T>(ptr);
	}
	virtual bool hasNext(ThreadContext* ctx) {
		return this->baseIt->hasNext();
	}
	virtual T* next(ThreadContext* ctx){
		return this->baseIt->next();
	}
	virtual void remove(ThreadContext* ctx){
		this->baseIt->remove();
	}
private:
	RawArrayIterator<T> *baseIt;
};

}} /* namespace alinous */

#endif /* BASELIB_ARRAYLISTITERATOR_H_ */
