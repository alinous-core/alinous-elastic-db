#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_DELETESTORE_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_DELETESTORE_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class DeleteStore;}}}}}

namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace btree {
class IBTree;}}

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
using ::alinous::btree::IBTree;
using ::alinous::btreememory::BTreeOnMemory;



class DeleteStore final : public virtual IObject {
public:
	DeleteStore(const DeleteStore& base) = default;
public:
	DeleteStore(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DeleteStore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* store;
public:
	DeleteStore* init(ThreadContext* ctx) throw() ;
	IBTree* getStore(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_DELETESTORE_H_ */
