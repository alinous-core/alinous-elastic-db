#ifndef ALINOUS_BTREEMEMORY_ABSTRACTMEMORYBTREELEAFCONTAINER_H_
#define ALINOUS_BTREEMEMORY_ABSTRACTMEMORYBTREELEAFCONTAINER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btreememory {
class MBTreeLeafContainer;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace alinous {namespace btreememory {namespace scan {
class MemoryLeafContainerIterator;}}}

namespace alinous {namespace btreememory {
class AbstractMemoryNode;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace util {
class Builtin;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btreememory {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeNodeLoader;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::btreememory::scan::MemoryLeafContainerIterator;
using ::alinous::runtime::dom::VariableException;
using ::alinous::util::Builtin;



class AbstractMemoryBTreeLeafContainer : public AbstractMemoryNode {
public:
	AbstractMemoryBTreeLeafContainer(const AbstractMemoryBTreeLeafContainer& base) = default;
public:
	AbstractMemoryBTreeLeafContainer(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() ;
	void __construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() ;
	virtual ~AbstractMemoryBTreeLeafContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int length;
	int nodeUsed;
	IArrayObject<IBTreeNode>* nodes;
public:
	bool isHasLeaf(ThreadContext* ctx) throw()  final;
	bool isFull(ThreadContext* ctx) throw()  final;
	void setNodeUsed(int nodeUsed, ThreadContext* ctx) throw()  final;
	IBTreeNode* addLeafNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx) final;
	int nodeToGoDown(IBTreeKey* key, ThreadContext* ctx) throw() ;
	void move(IBTreeNode* node, ThreadContext* ctx);
	int getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx);
	IBTreeNode* split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) final;
	IBTreeNode* getNodeAt(int index, ThreadContext* ctx) throw() ;
	int getNodeUsed(ThreadContext* ctx) throw() ;
	INodeIterator* iterator(bool endStart, ThreadContext* ctx) final;
private:
	bool putNode(IBTreeNode* btNode, bool ignoreOverflow, bool move, ThreadContext* ctx);
	int indexOfInsert(IBTreeNode* value, ThreadContext* ctx) throw() ;
	virtual void removeNode(int index, int count, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BTREEMEMORY_ABSTRACTMEMORYBTREELEAFCONTAINER_H_ */
