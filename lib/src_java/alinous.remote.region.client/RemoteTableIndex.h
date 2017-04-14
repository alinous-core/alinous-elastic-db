#ifndef ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLEINDEX_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLEINDEX_H_
namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

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
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class RemoteTableIndex final : public IScannableIndex, public virtual IObject {
public:
	RemoteTableIndex(const RemoteTableIndex& base) = default;
public:
	RemoteTableIndex(String* name, ArrayList<TableColumnMetadata>* keys, bool primary, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ArrayList<TableColumnMetadata>* keys, bool primary, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() ;
	virtual ~RemoteTableIndex() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	bool primary;
	ArrayList<TableColumnMetadata>* keys;
public:
	ArrayList<TableColumnMetadata>* getColumns(ThreadContext* ctx) throw()  final;
	BTree* getStorage(ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw()  final;
	bool isPrimary(ThreadContext* ctx) throw()  final;
	void addIndexValue(IDatabaseRecord* record, ThreadContext* ctx) final;
	void createIndex(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	bool isAvailableByScanId(ArrayList<ScanTableColumnIdentifier>* columnIds, ThreadContext* ctx) throw()  final;
	bool isAvailable(ArrayList<String>* columnsStr, ThreadContext* ctx) throw()  final;
	bool isOpened(ThreadContext* ctx) throw()  final;
	void open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void close(ThreadContext* ctx) final;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int archiveSize(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLEINDEX_H_ */
