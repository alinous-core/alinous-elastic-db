#ifndef ALINOUS_RUNTIME_COMPILEERROREXCEPTION_H_
#define ALINOUS_RUNTIME_COMPILEERROREXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::system::AlinousException;



class CompileErrorException final : public AlinousException {
public:
	CompileErrorException(const CompileErrorException& base) = default;
public:
	CompileErrorException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~CompileErrorException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{-5434324495718330503L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_RUNTIME_COMPILEERROREXCEPTION_H_ */
