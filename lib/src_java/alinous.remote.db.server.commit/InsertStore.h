#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class InsertStore;}}}}}

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



class InsertStore final : public virtual IObject {
public:
	InsertStore(const InsertStore& base) = default;
public:
	InsertStore(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~InsertStore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* store;
public:
	InsertStore* init(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_ */
