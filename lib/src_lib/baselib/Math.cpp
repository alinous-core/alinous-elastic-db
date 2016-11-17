/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "includes.h"

namespace java { namespace lang {

double Math::abs(double d, ThreadContext* ctx) {
	long long bits = Double::doubleToLongBits(d, ctx);
	bits &= 0x7fffffffffffffffL;
    return Double::longBitsToDouble(bits, ctx);
}
float Math::abs(float f, ThreadContext* ctx) {
    int bits = Float::floatToIntBits(f, ctx);
    bits &= 0x7fffffff;
    return Float::intBitsToFloat(bits, ctx);
}

}}


