/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "includes.h"

namespace alinous {
namespace util {

UnicodeString* AlinousDebug::scanf(ThreadContext* ctx){
	char str[1024]{};
	int ret = ::scanf("%s", str);
	if(ret < 0){
		return nullptr;
	}

	UnicodeString* uni = new(ctx) UnicodeString(str, ctx);

	return uni;
}

} /* namespace util */
} /* namespace alinous */
