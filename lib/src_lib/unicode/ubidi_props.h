/*
 * Copyright (c) Tomohiro Iizuka. All rights reserved.
 * Licensed under the MIT license.
 */



#include "unicode/stdtypes.h"

#ifndef UNICODE_UBIDI_PROPS_H_
#define UNICODE_UBIDI_PROPS_H_

namespace icu {



/* file definitions --------------------------------------------------------- */

#define UBIDI_DATA_NAME "ubidi"
#define UBIDI_DATA_TYPE "icu"

/* format "BiDi" */
#define UBIDI_FMT_0 0x42
#define UBIDI_FMT_1 0x69
#define UBIDI_FMT_2 0x44
#define UBIDI_FMT_3 0x69

/* indexes into indexes[] */
enum {
    UBIDI_IX_INDEX_TOP,
    UBIDI_IX_LENGTH,
    UBIDI_IX_TRIE_SIZE,
    UBIDI_IX_MIRROR_LENGTH,

    UBIDI_IX_JG_START,
    UBIDI_IX_JG_LIMIT,
    UBIDI_IX_JG_START2,  /* new in format version 2.2, ICU 54 */
    UBIDI_IX_JG_LIMIT2,

    UBIDI_MAX_VALUES_INDEX=15,
    UBIDI_IX_TOP=16
};

typedef enum UErrorCode {
    /* The ordering of U_ERROR_INFO_START Vs U_USING_FALLBACK_WARNING looks weird
     * and is that way because VC++ debugger displays first encountered constant,
     * which is not the what the code is used for
     */

    U_USING_FALLBACK_WARNING  = -128,   /**< A resource bundle lookup returned a fallback result (not an error) */

    U_ERROR_WARNING_START     = -128,   /**< Start of information results (semantically successful) */

    U_USING_DEFAULT_WARNING   = -127,   /**< A resource bundle lookup returned a result from the root locale (not an error) */

    U_SAFECLONE_ALLOCATED_WARNING = -126, /**< A SafeClone operation required allocating memory (informational only) */

    U_STATE_OLD_WARNING       = -125,   /**< ICU has to use compatibility layer to construct the service. Expect performance/memory usage degradation. Consider upgrading */

    U_STRING_NOT_TERMINATED_WARNING = -124,/**< An output string could not be NUL-terminated because output length==destCapacity. */

    U_SORT_KEY_TOO_SHORT_WARNING = -123, /**< Number of levels requested in getBound is higher than the number of levels in the sort key */

    U_AMBIGUOUS_ALIAS_WARNING = -122,   /**< This converter alias can go to different converter implementations */

    U_DIFFERENT_UCA_VERSION = -121,     /**< ucol_open encountered a mismatch between UCA version and collator image version, so the collator was constructed from rules. No impact to further function */

    U_PLUGIN_CHANGED_LEVEL_WARNING = -120, /**< A plugin caused a level change. May not be an error, but later plugins may not load. */

    U_ERROR_WARNING_LIMIT,              /**< This must always be the last warning value to indicate the limit for UErrorCode warnings (last warning code +1) */


    U_ZERO_ERROR              =  0,     /**< No error, no warning. */

    U_ILLEGAL_ARGUMENT_ERROR  =  1,     /**< Start of codes indicating failure */
    U_MISSING_RESOURCE_ERROR  =  2,     /**< The requested resource cannot be found */
    U_INVALID_FORMAT_ERROR    =  3,     /**< Data format is not what is expected */
    U_FILE_ACCESS_ERROR       =  4,     /**< The requested file cannot be found */
    U_INTERNAL_PROGRAM_ERROR  =  5,     /**< Indicates a bug in the library code */
    U_MESSAGE_PARSE_ERROR     =  6,     /**< Unable to parse a message (message format) */
    U_MEMORY_ALLOCATION_ERROR =  7,     /**< Memory allocation error */
    U_INDEX_OUTOFBOUNDS_ERROR =  8,     /**< Trying to access the index that is out of bounds */
    U_PARSE_ERROR             =  9,     /**< Equivalent to Java ParseException */
    U_INVALID_CHAR_FOUND      = 10,     /**< Character conversion: Unmappable input sequence. In other APIs: Invalid character. */
    U_TRUNCATED_CHAR_FOUND    = 11,     /**< Character conversion: Incomplete input sequence. */
    U_ILLEGAL_CHAR_FOUND      = 12,     /**< Character conversion: Illegal input sequence/combination of input units. */
    U_INVALID_TABLE_FORMAT    = 13,     /**< Conversion table file found, but corrupted */
    U_INVALID_TABLE_FILE      = 14,     /**< Conversion table file not found */
    U_BUFFER_OVERFLOW_ERROR   = 15,     /**< A result would not fit in the supplied buffer */
    U_UNSUPPORTED_ERROR       = 16,     /**< Requested operation not supported in current context */
    U_RESOURCE_TYPE_MISMATCH  = 17,     /**< an operation is requested over a resource that does not support it */
    U_ILLEGAL_ESCAPE_SEQUENCE = 18,     /**< ISO-2022 illlegal escape sequence */
    U_UNSUPPORTED_ESCAPE_SEQUENCE = 19, /**< ISO-2022 unsupported escape sequence */
    U_NO_SPACE_AVAILABLE      = 20,     /**< No space available for in-buffer expansion for Arabic shaping */
    U_CE_NOT_FOUND_ERROR      = 21,     /**< Currently used only while setting variable top, but can be used generally */
    U_PRIMARY_TOO_LONG_ERROR  = 22,     /**< User tried to set variable top to a primary that is longer than two bytes */
    U_STATE_TOO_OLD_ERROR     = 23,     /**< ICU cannot construct a service from this state, as it is no longer supported */
    U_TOO_MANY_ALIASES_ERROR  = 24,     /**< There are too many aliases in the path to the requested resource.
                                             It is very possible that a circular alias definition has occured */
    U_ENUM_OUT_OF_SYNC_ERROR  = 25,     /**< UEnumeration out of sync with underlying collection */
    U_INVARIANT_CONVERSION_ERROR = 26,  /**< Unable to convert a UChar* string to char* with the invariant converter. */
    U_INVALID_STATE_ERROR     = 27,     /**< Requested operation can not be completed with ICU in its current state */
    U_COLLATOR_VERSION_MISMATCH = 28,   /**< Collator version is not compatible with the base version */
    U_USELESS_COLLATOR_ERROR  = 29,     /**< Collator is options only and no base is specified */
    U_NO_WRITE_PERMISSION     = 30,     /**< Attempt to modify read-only or constant data. */

    U_STANDARD_ERROR_LIMIT,             /**< This must always be the last value to indicate the limit for standard errors */
    /*
     * the error code range 0x10000 0x10100 are reserved for Transliterator
     */
    U_BAD_VARIABLE_DEFINITION=0x10000,/**< Missing '$' or duplicate variable name */
    U_PARSE_ERROR_START = 0x10000,    /**< Start of Transliterator errors */
    U_MALFORMED_RULE,                 /**< Elements of a rule are misplaced */
    U_MALFORMED_SET,                  /**< A UnicodeSet pattern is invalid*/
    U_MALFORMED_SYMBOL_REFERENCE,     /**< UNUSED as of ICU 2.4 */
    U_MALFORMED_UNICODE_ESCAPE,       /**< A Unicode escape pattern is invalid*/
    U_MALFORMED_VARIABLE_DEFINITION,  /**< A variable definition is invalid */
    U_MALFORMED_VARIABLE_REFERENCE,   /**< A variable reference is invalid */
    U_MISMATCHED_SEGMENT_DELIMITERS,  /**< UNUSED as of ICU 2.4 */
    U_MISPLACED_ANCHOR_START,         /**< A start anchor appears at an illegal position */
    U_MISPLACED_CURSOR_OFFSET,        /**< A cursor offset occurs at an illegal position */
    U_MISPLACED_QUANTIFIER,           /**< A quantifier appears after a segment close delimiter */
    U_MISSING_OPERATOR,               /**< A rule contains no operator */
    U_MISSING_SEGMENT_CLOSE,          /**< UNUSED as of ICU 2.4 */
    U_MULTIPLE_ANTE_CONTEXTS,         /**< More than one ante context */
    U_MULTIPLE_CURSORS,               /**< More than one cursor */
    U_MULTIPLE_POST_CONTEXTS,         /**< More than one post context */
    U_TRAILING_BACKSLASH,             /**< A dangling backslash */
    U_UNDEFINED_SEGMENT_REFERENCE,    /**< A segment reference does not correspond to a defined segment */
    U_UNDEFINED_VARIABLE,             /**< A variable reference does not correspond to a defined variable */
    U_UNQUOTED_SPECIAL,               /**< A special character was not quoted or escaped */
    U_UNTERMINATED_QUOTE,             /**< A closing single quote is missing */
    U_RULE_MASK_ERROR,                /**< A rule is hidden by an earlier more general rule */
    U_MISPLACED_COMPOUND_FILTER,      /**< A compound filter is in an invalid location */
    U_MULTIPLE_COMPOUND_FILTERS,      /**< More than one compound filter */
    U_INVALID_RBT_SYNTAX,             /**< A "::id" rule was passed to the RuleBasedTransliterator parser */
    U_INVALID_PROPERTY_PATTERN,       /**< UNUSED as of ICU 2.4 */
    U_MALFORMED_PRAGMA,               /**< A 'use' pragma is invlalid */
    U_UNCLOSED_SEGMENT,               /**< A closing ')' is missing */
    U_ILLEGAL_CHAR_IN_SEGMENT,        /**< UNUSED as of ICU 2.4 */
    U_VARIABLE_RANGE_EXHAUSTED,       /**< Too many stand-ins generated for the given variable range */
    U_VARIABLE_RANGE_OVERLAP,         /**< The variable range overlaps characters used in rules */
    U_ILLEGAL_CHARACTER,              /**< A special character is outside its allowed context */
    U_INTERNAL_TRANSLITERATOR_ERROR,  /**< Internal transliterator system error */
    U_INVALID_ID,                     /**< A "::id" rule specifies an unknown transliterator */
    U_INVALID_FUNCTION,               /**< A "&fn()" rule specifies an unknown transliterator */
    U_PARSE_ERROR_LIMIT,              /**< The limit for Transliterator errors */

    /*
     * the error code range 0x10100 0x10200 are reserved for formatting API parsing error
     */
    U_UNEXPECTED_TOKEN=0x10100,       /**< Syntax error in format pattern */
    U_FMT_PARSE_ERROR_START=0x10100,  /**< Start of format library errors */
    U_MULTIPLE_DECIMAL_SEPARATORS,    /**< More than one decimal separator in number pattern */
    U_MULTIPLE_DECIMAL_SEPERATORS = U_MULTIPLE_DECIMAL_SEPARATORS, /**< Typo: kept for backward compatibility. Use U_MULTIPLE_DECIMAL_SEPARATORS */
    U_MULTIPLE_EXPONENTIAL_SYMBOLS,   /**< More than one exponent symbol in number pattern */
    U_MALFORMED_EXPONENTIAL_PATTERN,  /**< Grouping symbol in exponent pattern */
    U_MULTIPLE_PERCENT_SYMBOLS,       /**< More than one percent symbol in number pattern */
    U_MULTIPLE_PERMILL_SYMBOLS,       /**< More than one permill symbol in number pattern */
    U_MULTIPLE_PAD_SPECIFIERS,        /**< More than one pad symbol in number pattern */
    U_PATTERN_SYNTAX_ERROR,           /**< Syntax error in format pattern */
    U_ILLEGAL_PAD_POSITION,           /**< Pad symbol misplaced in number pattern */
    U_UNMATCHED_BRACES,               /**< Braces do not match in message pattern */
    U_UNSUPPORTED_PROPERTY,           /**< UNUSED as of ICU 2.4 */
    U_UNSUPPORTED_ATTRIBUTE,          /**< UNUSED as of ICU 2.4 */
    U_ARGUMENT_TYPE_MISMATCH,         /**< Argument name and argument index mismatch in MessageFormat functions */
    U_DUPLICATE_KEYWORD,              /**< Duplicate keyword in PluralFormat */
    U_UNDEFINED_KEYWORD,              /**< Undefined Plural keyword */
    U_DEFAULT_KEYWORD_MISSING,        /**< Missing DEFAULT rule in plural rules */
    U_DECIMAL_NUMBER_SYNTAX_ERROR,    /**< Decimal number syntax error */
    U_FORMAT_INEXACT_ERROR,           /**< Cannot format a number exactly and rounding mode is ROUND_UNNECESSARY @stable ICU 4.8 */
    U_FMT_PARSE_ERROR_LIMIT,          /**< The limit for format library errors */

    /*
     * the error code range 0x10200 0x102ff are reserved for Break Iterator related error
     */
    U_BRK_INTERNAL_ERROR=0x10200,          /**< An internal error (bug) was detected.             */
    U_BRK_ERROR_START=0x10200,             /**< Start of codes indicating Break Iterator failures */
    U_BRK_HEX_DIGITS_EXPECTED,             /**< Hex digits expected as part of a escaped char in a rule. */
    U_BRK_SEMICOLON_EXPECTED,              /**< Missing ';' at the end of a RBBI rule.            */
    U_BRK_RULE_SYNTAX,                     /**< Syntax error in RBBI rule.                        */
    U_BRK_UNCLOSED_SET,                    /**< UnicodeSet witing an RBBI rule missing a closing ']'.  */
    U_BRK_ASSIGN_ERROR,                    /**< Syntax error in RBBI rule assignment statement.   */
    U_BRK_VARIABLE_REDFINITION,            /**< RBBI rule $Variable redefined.                    */
    U_BRK_MISMATCHED_PAREN,                /**< Mis-matched parentheses in an RBBI rule.          */
    U_BRK_NEW_LINE_IN_QUOTED_STRING,       /**< Missing closing quote in an RBBI rule.            */
    U_BRK_UNDEFINED_VARIABLE,              /**< Use of an undefined $Variable in an RBBI rule.    */
    U_BRK_INIT_ERROR,                      /**< Initialization failure.  Probable missing ICU Data. */
    U_BRK_RULE_EMPTY_SET,                  /**< Rule contains an empty Unicode Set.               */
    U_BRK_UNRECOGNIZED_OPTION,             /**< !!option in RBBI rules not recognized.            */
    U_BRK_MALFORMED_RULE_TAG,              /**< The {nnn} tag on a rule is mal formed             */
    U_BRK_ERROR_LIMIT,                     /**< This must always be the last value to indicate the limit for Break Iterator failures */

    /*
     * The error codes in the range 0x10300-0x103ff are reserved for regular expression related errrs
     */
    U_REGEX_INTERNAL_ERROR=0x10300,       /**< An internal error (bug) was detected.              */
    U_REGEX_ERROR_START=0x10300,          /**< Start of codes indicating Regexp failures          */
    U_REGEX_RULE_SYNTAX,                  /**< Syntax error in regexp pattern.                    */
    U_REGEX_INVALID_STATE,                /**< RegexMatcher in invalid state for requested operation */
    U_REGEX_BAD_ESCAPE_SEQUENCE,          /**< Unrecognized backslash escape sequence in pattern  */
    U_REGEX_PROPERTY_SYNTAX,              /**< Incorrect Unicode property                         */
    U_REGEX_UNIMPLEMENTED,                /**< Use of regexp feature that is not yet implemented. */
    U_REGEX_MISMATCHED_PAREN,             /**< Incorrectly nested parentheses in regexp pattern.  */
    U_REGEX_NUMBER_TOO_BIG,               /**< Decimal number is too large.                       */
    U_REGEX_BAD_INTERVAL,                 /**< Error in {min,max} interval                        */
    U_REGEX_MAX_LT_MIN,                   /**< In {min,max}, max is less than min.                */
    U_REGEX_INVALID_BACK_REF,             /**< Back-reference to a non-existent capture group.    */
    U_REGEX_INVALID_FLAG,                 /**< Invalid value for match mode flags.                */
    U_REGEX_LOOK_BEHIND_LIMIT,            /**< Look-Behind pattern matches must have a bounded maximum length.    */
    U_REGEX_SET_CONTAINS_STRING,          /**< Regexps cannot have UnicodeSets containing strings.*/
#ifndef U_HIDE_DEPRECATED_API
    U_REGEX_OCTAL_TOO_BIG,                /**< Octal character constants must be <= 0377. @deprecated ICU 54. This error cannot occur. */
#endif  /* U_HIDE_DEPRECATED_API */
    U_REGEX_MISSING_CLOSE_BRACKET=U_REGEX_SET_CONTAINS_STRING+2, /**< Missing closing bracket on a bracket expression. */
    U_REGEX_INVALID_RANGE,                /**< In a character range [x-y], x is greater than y.   */
    U_REGEX_STACK_OVERFLOW,               /**< Regular expression backtrack stack overflow.       */
    U_REGEX_TIME_OUT,                     /**< Maximum allowed match time exceeded                */
    U_REGEX_STOPPED_BY_CALLER,            /**< Matching operation aborted by user callback fn.    */
#ifndef U_HIDE_DRAFT_API
    U_REGEX_PATTERN_TOO_BIG,              /**< Pattern exceeds limits on size or complexity. @draft ICU 55 */
    U_REGEX_INVALID_CAPTURE_GROUP_NAME,   /**< Invalid capture group name. @draft ICU 55 */
#endif  /* U_HIDE_DRAFT_API */
    U_REGEX_ERROR_LIMIT=U_REGEX_STOPPED_BY_CALLER+3, /**< This must always be the last value to indicate the limit for regexp errors */

    /*
     * The error code in the range 0x10400-0x104ff are reserved for IDNA related error codes
     */
    U_IDNA_PROHIBITED_ERROR=0x10400,
    U_IDNA_ERROR_START=0x10400,
    U_IDNA_UNASSIGNED_ERROR,
    U_IDNA_CHECK_BIDI_ERROR,
    U_IDNA_STD3_ASCII_RULES_ERROR,
    U_IDNA_ACE_PREFIX_ERROR,
    U_IDNA_VERIFICATION_ERROR,
    U_IDNA_LABEL_TOO_LONG_ERROR,
    U_IDNA_ZERO_LENGTH_LABEL_ERROR,
    U_IDNA_DOMAIN_NAME_TOO_LONG_ERROR,
    U_IDNA_ERROR_LIMIT,
    /*
     * Aliases for StringPrep
     */
    U_STRINGPREP_PROHIBITED_ERROR = U_IDNA_PROHIBITED_ERROR,
    U_STRINGPREP_UNASSIGNED_ERROR = U_IDNA_UNASSIGNED_ERROR,
    U_STRINGPREP_CHECK_BIDI_ERROR = U_IDNA_CHECK_BIDI_ERROR,

    /*
     * The error code in the range 0x10500-0x105ff are reserved for Plugin related error codes
     */
    U_PLUGIN_ERROR_START=0x10500,         /**< Start of codes indicating plugin failures */
    U_PLUGIN_TOO_HIGH=0x10500,            /**< The plugin's level is too high to be loaded right now. */
    U_PLUGIN_DIDNT_SET_LEVEL,             /**< The plugin didn't call uplug_setPlugLevel in response to a QUERY */
    U_PLUGIN_ERROR_LIMIT,                 /**< This must always be the last value to indicate the limit for plugin errors */

    U_ERROR_LIMIT=U_PLUGIN_ERROR_LIMIT      /**< This must always be the last value to indicate the limit for UErrorCode (last error code +1) */
} UErrorCode;

typedef struct {
    /** sizeof(UDataInfo)
     *  @stable ICU 2.0 */
    u_int16_t size;

    /** unused, set to 0
     *  @stable ICU 2.0*/
    u_int16_t reservedWord;

    /* platform data properties */
    /** 0 for little-endian machine, 1 for big-endian
     *  @stable ICU 2.0 */
    uint8_t isBigEndian;

    /** see U_CHARSET_FAMILY values in utypes.h
     *  @stable ICU 2.0*/
    uint8_t charsetFamily;

    /** sizeof(UChar), one of { 1, 2, 4 }
     *  @stable ICU 2.0*/
    uint8_t sizeofUChar;

    /** unused, set to 0
     *  @stable ICU 2.0*/
    uint8_t reservedByte;

    /** data format identifier
     *  @stable ICU 2.0*/
    uint8_t dataFormat[4];

    /** versions: [0] major [1] minor [2] milli [3] micro
     *  @stable ICU 2.0*/
    uint8_t formatVersion[4];

    /** versions: [0] major [1] minor [2] milli [3] micro
     *  @stable ICU 2.0*/
    uint8_t dataVersion[4];
} UDataInfo;

typedef struct  {
    u_int16_t    headerSize;
    uint8_t     magic1;
    uint8_t     magic2;
} MappedData;

typedef struct  {
    MappedData  dataHeader;
    UDataInfo   info;
} DataHeader;

struct UDataMemory;

typedef const DataHeader *
(* LookupFn)(const UDataMemory *pData,
                        const char *tocEntryName,
                        int32_t *pLength,
                        UErrorCode *pErrorCode);

typedef u_int32_t
(* NumEntriesFn)(const UDataMemory *pData);

typedef struct {
    LookupFn      Lookup;
    NumEntriesFn  NumEntries;
} commonDataFuncs;
struct UDataMemory {
    const commonDataFuncs  *vFuncs;      /* Function Pointers for accessing TOC             */

