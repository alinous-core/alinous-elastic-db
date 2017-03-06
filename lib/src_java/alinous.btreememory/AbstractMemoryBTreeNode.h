#ifndef ALINOUS_BTREEMEMORY_ABSTRACTMEMORYBTREENODE_H_
#define ALINOUS_BTREEMEMORY_ABSTRACTMEMORYBTREENODE_H_
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
class MBTreeNode;}}

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
using ::alinous::runtime::dom::VariableException;
using ::alinous::util::Builtin;



class AbstractMemoryBTreeNode : public AbstractMemoryNode {
public:
	AbstractMemoryBTreeNode(const AbstractMemoryBTreeNode& base) = default;
public:
	AbstractMemoryBTreeNode(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() ;
	void __construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() ;
	virtual ~AbstractMemoryBTreeNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int length;
	int nodeUsed;
	IArrayObject<IBTreeNode>* nodes;
public:
	void setNode(IBTreeNode* ref, int index, ThreadContext* ctx) throw() ;
	bool isHasLeaf(ThreadContext* ctx) throw()  final;
	virtual IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx);
	virtual int getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx);
	IBTreeNode* get(int index, ThreadContext* ctx) throw() ;
	int getNodeUsed(ThreadContext* ctx) throw() ;
	void setNodeUsed(int nodeUsed, ThreadContext* ctx) throw()  final;
	bool isFull(ThreadContext* ctx) throw()  final;
	IBTreeNode* split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) final;
	void addNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	IBTreeNode* removeNode(IBTreeKey* key, ThreadContext* ctx);
	void removeNode(int index, int count, ThreadContext* ctx);
	bool putNode(IBTreeNode* newNode, bool ignoreOverflow, bool move, ThreadContext* ctx);
	int indexOfInsert(IBTreeNode* value, ThreadContext* ctx) throw() ;
	int indexOf(IBTreeKey* value, ThreadContext* ctx) throw() ;
	int nodeToGoDown(IBTreeKey* key, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BTREEMEMORY_ABSTRACTMEMORYBTREENODE_H_ */
