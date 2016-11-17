/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */


#include "unicode/stdtypes.h"

#include "unicode/uchar_props_data.h"
#include "unicode/utrie2.h"
#include "unicode/uprops.h"
#include "unicode/ubidi_props.h"
#include "unicode/ubidi_props_data.h"
#include "unicode/ucase_props_data.h"

#ifndef UNICODE_UCHAR_H_
#define UNICODE_UCHAR_H_

namespace icu {

#define UCHAR_MAX_VALUE 0x10ffff

/**
 * Get a single-bit bit set (a flag) from a bit number 0..31.
 * @stable ICU 2.1
 */
#define U_MASK(x) ((u_int32_t)1<<(x))

#define U_NO_NUMERIC_VALUE ((double)-123456789.)

#define GET_PROPS(c, result) ((result)=UTRIE2_GET16(&propsTrie, c));
#define U_DEF_ICU_ENTRY_POINT_RENAME(x,y) x ## y
#define U_DEF2_ICU_ENTRY_POINT_RENAME(x,y) U_DEF_ICU_ENTRY_POINT_RENAME(x,y)
#define U_ICU_ENTRY_POINT_RENAME(x)    U_DEF2_ICU_ENTRY_POINT_RENAME(x,U_ICU_VERSION_SUFFIX)
#define u_getUnicodeProperties U_ICU_ENTRY_POINT_RENAME(u_getUnicodeProperties)

#define GET_CATEGORY(props) ((props)&0x1f)
#define CAT_MASK(props) U_MASK(GET_CATEGORY(props))




u_int32_t
u_getUnicodeProperties(u_int32_t c, int32_t column) throw();
u_char u_charType(u_int32_t c) throw();

/* Checks if ch is a lower case letter.*/
UBool
u_islower(u_int32_t c) throw();

/* Checks if ch is an upper case letter.*/
UBool
u_isupper(u_int32_t c) throw();

/* Checks if ch is a title case letter; usually upper case letters.*/
UBool
u_istitle(u_int32_t c) throw();

/* Checks if ch is a decimal digit. */
UBool
u_isdigit(u_int32_t c) throw();

UBool
u_isxdigit(u_int32_t c) throw();

/* Checks if the Unicode character is a letter.*/
UBool
u_isalpha(u_int32_t c) throw();

UBool
u_isUAlphabetic(u_int32_t c) throw();

/* Checks if c is a letter or a decimal digit */
UBool
u_isalnum(u_int32_t c) throw();

/**
 * Checks if c is alphabetic, or a decimal digit; implements UCHAR_POSIX_ALNUM.
 * @internal
 */
UBool
u_isalnumPOSIX(u_int32_t c) throw();

/* Checks if ch is a unicode character with assigned character type.*/
UBool
u_isdefined(u_int32_t c) throw();

/* Checks if the Unicode character is a base form character that can take a diacritic.*/
UBool
u_isbase(u_int32_t c) throw();

/* Checks if the Unicode character is a control character.*/
UBool
u_iscntrl(u_int32_t c) throw();

UBool
u_isISOControl(u_int32_t c) throw();

/* Some control characters that are used as space. */
#define IS_THAT_CONTROL_SPACE(c) \
    (c<=0x9f && ((c>=TAB && c<=CR) || (c>=0x1c && c <=0x1f) || c==NL))

/* Java has decided that U+0085 New Line is not whitespace any more. */
#define IS_THAT_ASCII_CONTROL_SPACE(c) \
    (c<=0x1f && c>=TAB && (c<=CR || c>=0x1c))

/* Checks if the Unicode character is a space character.*/
UBool
u_isspace(u_int32_t c) throw();

UBool
u_isJavaSpaceChar(u_int32_t c) throw();

/* Checks if the Unicode character is a whitespace character.*/
UBool
u_isWhitespace(u_int32_t c) throw();

UBool
u_isblank(u_int32_t c) throw();

UBool
u_isUWhiteSpace(u_int32_t c) throw();

/* Checks if the Unicode character is printable.*/
UBool
u_isprint(u_int32_t c) throw();

/**
 * Checks if c is in
 * [^\p{space}\p{gc=Control}\p{gc=Surrogate}\p{gc=Unassigned}]
 * with space=\p{Whitespace} and Control=Cc.
 * Implements UCHAR_POSIX_GRAPH.
 * @internal
 */
UBool
u_isgraphPOSIX(u_int32_t c) throw();

/**
 * Checks if c is in \p{graph}\p{blank} - \p{cntrl}.
 * Implements UCHAR_POSIX_PRINT.
 * @internal
 */
UBool
u_isprintPOSIX(u_int32_t c) throw();

UBool
u_isgraph(u_int32_t c) throw();

UBool
u_ispunct(u_int32_t c) throw();

/* Checks if the Unicode character can start a Unicode identifier.*/
UBool
u_isIDStart(u_int32_t c) throw();

/*Checks if the Unicode character can be ignorable in a Java or Unicode identifier.*/
UBool
u_isIDIgnorable(u_int32_t c) throw();


/* Checks if the Unicode character can be a Unicode identifier part other than starting the
 identifier.*/
UBool
u_isIDPart(u_int32_t c) throw();


/*Checks if the Unicode character can start a Java identifier.*/
UBool
u_isJavaIDStart(u_int32_t c) throw();

/*Checks if the Unicode character can be a Java identifier part other than starting the
 * identifier.
 */
UBool
u_isJavaIDPart(u_int32_t c) throw();

int32_t
u_charDigitValue(u_int32_t c) throw();

double
u_getNumericValue(u_int32_t c) throw();

int8_t
u_digit(u_int32_t ch, int8_t radix) throw();

u_int32_t
u_forDigit(int32_t digit, int8_t radix) throw();


UCharDirection
u_charDirection(u_int32_t c) throw();

UBool
u_isMirrored(u_int32_t c) throw();

u_int32_t
u_charMirror(u_int32_t c) throw();

/* definitions for 16-bit case properties word ------------------------------ */

/* 2-bit constants for types of cased characters */
#define UCASE_TYPE_MASK     3
enum {
    UCASE_NONE,
    UCASE_LOWER,
    UCASE_UPPER,
    UCASE_TITLE
};

#define UCASE_GET_TYPE(props) ((props)&UCASE_TYPE_MASK)
#define UCASE_GET_TYPE_AND_IGNORABLE(props) ((props)&7)

#define UCASE_IGNORABLE         4
#define UCASE_SENSITIVE         8
#define UCASE_EXCEPTION         0x10

#define UCASE_DOT_MASK      0x60
enum {
    UCASE_NO_DOT=0,         /* normal characters with cc=0 */
    UCASE_SOFT_DOTTED=0x20, /* soft-dotted characters with cc=0 */
    UCASE_ABOVE=0x40,       /* "above" accents with cc=230 */
    UCASE_OTHER_ACCENT=0x60 /* other accent character (0<cc!=230) */
};

/* no exception: bits 15..7 are a 9-bit signed case mapping delta */
#define UCASE_DELTA_SHIFT   7
#define UCASE_DELTA_MASK    0xff80
#define UCASE_MAX_DELTA     0xff
#define UCASE_MIN_DELTA     (-UCASE_MAX_DELTA-1)

#if U_SIGNED_RIGHT_SHIFT_IS_ARITHMETIC
#   define UCASE_GET_DELTA(props) ((int16_t)(props)>>UCASE_DELTA_SHIFT)
#else
#   define UCASE_GET_DELTA(props) (int16_t)(((props)&0x8000) ? (((props)>>UCASE_DELTA_SHIFT)|0xfe00) : ((uint16_t)(props)>>UCASE_DELTA_SHIFT))
#endif

/* exception: bits 15..5 are an unsigned 11-bit index into the exceptions array */
#define UCASE_EXC_SHIFT     5
#define UCASE_EXC_MASK      0xffe0
#define UCASE_MAX_EXCEPTIONS ((UCASE_EXC_MASK>>UCASE_EXC_SHIFT)+1)

/* definitions for 16-bit main exceptions word ------------------------------ */

/* first 8 bits indicate values in optional slots */
enum {
    UCASE_EXC_LOWER,
    UCASE_EXC_FOLD,
    UCASE_EXC_UPPER,
    UCASE_EXC_TITLE,
    UCASE_EXC_4,            /* reserved */
    UCASE_EXC_5,            /* reserved */
    UCASE_EXC_CLOSURE,
    UCASE_EXC_FULL_MAPPINGS,
    UCASE_EXC_ALL_SLOTS     /* one past the last slot */
};

/* each slot is 2 uint16_t instead of 1 */
#define UCASE_EXC_DOUBLE_SLOTS      0x100

/* reserved: exception bits 11..9 */

/* UCASE_EXC_DOT_MASK=UCASE_DOT_MASK<<UCASE_EXC_DOT_SHIFT */
#define UCASE_EXC_DOT_SHIFT     7

/* normally stored in the main word, but pushed out for larger exception indexes */
#define UCASE_EXC_DOT_MASK      0x3000
enum {
    UCASE_EXC_NO_DOT=0,
    UCASE_EXC_SOFT_DOTTED=0x1000,
    UCASE_EXC_ABOVE=0x2000,         /* "above" accents with cc=230 */
    UCASE_EXC_OTHER_ACCENT=0x3000   /* other character (0<cc!=230) */
};

/* complex/conditional mappings */
#define UCASE_EXC_CONDITIONAL_SPECIAL   0x4000
#define UCASE_EXC_CONDITIONAL_FOLD      0x8000

/* definitions for lengths word for full case mappings */
#define UCASE_FULL_LOWER    0xf
#define UCASE_FULL_FOLDING  0xf0
#define UCASE_FULL_UPPER    0xf00
#define UCASE_FULL_TITLE    0xf000

/* maximum lengths */
#define UCASE_FULL_MAPPINGS_MAX_LENGTH (4*0xf)
#define UCASE_CLOSURE_MAX_LENGTH 0xf

/* constants for reverse case folding ("unfold") data */
enum {
    UCASE_UNFOLD_ROWS,
    UCASE_UNFOLD_ROW_WIDTH,
    UCASE_UNFOLD_STRING_WIDTH
};

/* exception: bits 15..5 are an unsigned 11-bit index into the exceptions array */
#define UCASE_EXC_SHIFT     5
#define UCASE_EXC_MASK      0xffe0
#define UCASE_MAX_EXCEPTIONS ((UCASE_EXC_MASK>>UCASE_EXC_SHIFT)+1)

/* data access primitives --------------------------------------------------- */

#define GET_EXCEPTIONS(csp, props) ((csp)->exceptions+((props)>>UCASE_EXC_SHIFT))

#define PROPS_HAS_EXCEPTION(props) ((props)&UCASE_EXCEPTION)

/* number of bits in an 8-bit integer value */
constexpr static const uint8_t flagsOffset[256]={
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};

#define HAS_SLOT(flags, idx) ((flags)&(1<<(idx)))
#define SLOT_OFFSET(flags, idx) flagsOffset[(flags)&((1<<(idx))-1)]

/*
 * Get the value of an optional-value slot where HAS_SLOT(excWord, idx).
 *
 * @param excWord (in) initial exceptions word
 * @param idx (in) desired slot index
 * @param pExc16 (in/out) const uint16_t * after excWord=*pExc16++;
 *               moved to the last uint16_t of the value, use +1 for beginning of next slot
 * @param value (out) int32_t or uint32_t output if hasSlot, otherwise not modified
 */
#define GET_SLOT_VALUE(excWord, idx, pExc16, value) \
    if(((excWord)&UCASE_EXC_DOUBLE_SLOTS)==0) { \
        (pExc16)+=SLOT_OFFSET(excWord, idx); \
        (value)=*pExc16; \
    } else { \
        (pExc16)+=2*SLOT_OFFSET(excWord, idx); \
        (value)=*pExc16++; \
        (value)=((value)<<16)|*pExc16; \
    }

/* simple case mappings ----------------------------------------------------- */

u_int32_t
ucase_tolower(const UCaseProps *csp, u_int32_t c) throw();

u_int32_t
ucase_toupper(const UCaseProps *csp, u_int32_t c) throw();

u_int32_t
ucase_totitle(const UCaseProps *csp, u_int32_t c) throw();

#define _FOLD_CASE_OPTIONS_MASK 0xff
#define U_FOLD_CASE_DEFAULT 0

u_int32_t
ucase_fold(const UCaseProps *csp, u_int32_t c, uint32_t options) throw();

/* case mapping properties API ---------------------------------------------- */

#define GET_CASE_PROPS() &ucase_props_singleton

/* Transforms the Unicode character to its lower case equivalent.*/
u_int32_t
u_tolower(u_int32_t c) throw();

/* Transforms the Unicode character to its upper case equivalent.*/
u_int32_t
u_toupper(u_int32_t c) throw();

/* Transforms the Unicode character to its title case equivalent.*/
u_int32_t
u_totitle(u_int32_t c) throw();

/* return the simple case folding mapping for c */
u_int32_t
u_foldCase(u_int32_t c, uint32_t options) throw();

}

#endif
