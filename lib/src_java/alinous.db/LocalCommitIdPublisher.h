#ifndef ALINOUS_DB_LOCALCOMMITIDPUBLISHER_H_
#define ALINOUS_DB_LOCALCOMMITIDPUBLISHER_H_
namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace db {
class ICommidIdPublisher;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::LockObject;



class LocalCommitIdPublisher final : public ICommidIdPublisher, public virtual IObject {
public:
	LocalCommitIdPublisher(const LocalCommitIdPublisher& base) = default;
public:
	LocalCommitIdPublisher(AlinousDatabase* database, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousDatabase* database, ThreadContext* ctx) throw() ;
	virtual ~LocalCommitIdPublisher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long maxCommitId;
	LockObject* lock;
	AlinousDatabase* database;
	long long trxId;
public:
	void setMaxCommitId(long long maxCommitId, ThreadContext* ctx) throw()  final;
	long long getMaxCommitId(ThreadContext* ctx) throw()  final;
	long long newCommitId(ThreadContext* ctx) final;
	DbVersionContext* newTransactionContext(ThreadContext* ctx) throw()  final;
	void dispose(ThreadContext* ctx) throw()  final;
private:
	long long getNextTrxId(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_LOCALCOMMITIDPUBLISHER_H_ */
