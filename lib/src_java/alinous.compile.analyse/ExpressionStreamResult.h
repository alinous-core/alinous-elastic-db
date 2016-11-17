#ifndef ALINOUS_COMPILE_ANALYSE_EXPRESSIONSTREAMRESULT_H_
#define ALINOUS_COMPILE_ANALYSE_EXPRESSIONSTREAMRESULT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::expression::DomVariableDescriptor;



class ExpressionStreamResult final : public virtual IObject {
public:
	ExpressionStreamResult(const ExpressionStreamResult& base) = default;
public:
	ExpressionStreamResult(ThreadContext* ctx) throw()  : IObject(ctx), domPath(nullptr), type(nullptr), functionPrefix(nullptr), staticMember(0), maxCount(0), count(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ExpressionStreamResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DomVariableDescriptor* domPath;
	AlinousType* type;
	String* functionPrefix;
	bool staticMember;
	int maxCount;
	int count;
public:
	void clear(ThreadContext* ctx) throw() ;
	bool isLastSegment(ThreadContext* ctx) throw() ;
	void setMaxCount(int maxCount, ThreadContext* ctx) throw() ;
	void setCount(int count, ThreadContext* ctx) throw() ;
	DomVariableDescriptor* getDomPath(ThreadContext* ctx) throw() ;
	void setDomPath(DomVariableDescriptor* domPath, ThreadContext* ctx) throw() ;
	AlinousType* getType(ThreadContext* ctx) throw() ;
	void setType(AlinousType* type, ThreadContext* ctx) throw() ;
	String* getFunctionPrefix(ThreadContext* ctx) throw() ;
	void setFunctionPrefix(String* functionPrefix, ThreadContext* ctx) throw() ;
	bool isStaticMember(ThreadContext* ctx) throw() ;
	void setStaticMember(bool staticMethod, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_EXPRESSIONSTREAMRESULT_H_ */
