#ifndef ALINOUS_BTREE_ABSTRACTBTREENODE_H_
#define ALINOUS_BTREE_ABSTRACTBTREENODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class NodeRef;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class BTreeNodeHandler;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeNode;}}

namespace alinous {namespace btree {
class AbstractNode;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::buffer::FifoElement;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class AbstractBTreeNode : public AbstractNode {
public:
	AbstractBTreeNode(const AbstractBTreeNode& base) = default;
public:
	AbstractBTreeNode(int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void __construct_impl(int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	virtual ~AbstractBTreeNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int length;
	int nodeUsed;
	IArrayObject<NodeRef>* nodes;
	BTreeNodeHandler* nodeHandler;
public:
	void setNode(NodeRef* ref, int index, ThreadContext* ctx) throw() ;
	bool isHasLeaf(ThreadContext* ctx) throw()  final;
	virtual IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx);
	virtual int getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx);
	NodeRef* get(int index, ThreadContext* ctx) throw() ;
	int getNodeUsed(ThreadContext* ctx) throw() ;
	void setNodeUsed(int nodeUsed, ThreadContext* ctx) throw()  final;
	bool isFull(ThreadContext* ctx) throw()  final;
	IBTreeNode* split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) final;
	void addNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	virtual void endUse(ThreadContext* ctx);
	void unloadChildren(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_ABSTRACTBTREENODE_H_ */
