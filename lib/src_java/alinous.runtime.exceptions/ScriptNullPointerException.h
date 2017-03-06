#ifndef ALINOUS_RUNTIME_EXCEPTIONS_SCRIPTNULLPOINTEREXCEPTION_H_
#define ALINOUS_RUNTIME_EXCEPTIONS_SCRIPTNULLPOINTEREXCEPTION_H_
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace exceptions {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::system::AlinousException;



class ScriptNullPointerException final : public AlinousException {
public:
	ScriptNullPointerException(const ScriptNullPointerException& base) = default;
public:
	ScriptNullPointerException(AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	void __construct_impl(AbstractSrcElement* element, ThreadContext* ctx) throw() ;
	virtual ~ScriptNullPointerException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AbstractSrcElement* element;
private:
	constexpr static const long long serialVersionUID{1L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_EXCEPTIONS_SCRIPTNULLPOINTEREXCEPTION_H_ */
