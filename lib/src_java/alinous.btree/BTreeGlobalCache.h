#ifndef ALINOUS_BTREE_BTREEGLOBALCACHE_H_
#define ALINOUS_BTREE_BTREEGLOBALCACHE_H_
namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace buffer {
class HashArrayList;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoList;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace btree {
class BTreeCacheRecord;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::FifoElement;
using ::alinous::buffer::FifoList;
using ::alinous::buffer::HashArrayList;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::lock::LockObject;



class BTreeGlobalCache final : public virtual IObject {
public:
	BTreeGlobalCache(const BTreeGlobalCache& base) = default;
public:
	BTreeGlobalCache(ThreadContext* ctx) throw()  : IObject(ctx), maxCache(0), cache(nullptr), fifo(nullptr), fifoDeletable(nullptr), tmp(nullptr), sync(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~BTreeGlobalCache() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int maxCache;
	HashArrayList* cache;
	FifoList<IBTreeNode>* fifo;
	FifoList<IBTreeNode>* fifoDeletable;
	BTreeCacheRecord* tmp;
	LockObject* sync;
public:
	BTreeGlobalCache* init(int maxCache, ThreadContext* ctx);
	IBTreeNode* search(FileStorage* storage, long long filePointer, ThreadContext* ctx) throw() ;
	void addCache(FifoElement<IBTreeNode>* fifoElement, FileStorage* storage, ThreadContext* ctx);
	void moveToUsing(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void moveToDeletable(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREEGLOBALCACHE_H_ */
