#ifndef ALINOUS_COMPILE_ANALYSE_DOMVARIABLEDECLARESOURCE_H_
#define ALINOUS_COMPILE_ANALYSE_DOMVARIABLEDECLARESOURCE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

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
using ::alinous::compile::expression::IExpression;



class DomVariableDeclareSource final : public virtual IObject {
public:
	DomVariableDeclareSource(const DomVariableDeclareSource& base) = default;
public:
	DomVariableDeclareSource(String* domPath, IExpression* exp, ThreadContext* ctx) throw() ;
	void __construct_impl(String* domPath, IExpression* exp, ThreadContext* ctx) throw() ;
	virtual ~DomVariableDeclareSource() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* domPath;
	IExpression* exp;
public:
	String* getDomPath(ThreadContext* ctx) throw() ;
	void setDomPath(String* domPath, ThreadContext* ctx) throw() ;
	IExpression* getExp(ThreadContext* ctx) throw() ;
	void setExp(IExpression* exp, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_DOMVARIABLEDECLARESOURCE_H_ */
