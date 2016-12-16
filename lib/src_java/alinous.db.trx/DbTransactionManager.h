#ifndef ALINOUS_DB_TRX_DBTRANSACTIONMANAGER_H_
#define ALINOUS_DB_TRX_DBTRANSACTIONMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace db {namespace trx {
class ReadCommittedTransaction;}}}

namespace alinous {namespace db {namespace trx {
class RepeatableReadTransaction;}}}

namespace alinous {namespace db {namespace trx {
class SerializableTransaction;}}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace alinous {namespace system {namespace utils {
class FileUtils;}}}

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
using ::java::io::File;
using ::java::util::ArrayList;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dbif::IDatabaseDriver;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::utils::FileUtils;



class DbTransactionManager final : public virtual IObject {
public:
	DbTransactionManager(const DbTransactionManager& base) = default;
public:
	DbTransactionManager(AlinousDatabase* database, String* trxTmpDir, int maxConnection, AlinousCore* core, ThreadPool* workerThreadsPool, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousDatabase* database, String* trxTmpDir, int maxConnection, AlinousCore* core, ThreadPool* workerThreadsPool, ThreadContext* ctx) throw() ;
	virtual ~DbTransactionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* trxTmpDir;
	int maxConnection;
	int trxCount;
	AlinousDatabase* database;
	LockObject* lock;
	AlinousCore* core;
	ArrayList<DbTransaction>* trxReady;
	ThreadPool* workerThreadsPool;
public:
	DbTransaction* borrowTransaction(int acid, ThreadContext* ctx);
	void returnTransaction(DbTransaction* trx, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	ThreadPool* getWorkerThreadsPool(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TRX_DBTRANSACTIONMANAGER_H_ */
