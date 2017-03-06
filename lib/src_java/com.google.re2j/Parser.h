#ifndef COM_GOOGLE_RE2J_PARSER_H_
#define COM_GOOGLE_RE2J_PARSER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class Regexp;}}}

namespace com {namespace google {namespace re2j {
class PatternSyntaxException;}}}

namespace com {namespace google {namespace re2j {
class CharClass;}}}

namespace com {namespace google {namespace re2j {
class Parser;}}}

namespace com {namespace google {namespace re2j {
class CharGroup;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace com {namespace google {namespace re2j {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class Parser final : public virtual IObject {
public:
	class Stack;
	class StringIterator;
	template <typename F, typename S> class Pair;
	Parser(const Parser& base) = default;
public:
	Parser(String* wholeRegexp, int flags, ThreadContext* ctx) throw() ;
	void __construct_impl(String* wholeRegexp, int flags, ThreadContext* ctx) throw() ;
	virtual ~Parser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* wholeRegexp;
	int flags;
	Parser::Stack* stack;
	Regexp* free;
	int numCap;
public:
	static String* ERR_INVALID_CHAR_CLASS;
private:
	static String* ERR_INTERNAL_ERROR;
	static String* ERR_INVALID_CHAR_RANGE;
	static String* ERR_INVALID_ESCAPE;
	static String* ERR_INVALID_NAMED_CAPTURE;
	static String* ERR_INVALID_PERL_OP;
	static String* ERR_INVALID_REPEAT_OP;
	static String* ERR_INVALID_REPEAT_SIZE;
	static String* ERR_MISSING_BRACKET;
	static String* ERR_MISSING_PAREN;
	static String* ERR_MISSING_REPEAT_ARGUMENT;
	static String* ERR_TRAILING_BACKSLASH;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __ANY_TABLE;
	static IArrayObject<IArrayObjectPrimitive<int>>* ANY_TABLE;
private:
	Regexp* newRegexp(Regexp::Op op, ThreadContext* ctx) throw() ;
	void reuse(Regexp* re, ThreadContext* ctx) throw() ;
	Regexp* pop(ThreadContext* ctx) throw() ;
	IArrayObject<Regexp>* popToPseudo(ThreadContext* ctx) throw() ;
	Regexp* push(Regexp* re, ThreadContext* ctx) throw() ;
	bool maybeConcat(int r, int flags, ThreadContext* ctx) throw() ;
	Regexp* newLiteral(int r, int flags, ThreadContext* ctx) throw() ;
	void literal(int r, ThreadContext* ctx) throw() ;
	Regexp* op(Regexp::Op op, ThreadContext* ctx) throw() ;
	void repeat(Regexp::Op op, int min, int max, int beforePos, Parser::StringIterator* t, int lastRepeatPos, ThreadContext* ctx);
	Regexp* concat(ThreadContext* ctx) throw() ;
	Regexp* alternate(ThreadContext* ctx) throw() ;
	void cleanAlt(Regexp* re, ThreadContext* ctx) throw() ;
	Regexp* collapse(IArrayObject<Regexp>* subs, Regexp::Op op, ThreadContext* ctx) throw() ;
	IArrayObject<Regexp>* factor(IArrayObject<Regexp>* array, int flags, ThreadContext* ctx) throw() ;
	Regexp* removeLeadingString(Regexp* re, int n, ThreadContext* ctx) throw() ;
	Regexp* removeLeadingRegexp(Regexp* re, bool _reuse, ThreadContext* ctx) throw() ;
	Regexp* parseInternal(ThreadContext* ctx);
	void parsePerlFlags(Parser::StringIterator* t, ThreadContext* ctx);
	void parseVerticalBar(ThreadContext* ctx) throw() ;
	bool swapVerticalBar(ThreadContext* ctx) throw() ;
	void parseRightParen(ThreadContext* ctx);
	bool parsePerlClassEscape(Parser::StringIterator* t, CharClass* cc, ThreadContext* ctx) throw() ;
	bool parseNamedClass(Parser::StringIterator* t, CharClass* cc, ThreadContext* ctx);
	bool parseUnicodeClass(Parser::StringIterator* t, CharClass* cc, ThreadContext* ctx);
	void parseClass(Parser::StringIterator* t, ThreadContext* ctx);
public:
	static Regexp* parse(String* pattern, int flags, ThreadContext* ctx);
	static IArrayObject<Regexp>* subarray(IArrayObject<Regexp>* array, int start, int end, ThreadContext* ctx) throw() ;
private:
	static int minFoldRune(int r, ThreadContext* ctx) throw() ;
	static Regexp* leadingRegexp(Regexp* re, ThreadContext* ctx) throw() ;
	static Regexp* literalRegexp(String* s, int flags, ThreadContext* ctx) throw() ;
	static int parseRepeat(Parser::StringIterator* t, ThreadContext* ctx);
	static bool isValidCaptureName(String* name, ThreadContext* ctx) throw() ;
	static int parseInt(Parser::StringIterator* t, ThreadContext* ctx) throw() ;
	static bool isCharClass(Regexp* re, ThreadContext* ctx) throw() ;
	static bool matchRune(Regexp* re, int r, ThreadContext* ctx) throw() ;
	static void mergeCharClass(Regexp* dst, Regexp* src, ThreadContext* ctx) throw() ;
	static int parseEscape(Parser::StringIterator* t, ThreadContext* ctx);
	static int parseClassChar(Parser::StringIterator* t, int wholeClassPos, ThreadContext* ctx);
	static Parser::Pair<IArrayObject<IArrayObjectPrimitive<int>>,IArrayObject<IArrayObjectPrimitive<int>>>* unicodeTable(String* name, ThreadContext* ctx) throw() ;
	static IArrayObjectPrimitive<int>* concatRunes(IArrayObjectPrimitive<int>* x, IArrayObjectPrimitive<int>* y, ThreadContext* ctx) throw() ;
public:



