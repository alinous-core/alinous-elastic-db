#ifndef ALINOUS_BTREE_BTREEMAXNODE_H_
#define ALINOUS_BTREE_BTREEMAXNODE_H_
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
class IBTreeKey;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class BTreeMaxNode;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace alinous {namespace btree {namespace scan {
class MaxNodeIterator;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class AbstractBTreeNode;}}

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
using ::java::util::ArrayList;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::btree::scan::MaxNodeIterator;
using ::alinous::buffer::FifoElement;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::lock::LockObject;
using ::alinous::system::AlinousException;



class BTreeMaxNode final : public AbstractBTreeNode {
public:
	BTreeMaxNode(const BTreeMaxNode& base) = default;
public:
	BTreeMaxNode(int numNodes, IArrayObject<NodeRef>* nodes, long long maxFilePointer, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void __construct_impl(int numNodes, IArrayObject<NodeRef>* nodes, long long maxFilePointer, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	virtual ~BTreeMaxNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	NodeRef* max;
public:
	NodeRef* getMax(ThreadContext* ctx) throw() ;
	int getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx) final;
	IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx) final;
	int nodeSize(ThreadContext* ctx) throw()  final;
	FileStorageEntry* toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx) throw()  final;
	IBTreeNode* addLeafNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	IBTreeKey* getKey(ThreadContext* ctx) throw()  final;
	void endUse(ThreadContext* ctx) final;
	void loadChildren(ThreadContext* ctx) final;
	INodeIterator* iterator(bool endStart, ThreadContext* ctx) final;
	char getNodeType(ThreadContext* ctx) throw()  final;
	void printNode(StringBuffer* buff, int level, ThreadContext* ctx) final;
	bool removeChild(IBTreeKey* key, ThreadContext* ctx) final;
	bool isEmpty(ThreadContext* ctx) throw()  final;
	void setKey(IBTreeKey* key, ThreadContext* ctx) final;
	bool hasMaxNode(ThreadContext* ctx) throw()  final;
	ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw()  final;
public:
	static IBTreeNode* fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREEMAXNODE_H_ */
