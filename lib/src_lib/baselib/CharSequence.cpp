/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"


namespace java { namespace lang {

CharSequence::CharSequence() throw() : IObject(), __hashCode(0) {}
CharSequence::CharSequence(ThreadContext* ctx) throw() : IObject(ctx), __hashCode(0) {}


}}




