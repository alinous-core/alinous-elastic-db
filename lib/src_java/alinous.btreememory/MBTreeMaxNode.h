#ifndef ALINOUS_BTREEMEMORY_MBTREEMAXNODE_H_
#define ALINOUS_BTREEMEMORY_MBTREEMAXNODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace alinous {namespace btreememory {namespace scan {
class MemoryMaxNodeIterator;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace btreememory {
class AbstractMemoryBTreeNode;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btreememory {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::btreememory::scan::MemoryMaxNodeIterator;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class MBTreeMaxNode final : public AbstractMemoryBTreeNode {
public:
	MBTreeMaxNode(const MBTreeMaxNode& base) = default;
public:
	MBTreeMaxNode(int numNodes, IArrayObject<IBTreeNode>* nodes, IBTreeNode* max, ThreadContext* ctx) throw() ;
	void __construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, IBTreeNode* max, ThreadContext* ctx) throw() ;
	virtual ~MBTreeMaxNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IBTreeNode* max;
public:
	IBTreeNode* getMax(ThreadContext* ctx) throw() ;
	int getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx) final;
	IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx) final;
	IBTreeNode* addLeafNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	IBTreeKey* getKey(ThreadContext* ctx) throw()  final;
	void printNode(StringBuffer* buff, int level, ThreadContext* ctx) final;
	bool removeChild(IBTreeKey* key, ThreadContext* ctx) final;
	bool isEmpty(ThreadContext* ctx) throw()  final;
	void setKey(IBTreeKey* key, ThreadContext* ctx) final;
	bool hasMaxNode(ThreadContext* ctx) throw()  final;
	char getNodeType(ThreadContext* ctx) throw()  final;
	INodeIterator* iterator(bool endStart, ThreadContext* ctx) final;
	void loadChildren(ThreadContext* ctx) final;
	ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw()  final;
	void unloadChildren(ThreadContext* ctx) final;
	FileStorage* getStorage(ThreadContext* ctx) throw()  final;
	void setStorage(FileStorage* storage, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREEMEMORY_MBTREEMAXNODE_H_ */
