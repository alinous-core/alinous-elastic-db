/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_STATICARRAYOBJECTPRIMITIVE_H_
#define BASELIB_STATICARRAYOBJECTPRIMITIVE_H_

namespace alinous {


template <typename T>
class StaticArrayObjectPrimitive : public IArrayObjectPrimitive<T> {
public:
	StaticArrayObjectPrimitive() : IArrayObjectPrimitive<T>(0, nullptr) {
		this->raw = nullptr;
	}

	StaticArrayObjectPrimitive(const StaticArrayObjectPrimitive& base): IArrayObjectPrimitive<T>(base.raw->size(), nullptr){
		this->raw = new RawArrayPrimitive<T>(16);
		int maxLoop = base.raw->size();
		for(int i = 0; i < maxLoop; ++i){
			this->raw->addElement(base.raw->get(i));
		}

	}

	StaticArrayObjectPrimitive(const std::initializer_list<const T>& init): IArrayObjectPrimitive<T>(init.size(), nullptr)
	{
		this->raw = new RawArrayPrimitive<T>(16);
		for (auto iter = init.begin() ; iter != init.end() ; ++iter ){
			T val = *iter;
			this->raw->addElement(val);
		}
	}

	virtual ~StaticArrayObjectPrimitive(){
		__releaseRegerences(false, nullptr);
	}

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {
		if(this->raw != nullptr){
			delete this->raw;
			this->raw = nullptr;
		}
	}

	void set(T v, int index, ThreadContext* ctx){};

	int size() const {
		return this->raw->size();
	}
	IArrayObjectPrimitive<T>* clone(ThreadContext* ctx){
		ArrayObjectPrimitive<T>* cloned = new ArrayObjectPrimitive<T>(this, ctx);

		return cloned;
	}
};


} /* namespace alinous */

#endif /* BASELIB_STATICARRAYOBJECTPRIMITIVE_H_ */
