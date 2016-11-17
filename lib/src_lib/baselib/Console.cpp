/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "includes.h"

namespace alinous { namespace util {

void out(UnicodeString *str, ThreadContext* ctx)
{
	const wchar_t* wstr = str->towString();
	printf("%S\n", wstr);
}

void __cleanUp(ThreadContext* ctx){
}

}}
