#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODECLUSTER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODECLUSTER_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class RequestSyncOidCommand;}}}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace monitor {
class NodeInfo;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::remote::db::client::command::RequestSyncOidCommand;
using ::alinous::remote::db::client::command::data::SchemasStructureInfoData;
using ::alinous::remote::monitor::NodeInfo;
using ::alinous::remote::monitor::RegionNodeInfo;
using ::alinous::system::AlinousException;



class NodeCluster final : public virtual IObject {
public:
	NodeCluster(const NodeCluster& base) = default;
public:
	NodeCluster(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~NodeCluster() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<NodeReference>* nodes;
public:
	void requestSyncMaxOid(ThreadContext* ctx);
	SchemasStructureInfoData* getSchemeInfo(String* region, ThreadContext* ctx);
	void update(RegionNodeInfo* refinfo, ThreadContext* ctx) throw() ;
	NodeReference* getNode(String* host, int port, bool ipv6, ThreadContext* ctx) throw() ;
	void addNode(NodeReference* nodeRef, ThreadContext* ctx) throw() ;
	List<NodeReference>* getNodes(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
private:
	void sendOidRequestCommand(NodeReference* ref, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODECLUSTER_H_ */
