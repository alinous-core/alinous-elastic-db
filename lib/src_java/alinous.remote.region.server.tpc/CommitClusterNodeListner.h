#ifndef ALINOUS_REMOTE_REGION_SERVER_TPC_COMMITCLUSTERNODELISTNER_H_
#define ALINOUS_REMOTE_REGION_SERVER_TPC_COMMITCLUSTERNODELISTNER_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {
class CommitDMLCommand;}}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::db::client::command::dml::CommitDMLCommand;
using ::alinous::remote::region::server::schema::NodeReference;
using ::alinous::system::AlinousException;



class CommitClusterNodeListner final : public virtual IObject {
public:
	CommitClusterNodeListner(const CommitClusterNodeListner& base) = default;
public:
	CommitClusterNodeListner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CommitClusterNodeListner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,NodeReference>* nodeRefs;
public:
	void addNode(NodeReference* ref, ThreadContext* ctx) throw() ;
	void sendCommit(long long newCommitId, DbVersionContext* vctx, ThreadContext* ctx);
private:
	void sendCommitCommand(long long newCommitId, DbVersionContext* vctx, NodeReference* ref, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_TPC_COMMITCLUSTERNODELISTNER_H_ */
