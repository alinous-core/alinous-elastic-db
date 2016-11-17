#ifndef ALINOUS_SYSTEM_CONFIG_ALINOUSINITEXCEPTION_H_
#define ALINOUS_SYSTEM_CONFIG_ALINOUSINITEXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::system::AlinousException;



class AlinousInitException final : public AlinousException {
public:
	AlinousInitException(const AlinousInitException& base) = default;
public:
	AlinousInitException(String* msg, ThreadContext* ctx) throw() ;
	void __construct_impl(String* msg, ThreadContext* ctx) throw() ;
	virtual ~AlinousInitException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{1L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_ALINOUSINITEXCEPTION_H_ */
