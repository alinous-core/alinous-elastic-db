#ifndef COM_GOOGLE_RE2J_REGEXP_H_
#define COM_GOOGLE_RE2J_REGEXP_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class Regexp;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace util {
class Arrays;}}

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
using ::java::util::Arrays;

class __Regexp__Op : public EnumBase {
public:
	__Regexp__Op() = default;
	constexpr __Regexp__Op(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __Regexp__Op(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  NO_MATCH{1};
	static constexpr EnumBase  EMPTY_MATCH{2};
	static constexpr EnumBase  LITERAL{3};
	static constexpr EnumBase  CHAR_CLASS{4};
	static constexpr EnumBase  ANY_CHAR_NOT_NL{5};
	static constexpr EnumBase  ANY_CHAR{6};
	static constexpr EnumBase  BEGIN_LINE{7};
	static constexpr EnumBase  END_LINE{8};
	static constexpr EnumBase  BEGIN_TEXT{9};
	static constexpr EnumBase  END_TEXT{10};
	static constexpr EnumBase  WORD_BOUNDARY{11};
	static constexpr EnumBase  NO_WORD_BOUNDARY{12};
	static constexpr EnumBase  CAPTURE{13};
	static constexpr EnumBase  STAR{14};
	static constexpr EnumBase  PLUS{15};
	static constexpr EnumBase  QUEST{16};
	static constexpr EnumBase  REPEAT{17};
	static constexpr EnumBase  CONCAT{18};
	static constexpr EnumBase  ALTERNATE{19};
	static constexpr EnumBase  LEFT_PAREN{20};
	static constexpr EnumBase  VERTICAL_BAR{21};
};


class Regexp final : public virtual IObject {
public:
	class Op : public __Regexp__Op {
	public:
		Op() = default;constexpr Op(const EnumBase& base) :  __Regexp__Op(base) {};
	};
public:
	Regexp(const Regexp& base) = default;
public:
	Regexp(Regexp::Op op, ThreadContext* ctx) throw() ;
	void __construct_impl(Regexp::Op op, ThreadContext* ctx) throw() ;
	Regexp(Regexp* that, ThreadContext* ctx) throw() ;
	void __construct_impl(Regexp* that, ThreadContext* ctx) throw() ;
	virtual ~Regexp() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Regexp::Op op;
	int flags;
	IArrayObject<Regexp>* subs;
	IArrayObjectPrimitive<int>* runes;
	int min; int max;
	int cap;
	String* name;
public:
	static const StaticArrayObject<Regexp> __EMPTY_SUBS;
	static IArrayObject<Regexp>* EMPTY_SUBS;
public:
	String* toString(ThreadContext* ctx) throw() ;
	bool equals(IObject* that, ThreadContext* ctx) throw() ;
	void reinit(ThreadContext* ctx) throw() ;
	int maxCap(ThreadContext* ctx) throw() ;
private:
	void appendTo(StringBuilder* out, ThreadContext* ctx) throw() ;
public:
	static bool isPseudo(Regexp::Op op, ThreadContext* ctx) throw() ;
private:
	static void quoteIfHyphen(StringBuilder* out, int rune, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_REGEXP_H_ */
