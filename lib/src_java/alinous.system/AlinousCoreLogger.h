#ifndef ALINOUS_SYSTEM_ALINOUSCORELOGGER_H_
#define ALINOUS_SYSTEM_ALINOUSCORELOGGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace system {
class ISystemLog;}}

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



class AlinousCoreLogger final : public ISystemLog, public virtual IObject {
public:
	AlinousCoreLogger(const AlinousCoreLogger& base) = default;
public:
	AlinousCoreLogger(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AlinousCoreLogger() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void logError(Throwable* e, ThreadContext* ctx) throw()  final;
	void logWarning(String* message, ThreadContext* ctx) throw()  final;
	void logInfo(String* message, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_SYSTEM_ALINOUSCORELOGGER_H_ */
