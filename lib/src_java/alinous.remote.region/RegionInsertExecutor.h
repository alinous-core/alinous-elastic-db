#ifndef ALINOUS_REMOTE_REGION_REGIONINSERTEXECUTOR_H_
#define ALINOUS_REMOTE_REGION_REGIONINSERTEXECUTOR_H_
namespace alinous {namespace remote {namespace region {
class NodeReferenceManager;}}}

namespace java {namespace lang {
class Long;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace remote {namespace region {
class RegionShardTable;}}}

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
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;



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
public:
	void prepareInsert(ArrayList<ClientNetworkRecord>* list, String* schema, String* table, ThreadContext* ctx) throw() ;
	void tpcCommitInsert(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	Long* getTrxId(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_REGIONINSERTEXECUTOR_H_ */
