/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace alinous {

IObject* StaticInitializer::reg(IObject *ptr)throw()
{
	return ptr;
}
IObject* StaticInitializer::inc(IObject *ptr) throw() {

	ThreadContext* ctx = ThreadContext::newThreadContext();
	ctx->ins(nullptr, ptr);
	delete ctx;

	return ptr;
}
IObject* StaticInitializer::dec(IObject *ptr) throw() {
	ThreadContext* ctx = ThreadContext::newThreadContext();
	ctx->dec(nullptr, ptr);
	delete ctx;

	return ptr;
}

}
