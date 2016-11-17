/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_CLONEABLE_H_
#define BASELIB_CLONEABLE_H_

namespace java { namespace lang {

class Cloneable : public virtual IObject {
public:
	Cloneable(ThreadContext* ctx) throw() : IObject(ctx) {}

	virtual ~Cloneable() throw() {}

public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}} /* namespace java lang */

#endif /* BASELIB_CLONEABLE_H_ */
