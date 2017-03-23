#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_UPDATESTORE_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_UPDATESTORE_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class UpdateStore;}}}}}

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



class UpdateStore final : public virtual IObject {
public:
	UpdateStore(const UpdateStore& base) = default;
public:
	UpdateStore(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~UpdateStore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* store;
public:
	UpdateStore* init(ThreadContext* ctx) throw() ;
	IBTree* getStore(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_UPDATESTORE_H_ */
