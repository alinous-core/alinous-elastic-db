#ifndef ALINOUS_REMOTE_REGION_SERVER_TPC_REGIONINSERTEXECUTOR_H_
#define ALINOUS_REMOTE_REGION_SERVER_TPC_REGIONINSERTEXECUTOR_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReferenceManager;}}}}}

namespace java {namespace lang {
class Long;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionPartitionTableAccess;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class InsertTableStrategy;}}}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {
class InsertPrepareCommand;}}}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

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
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::db::client::command::dml::InsertPrepareCommand;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::server::schema::NodeReferenceManager;
using ::alinous::remote::region::server::schema::strategy::InsertTableStrategy;
using ::alinous::remote::region::server::schema::strategy::RegionPartitionTableAccess;



class RegionInsertExecutor final : public virtual IObject {
public:
	RegionInsertExecutor(const RegionInsertExecutor& base) = default;
public:
	RegionInsertExecutor(long long trxId, long long commitId, NodeReferenceManager* ref, ThreadContext* ctx) throw() ;
	void __construct_impl(long long trxId, long long commitId, NodeReferenceManager* ref, ThreadContext* ctx) throw() ;
	virtual ~RegionInsertExecutor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	NodeReferenceManager* ref;
	Long* trxId;
	long long commitId;
	InsertTableStrategy* strategy;
public:
	void prepareInsert(ArrayList<ClientNetworkRecord>* list, String* schema, String* table, ThreadContext* ctx);
	void tpcCommitInsert(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	Long* getTrxId(ThreadContext* ctx) throw() ;
private:
	void sendPrepareCommand(InsertPrepareCommand* cmd, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_TPC_REGIONINSERTEXECUTOR_H_ */
