#ifndef ALINOUS_DB_TABLE_ISCANNABLEINDEX_H_
#define ALINOUS_DB_TABLE_ISCANNABLEINDEX_H_
namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousCore;



class IScannableIndex : public virtual IObject {
public:
	IScannableIndex(const IScannableIndex& base) = default;
public:
	IScannableIndex(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IScannableIndex() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual ArrayList<TableColumnMetadata>* getColumns(ThreadContext* ctx) throw()  = 0;
	virtual BTree* getStorage(ThreadContext* ctx) throw()  = 0;
	virtual String* getName(ThreadContext* ctx) throw()  = 0;
	virtual bool isPrimary(ThreadContext* ctx) throw()  = 0;
	virtual void addIndexValue(DatabaseRecord* record, ThreadContext* ctx) = 0;
	virtual void createIndex(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) = 0;
	virtual bool isAvailableByScanId(ArrayList<ScanTableColumnIdentifier>* columnIds, ThreadContext* ctx) throw()  = 0;
	virtual bool isAvailable(ArrayList<String>* columnsStr, ThreadContext* ctx) throw()  = 0;
	virtual bool isOpened(ThreadContext* ctx) throw()  = 0;
	virtual void open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) = 0;
	virtual void close(ThreadContext* ctx) = 0;
	virtual void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) = 0;
	virtual int archiveSize(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_ISCANNABLEINDEX_H_ */
