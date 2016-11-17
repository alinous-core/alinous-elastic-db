/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */

#ifndef BASELIB_CHARACTER_H_
#define BASELIB_CHARACTER_H_

namespace java { namespace lang {

using namespace alinous;
using namespace icu;

class Character final : public virtual IObject {
public:
	wchar_t value;
	Character(wchar_t value, ThreadContext* ctx);
	virtual ~Character();
	wchar_t charValue(ThreadContext* ctx) throw();
	static UnicodeString* toString(wchar_t ch, ThreadContext* ctx) throw();
	static char toUpperCase(wchar_t ch, ThreadContext* ctx) throw();
	static int toUpperCase(int codePoint, ThreadContext* ctx) throw();
	static wchar_t toTitleCase(wchar_t ch, ThreadContext* ctx) throw();
	static int toTitleCase(int codePoint, ThreadContext* ctx) throw();
	static wchar_t reverseBytes(wchar_t c, ThreadContext* ctx) throw();
	static wchar_t toLowerCase(wchar_t ch, ThreadContext* ctx) throw();
	static int toLowerCase(int codePoint, ThreadContext* ctx) throw();
	static bool isTitleCase(wchar_t ch, ThreadContext* ctx) throw();
	static bool isTitleCase(int codePoint, ThreadContext* ctx) throw();
	static bool isUnicodeIdentifierPart(wchar_t ch, ThreadContext* ctx) throw();
	static bool isUnicodeIdentifierPart(int codePoint, ThreadContext* ctx) throw();
	static bool isUnicodeIdentifierStart(wchar_t ch, ThreadContext* ctx) throw();
	static bool isUnicodeIdentifierStart(int codePoint, ThreadContext* ctx) throw();
	static bool isUpperCase(wchar_t ch, ThreadContext* ctx) throw();
	static bool isUpperCase(int codePoint, ThreadContext* ctx) throw();
	static bool isWhitespace(wchar_t ch, ThreadContext* ctx) throw();
	static bool isWhitespace(int codePoint, ThreadContext* ctx) throw();
	static bool isSpaceChar(wchar_t ch, ThreadContext* ctx) throw();
	static bool isSpaceChar(int codePoint, ThreadContext* ctx) throw();
	static bool isSpace(wchar_t ch, ThreadContext* ctx) throw();
	static bool isSpace(int codePoint, ThreadContext* ctx) throw();
	static bool isLowerCase(wchar_t ch, ThreadContext* ctx) throw();
	static bool isLowerCase(int codePoint, ThreadContext* ctx) throw();
	static bool isLetterOrDigit(wchar_t ch, ThreadContext* ctx) throw();
	static bool isLetterOrDigit(int codePoint, ThreadContext* ctx) throw();
	static bool isLetter(wchar_t ch, ThreadContext* ctx) throw();
	static bool isLetter(int codePoint, ThreadContext* ctx) throw();
	static bool isJavaIdentifierStart(wchar_t ch, ThreadContext* ctx) throw();
	static bool isJavaIdentifierStart(int codePoint, ThreadContext* ctx) throw();
	static bool isJavaIdentifierPart(wchar_t ch, ThreadContext* ctx) throw();
	static bool isJavaIdentifierPart(int codePoint, ThreadContext* ctx) throw();
	static bool isISOControl(wchar_t ch, ThreadContext* ctx) throw();
	static bool isISOControl(int codePoint, ThreadContext* ctx) throw();
	static bool isIdentifierIgnorable(wchar_t ch, ThreadContext* ctx) throw();
	static bool isIdentifierIgnorable(int codePoint, ThreadContext* ctx) throw();
	static bool isDigit(wchar_t ch, ThreadContext* ctx) throw();
	static bool isDigit(int codePoint, ThreadContext* ctx) throw();
	static bool isDefined(wchar_t ch, ThreadContext* ctx) throw();
	static bool isDefined(int codePoint, ThreadContext* ctx) throw();
	static bool isMirrored(wchar_t ch, ThreadContext* ctx) throw();
	static bool isMirrored(int codePoint, ThreadContext* ctx) throw();
	static u_int8_t getDirectionality(wchar_t ch, ThreadContext* ctx) throw();
	static u_int8_t getDirectionality(int codePoint, ThreadContext* ctx) throw();
	static int getType(wchar_t ch, ThreadContext* ctx) throw();
	static int getType(int codePoint, ThreadContext* ctx) throw();
	static int getNumericValue(wchar_t ch, ThreadContext* ctx) throw();
	static int getNumericValue(int codePoint, ThreadContext* ctx) throw();
	static wchar_t forDigit(int digit, int radix, ThreadContext* ctx) throw();
	static int digit(wchar_t ch, int radix, ThreadContext* ctx) throw();
	static int digit(int codePoint, int radix, ThreadContext* ctx) throw();
	constexpr static bool isSurrogatePair(wchar_t high, wchar_t low, ThreadContext* ctx) throw();
	constexpr static bool isHighSurrogate(wchar_t ch, ThreadContext* ctx) throw();
	constexpr static bool isLowSurrogate(wchar_t ch, ThreadContext* ctx) throw();
	static int charCount(int codePoint, ThreadContext* ctx) throw();
	static int toCodePoint(wchar_t high, wchar_t low, ThreadContext* ctx) throw();
	static int codePointAt(CharSequence* seq, int index, ThreadContext* ctx) throw();
	static int codePointAt(ArrayObjectPrimitive<wchar_t>* seq, int index, ThreadContext* ctx) throw();
	static int codePointAt(ArrayObjectPrimitive<wchar_t>* seq, int index, int limit, ThreadContext* ctx) throw();
	static int codePointBefore(CharSequence* seq, int index, ThreadContext* ctx) throw();
	static int codePointCount(CharSequence* seq, int beginIndex, int endIndex, ThreadContext* ctx) throw();
	constexpr static bool isValidCodePoint(int codePoint, ThreadContext* ctx) throw();
	constexpr static bool isSupplementaryCodePoint(int codePoint, ThreadContext* ctx) throw();
	static ArrayObjectPrimitive<wchar_t>* toChars(int codePoint, ThreadContext* ctx) throw();
	static int toChars(int codePoint, ArrayObjectPrimitive<wchar_t>* dst, int dstIndex, ThreadContext* ctx) throw();
    /**
     * The minimum {@code Character} value.
     */
    static const wchar_t MIN_VALUE = L'\u0000';

