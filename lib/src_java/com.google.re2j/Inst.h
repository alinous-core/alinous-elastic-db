#ifndef COM_GOOGLE_RE2J_INST_H_
#define COM_GOOGLE_RE2J_INST_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IllegalStateException;}}

namespace java {namespace lang {
class StringBuilder;}}

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

class __Inst__Op : public EnumBase {
public:
	__Inst__Op() = default;
	constexpr __Inst__Op(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __Inst__Op(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  ALT{1};
	static constexpr EnumBase  ALT_MATCH{2};
	static constexpr EnumBase  CAPTURE{3};
	static constexpr EnumBase  EMPTY_WIDTH{4};
	static constexpr EnumBase  FAIL{5};
	static constexpr EnumBase  MATCH{6};
	static constexpr EnumBase  NOP{7};
	static constexpr EnumBase  RUNE{8};
	static constexpr EnumBase  RUNE1{9};
	static constexpr EnumBase  RUNE_ANY{10};
	static constexpr EnumBase  RUNE_ANY_NOT_NL{11};
};


class Inst final : public virtual IObject {
public:
	class Op : public __Inst__Op {
	public:
		Op() = default;constexpr Op(const EnumBase& base) :  __Inst__Op(base) {};
	};
public:
	Inst(const Inst& base) = default;
public:
	Inst(Inst::Op op, ThreadContext* ctx) throw() ;
	void __construct_impl(Inst::Op op, ThreadContext* ctx) throw() ;
	virtual ~Inst() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Inst::Op _op;
	int out;
	int arg;
	IArrayObjectPrimitive<int>* runes;
public:
	String* toString(ThreadContext* ctx) throw() ;
	Inst::Op op(ThreadContext* ctx) throw() ;
	bool matchRune(int r, ThreadContext* ctx) throw() ;
private:
	static String* escapeRunes(IArrayObjectPrimitive<int>* runes, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_INST_H_ */
