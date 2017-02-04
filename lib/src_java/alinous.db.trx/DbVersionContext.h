#ifndef ALINOUS_DB_TRX_DBVERSIONCONTEXT_H_
#define ALINOUS_DB_TRX_DBVERSIONCONTEXT_H_
namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class DbVersionContext final : public ICommandData, public virtual IObject {
public:
	DbVersionContext(const DbVersionContext& base) = default;
public:
	DbVersionContext(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), commitId(0), trxId(0), schemaVersion(0), nodeClusterVersion(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DbVersionContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long commitId;
	long long trxId;
	long long schemaVersion;
	long long nodeClusterVersion;
public:
	long long getCommitId(ThreadContext* ctx) throw() ;
	void setCommitId(long long commitId, ThreadContext* ctx) throw() ;
	long long getSchemaVersion(ThreadContext* ctx) throw() ;
	void setSchemaVersion(long long schemaVersion, ThreadContext* ctx) throw() ;
	long long getNodeClusterVersion(ThreadContext* ctx) throw() ;
	void setNodeClusterVersion(long long nodeClusterVersion, ThreadContext* ctx) throw() ;
	long long getTrxId(ThreadContext* ctx) throw() ;
	void setTrxId(long long trxId, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TRX_DBVERSIONCONTEXT_H_ */
