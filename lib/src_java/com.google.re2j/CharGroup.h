#ifndef COM_GOOGLE_RE2J_CHARGROUP_H_
#define COM_GOOGLE_RE2J_CHARGROUP_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace util {
template <typename  T, typename V> class StaticMap;}}

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
using ::alinous::util::StaticMap;



class CharGroup final : public virtual IObject {
public:
	CharGroup(const CharGroup& base) = default;
public:
	CharGroup(int sign, IArrayObjectPrimitive<int>* cls, ThreadContext* ctx) throw() ;
	void __construct_impl(int sign, IArrayObjectPrimitive<int>* cls, ThreadContext* ctx) throw() ;
	virtual ~CharGroup() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int sign;
	IArrayObjectPrimitive<int>* cls;
public:
	static StaticMap<String, CharGroup> __HASH__PERL_GROUPS;
	static StaticMap<String,CharGroup>* PERL_GROUPS;
	static StaticMap<String, CharGroup> __HASH__POSIX_GROUPS;
	static StaticMap<String,CharGroup>* POSIX_GROUPS;
private:
	static const StaticArrayObjectPrimitive<int> __code1;
	static IArrayObjectPrimitive<int>* code1;
	static const StaticArrayObjectPrimitive<int> __code2;
	static IArrayObjectPrimitive<int>* code2;
	static const StaticArrayObjectPrimitive<int> __code3;
	static IArrayObjectPrimitive<int>* code3;
	static const StaticArrayObjectPrimitive<int> __code4;
	static IArrayObjectPrimitive<int>* code4;
	static const StaticArrayObjectPrimitive<int> __code5;
	static IArrayObjectPrimitive<int>* code5;
	static const StaticArrayObjectPrimitive<int> __code6;
	static IArrayObjectPrimitive<int>* code6;
	static const StaticArrayObjectPrimitive<int> __code7;
	static IArrayObjectPrimitive<int>* code7;
	static const StaticArrayObjectPrimitive<int> __code8;
	static IArrayObjectPrimitive<int>* code8;
	static const StaticArrayObjectPrimitive<int> __code9;
	static IArrayObjectPrimitive<int>* code9;
	static const StaticArrayObjectPrimitive<int> __code10;
	static IArrayObjectPrimitive<int>* code10;
	static const StaticArrayObjectPrimitive<int> __code11;
	static IArrayObjectPrimitive<int>* code11;
	static const StaticArrayObjectPrimitive<int> __code12;
	static IArrayObjectPrimitive<int>* code12;
	static const StaticArrayObjectPrimitive<int> __code13;
	static IArrayObjectPrimitive<int>* code13;
	static const StaticArrayObjectPrimitive<int> __code14;
	static IArrayObjectPrimitive<int>* code14;
	static const StaticArrayObjectPrimitive<int> __code15;
	static IArrayObjectPrimitive<int>* code15;
	static const StaticArrayObjectPrimitive<int> __code16;
	static IArrayObjectPrimitive<int>* code16;
	static const StaticArrayObjectPrimitive<int> __code17;
	static IArrayObjectPrimitive<int>* code17;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_CHARGROUP_H_ */
