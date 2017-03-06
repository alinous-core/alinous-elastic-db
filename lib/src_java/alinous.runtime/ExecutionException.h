#ifndef ALINOUS_RUNTIME_EXECUTIONEXCEPTION_H_
#define ALINOUS_RUNTIME_EXECUTIONEXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::system::AlinousException;



class ExecutionException : public AlinousException {
public:
	ExecutionException(const ExecutionException& base) = default;
public:
	ExecutionException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	ExecutionException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	ExecutionException(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	ExecutionException(Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~ExecutionException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{1L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_RUNTIME_EXECUTIONEXCEPTION_H_ */
