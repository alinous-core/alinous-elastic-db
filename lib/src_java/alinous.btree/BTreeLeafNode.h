#ifndef ALINOUS_BTREE_BTREELEAFNODE_H_
#define ALINOUS_BTREE_BTREELEAFNODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class KeyValue;}}

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
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class BTreeLeafNode;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace java {namespace lang {
class StringBuffer;}}

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
using ::java::util::ArrayList;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::buffer::FifoElement;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class BTreeLeafNode final : public AbstractNode {
public:
	BTreeLeafNode(const BTreeLeafNode& base) = default;
public:
	BTreeLeafNode(KeyValue* kv, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void __construct_impl(KeyValue* kv, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	BTreeLeafNode(IBTreeKey* key, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void __construct_impl(IBTreeKey* key, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	virtual ~BTreeLeafNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	KeyValue* keyValue;
public:
	void save(ThreadContext* ctx);
	int nodeSize(ThreadContext* ctx) final;
	FileStorageEntry* toFileStorageEntry(FileStorageEntry* entry, ThreadContext* ctx);
	FileStorageEntry* toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx) final;
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
public:
	static BTreeLeafNode* fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREELEAFNODE_H_ */
