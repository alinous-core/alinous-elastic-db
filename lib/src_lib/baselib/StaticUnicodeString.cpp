/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "includes.h"

namespace java { namespace lang {


CharSequence* StaticUnicodeString::subSequence(int start, int end, ThreadContext* ctx){
	UnicodeString* str = new UnicodeString(buff, start, end - start, ctx);

	return str;
}

}} /* namespace alinous */

