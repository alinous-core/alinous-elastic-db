#ifndef ALINOUS_REMOTE_REGION_NODECLUSTER_H_
#define ALINOUS_REMOTE_REGION_NODECLUSTER_H_
namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace monitor {
class NodeInfo;}}}

namespace alinous {namespace remote {namespace region {
class NodeReference;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::remote::monitor::NodeInfo;
using ::alinous::remote::monitor::RegionNodeInfo;



class NodeCluster final : public virtual IObject {
public:
	NodeCluster(const NodeCluster& base) = default;
public:
	NodeCluster(ThreadContext* ctx) throw()  : IObject(ctx), nodes(GCUtils<List<NodeReference> >::ins(this, (new(ctx) ArrayList<NodeReference>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeCluster() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<NodeReference>* nodes;
public:
	void update(RegionNodeInfo* refinfo, ThreadContext* ctx) throw() ;
	void addNode(NodeReference* nodeRef, ThreadContext* ctx) throw() ;
	List<NodeReference>* getNodes(ThreadContext* ctx) throw() ;
private:
	NodeReference* getNode(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODECLUSTER_H_ */
