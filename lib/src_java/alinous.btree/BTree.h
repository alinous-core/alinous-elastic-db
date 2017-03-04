#ifndef ALINOUS_BTREE_BTREE_H_
#define ALINOUS_BTREE_BTREE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTree;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace io {
class DiskCacheManager;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class BTreeLeafNode;}}

namespace alinous {namespace btree {
class BTreeMachine;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryReader;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryWriter;}}}

namespace alinous {namespace btree {
class IBTree;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::java::io::File;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::buffer::storage::FileStorageEntryReader;
using ::alinous::buffer::storage::FileStorageEntryWriter;
using ::alinous::io::DiskCacheManager;
using ::alinous::lock::ConcurrentGate;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class BTree final : public IBTree, public virtual IObject {
public:
	BTree(const BTree& base) = default;
public:
	BTree(ThreadContext* ctx) throw()  : IObject(ctx), IBTree(ctx), gate(nullptr), root(0), storage(nullptr), nodeCapacity(0), keyType(0), valueType(0), loader(nullptr), fetcher(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~BTree() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ConcurrentGate* gate;
private:
	long long root;
	FileStorage* storage;
	int nodeCapacity;
	int keyType;
	int valueType;
	BTreeNodeLoader* loader;
	FileStorageEntryFetcher* fetcher;
public:
	BTree* init(File* file, BTreeGlobalCache* cacheEngine, DiskCacheManager* diskCache, ThreadContext* ctx);
	ArrayList<IBTreeValue>* getValues(IBTreeKey* key, ThreadContext* ctx);
	bool putUniqueKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx);
	void appendKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx) final;
	void putKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx) final;
	IBTreeNode* findByKey(IBTreeKey* key, ThreadContext* ctx) final;
	void putKey(IBTreeKey* key, ThreadContext* ctx) final;
	void removeKey(IBTreeKey* key, ThreadContext* ctx);
	void saveNode(IBTreeNode* node, ThreadContext* ctx);
	IBTreeNode* getRootNode(ThreadContext* ctx) final;
	void initTreeStorage(int nodeCapacity, int keyType, int valueType, long long capacity, long long BLOCK_SIZE, ThreadContext* ctx) final;
	void open(ThreadContext* ctx) final;
	void printNode(StringBuffer* buff, ThreadContext* ctx);
	bool isOpened(ThreadContext* ctx) throw()  final;
	void close(ThreadContext* ctx) final;
	void assertCache(ThreadContext* ctx);
	void updateMasterSection(ThreadContext* ctx);
	bool isEmpty(ThreadContext* ctx) throw()  final;
	long long getRoot(ThreadContext* ctx) throw() ;
	void setRoot(long long root, ThreadContext* ctx) throw() ;
	BTreeNodeLoader* getLoader(ThreadContext* ctx) throw() ;
	int getNodeCapacity(ThreadContext* ctx) throw() ;
private:
	BTreeLeafNode* internalPutKey(IBTreeKey* key, ThreadContext* ctx);
	void putRooNode(ThreadContext* ctx);
	void loadStorageinfo(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREE_H_ */
