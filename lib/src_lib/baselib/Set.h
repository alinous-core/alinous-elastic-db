/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_SET_H_
#define BASELIB_SET_H_

namespace java { namespace lang{
class IObject;
}}

namespace java { namespace util {

using namespace java::lang;

template <typename T> class Iterator;

template <typename T>
class Set : public virtual IObject {
public:
	Set(ThreadContext* ctx) :IObject(ctx) {}
	virtual ~Set() {}

	virtual void add(T* e, ThreadContext* ctx) = 0;
	virtual void clear(ThreadContext* ctx) = 0;
	virtual Iterator<T>* iterator(ThreadContext* ctx) = 0;
	virtual void remove(T* o, ThreadContext* ctx) = 0;
	virtual int size(ThreadContext* ctx) = 0;
	virtual bool isEmpty(ThreadContext* ctx) = 0;
	virtual bool equals(Set<T>* o, ThreadContext* ctx) = 0;

private:

};

}} /* namespace alinous */

#endif /* BASELIB_SET_H_ */
