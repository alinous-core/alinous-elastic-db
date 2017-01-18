#ifndef ALINOUS_DB_TABLE_DATATABLESTORAGESUPPORT_H_
#define ALINOUS_DB_TABLE_DATATABLESTORAGESUPPORT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class BTreeLeafNode;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace db {namespace table {namespace cache {
class RecordCacheEngine;}}}}

namespace alinous {namespace db {namespace table {
class AbstractDatabaseTable;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeLeafNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongValue;
using ::alinous::db::table::cache::RecordCacheEngine;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class DataTableStorageSupport : public AbstractDatabaseTable {
public:
	DataTableStorageSupport(const DataTableStorageSupport& base) = default;
public:
	DataTableStorageSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	virtual ~DataTableStorageSupport() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	RecordCacheEngine* cacheEngine;
public:
	IDatabaseRecord* loadRecord(long long filePointer, ThreadContext* ctx) final;
	bool hasLaterVersionBefore(long long oid, long long commitId, long long currentCommitId, ThreadContext* ctx) final;
	bool hasLaterVersion(long long oid, long long commitId, ThreadContext* ctx) final;
	bool isDeleted(long long oid, ThreadContext* ctx);
	bool isLatest(long long oid, long long commitId, ThreadContext* ctx);
	DatabaseRecord* getLastRecord(long long oid, long long commitId, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATATABLESTORAGESUPPORT_H_ */
