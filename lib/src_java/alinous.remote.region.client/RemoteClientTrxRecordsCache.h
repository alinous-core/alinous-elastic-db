#ifndef ALINOUS_REMOTE_REGION_CLIENT_REMOTECLIENTTRXRECORDSCACHE_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REMOTECLIENTTRXRECORDSCACHE_H_
namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::cache::CachedRecord;
using ::alinous::db::trx::cache::TrxRecordsCache;
using ::alinous::system::AlinousException;



class RemoteClientTrxRecordsCache final : public TrxRecordsCache {
public:
	RemoteClientTrxRecordsCache(const RemoteClientTrxRecordsCache& base) = default;
public:
	RemoteClientTrxRecordsCache(ThreadContext* ctx) throw()  : IObject(ctx), TrxRecordsCache(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RemoteClientTrxRecordsCache() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void commitInsertRecord(DbTransaction* trx, AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REMOTECLIENTTRXRECORDSCACHE_H_ */
