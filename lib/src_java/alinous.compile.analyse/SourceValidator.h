#ifndef ALINOUS_COMPILE_ANALYSE_SOURCEVALIDATOR_H_
#define ALINOUS_COMPILE_ANALYSE_SOURCEVALIDATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidationError;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

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
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IStatement;



class SourceValidator final : public IAlinousElementVisitor, public virtual IObject {
public:
	SourceValidator(const SourceValidator& base) = default;
public:
	SourceValidator(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~SourceValidator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<SourceValidationError>* errors;
public:
	bool visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void addError(String* message, IAlinousElement* element, ThreadContext* ctx) throw() ;
	void addWarning(String* message, IAlinousElement* element, ThreadContext* ctx) throw() ;
	void addInfo(String* message, IAlinousElement* element, ThreadContext* ctx) throw() ;
	ArrayList<SourceValidationError>* getErrors(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_SOURCEVALIDATOR_H_ */
