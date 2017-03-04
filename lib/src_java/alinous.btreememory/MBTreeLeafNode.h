#ifndef ALINOUS_BTREEMEMORY_MBTREELEAFNODE_H_
#define ALINOUS_BTREEMEMORY_MBTREELEAFNODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace btreememory {
class AbstractMemoryNode;}}

namespace java {namespace io {
class IOException;}}

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
using ::alinous::btree::BTreeNodeLoader;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::buffer::storage::FileStorage;



class MBTreeLeafNode final : public AbstractMemoryNode {
public:
	MBTreeLeafNode(const MBTreeLeafNode& base) = default;
public:
	MBTreeLeafNode(IBTreeKey* key, ThreadContext* ctx) throw() ;
	void __construct_impl(IBTreeKey* key, ThreadContext* ctx) throw() ;
	virtual ~MBTreeLeafNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTreeKey* key;
	ArrayList<IBTreeValue>* values;
public:
	IBTreeKey* getKey(ThreadContext* ctx) throw()  final;
	ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw()  final;
	bool isHasLeaf(ThreadContext* ctx) throw()  final;
	bool isFull(ThreadContext* ctx) throw()  final;
	IBTreeNode* addLeafNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx) final;
	void setNodeUsed(int nodeUsed, ThreadContext* ctx) final;
	IBTreeNode* split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) throw()  final;
	void addNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	INodeIterator* iterator(bool endStart, ThreadContext* ctx) final;
	void loadChildren(ThreadContext* ctx) final;
	char getNodeType(ThreadContext* ctx) throw()  final;
	void printNode(StringBuffer* buff, int level, ThreadContext* ctx) throw()  final;
	bool removeChild(IBTreeKey* key, ThreadContext* ctx) final;
	bool isEmpty(ThreadContext* ctx) throw()  final;
	void setKey(IBTreeKey* key, ThreadContext* ctx) throw()  final;
	bool hasMaxNode(ThreadContext* ctx) throw()  final;
	void unloadChildren(ThreadContext* ctx) final;
	FileStorage* getStorage(ThreadContext* ctx) throw()  final;
	void setStorage(FileStorage* storage, ThreadContext* ctx) throw()  final;
	void save(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREEMEMORY_MBTREELEAFNODE_H_ */
