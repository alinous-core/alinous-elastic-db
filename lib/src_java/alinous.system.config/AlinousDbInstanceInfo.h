#ifndef ALINOUS_SYSTEM_CONFIG_ALINOUSDBINSTANCEINFO_H_
#define ALINOUS_SYSTEM_CONFIG_ALINOUSDBINSTANCEINFO_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {namespace config {namespace remote {
class RegionsRef;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Regions;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Nodes;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Monitor;}}}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

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
using ::alinous::system::config::remote::Monitor;
using ::alinous::system::config::remote::Nodes;
using ::alinous::system::config::remote::Regions;
using ::alinous::system::config::remote::RegionsRef;



class AlinousDbInstanceInfo final : public IAlinousConfigElement, public virtual IObject {
public:
	AlinousDbInstanceInfo(const AlinousDbInstanceInfo& base) = default;
public:
	AlinousDbInstanceInfo(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), id(nullptr), dataDir(nullptr), trxTmpDir(nullptr), maxConnections(16), regionsRef(nullptr), regions(nullptr), nodes(nullptr), monitor(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousDbInstanceInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* id;
	String* dataDir;
	String* trxTmpDir;
	int maxConnections;
	RegionsRef* regionsRef;
	Regions* regions;
	Nodes* nodes;
	Monitor* monitor;
public:
	String* getId(ThreadContext* ctx) throw() ;
	void setId(String* id, ThreadContext* ctx) throw() ;
	String* getDataDir(ThreadContext* ctx) throw() ;
	void setDataDir(String* dataDir, ThreadContext* ctx) throw() ;
	String* getTrxTmpDir(ThreadContext* ctx) throw() ;
	void setTrxTmpDir(String* trxTmpDir, ThreadContext* ctx) throw() ;
	int getMaxConnections(ThreadContext* ctx) throw() ;
	void setMaxConnections(int maxConnections, ThreadContext* ctx) throw() ;
	RegionsRef* getRegionsRef(ThreadContext* ctx) throw() ;
	void setRegionsRef(RegionsRef* regionsRef, ThreadContext* ctx) throw() ;
	Regions* getRegions(ThreadContext* ctx) throw() ;
	void setRegions(Regions* regions, ThreadContext* ctx) throw() ;
	Nodes* getNodes(ThreadContext* ctx) throw() ;
	void setNodes(Nodes* nodes, ThreadContext* ctx) throw() ;
	Monitor* getMonitor(ThreadContext* ctx) throw() ;
	void setMonitor(Monitor* monitor, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_ALINOUSDBINSTANCEINFO_H_ */
