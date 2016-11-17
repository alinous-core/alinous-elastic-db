/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_IARRAYOBJECT_H_
#define BASELIB_IARRAYOBJECT_H_

namespace alinous {

class IArrayObjectBase {
public:
	IArrayObjectBase() = default;
	IArrayObjectBase(ThreadContext* ctx) throw() {

	}
	virtual ~IArrayObjectBase(){
	}

	virtual void arraycopy(int srcPos, IArrayObjectBase* dest, int destPos, int length, ThreadContext* ctx)
	{
		arraycopy(srcPos, dest, destPos, length, ctx);
	}

};

} /* namespace alinous */

#endif /* BASELIB_IARRAYOBJECT_H_ */
