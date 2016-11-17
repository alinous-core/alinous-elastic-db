#ifndef ALINOUS_SYSTEM_CONFIG_ALINOUSDBINSTANCEINFO_H_
#define ALINOUS_SYSTEM_CONFIG_ALINOUSDBINSTANCEINFO_H_
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



class AlinousDbInstanceInfo final : public virtual IObject {
public:
	AlinousDbInstanceInfo(const AlinousDbInstanceInfo& base) = default;
public:
	AlinousDbInstanceInfo(ThreadContext* ctx) throw()  : IObject(ctx), id(nullptr), dataDir(nullptr), trxTmpDir(nullptr), maxConnections(16)
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
public:
	String* getId(ThreadContext* ctx) throw() ;
	void setId(String* id, ThreadContext* ctx) throw() ;
	String* getDataDir(ThreadContext* ctx) throw() ;
	void setDataDir(String* dataDir, ThreadContext* ctx) throw() ;
	String* getTrxTmpDir(ThreadContext* ctx) throw() ;
	void setTrxTmpDir(String* trxTmpDir, ThreadContext* ctx) throw() ;
	int getMaxConnections(ThreadContext* ctx) throw() ;
	void setMaxConnections(int maxConnections, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_ALINOUSDBINSTANCEINFO_H_ */
