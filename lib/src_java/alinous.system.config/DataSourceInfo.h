#ifndef ALINOUS_SYSTEM_CONFIG_DATASOURCEINFO_H_
#define ALINOUS_SYSTEM_CONFIG_DATASOURCEINFO_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

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
using ::alinous::runtime::dbif::IDatabaseDriver;



class DataSourceInfo final : public IAlinousConfigElement, public virtual IObject {
public:
	DataSourceInfo(const DataSourceInfo& base) = default;
public:
	DataSourceInfo(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), connect(nullptr), user(nullptr), pass(nullptr), defaultAcid(IDatabaseDriver::READ_COMMITTED)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DataSourceInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* connect;
	String* user;
	String* pass;
	int defaultAcid;
public:
	String* getConnect(ThreadContext* ctx) throw() ;
	void setConnect(String* connect, ThreadContext* ctx) throw() ;
	String* getUser(ThreadContext* ctx) throw() ;
	void setUser(String* user, ThreadContext* ctx) throw() ;
	String* getPass(ThreadContext* ctx) throw() ;
	void setPass(String* pass, ThreadContext* ctx) throw() ;
	int getDefaultAcid(ThreadContext* ctx) throw() ;
	void setDefaultAcid(int defaultAcid, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_DATASOURCEINFO_H_ */