    /**
     * The maximum {@code Character} value.
     */
    static const wchar_t MAX_VALUE = L'\uffff';

    /**
     * The minimum radix used for conversions between characters and integers.
     */
    static const int MIN_RADIX = 2;

    /**
     * The maximum radix used for conversions between characters and integers.
     */
    static const int MAX_RADIX = 36;

    /**
     * Unicode category constant Cn.
     */
    static const u_int8_t UNASSIGNED = 0;

    /**
     * Unicode category constant Lu.
     */
    static const u_int8_t UPPERCASE_LETTER = 1;

    /**
     * Unicode category constant Ll.
     */
    static const u_int8_t LOWERCASE_LETTER = 2;

    /**
     * Unicode category constant Lt.
     */
    static const u_int8_t TITLECASE_LETTER = 3;

    /**
     * Unicode category constant Lm.
     */
    static const u_int8_t MODIFIER_LETTER = 4;

    /**
     * Unicode category constant Lo.
     */
    static const u_int8_t OTHER_LETTER = 5;

    /**
     * Unicode category constant Mn.
     */
    static const u_int8_t NON_SPACING_MARK = 6;

    /**
     * Unicode category constant Me.
     */
    static const u_int8_t ENCLOSING_MARK = 7;

    /**
     * Unicode category constant Mc.
     */
    static const u_int8_t COMBINING_SPACING_MARK = 8;

    /**
     * Unicode category constant Nd.
     */
    static const u_int8_t DECIMAL_DIGIT_NUMBER = 9;

    /**
     * Unicode category constant Nl.
     */
    static const u_int8_t LETTER_NUMBER = 10;

    /**
     * Unicode category constant No.
     */
    static const u_int8_t OTHER_NUMBER = 11;

    /**
     * Unicode category constant Zs.
     */
    static const u_int8_t SPACE_SEPARATOR = 12;

    /**
     * Unicode category constant Zl.
     */
    static const u_int8_t LINE_SEPARATOR = 13;

    /**
     * Unicode category constant Zp.
     */
    static const u_int8_t PARAGRAPH_SEPARATOR = 14;

    /**
     * Unicode category constant Cc.
     */
    static const u_int8_t CONTROL = 15;

    /**
     * Unicode category constant Cf.
     */
    static const u_int8_t FORMAT = 16;

    /**
     * Unicode category constant Co.
     */
    static const u_int8_t PRIVATE_USE = 18;

    /**
     * Unicode category constant Cs.
     */
    static const u_int8_t SURROGATE = 19;

    /**
     * Unicode category constant Pd.
     */
    static const u_int8_t DASH_PUNCTUATION = 20;

    /**
     * Unicode category constant Ps.
     */
    static const u_int8_t START_PUNCTUATION = 21;

    /**
     * Unicode category constant Pe.
     */
    static const u_int8_t END_PUNCTUATION = 22;

    /**
     * Unicode category constant Pc.
     */
    static const u_int8_t CONNECTOR_PUNCTUATION = 23;

    /**
     * Unicode category constant Po.
     */
    static const u_int8_t OTHER_PUNCTUATION = 24;

