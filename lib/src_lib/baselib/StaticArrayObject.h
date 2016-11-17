/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"

#ifndef BASELIB_STATICARRAYOBJECT_H_
#define BASELIB_STATICARRAYOBJECT_H_


namespace alinous {

template <typename T>
class StaticArrayObject final : public IArrayObject<T> {
private:
	bool ptrInit;
public:
	StaticArrayObject() :  IArrayObject<T>(0, nullptr), ptrInit(false) {}
	StaticArrayObject(const StaticArrayObject<T>& base) : IArrayObject<T>(base.length, nullptr), ptrInit(false) {
	}

	StaticArrayObject(const std::initializer_list<T>& init): IArrayObject<T>(init.size(), nullptr), ptrInit(false)
	{
		this->raw = new RawArray<T>(init.size());
		for (auto iter = init.begin() ; iter != init.end() ; ++iter ){
			const T* val = iter;

			T* copy = new T(*val);
			this->raw->addElement(copy);
		}
	}
	StaticArrayObject(const std::initializer_list<T*>& init): IArrayObject<T>(init.size(), nullptr), ptrInit(true)
	{
		this->raw = new RawArray<T>(init.size());
		for (auto iter = init.begin() ; iter != init.end() ; ++iter ){
			T* const * val = iter;

			this->raw->addElement(*val);
		}
	}
	virtual ~StaticArrayObject(){
		__releaseRegerences(false, nullptr);
	}
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(this->raw != nullptr && !ptrInit){
			const int maxLoop = this->raw->size();
			for(int i = 0; i < maxLoop; i++){
				T* ptr = this->raw->get(i);
				delete ptr;
			}

			delete this->raw; this->raw = nullptr;
		}
	}

	void set(T* ptr, int n, ThreadContext* ctx){};
};


} /* namespace alinous */

#endif /* BASELIB_STATICARRAYOBJECT_H_ */
