#ifndef COM_GOOGLE_RE2J_UNICODETABLE2_H_
#define COM_GOOGLE_RE2J_UNICODETABLE2_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
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



class UnicodeTable2 final : public virtual IObject {
public:
	UnicodeTable2(const UnicodeTable2& base) = default;
public:
	UnicodeTable2(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~UnicodeTable2() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lm;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lm;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Ll;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Ll;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___C;
	static IArrayObject<IArrayObjectPrimitive<int>>* _C;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___M;
	static IArrayObject<IArrayObjectPrimitive<int>>* _M;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___L;
	static IArrayObject<IArrayObjectPrimitive<int>>* _L;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___N;
	static IArrayObject<IArrayObjectPrimitive<int>>* _N;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___P;
	static IArrayObject<IArrayObjectPrimitive<int>>* _P;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___S;
	static IArrayObject<IArrayObjectPrimitive<int>>* _S;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Z;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Z;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Me;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Me;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Mc;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Mc;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Mn;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Mn;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Zl;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Zl;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Zp;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Zp;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Zs;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Zs;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cs;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cs;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Co;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Co;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cf;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cf;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cc;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cc;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Po;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Po;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Pi;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Pi;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Pf;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Pf;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Pe;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Pe;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Pd;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Pd;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Pc;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Pc;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Ps;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Ps;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Nd;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Nd;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Nl;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Nl;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___No;
	static IArrayObject<IArrayObjectPrimitive<int>>* _No;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___So;
	static IArrayObject<IArrayObjectPrimitive<int>>* _So;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_UNICODETABLE2_H_ */