	class Stack final : public ArrayList<Regexp> {
	public:
		Stack(const Stack& base) = default;
	public:
		Stack(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~Stack() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		constexpr static const long long serialVersionUID{-121602136579413677L};
	public:
		void removeRange(int fromIndex, int toIndex, ThreadContext* ctx) throw()  final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};




	class StringIterator final : public virtual IObject {
	public:
		StringIterator(const StringIterator& base) = default;
	public:
		StringIterator(String* str, ThreadContext* ctx) throw() ;
		void __construct_impl(String* str, ThreadContext* ctx) throw() ;
		virtual ~StringIterator() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	private:
		String* str;
		int _pos;
	public:
		String* toString(ThreadContext* ctx) throw() ;
		int pos(ThreadContext* ctx) throw() ;
		void rewindTo(int pos, ThreadContext* ctx) throw() ;
		bool more(ThreadContext* ctx) throw() ;
		int peek(ThreadContext* ctx) throw() ;
		void skip(int n, ThreadContext* ctx) throw() ;
		void skipString(String* s, ThreadContext* ctx) throw() ;
		int pop(ThreadContext* ctx) throw() ;
		bool lookingAt(wchar_t c, ThreadContext* ctx) throw() ;
		bool lookingAt(String* s, ThreadContext* ctx) throw() ;
		String* rest(ThreadContext* ctx) throw() ;
		String* from(int beforePos, ThreadContext* ctx) throw() ;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};




	template <typename F, typename S>
	class Pair final : public virtual IObject {
	public:
		Pair(const Pair& base) = default;
	public:
		Pair(F* first, S* second, ThreadContext* ctx) throw() ;
		void __construct_impl(F* first, S* second, ThreadContext* ctx) throw() ;
		virtual ~Pair() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		F* first;
		S* second;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_PARSER_H_ */
