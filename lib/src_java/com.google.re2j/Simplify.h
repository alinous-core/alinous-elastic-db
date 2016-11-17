#ifndef COM_GOOGLE_RE2J_SIMPLIFY_H_
#define COM_GOOGLE_RE2J_SIMPLIFY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class Regexp;}}}

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



class Simplify final : public virtual IObject {
public:
	Simplify(const Simplify& base) = default;
public:
	Simplify(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Simplify() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static Regexp* simplify(Regexp* re, ThreadContext* ctx) throw() ;
private:
	static Regexp* simplify1(Regexp::Op op, int flags, Regexp* sub, Regexp* re, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_SIMPLIFY_H_ */
