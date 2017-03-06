#ifndef ALINOUS_RUNTIME_ENGINE_ALINOUSNULLPOINTEREXCEPTION_H_
#define ALINOUS_RUNTIME_ENGINE_ALINOUSNULLPOINTEREXCEPTION_H_
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

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::system::AlinousException;



class AlinousNullPointerException final : public AlinousException {
public:
	AlinousNullPointerException(const AlinousNullPointerException& base) = default;
public:
	AlinousNullPointerException(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	AlinousNullPointerException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	AlinousNullPointerException(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() ;
	virtual ~AlinousNullPointerException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{-7328765477824956191L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_ALINOUSNULLPOINTEREXCEPTION_H_ */
