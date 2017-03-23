#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class InsertStore;}}}}}

namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace btree {
class StringKey;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class IBTree;}}

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
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::StringKey;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class InsertStore final : public virtual IObject {
public:
	InsertStore(const InsertStore& base) = default;
public:
	InsertStore(String* filePath, ThreadContext* ctx) throw() ;
	void __construct_impl(String* filePath, ThreadContext* ctx) throw() ;
	virtual ~InsertStore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* store;
	String* baseDir;
public:
	InsertStore* init(ThreadContext* ctx) throw() ;
	void add(IDatabaseTable* table, List<ClientNetworkRecord>* records, ThreadContext* ctx);
	IBTree* getStore(ThreadContext* ctx) throw() ;
	String* getBaseDir(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_ */