    /**
     * Unicode category constant Sm.
     */
    static const u_int8_t MATH_SYMBOL = 25;

    /**
     * Unicode category constant Sc.
     */
    static const u_int8_t CURRENCY_SYMBOL = 26;

    /**
     * Unicode category constant Sk.
     */
    static const u_int8_t MODIFIER_SYMBOL = 27;

    /**
     * Unicode category constant So.
     */
    static const u_int8_t OTHER_SYMBOL = 28;

    /**
     * Unicode category constant Pi.
     *
     * @since 1.4
     */
    static const u_int8_t INITIAL_QUOTE_PUNCTUATION = 29;

    /**
     * Unicode category constant Pf.
     *
     * @since 1.4
     */
    static const u_int8_t FINAL_QUOTE_PUNCTUATION = 30;

    /**
     * Unicode bidirectional constant.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_UNDEFINED = -1;

    /**
     * Unicode bidirectional constant L.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_LEFT_TO_RIGHT = 0;

    /**
     * Unicode bidirectional constant R.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_RIGHT_TO_LEFT = 1;

    /**
     * Unicode bidirectional constant AL.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = 2;

    /**
     * Unicode bidirectional constant EN.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_EUROPEAN_NUMBER = 3;

    /**
     * Unicode bidirectional constant ES.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR = 4;

    /**
     * Unicode bidirectional constant ET.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR = 5;

    /**
     * Unicode bidirectional constant AN.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_ARABIC_NUMBER = 6;

    /**
     * Unicode bidirectional constant CS.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_COMMON_NUMBER_SEPARATOR = 7;

    /**
     * Unicode bidirectional constant NSM.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_NONSPACING_MARK = 8;

    /**
     * Unicode bidirectional constant BN.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_BOUNDARY_NEUTRAL = 9;

    /**
     * Unicode bidirectional constant B.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_PARAGRAPH_SEPARATOR = 10;

    /**
     * Unicode bidirectional constant S.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_SEGMENT_SEPARATOR = 11;

    /**
     * Unicode bidirectional constant WS.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_WHITESPACE = 12;

    /**
     * Unicode bidirectional constant ON.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_OTHER_NEUTRALS = 13;

    /**
     * Unicode bidirectional constant LRE.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = 14;

    /**
     * Unicode bidirectional constant LRO.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = 15;

    /**
     * Unicode bidirectional constant RLE.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = 16;

    /**
     * Unicode bidirectional constant RLO.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = 17;

    /**
     * Unicode bidirectional constant PDF.
     *
     * @since 1.4
     */
    static const u_int8_t DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = 18;

    /**
     * The minimum value of a high surrogate or leading surrogate unit in UTF-16
     * encoding, {@code '\uD800'}.
     *
     * @since 1.5
     */
    constexpr static const wchar_t MIN_HIGH_SURROGATE = 0xD800;

    /**
     * The maximum value of a high surrogate or leading surrogate unit in UTF-16
     * encoding, {@code '\uDBFF'}.
     *
     * @since 1.5
     */
    constexpr static const wchar_t MAX_HIGH_SURROGATE = 0xDBFF;

    /**
     * The minimum value of a low surrogate or trailing surrogate unit in UTF-16
     * encoding, {@code '\uDC00'}.
     *
     * @since 1.5
     */
    constexpr static const wchar_t MIN_LOW_SURROGATE = 0xDC00;

    /**
     * The maximum value of a low surrogate or trailing surrogate unit in UTF-16
     * encoding, {@code '\uDFFF'}.
     *
     * @since 1.5
     */
    constexpr static const wchar_t MAX_LOW_SURROGATE = 0xDFFF;

    /**
     * The minimum value of a surrogate unit in UTF-16 encoding, {@code '\uD800'}.
     *
     * @since 1.5
     */
    constexpr static const wchar_t MIN_SURROGATE = 0xD800;

    /**
     * The maximum value of a surrogate unit in UTF-16 encoding, {@code '\uDFFF'}.
     *
     * @since 1.5
     */
    constexpr static const wchar_t MAX_SURROGATE = 0xDFFF;

    /**
     * The minimum value of a supplementary code point, {@code U+010000}.
     *
     * @since 1.5
     */
    constexpr static const int MIN_SUPPLEMENTARY_CODE_POINT = 0x10000;

    /**
     * The minimum code point value, {@code U+0000}.
     *
     * @since 1.5
     */
    constexpr static const int MIN_CODE_POINT = 0x000000;

    /**
     * The maximum code point value, {@code U+10FFFF}.
     *
     * @since 1.5
     */
    constexpr static const int MAX_CODE_POINT = 0x10FFFF;


public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}} /* namespace alinous */

#endif /* BASELIB_CHARACTER_H_ */
