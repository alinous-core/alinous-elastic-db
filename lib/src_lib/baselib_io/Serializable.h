/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_SERIALIZABLE_H_
#define BASELIB_IO_SERIALIZABLE_H_


namespace java { namespace io {

using namespace java::lang;

class Serializable : public virtual IObject {
public:
	Serializable(ThreadContext* ctx) : IObject(ctx) {}
	virtual ~Serializable(){}

};

}}


#endif /* BASELIB_IO_SERIALIZABLE_H_ */
