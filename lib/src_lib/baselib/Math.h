/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_MATH_H_
#define BASELIB_MATH_H_

namespace alinous {
class ThreadContext;
}

namespace java { namespace lang {

using namespace alinous;

class Math {
public:
	static constexpr double PI{3.141592653589793};
	static constexpr double E{2.718281828459045};

	static int max(int a, int b, ThreadContext* ctx) {
		return a > b ? a : b;
	}
	static int min(int a, int b, ThreadContext* ctx) {
		return a > b ? b : a;
	}

	static double ceil(double a, ThreadContext* ctx) {
		return ::ceil(a);
	}

	static double log(double a, ThreadContext* ctx) {
		return ::log(a);
	}
	static double sqrt(double d, ThreadContext* ctx) {
		return ::sqrt(d);
	}
	static double tan(double d, ThreadContext* ctx) {
		return ::tan(d);
	}
	static double tanh(double d, ThreadContext* ctx){
		return ::tanh(d);
	}
	static double acos(double d) {
		return ::acos(d);
	}

	static double asin(double d, ThreadContext* ctx) {
		return ::asin(d);
	}
	static double atan(double d, ThreadContext* ctx) {
		return ::atan(d);
	}
	static double atan2(double x, double y, ThreadContext* ctx) {
		return ::atan2(y, x);
	}
	static double cbrt(double d, ThreadContext* ctx) {
		return ::cbrt(d);
	}
	static double cos(double d, ThreadContext* ctx) {
		return ::cos(d);
	}
	static double cosh(double d, ThreadContext* ctx) {
		return ::cosh(d);
	}
	static double sin(double d, ThreadContext* ctx) {
		return ::sin(d);
	}
	static double sinh(double d, ThreadContext* ctx) {
		return ::sinh(d);
	}

	static double exp(double d, ThreadContext* ctx) {
		return ::exp(d);
	}
	static double expm1(double d, ThreadContext* ctx) {
		return ::expm1(d);
	}

	static double log10(double d, ThreadContext* ctx) {
		return ::log10(d);
	}
	static double log1p(double d, ThreadContext* ctx) {
		return ::log1p(d);
	}

	static double pow(double x, double y, ThreadContext* ctx) {
		return ::pow(x, y);
	}

	static long round(double d, ThreadContext* ctx) {
		// check for NaN
		if (d != d) {
			return 0L;
		}
		return (long) floor(d + 0.5);
	}
	static int round(float f, ThreadContext* ctx) {
		// check for NaN
		if (f != f) {
			return 0;
		}
		return (int) floor(f + 0.5f);
	}


	static double toRadians(double angdeg, ThreadContext* ctx) {
		return angdeg / 180.0F * PI;
	}
	static double toDegrees(double angrad, ThreadContext* ctx) {
		return angrad * 180 / PI;
	}
	static double abs(double d, ThreadContext* ctx);
	static float abs(float f, ThreadContext* ctx);
	static int abs(int i, ThreadContext* ctx) {
		return i >= 0 ? i : -i;
	}
	static long long abs(long long i, ThreadContext* ctx) {
		return i >= 0 ? i : -i;
	}


};


class MathUnsigned {
public:
	static u_int32_t max(u_int32_t a, u_int32_t b, ThreadContext* ctx) {
		return a > b ? a : b;
	}
	static u_int32_t min(u_int32_t a, u_int32_t b, ThreadContext* ctx) {
		return a > b ? b : a;
	}
public:
	static void __cleanUp(ThreadContext* ctx)
	{
	}
};

}} /* namespace alinous */

#endif /* BASELIB_MATH_H_ */
