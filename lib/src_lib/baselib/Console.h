/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_CONSOLE_H_
#define BASELIB_CONSOLE_H_

namespace alinous { namespace util {

class Console {
public:
	static void out(UnicodeString *str, ThreadContext* ctx);

public:
	static void __cleanUp(ThreadContext* ctx);
};

}} /* namespace alinous */


#endif /* BASELIB_CONSOLE_H_ */
