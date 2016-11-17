#ifndef ALINOUS_RUNTIME_DOM_VARIABLEEXCEPTION_H_
#define ALINOUS_RUNTIME_DOM_VARIABLEEXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace runtime {
class ExecutionException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::runtime::ExecutionException;



class VariableException final : public ExecutionException {
public:
	VariableException(const VariableException& base) = default;
public:
	VariableException(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	VariableException(Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(Throwable* e, ThreadContext* ctx) throw() ;
	VariableException(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	VariableException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	VariableException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	virtual ~VariableException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{4881047534879847288L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_VARIABLEEXCEPTION_H_ */
