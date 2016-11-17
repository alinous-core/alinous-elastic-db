#ifndef ALINOUS_COMPILE_IALINOUSELEMENTVISITOR_H_
#define ALINOUS_COMPILE_IALINOUSELEMENTVISITOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
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



class IAlinousElementVisitor : public virtual IObject {
public:
	IAlinousElementVisitor(const IAlinousElementVisitor& base) = default;
public:
	IAlinousElementVisitor(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IAlinousElementVisitor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual bool visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_IALINOUSELEMENTVISITOR_H_ */
