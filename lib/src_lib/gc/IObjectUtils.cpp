/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "include/global.h"

namespace alinous {

void IObjectUtils::resigter(GCObject *ptr, ThreadContext* ctx) throw() {
	__GC_ALLOC(ptr, GCObject);
}

void IObjectUtils::forceReleaseRefs(GCObject *ptr, ThreadContext* ctx, bool lostExt) throw() {


	bool lastValue = ctx->setLostExt(lostExt);
	ctx->incGcDenial();
	ptr->__releaseRegerences(true, ctx);
	ctx->decGcDenial();
	ctx->setLostExt(lastValue);

	ptr->released = true;
}

void IObjectUtils::deleteIObject(GCObject *ptr) throw() {
	delete ptr;
}

}

