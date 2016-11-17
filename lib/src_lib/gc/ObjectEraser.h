/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef GC_OBJECTERASER_H_
#define GC_OBJECTERASER_H_

namespace java { namespace lang{
class IObject;
}}

namespace alinous {

using namespace java::lang;

class ThreadContext;
template <typename T> class RawArrayPrimitive;

class ObjectEraser {
public:
	class RemovalPair {
	public:
		RemovalPair(IObject* obj, IObject* owner) throw() : obj(obj), owner(owner) {}
		IObject* const obj;
		IObject* const owner;
	};

	ObjectEraser(ThreadContext* ctx, const wchar_t* file, int line, const wchar_t* clsstr, const wchar_t* funcstr) throw();

private:
	void setup(ThreadContext* ctx, const wchar_t* file, int line, const wchar_t* clsstr, const wchar_t* funcstr) throw();
public:

	~ObjectEraser() throw();
	void releaseAll() throw();

	void add(IObject* obj, IObject* owner) const throw();

private:
	RawArrayPrimitive<const RemovalPair*> *list;
	ThreadContext* ctx;
	const wchar_t* file;
	const wchar_t* clsstr;
	const wchar_t* funcstr;
	int line;
};

} /* namespace alinous */

#endif /* GC_OBJECTERASER_H_ */
