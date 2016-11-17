/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ITERATOR_H_
#define BASELIB_ITERATOR_H_

namespace alinous {
class ThreadContext;
}

namespace java { namespace lang{
class IObject;
}}

namespace java {
namespace util {

using namespace alinous;
using namespace java::lang;


template <typename T>
class Iterator : public virtual IObject {
public:
	Iterator(ThreadContext* ctx) throw() : IObject(ctx)
	{

	}
	virtual ~Iterator() throw() {}

	virtual bool hasNext(ThreadContext* ctx) = 0;
	virtual T* next(ThreadContext* ctx) = 0;
	virtual void remove(ThreadContext* ctx) = 0;

public:
	static void __cleanUp(ThreadContext* ctx) throw()
	{
	}
};

}} /* namespace alinous */

#endif /* BASELIB_ITERATOR_H_ */
