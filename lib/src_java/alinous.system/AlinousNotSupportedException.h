#ifndef ALINOUS_SYSTEM_ALINOUSNOTSUPPORTEDEXCEPTION_H_
#define ALINOUS_SYSTEM_ALINOUSNOTSUPPORTEDEXCEPTION_H_
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

namespace alinous {namespace system {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class AlinousNotSupportedException final : public AlinousException {
public:
	AlinousNotSupportedException(const AlinousNotSupportedException& base) = default;
public:
	AlinousNotSupportedException(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	AlinousNotSupportedException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	AlinousNotSupportedException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~AlinousNotSupportedException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{-707132385537860775L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_SYSTEM_ALINOUSNOTSUPPORTEDEXCEPTION_H_ */
