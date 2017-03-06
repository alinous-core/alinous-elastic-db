#ifndef ALINOUS_COMPILE_SQL_TABLEANDSCHEMA_H_
#define ALINOUS_COMPILE_SQL_TABLEANDSCHEMA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::runtime::dom::VariableException;



class TableAndSchema final : public virtual IObject {
public:
	TableAndSchema(const TableAndSchema& base) = default;
public:
	TableAndSchema(String* schema, String* table, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* table, ThreadContext* ctx) throw() ;
	virtual ~TableAndSchema() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* table;
	String* schema;
	String* toStr;
public:
	String* getTable(ThreadContext* ctx) throw() ;
	void setTable(String* table, ThreadContext* ctx) throw() ;
	String* getSchema(ThreadContext* ctx) throw() ;
	void setSchema(String* schema, ThreadContext* ctx) throw() ;
	TableAndSchema* copy(ThreadContext* ctx) throw() ;
	int getArchiveSize(ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static TableAndSchema* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_SQL_TABLEANDSCHEMA_H_ */
