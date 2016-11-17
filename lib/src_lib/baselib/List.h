/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_LIST_H_
#define BASELIB_LIST_H_


namespace java { namespace lang{
class IObject;
}}


namespace alinous {
class ThreadContext;
}


namespace java {
namespace util {

using namespace alinous;
using namespace java::lang;

template <typename T> class Iterator;


template <typename T>
class List : public virtual IObject{
public:
	List(ThreadContext* ctx) throw() : IObject(ctx) {}
	virtual ~List() throw() {}

	virtual void add(T* obj, ThreadContext* ctx) = 0;
	virtual void add(int index, T* element, ThreadContext* ctx) = 0;
	virtual void addAll(List<T>* list, ThreadContext* ctx) = 0;
	virtual void clear(ThreadContext* ctx) = 0;
	virtual bool contains(T* o, ThreadContext* ctx) = 0;
	virtual T* get(int index, ThreadContext* ctx) = 0;
	virtual T* set(int index, T* element, ThreadContext* ctx) = 0;

	virtual int indexOf(T* o,ThreadContext* ctx) = 0;
	virtual bool isEmpty(ThreadContext* ctx) = 0;
	virtual Iterator<T> *iterator(ThreadContext* ctx) = 0;
	virtual T* remove(int index, ThreadContext* ctx) = 0;
	virtual bool remove(T* o, ThreadContext* ctx) = 0;
	virtual int size(ThreadContext* ctx) = 0;
	virtual List<T>* subList(int fromIndex, int toIndex, ThreadContext* ctx) = 0;

	virtual ArrayObject<T>* toArray(IArrayObject<T>* dummy, ThreadContext* ctx) = 0;

public:
	static void __cleanUp(ThreadContext* ctx){}
};


}} /* namespace alinous */

#endif /* BASELIB_LIST_H_ */
