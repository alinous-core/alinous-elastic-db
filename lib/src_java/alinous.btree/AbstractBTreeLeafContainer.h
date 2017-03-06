#ifndef ALINOUS_BTREE_ABSTRACTBTREELEAFCONTAINER_H_
#define ALINOUS_BTREE_ABSTRACTBTREELEAFCONTAINER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class NodeRef;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class BTreeNodeHandler;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeLeafContainer;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace alinous {namespace btree {namespace scan {
class LeafContainerIterator;}}}

namespace alinous {namespace btree {
class AbstractNode;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::btree::scan::LeafContainerIterator;
using ::alinous::buffer::FifoElement;
using ::alinous::lock::LockObject;
using ::alinous::system::AlinousException;



class AbstractBTreeLeafContainer : public AbstractNode {
public:
	AbstractBTreeLeafContainer(const AbstractBTreeLeafContainer& base) = default;
public:
	AbstractBTreeLeafContainer(int numNodes, IArrayObject<NodeRef>* nodes, BTreeNodeLoader* loader, LockObject* sync, int BLOCK_SIZE, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void __construct_impl(int numNodes, IArrayObject<NodeRef>* nodes, BTreeNodeLoader* loader, LockObject* sync, int BLOCK_SIZE, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	virtual ~AbstractBTreeLeafContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int length;
	IArrayObject<NodeRef>* nodes;
	int nodeUsed;
	BTreeNodeHandler* nodeHandler;
public:
	bool isHasLeaf(ThreadContext* ctx) throw()  final;
	bool isFull(ThreadContext* ctx) throw()  final;
	void setNodeUsed(int nodeUsed, ThreadContext* ctx) throw()  final;
	IBTreeNode* addLeafNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx) final;
	int getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx);
	IBTreeNode* split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) final;
	void put(IBTreeNode* node, ThreadContext* ctx);
	void move(IBTreeNode* node, ThreadContext* ctx);
	void endUse(ThreadContext* ctx) final;
	INodeIterator* iterator(bool endStart, ThreadContext* ctx) final;
	NodeRef* getNodeAt(int index, ThreadContext* ctx) throw() ;
	int getNodeUsed(ThreadContext* ctx) throw() ;
	void loadChildren(ThreadContext* ctx) final;
	void unloadChildren(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BTREE_ABSTRACTBTREELEAFCONTAINER_H_ */
