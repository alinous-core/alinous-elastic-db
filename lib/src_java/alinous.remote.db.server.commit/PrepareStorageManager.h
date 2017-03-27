#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_PREPARESTORAGEMANAGER_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_PREPARESTORAGEMANAGER_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class PrepareStorageManager;}}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class InsertStore;}}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

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

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class PrepareStorageManager final : public virtual IObject {
public:
	PrepareStorageManager(const PrepareStorageManager& base) = default;
public:
	PrepareStorageManager(String* tmpDir, long long strxId, ThreadContext* ctx) throw() ;
	void __construct_impl(String* tmpDir, long long strxId, ThreadContext* ctx) throw() ;
	virtual ~PrepareStorageManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* tmpDir;
	long long strxId;
	String* filePath;
	InsertStore* insertStore;
public:
	PrepareStorageManager* init(ThreadContext* ctx) throw() ;
	void addInsert(IDatabaseTable* table, List<ClientNetworkRecord>* records, ThreadContext* ctx);
	String* getFilePath(ThreadContext* ctx) throw() ;
	InsertStore* getInsertStore(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_PREPARESTORAGEMANAGER_H_ */
