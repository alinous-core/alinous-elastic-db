#ifndef ALINOUS_REMOTE_MONITOR_REGIONNODEINFO_H_
#define ALINOUS_REMOTE_MONITOR_REGIONNODEINFO_H_
namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Region;}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {namespace remote {
class NodeRef;}}}}

namespace alinous {namespace remote {namespace monitor {
class NodeInfo;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::db::AlinousDbException;
using ::alinous::system::config::remote::NodeRef;
using ::alinous::system::config::remote::Region;



class RegionNodeInfo final : public virtual IObject {
public:
	RegionNodeInfo(const RegionNodeInfo& base) = default;
public:
	RegionNodeInfo(ThreadContext* ctx) throw()  : IObject(ctx), name(nullptr), nodes(GCUtils<List<NodeInfo> >::ins(this, (new(ctx) ArrayList<NodeInfo>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RegionNodeInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	List<NodeInfo>* nodes;
public:
	void addNode(NodeInfo* node, ThreadContext* ctx) throw() ;
	List<NodeInfo>* getNodes(ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
public:
	static RegionNodeInfo* fromConfig(Region* reg, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_REGIONNODEINFO_H_ */
