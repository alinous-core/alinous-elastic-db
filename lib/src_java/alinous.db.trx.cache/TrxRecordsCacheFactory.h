#ifndef ALINOUS_DB_TRX_CACHE_TRXRECORDSCACHEFACTORY_H_
#define ALINOUS_DB_TRX_CACHE_TRXRECORDSCACHEFACTORY_H_
namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace remote {namespace region {namespace client {
class RemoteClientTrxRecordsCache;}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace cache {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::DbTransaction;
using ::alinous::remote::region::client::RemoteClientTrxRecordsCache;



class TrxRecordsCacheFactory final : public virtual IObject {
public:
	TrxRecordsCacheFactory(const TrxRecordsCacheFactory& base) = default;
public:
	TrxRecordsCacheFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TrxRecordsCacheFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static TrxRecordsCache* createCache(String* tmpDir, String* schema, String* tableName, TableMetadata* metadata, DbTransaction* trx, bool insert, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_TRXRECORDSCACHEFACTORY_H_ */
