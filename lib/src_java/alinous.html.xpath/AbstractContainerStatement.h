#ifndef ALINOUS_HTML_XPATH_ABSTRACTCONTAINERSTATEMENT_H_
#define ALINOUS_HTML_XPATH_ABSTRACTCONTAINERSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IXpathBooleanCondition;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class AbstractContainerStatement : public IXpathBooleanCondition, public virtual IObject {
public:
	AbstractContainerStatement(const AbstractContainerStatement& base) = default;
public:
	AbstractContainerStatement(ThreadContext* ctx) throw()  : IObject(ctx), IXpathBooleanCondition(ctx), statements(GCUtils<ArrayList<IXpathBooleanCondition> >::ins(this, (new(ctx) ArrayList<IXpathBooleanCondition>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractContainerStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<IXpathBooleanCondition>* statements;
public:
	void addStatement(IXpathBooleanCondition* stmt, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_ABSTRACTCONTAINERSTATEMENT_H_ */
