#ifndef ALINOUS_DB_TABLE_TABLEINDEXMETADATA_H_
#define ALINOUS_DB_TABLE_TABLEINDEXMETADATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TableIndexMetadata;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

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
using ::java::util::ArrayList;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class TableIndexMetadata final : public ICommandData, public virtual IObject {
public:
	TableIndexMetadata(const TableIndexMetadata& base) = default;
public:
	TableIndexMetadata(String* name, ArrayList<String>* columns, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ArrayList<String>* columns, ThreadContext* ctx) throw() ;
	virtual ~TableIndexMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	ArrayList<String>* columns;
	ArrayList<TableColumnMetadata>* metadata;
public:
	void setupColumnMetadata(TableMetadata* meta, ThreadContext* ctx);
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	int fileSize(ThreadContext* ctx) throw() ;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	ArrayList<String>* getColumns(ThreadContext* ctx) throw() ;
	void setColumns(ArrayList<String>* columns, ThreadContext* ctx) throw() ;
	ArrayList<TableColumnMetadata>* getMetadata(ThreadContext* ctx) throw() ;
public:
	static TableIndexMetadata* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEINDEXMETADATA_H_ */
