#ifndef ALINOUS_BTREE_BTREENODELOADER_H_
#define ALINOUS_BTREE_BTREENODELOADER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace btree {
class BTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class BTreeMaxNode;}}

namespace alinous {namespace btree {
class BTreeMaxLeafContainer;}}

namespace alinous {namespace btree {
class BTreeLeafContainer;}}

namespace alinous {namespace btree {
class BTreeLeafNode;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageBlock;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryReader;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryWriter;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::io::IOException;
using ::alinous::buffer::FifoElement;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::buffer::storage::FileStorageBlock;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::buffer::storage::FileStorageEntryReader;
using ::alinous::buffer::storage::FileStorageEntryWriter;
using ::alinous::lock::LockObject;
using ::alinous::system::AlinousException;



class BTreeNodeLoader final : public virtual IObject {
public:
	BTreeNodeLoader(const BTreeNodeLoader& base) = default;
public:
	BTreeNodeLoader(FileStorage* storage, BTreeGlobalCache* cacheEngine, ThreadContext* ctx);
	void __construct_impl(FileStorage* storage, BTreeGlobalCache* cacheEngine, ThreadContext* ctx);
	virtual ~BTreeNodeLoader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	BTreeGlobalCache* cacheEngine;
	FileStorage* storage;
	LockObject* sync;
	FileStorageEntry* buffEntry;
	FileStorageEntryBuilder* buffBuilder;
	FileStorageEntryWriter* writer;
	FileStorageEntryReader* reader;
public:
	void open(ThreadContext* ctx);
	void close(ThreadContext* ctx) throw() ;
	BTreeNode* newNode(IBTreeKey* key, int numNodes, ThreadContext* ctx);
	BTreeMaxNode* newMaxNode(int numNodes, long long maxFilePointer, ThreadContext* ctx);
	BTreeMaxLeafContainer* newBTreeMaxLeafContainer(int numNodes, ThreadContext* ctx);
	BTreeLeafContainer* newLeafContainerNode(IBTreeKey* key, int numNodes, ThreadContext* ctx);
	BTreeMaxLeafContainer* newBTreeMaxLeafContainerNode(int numNodes, ThreadContext* ctx);
	BTreeLeafNode* newLeafNode(IBTreeKey* key, ThreadContext* ctx);
	void moveToUsing(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void moveToDeletable(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void deleteBTreeNode(IBTreeNode* node, ThreadContext* ctx);
	void saveBTreeNode(IBTreeNode* node, ThreadContext* ctx);
	void reloadKey(IBTreeNode* node, ThreadContext* ctx);
	IBTreeNode* loadBTreeNode(long long filePointer, ThreadContext* ctx);
	int getBlockSize(ThreadContext* ctx) throw() ;
	void assertCache(ThreadContext* ctx);
private:
	void addCache(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREENODELOADER_H_ */
