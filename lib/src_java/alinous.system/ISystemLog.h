#ifndef ALINOUS_SYSTEM_ISYSTEMLOG_H_
#define ALINOUS_SYSTEM_ISYSTEMLOG_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Throwable;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class ISystemLog : public virtual IObject {
public:
	ISystemLog(const ISystemLog& base) = default;
public:
	ISystemLog(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ISystemLog() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void logError(Throwable* e, ThreadContext* ctx) throw()  = 0;
	virtual void logWarning(String* message, ThreadContext* ctx) throw()  = 0;
	virtual void logInfo(String* message, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_SYSTEM_ISYSTEMLOG_H_ */
