#ifndef ALINOUS_DB_TABLE_TABLEMETADATAUNIQUE_H_
#define ALINOUS_DB_TABLE_TABLEMETADATAUNIQUE_H_
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TableMetadataUnique;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

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

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class TableMetadataUnique : public ICommandData, public virtual IObject {
public:
	TableMetadataUnique(const TableMetadataUnique& base) = default;
public:
	TableMetadataUnique(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableMetadataUnique() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<TableColumnMetadata>* uniqueColList;
public:
	ScanUnique* toScanUnique(String* tableFullName, ThreadContext* ctx) throw() ;
	void addUnique(TableColumnMetadata* col, ThreadContext* ctx) throw() ;
	List<TableColumnMetadata>* getUniqueColList(ThreadContext* ctx) throw() ;
	virtual int fileSize(ThreadContext* ctx);
	virtual void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	virtual void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	virtual void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static TableMetadataUnique* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
	static TableMetadataUnique* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEMETADATAUNIQUE_H_ */