    const DataHeader *pHeader;     /* Header of the memory being described by this    */
                                   /*   UDataMemory object.                           */
    const void       *toc;         /* For common memory, table of contents for        */
                                   /*   the pieces within.                            */
    UBool             heapAllocated;  /* True if this UDataMemory Object is on the    */
                                   /*  heap and thus needs to be deleted when closed. */

    void             *mapAddr;     /* For mapped or allocated memory, the start addr. */
                                   /* Only non-null if a close operation should unmap */
                                   /*  the associated data.                           */
    void             *map;         /* Handle, or other data, OS dependent.            */
                                   /* Only non-null if a close operation should unmap */
                                   /*  the associated data, and additional info       */
                                   /*   beyond the mapAddr is needed to do that.      */
    int32_t           length;      /* Length of the data in bytes; -1 if unknown.     */
};
struct UBiDiProps {
    UDataMemory *mem;
    const int32_t *indexes;
    const u_int32_t *mirrors;
    const uint8_t *jgArray;
    const uint8_t *jgArray2;

    UTrie2 trie;
    uint8_t formatVersion[4];
};

/* definitions for 16-bit bidi/shaping properties word ---------------------- */

enum {
 /* UBIDI_CLASS_SHIFT=0, */     /* bidi class: 5 bits (4..0) */
    UBIDI_JT_SHIFT=5,           /* joining type: 3 bits (7..5) */

