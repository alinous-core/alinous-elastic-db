/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_ENUMBASE_H_
#define BASELIB_ENUMBASE_H_

namespace alinous {

class ThreadContext;

class EnumBase {
public:
	int data;
	EnumBase() = default;
	EnumBase(const EnumBase& base) = default;
	constexpr explicit EnumBase(const int ord) : data(ord) {}

	constexpr operator int() const { return data; }

	constexpr int ordinal(const ThreadContext* const ctx) const {
		return data;
	}
};



} /* namespace alinous */

#endif /* BASELIB_ENUMBASE_H_ */
