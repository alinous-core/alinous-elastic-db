#ifndef ALINOUS_RUNTIME_MODULENOTFOUNDEXCEPTION_H_
#define ALINOUS_RUNTIME_MODULENOTFOUNDEXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
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



class ModuleNotFoundException final : public AlinousException {
public:
	ModuleNotFoundException(const ModuleNotFoundException& base) = default;
public:
	ModuleNotFoundException(ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ModuleNotFoundException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{-2062009472954794517L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_RUNTIME_MODULENOTFOUNDEXCEPTION_H_ */