    UBIDI_BPT_SHIFT=8,          /* Bidi_Paired_Bracket_Type(bpt): 2 bits (9..8) */

    UBIDI_JOIN_CONTROL_SHIFT=10,
    UBIDI_BIDI_CONTROL_SHIFT=11,

    UBIDI_IS_MIRRORED_SHIFT=12,         /* 'is mirrored' */
    UBIDI_MIRROR_DELTA_SHIFT=13,        /* bidi mirroring delta: 3 bits (15..13) */

    UBIDI_MAX_JG_SHIFT=16               /* max JG value in indexes[UBIDI_MAX_VALUES_INDEX] bits 23..16 */
};
#define UBIDI_CLASS_MASK        0x0000001f
#define UBIDI_JT_MASK           0x000000e0
#define UBIDI_BPT_MASK          0x00000300

#define UBIDI_MAX_JG_MASK       0x00ff0000

#define UBIDI_GET_CLASS(props) ((props)&UBIDI_CLASS_MASK)
#define UBIDI_GET_FLAG(props, shift) (((props)>>(shift))&1)

#if U_SIGNED_RIGHT_SHIFT_IS_ARITHMETIC
#   define UBIDI_GET_MIRROR_DELTA(props) ((int16_t)(props)>>UBIDI_MIRROR_DELTA_SHIFT)
#else
#   define UBIDI_GET_MIRROR_DELTA(props) (int16_t)(((props)&0x8000) ? (((props)>>UBIDI_MIRROR_DELTA_SHIFT)|0xe000) : ((props)>>UBIDI_MIRROR_DELTA_SHIFT))
#endif

/* definitions for 32-bit mirror table entry -------------------------------- */

enum {
    /* the source Unicode code point takes 21 bits (20..0) */
    UBIDI_MIRROR_INDEX_SHIFT=21,
    UBIDI_MAX_MIRROR_INDEX=0x7ff
};
enum {
    UBIDI_ESC_MIRROR_DELTA=-4,
    UBIDI_MIN_MIRROR_DELTA=-3,
    UBIDI_MAX_MIRROR_DELTA=3
};

#define UBIDI_GET_MIRROR_CODE_POINT(m) (u_int32_t)((m)&0x1fffff)

#define UBIDI_GET_MIRROR_INDEX(m) ((m)>>UBIDI_MIRROR_INDEX_SHIFT)

/**
 * This specifies the language directional property of a character set.
 * @stable ICU 2.0
 */
typedef enum UCharDirection {
    /*
     * Note: UCharDirection constants and their API comments are parsed by preparseucd.py.
     * It matches pairs of lines like
     *     / ** <Unicode 1..3-letter Bidi_Class value> comment... * /
     *     U_<[A-Z_]+> = <integer>,
     */

    /** L @stable ICU 2.0 */
    U_LEFT_TO_RIGHT               = 0,
    /** R @stable ICU 2.0 */
    U_RIGHT_TO_LEFT               = 1,
    /** EN @stable ICU 2.0 */
    U_EUROPEAN_NUMBER             = 2,
    /** ES @stable ICU 2.0 */
    U_EUROPEAN_NUMBER_SEPARATOR   = 3,
    /** ET @stable ICU 2.0 */
    U_EUROPEAN_NUMBER_TERMINATOR  = 4,
    /** AN @stable ICU 2.0 */
    U_ARABIC_NUMBER               = 5,
    /** CS @stable ICU 2.0 */
    U_COMMON_NUMBER_SEPARATOR     = 6,
    /** B @stable ICU 2.0 */
    U_BLOCK_SEPARATOR             = 7,
    /** S @stable ICU 2.0 */
    U_SEGMENT_SEPARATOR           = 8,
    /** WS @stable ICU 2.0 */
    U_WHITE_SPACE_NEUTRAL         = 9,
    /** ON @stable ICU 2.0 */
    U_OTHER_NEUTRAL               = 10,
    /** LRE @stable ICU 2.0 */
    U_LEFT_TO_RIGHT_EMBEDDING     = 11,
    /** LRO @stable ICU 2.0 */
    U_LEFT_TO_RIGHT_OVERRIDE      = 12,
    /** AL @stable ICU 2.0 */
    U_RIGHT_TO_LEFT_ARABIC        = 13,
    /** RLE @stable ICU 2.0 */
    U_RIGHT_TO_LEFT_EMBEDDING     = 14,
    /** RLO @stable ICU 2.0 */
    U_RIGHT_TO_LEFT_OVERRIDE      = 15,
    /** PDF @stable ICU 2.0 */
    U_POP_DIRECTIONAL_FORMAT      = 16,
    /** NSM @stable ICU 2.0 */
    U_DIR_NON_SPACING_MARK        = 17,
    /** BN @stable ICU 2.0 */
    U_BOUNDARY_NEUTRAL            = 18,
    /** FSI @stable ICU 52 */
    U_FIRST_STRONG_ISOLATE        = 19,
    /** LRI @stable ICU 52 */
    U_LEFT_TO_RIGHT_ISOLATE       = 20,
    /** RLI @stable ICU 52 */
    U_RIGHT_TO_LEFT_ISOLATE       = 21,
    /** PDI @stable ICU 52 */
    U_POP_DIRECTIONAL_ISOLATE     = 22,
    /** @stable ICU 2.0 */
    U_CHAR_DIRECTION_COUNT
} UCharDirection;


UCharDirection
ubidi_getClass(const UBiDiProps *bdp, u_int32_t c) throw();

UBool
ubidi_isMirrored(const UBiDiProps *bdp, u_int32_t c) throw();

u_int32_t
getMirror(const UBiDiProps *bdp, u_int32_t c, uint16_t props) throw();

u_int32_t
ubidi_getMirror(const UBiDiProps *bdp, u_int32_t c) throw();

}

#endif /* UNICODE_UBIDI_PROPS_H_ */
