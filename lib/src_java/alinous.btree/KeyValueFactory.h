#ifndef ALINOUS_BTREE_KEYVALUEFACTORY_H_
#define ALINOUS_BTREE_KEYVALUEFACTORY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTreeValues;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class IntValue;}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace btree {
class StringValue;}}

namespace alinous {namespace btree {
class TimestampValue;}}

namespace alinous {namespace btree {
class DoubleValue;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class IntKey;}}

namespace alinous {namespace btree {
class LongKey;}}

namespace alinous {namespace btree {
class StringKey;}}

namespace alinous {namespace btree {
class DoubleKey;}}

namespace alinous {namespace btree {
class TimestampKey;}}

namespace alinous {namespace db {
class SchemaManager;}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class TableIndexValue;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::AlinousDbException;
using ::alinous::db::SchemaManager;
using ::alinous::db::table::BTreeIndexKey;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::db::table::TableIndexValue;
using ::alinous::db::trx::cache::CachedRecord;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::VariableException;



class KeyValueFactory final : public virtual IObject {
public:
	KeyValueFactory(const KeyValueFactory& base) = default;
public:
	KeyValueFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~KeyValueFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static BTreeValues* valuesFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static IBTreeValue* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static IBTreeKey* keyFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_KEYVALUEFACTORY_H_ */
