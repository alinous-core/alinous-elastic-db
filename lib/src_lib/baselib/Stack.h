/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_STACK_H_
#define BASELIB_STACK_H_

namespace java { namespace lang{
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java { namespace util {

using namespace alinous;
using namespace java::lang;



template <typename T>
class Stack final : public ArrayList<T> {
public:
	Stack(ThreadContext* ctx) throw() : IObject(ctx), ArrayList<T>(ctx) {}
	virtual ~Stack() throw() {
	}

	T* peek(ThreadContext* ctx) throw() {
		int index = ArrayList<T>::size(ctx) - 1;
		return ArrayList<T>::get(index, ctx);
	}

	void push(T* obj, ThreadContext* ctx) throw() {
		 ArrayList<T>::add(obj, ctx);
	}
	T* pop(ThreadContext* ctx) throw() {
		int index = ArrayList<T>::size(ctx) - 1;
		T* obj = ArrayList<T>::get(index, ctx);

		ArrayList<T>::remove(index, ctx);
		return obj;
	}
};

}} /* namespace alinous */

#endif /* BASELIB_STACK_H_ */
