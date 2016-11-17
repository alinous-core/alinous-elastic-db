#ifndef ALINOUS_COMPILE_DECLARE_IDECLARE_H_
#define ALINOUS_COMPILE_DECLARE_IDECLARE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousVisitorContainer;



class IDeclare : public IAlinousElement, public IAlinousVisitorContainer {
public:
	IDeclare(const IDeclare& base) = default;
public:
	IDeclare(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDeclare() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_IDECLARE_H_ */
