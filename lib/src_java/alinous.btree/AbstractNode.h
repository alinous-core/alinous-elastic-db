#ifndef ALINOUS_BTREE_ABSTRACTNODE_H_
#define ALINOUS_BTREE_ABSTRACTNODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

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
using ::alinous::buffer::storage::FileStorage;
using ::alinous::lock::LockObject;



class AbstractNode : public IBTreeNode, public virtual IObject {
public:
	AbstractNode(const AbstractNode& base) = default;
public:
	AbstractNode(LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void __construct_impl(LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	virtual ~AbstractNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	LockObject* sync;
	FifoElement<IBTreeNode>* fifoElement;
	BTreeNodeLoader* loader;
private:
	long long filePointer;
	int useGCRefCount;
	FileStorage* storage;
public:
	int compareTo(IBTreeNode* another, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	long long getFilePointer(ThreadContext* ctx) throw()  final;
	void setFilePointer(long long position, ThreadContext* ctx) throw()  final;
	void use(ThreadContext* ctx) final;
	void incCount(ThreadContext* ctx) throw()  final;
	virtual void endUse(ThreadContext* ctx);
	void doEndUseWithoutLock(ThreadContext* ctx) throw() ;
	bool isDeletable(ThreadContext* ctx) throw()  final;
	long long getHashKey(ThreadContext* ctx) throw()  final;
	int getUseGCRefCount(ThreadContext* ctx) throw()  final;
	void printTab(StringBuffer* buff, int level, ThreadContext* ctx) throw() ;
	FileStorage* getStorage(ThreadContext* ctx) throw()  final;
	void setStorage(FileStorage* storage, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (IBTreeNode* _this, IBTreeNode* another, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_BTREE_ABSTRACTNODE_H_ */
