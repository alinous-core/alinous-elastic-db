#ifndef ALINOUS_SYSTEM_CONFIG_SYSTEMINFO_H_
#define ALINOUS_SYSTEM_CONFIG_SYSTEMINFO_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class SystemInfo final : public virtual IObject {
public:
	SystemInfo(const SystemInfo& base) = default;
public:
	SystemInfo(String* alinousHome, ThreadContext* ctx) throw() ;
	void __construct_impl(String* alinousHome, ThreadContext* ctx) throw() ;
	virtual ~SystemInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* moduleDir;
	String* systemDatastore;
	String* defaultDatastore;
	String* alinousHome;
public:
	String* getModuleDir(ThreadContext* ctx) throw() ;
	void setModuleDir(String* moduleDir, ThreadContext* ctx) throw() ;
	String* getSystemDatastore(ThreadContext* ctx) throw() ;
	void setSystemDatastore(String* systemDatastore, ThreadContext* ctx) throw() ;
	String* getDefaultDatastore(ThreadContext* ctx) throw() ;
	void setDefaultDatastore(String* defaultDatastore, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_SYSTEMINFO_H_ */
