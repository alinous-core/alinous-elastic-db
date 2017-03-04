/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"

namespace java {
namespace lang {

#ifdef COUNT_IOBJECT
int IObject::newCtr = 0;
bool IObject::startCtr = false;
#endif



UnicodeString* IObject::toString(ThreadContext* ctx) {
	return new(ctx) UnicodeString(L"Object", ctx);
}


}}
