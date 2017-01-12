#ifndef ALINOUS_COMPILE_IALINOUSELEMENT_H_
#define ALINOUS_COMPILE_IALINOUSELEMENT_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::remote::socket::ICommandData;



class IAlinousElement : public AbstractSrcElement, public ICommandData {
public:
	IAlinousElement(const IAlinousElement& base) = default;
public:
	IAlinousElement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSrcElement(ctx), ICommandData(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IAlinousElement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_IALINOUSELEMENT_H_ */
