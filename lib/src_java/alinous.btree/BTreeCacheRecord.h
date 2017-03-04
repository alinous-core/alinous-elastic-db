#ifndef ALINOUS_BTREE_BTREECACHERECORD_H_
#define ALINOUS_BTREE_BTREECACHERECORD_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

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
using ::java::util::ArrayList;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::system::AlinousException;



class BTreeCacheRecord final : public IBTreeNode, public virtual IObject {
public:
	BTreeCacheRecord(const BTreeCacheRecord& base) = default;
public:
	BTreeCacheRecord(long long BLOCK_SIZE, ThreadContext* ctx) throw() ;
	void __construct_impl(long long BLOCK_SIZE, ThreadContext* ctx) throw() ;
	virtual ~BTreeCacheRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	FileStorage* storage;
	long long filePointer;
public:
	void setFilePointer(long long position, ThreadContext* ctx) throw()  final;
	long long getHashKey(ThreadContext* ctx) throw()  final;
	int compareTo(IBTreeNode* another, ThreadContext* ctx) throw() ;
	bool isHasLeaf(ThreadContext* ctx) throw()  final;
	long long getFilePointer(ThreadContext* ctx) throw()  final;
	int nodeSize(ThreadContext* ctx) throw()  final;
	void endUse(ThreadContext* ctx) final;
	FileStorageEntry* toFileStorageEntry(FileStorageEntryBuilder* buffBuilder, FileStorageEntry* buffEntry, ThreadContext* ctx) throw()  final;
	void use(ThreadContext* ctx) throw()  final;
	bool isFull(ThreadContext* ctx) throw()  final;
	IBTreeNode* addLeafNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	IBTreeKey* getKey(ThreadContext* ctx) throw()  final;
	IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx) final;
	bool isDeletable(ThreadContext* ctx) throw()  final;
	void setNodeUsed(int nodeUsed, ThreadContext* ctx) final;
	IBTreeNode* split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) throw()  final;
	void addNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	void incCount(ThreadContext* ctx) throw()  final;
	int getUseGCRefCount(ThreadContext* ctx) throw()  final;
	INodeIterator* iterator(bool endStart, ThreadContext* ctx) throw()  final;
	void loadChildren(ThreadContext* ctx) throw()  final;
	char getNodeType(ThreadContext* ctx) throw()  final;
	void printNode(StringBuffer* buff, int level, ThreadContext* ctx) throw()  final;
	bool removeChild(IBTreeKey* key, ThreadContext* ctx) throw()  final;
	bool isEmpty(ThreadContext* ctx) throw()  final;
	void setKey(IBTreeKey* key, ThreadContext* ctx) throw()  final;
	bool hasMaxNode(ThreadContext* ctx) throw()  final;
	ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw()  final;
	void unloadChildren(ThreadContext* ctx) throw()  final;
	FileStorage* getStorage(ThreadContext* ctx) throw()  final;
	void setStorage(FileStorage* storage, ThreadContext* ctx) throw()  final;
	void save(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (IBTreeNode* _this, IBTreeNode* another, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_BTREE_BTREECACHERECORD_H_ */
