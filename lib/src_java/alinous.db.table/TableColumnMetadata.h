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



class TableColumnMetadata final : public virtual IObject {
public:
	TableColumnMetadata(const TableColumnMetadata& base) = default;
public:
	TableColumnMetadata(String* name, int type, int length, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, int type, int length, ThreadContext* ctx) throw() ;
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
	int fileSize(ThreadContext* ctx) throw() ;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() ;
	CheckDefinition* getCheck(ThreadContext* ctx) throw() ;
	void setCheck(CheckDefinition* check, ThreadContext* ctx) throw() ;
	bool isPrimaryKey(ThreadContext* ctx) throw() ;
	void setPrimaryKey(bool primaryKey, ThreadContext* ctx) throw() ;
public:
	static TableColumnMetadata* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLECOLUMNMETADATA_H_ */
