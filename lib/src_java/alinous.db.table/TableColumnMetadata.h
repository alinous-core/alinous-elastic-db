#ifndef ALINOUS_DB_TABLE_TABLECOLUMNMETADATA_H_
#define ALINOUS_DB_TABLE_TABLECOLUMNMETADATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class CheckDefinition;}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ColumnTypeDescriptor;}}}}

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
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::sql::ddl::CheckDefinition;
using ::alinous::compile::sql::ddl::ColumnTypeDescriptor;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class TableColumnMetadata final : public ICommandData, public virtual IObject {
public:
	TableColumnMetadata(const TableColumnMetadata& base) = default;
public:
	TableColumnMetadata(String* name, int type, int length, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, int type, int length, ThreadContext* ctx) throw() ;
	TableColumnMetadata(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), notnull(0), unique(0), primaryKey(0), defaultValue(nullptr), columnOrder(0), type(0), length(0), check(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableColumnMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* name;
	bool notnull;
	bool unique;
	bool primaryKey;
	String* defaultValue;
	int columnOrder;
private:
	int type;
	int length;
	CheckDefinition* check;
public:
	int fileSize(ThreadContext* ctx);
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() ;
	CheckDefinition* getCheck(ThreadContext* ctx) throw() ;
	void setCheck(CheckDefinition* check, ThreadContext* ctx) throw() ;
	bool isPrimaryKey(ThreadContext* ctx) throw() ;
	void setPrimaryKey(bool primaryKey, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	int getType(ThreadContext* ctx) throw() ;
	bool isUnique(ThreadContext* ctx) throw() ;
	void setUnique(bool unique, ThreadContext* ctx) throw() ;
public:
	static TableColumnMetadata* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
	static TableColumnMetadata* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLECOLUMNMETADATA_H_ */
