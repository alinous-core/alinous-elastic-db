#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_TABLEFULLNAMEKEY_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_TABLEFULLNAMEKEY_H_
namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class TableFullNameKey;}}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::btree::IBTreeKey;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::runtime::dom::VariableException;



class TableFullNameKey final : public IBTreeKey, public virtual IObject {
public:
	TableFullNameKey(const TableFullNameKey& base) = default;
public:
	TableFullNameKey(String* schema, String* table, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* table, ThreadContext* ctx) throw() ;
	virtual ~TableFullNameKey() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* schema;
	String* table;
public:
	int compareTo(IBTreeKey* another, ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int size(ThreadContext* ctx) final;
	String* getSchema(ThreadContext* ctx) throw() ;
	String* getTable(ThreadContext* ctx) throw() ;
public:
	static IBTreeKey* fetchFromEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw();
	};
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_TABLEFULLNAMEKEY_H_ */
