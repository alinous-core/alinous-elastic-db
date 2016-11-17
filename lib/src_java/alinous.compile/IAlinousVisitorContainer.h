#ifndef ALINOUS_COMPILE_IALINOUSVISITORCONTAINER_H_
#define ALINOUS_COMPILE_IALINOUSVISITORCONTAINER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IAlinousVisitorContainer : public virtual IObject {
public:
	IAlinousVisitorContainer(const IAlinousVisitorContainer& base) = default;
public:
	IAlinousVisitorContainer(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IAlinousVisitorContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_IALINOUSVISITORCONTAINER_H_ */
