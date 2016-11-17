#ifndef ALINOUS_SYSTEM_FUNCTIONS_IALINOUSSYSTEM_H_
#define ALINOUS_SYSTEM_FUNCTIONS_IALINOUSSYSTEM_H_
namespace org{namespace alinous{namespace jdk{
class JavaConnectorFunctionCallback;
}}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace functions {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::org::alinous::jdk::JavaConnectorFunctionCallback;
using ::alinous::system::ISystemLog;



class IAlinousSystem : public virtual IObject {
public:
	IAlinousSystem(const IAlinousSystem& base) = default;
public:
	IAlinousSystem(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IAlinousSystem() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual String* getHome(ThreadContext* ctx) throw()  = 0;
	virtual JavaConnectorFunctionCallback* getJavaConnectorFunctionCallback(ThreadContext* ctx) throw()  = 0;
	virtual ISystemLog* getLogger(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_FUNCTIONS_IALINOUSSYSTEM_H_ */
