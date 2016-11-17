/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ALINOUSDEBUG_H_
#define BASELIB_ALINOUSDEBUG_H_

namespace alinous {
class ThreadContext;
}


namespace alinous {
namespace util {

using namespace alinous;

class AlinousDebug {
public:
	static UnicodeString* scanf(ThreadContext* ctx);
};

} /* namespace util */
} /* namespace alinous */

#endif /* BASELIB_ALINOUSDEBUG_H_ */
