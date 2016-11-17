/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#ifndef BASELIB_IO_CHARSET_CODERRESULT_H_
#define BASELIB_IO_CHARSET_CODERRESULT_H_

namespace java { namespace lang{
class IObject;
}}

namespace alinous {
class ThreadContext;
}


namespace java {
namespace nio {
namespace charset {

using namespace java::lang;
using namespace alinous;

class CoderResult : public IObject {
public:
	static const int CR_UNDERFLOW  = 0;
	static const int CR_OVERFLOW   = 1;
	static const int CR_ERROR_MIN  = 2;
	static const int CR_MALFORMED  = 2;
	static const int CR_UNMAPPABLE = 3;

    // indicating underflow error type
    static const int TYPE_UNDERFLOW = 1;
    // indicating overflow error type
    static const int TYPE_OVERFLOW = 2;
    // indicating malformed-input error type
    static const int TYPE_MALFORMED_INPUT = 3;
    // indicating unmappable character error type
    static const int TYPE_UNMAPPABLE_CHAR = 4;

	static CoderResult __UNDERFLOW;
	static CoderResult __OVERFLOW;
	constexpr static CoderResult* UNDERFLOW{&__UNDERFLOW};
	constexpr static CoderResult* OVERFLOW{&__OVERFLOW};

	CoderResult(int type, int length) : IObject(0), type(type), length(length){
	}

	CoderResult(int type, int length, ThreadContext* ctx) : IObject(ctx), type(type), length(length) {
	}
	~CoderResult(){};

	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw() {

	}

	static CoderResult* malformedForLength(int length, ThreadContext* ctx){
		return new CoderResult(CR_MALFORMED, length, ctx);
	}

    bool isUnderflow(ThreadContext* ctx){
        return this->type == TYPE_UNDERFLOW;
    }
    bool isOverflow(){
        return this->type == TYPE_OVERFLOW;
    }
    bool isUnmappable(){
        return this->type == TYPE_UNMAPPABLE_CHAR;
    }
	static CoderResult* unmappableForLength(int length, ThreadContext* ctx){
		if (length > 0) {
			CoderResult* r = new CoderResult(TYPE_UNMAPPABLE_CHAR, length);
			return r;
		}
		// niochar.08=The length must be positive: {0}.
		throw new IllegalArgumentException(ctx);
	}


	int type;
	int length;

public:
	static void __cleanUp(ThreadContext* ctx){

	}


};

}}} /* namespace alinous */


#endif /* BASELIB_IO_CHARSET_CODERRESULT_H_ */
