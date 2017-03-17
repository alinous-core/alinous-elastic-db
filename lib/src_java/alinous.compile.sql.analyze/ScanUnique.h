#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace db {namespace table {
class TableMetadataUnique;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableMetadataUnique;
using ::alinous::db::table::TablePartitionKey;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class ScanUnique final : public TableMetadataUnique {
public:
	ScanUnique(const ScanUnique& base) = default;
public:
	ScanUnique(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ScanUnique() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TablePartitionKey* coveredKey;
	int matchLength;
	String* tableFullName;
public:
	List<VariantValue>* makeValues(IDatabaseRecord* record, ThreadContext* ctx) throw() ;
	int fileSize(ThreadContext* ctx) final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	TablePartitionKey* getCoveredKey(ThreadContext* ctx) throw() ;
	void setCoveredKey(TablePartitionKey* coveredKey, ThreadContext* ctx) throw() ;
	bool isCovered(ThreadContext* ctx) throw() ;
	int getMatchLength(ThreadContext* ctx) throw() ;
	bool calcCoverage(TablePartitionKey* key, ThreadContext* ctx) throw() ;
	String* getTableFullName(ThreadContext* ctx) throw() ;
	void setTableFullName(String* tableFullName, ThreadContext* ctx) throw() ;
public:
	static ScanUnique* loadScannerFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static ScanUnique* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_ */
