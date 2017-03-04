/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#include "include/global.h"

namespace java { namespace lang {

Character::Character(wchar_t value, ThreadContext* ctx) : IObject(ctx) {
	this->value = value;
}
Character::~Character(){

}
wchar_t Character::charValue(ThreadContext* ctx) throw() {
	return value;
}

UnicodeString* Character::toString(wchar_t ch, ThreadContext* ctx) throw() {
	UnicodeString* str = new(ctx) UnicodeString(ctx);
	str->append(ch, ctx);
	return str;
}

char Character::toUpperCase(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_toupper(codePoint);
}
int Character::toUpperCase(int codePoint, ThreadContext* ctx) throw() {
	return u_toupper(codePoint);
}

wchar_t Character::toTitleCase(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_totitle(codePoint);

}
int Character::toTitleCase(int codePoint, ThreadContext* ctx) throw() {
	return u_totitle(codePoint);
}

wchar_t Character::reverseBytes(wchar_t c, ThreadContext* ctx) throw() {
	return (wchar_t)((c<<8) | (c>>8));
}

wchar_t Character::toLowerCase(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_tolower(codePoint);
}
int Character::toLowerCase(int codePoint, ThreadContext* ctx) throw() {
	return u_tolower(codePoint);
}

bool Character::isTitleCase(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_istitle(codePoint);
}
bool Character::isTitleCase(int codePoint, ThreadContext* ctx)  throw() {
	return u_istitle(codePoint);
}

bool Character::isUnicodeIdentifierPart(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isIDPart(codePoint);
}
bool Character::isUnicodeIdentifierPart(int codePoint, ThreadContext* ctx) throw() {
	return u_isIDPart(codePoint);
}

bool Character::isUnicodeIdentifierStart(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isIDStart(codePoint);
}
bool Character::isUnicodeIdentifierStart(int codePoint, ThreadContext* ctx) throw() {
	return u_isIDStart(codePoint);
}

bool Character::isUpperCase(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isupper(codePoint);
}
bool Character::isUpperCase(int codePoint, ThreadContext* ctx) throw() {
	return u_isupper(codePoint);
}

bool Character::isWhitespace(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isWhitespace(codePoint);
}
bool Character::isWhitespace(int codePoint, ThreadContext* ctx) throw() {
	return u_isWhitespace(codePoint);
}

bool Character::isSpaceChar(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isJavaSpaceChar(codePoint);
}
bool Character::isSpaceChar(int codePoint, ThreadContext* ctx) throw() {
	return u_isJavaSpaceChar(codePoint);
}

bool Character::isSpace(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isspace(codePoint);
}
bool Character::isSpace(int codePoint, ThreadContext* ctx) throw() {
	return u_isspace(codePoint);
}

bool Character::isLowerCase(wchar_t ch, ThreadContext* ctx)  throw() {
	int codePoint = (int)ch;
	return u_islower(codePoint);
}
bool Character::isLowerCase(int codePoint, ThreadContext* ctx) throw() {
	return u_islower(codePoint);
}

bool Character::isLetterOrDigit(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isalnum(codePoint);
}
bool Character::isLetterOrDigit(int codePoint, ThreadContext* ctx) throw() {
	return u_isalnum(codePoint);
}

bool Character::isLetter(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isalpha(codePoint);

}
bool Character::isLetter(int codePoint, ThreadContext* ctx) throw() {
	return u_isalpha(codePoint);
}

bool Character::isJavaIdentifierStart(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isJavaIDStart(codePoint);
}
bool Character::isJavaIdentifierStart(int codePoint, ThreadContext* ctx) throw() {
	return u_isJavaIDStart(codePoint);
}

bool Character::isJavaIdentifierPart(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isJavaIDPart(codePoint);
}
bool Character::isJavaIdentifierPart(int codePoint, ThreadContext* ctx) throw() {
	return u_isJavaIDPart(codePoint);
}

bool Character::isISOControl(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isISOControl(codePoint);
}
bool Character::isISOControl(int codePoint, ThreadContext* ctx) throw() {
	return u_isISOControl(codePoint);
}

bool Character::isIdentifierIgnorable(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isIDIgnorable(codePoint);
}
bool Character::isIdentifierIgnorable(int codePoint, ThreadContext* ctx) throw() {
	return u_isIDIgnorable(codePoint);
}

bool Character::isDigit(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isdigit(codePoint);
}
bool Character::isDigit(int codePoint, ThreadContext* ctx) throw() {
	return u_isdigit(codePoint);
}

bool Character::isDefined(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isdefined(codePoint);
}
bool Character::isDefined(int codePoint, ThreadContext* ctx) throw() {
	return u_isdefined(codePoint);
}

bool Character::isMirrored(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_isMirrored(codePoint);
}
bool Character::isMirrored(int codePoint, ThreadContext* ctx) throw() {
	return u_isMirrored(codePoint);
}

u_int8_t Character::getDirectionality(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_charDirection(codePoint);
}
u_int8_t Character::getDirectionality(int codePoint, ThreadContext* ctx) throw() {
	return u_charDirection(codePoint);
}

int Character::getType(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_charType(codePoint);
}
int Character::getType(int codePoint, ThreadContext* ctx) throw() {
	return u_charType(codePoint);
}

int Character::getNumericValue(wchar_t ch, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_getNumericValue(codePoint);
}
int Character::getNumericValue(int codePoint, ThreadContext* ctx) throw() {
	return u_getNumericValue(codePoint);
}

wchar_t Character::forDigit(int digit, int radix, ThreadContext* ctx) throw() {
	return u_forDigit(digit, radix);
}

int Character::digit(wchar_t ch, int radix, ThreadContext* ctx) throw() {
	int codePoint = (int)ch;
	return u_digit(codePoint, radix);
}
int Character::digit(int codePoint, int radix, ThreadContext* ctx) throw() {
	return u_digit(codePoint, radix);
}


constexpr bool Character::isSurrogatePair(wchar_t high, wchar_t low, ThreadContext* ctx) throw() {
	return (isHighSurrogate(high, ctx) && isLowSurrogate(low, ctx));
}
constexpr bool Character::isHighSurrogate(wchar_t ch, ThreadContext* ctx) throw() {
	return (MIN_HIGH_SURROGATE <= ch && MAX_HIGH_SURROGATE >= ch);
}
constexpr bool Character::isLowSurrogate(wchar_t ch, ThreadContext* ctx) throw() {
	return (MIN_LOW_SURROGATE <= ch && MAX_LOW_SURROGATE >= ch);
}
int Character::charCount(int codePoint, ThreadContext* ctx) throw() {
    return (codePoint >= 0x10000 ? 2 : 1);
}
int Character::toCodePoint(wchar_t high, wchar_t low, ThreadContext* ctx) throw() {
	int h = (high & 0x3FF) << 10;
	int l = low & 0x3FF;
	return (h | l) + 0x10000;
}

int Character::codePointAt(CharSequence* seq, int index, ThreadContext* ctx) throw() {
	if (seq == 0) {
		throw new(ctx) NullPointerException(ctx);
	}
	int len = seq->length(ctx);
	if (index < 0 || index >= len) {
		throw new(ctx) StringIndexOutOfBoundsException(index, ctx);
	}

	wchar_t high = seq->charAt(index++, ctx);
	if (index >= len) {
		return high;
	}
	wchar_t low = seq->charAt(index, ctx);
	if (isSurrogatePair(high, low, ctx)) {
		return toCodePoint(high, low, ctx);
	}
	return high;
}
int Character::codePointAt(ArrayObjectPrimitive<wchar_t>* seq, int index, ThreadContext* ctx) throw() {
	if (seq == 0) {
		throw new(ctx) NullPointerException(ctx);
	}
	int len = seq->length;
	if (index < 0 || index >= len) {
		throw new(ctx) ArrayIndexOutOfBoundsException(index, ctx);
	}

	wchar_t high = seq->get(index++);
	if (index >= len) {
		return high;
	}
	wchar_t low = seq->get(index);
	if (isSurrogatePair(high, low, ctx)) {
		return toCodePoint(high, low, ctx);
	}
	return high;
}
int Character::codePointAt(ArrayObjectPrimitive<wchar_t>* seq, int index, int limit, ThreadContext* ctx) throw() {
	if (index < 0 || index >= limit || limit < 0 || limit > seq->length) {
		throw new(ctx) ArrayIndexOutOfBoundsException(ctx);
	}

	char high = seq->get(index++);
	if (index >= limit) {
		return high;
	}
	char low = seq->get(index);
	if (isSurrogatePair(high, low, ctx)) {
		return toCodePoint(high, low, ctx);
	}
	return high;
}

int Character::codePointBefore(CharSequence* seq, int index, ThreadContext* ctx) throw() {
	if (seq == nullptr) {
		throw new(ctx) NullPointerException(ctx);
	}
	int len = seq->length(ctx);
	if (index < 1 || index > len) {
		throw new(ctx) StringIndexOutOfBoundsException(index, ctx);
	}

	wchar_t low = seq->charAt(--index, ctx);
	if (--index < 0) {
		return low;
	}
	wchar_t high = seq->charAt(index, ctx);
	if (isSurrogatePair(high, low, ctx)) {
		return toCodePoint(high, low, ctx);
	}
	return low;
}

int Character::codePointCount(CharSequence* seq, int beginIndex, int endIndex, ThreadContext* ctx) throw() {
	if (seq == nullptr) {
		throw new(ctx) NullPointerException(ctx);
	}
	int len = seq->length(ctx);
	if (beginIndex < 0 || endIndex > len || beginIndex > endIndex) {
		throw new(ctx) IndexOutOfBoundsException(ctx);
	}

	int result = 0;
	for (int i = beginIndex; i < endIndex; i++) {
		wchar_t c = seq->charAt(i, ctx);
		if (isHighSurrogate(c, ctx)) {
			if (++i < endIndex) {
				c = seq->charAt(i, ctx);
				if (!isLowSurrogate(c, ctx)) {
					result++;
				}
			}
		}
		result++;
	}
	return result;
}
constexpr bool Character::isValidCodePoint(int codePoint, ThreadContext* ctx) throw() {
	return (MIN_CODE_POINT <= codePoint && MAX_CODE_POINT >= codePoint);

}
constexpr bool Character::isSupplementaryCodePoint(int codePoint, ThreadContext* ctx) throw() {
	return (MIN_SUPPLEMENTARY_CODE_POINT <= codePoint && MAX_CODE_POINT >= codePoint);
}

ArrayObjectPrimitive<wchar_t>* Character::toChars(int codePoint, ThreadContext* ctx) throw() {
	if (isSupplementaryCodePoint(codePoint, ctx)) {
		int cpPrime = codePoint - 0x10000;
		int high = 0xD800 | ((cpPrime >> 10) & 0x3FF);
		int low = 0xDC00 | (cpPrime & 0x3FF);

		wchar_t*  array = new wchar_t [2]  { (wchar_t)high, (wchar_t)low };
		//wchar_t array[2] = { (wchar_t)high, (wchar_t)low };
		ArrayObjectPrimitive<wchar_t>* ret = new(ctx) ArrayObjectPrimitive<wchar_t>(array, 2, ctx);

		return ret;
	}

	wchar_t*  array = new wchar_t [1]  { (wchar_t) codePoint };
	//wchar_t array[1] = { (wchar_t) codePoint };
	ArrayObjectPrimitive<wchar_t>* ret = new(ctx) ArrayObjectPrimitive<wchar_t>(array, 1, ctx);
	return ret;
}

int Character::toChars(int codePoint, ArrayObjectPrimitive<wchar_t>* dst, int dstIndex, ThreadContext* ctx) throw() {
	if (!isValidCodePoint(codePoint, ctx)) {
		throw new(ctx) IllegalArgumentException(ctx);
	}
	if (dst == 0) {
		throw new(ctx) NullPointerException(ctx);
	}
	if (dstIndex < 0 || dstIndex >= dst->length) {
		throw new(ctx) IndexOutOfBoundsException(ctx);
	}

	if (isSupplementaryCodePoint(codePoint, ctx)) {
		if (dstIndex == dst->length - 1) {
			throw new(ctx) IndexOutOfBoundsException(ctx);
		}
		// See RFC 2781, Section 2.1
		// http://www.faqs.org/rfcs/rfc2781.html
		int cpPrime = codePoint - 0x10000;
		int high = 0xD800 | ((cpPrime >> 10) & 0x3FF);
		int low = 0xDC00 | (cpPrime & 0x3FF);
		dst->set((wchar_t) high, dstIndex, ctx);
		dst->set((wchar_t) low, dstIndex + 1,ctx);

		return 2;
	}

	dst->set((wchar_t) codePoint, dstIndex, ctx);

	return 1;
}



}}

