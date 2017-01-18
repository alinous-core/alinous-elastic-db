#ifndef ALINOUS_BTREE_IBTREENODE_H_
#define ALINOUS_BTREE_IBTREENODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace java {namespace lang {
template <typename  T> class Comparable;}}

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
using ::alinous::buffer::storage::FileStorage;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class IBTreeNode : public virtual IObject, public Comparable<IBTreeNode> {
public:
	IBTreeNode(const IBTreeNode& base) = default;
public:
	IBTreeNode(ThreadContext* ctx) throw()  : IObject(ctx), Comparable<IBTreeNode>(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IBTreeNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const char BTREE_TYPE_LEAF{1};
	constexpr static const char BTREE_TYPE_NODE{2};
	constexpr static const char BTREE_TYPE_LEAF_CONTAINER{3};
	constexpr static const char BTREE_TYPE_MAX_NODE{4};
	constexpr static const char BTREE_TYPE_MAX_LEAF_CONTAINER{5};
public:
	virtual char getNodeType(ThreadContext* ctx) throw()  = 0;
	virtual bool isHasLeaf(ThreadContext* ctx) throw()  = 0;
	virtual bool hasMaxNode(ThreadContext* ctx) throw()  = 0;
	virtual long long getFilePointer(ThreadContext* ctx) throw()  = 0;
	virtual int nodeSize(ThreadContext* ctx) = 0;
	virtual void use(ThreadContext* ctx) = 0;
	virtual void endUse(ThreadContext* ctx) = 0;
	virtual FileStorageEntry* toFileStorageEntry(FileStorageEntryBuilder* buffBuilder, FileStorageEntry* buffEntry, ThreadContext* ctx) = 0;
	virtual void setFilePointer(long long position, ThreadContext* ctx) throw()  = 0;
	virtual bool isFull(ThreadContext* ctx) throw()  = 0;
	virtual IBTreeNode* addLeafNode(IBTreeNode* newNode, ThreadContext* ctx) = 0;
	virtual void addNode(IBTreeNode* newNode, ThreadContext* ctx) = 0;
	virtual IBTreeKey* getKey(ThreadContext* ctx) throw()  = 0;
	virtual void setKey(IBTreeKey* key, ThreadContext* ctx) = 0;
	virtual IBTreeNode* getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx) = 0;
	virtual bool isDeletable(ThreadContext* ctx) throw()  = 0;
	virtual void setNodeUsed(int nodeUsed, ThreadContext* ctx) = 0;
	virtual IBTreeNode* split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) = 0;
	virtual void incCount(ThreadContext* ctx) throw()  = 0;
	virtual int getUseGCRefCount(ThreadContext* ctx) throw()  = 0;
	virtual INodeIterator* iterator(bool endStart, ThreadContext* ctx) = 0;
	virtual void loadChildren(ThreadContext* ctx) = 0;
	virtual void unloadChildren(ThreadContext* ctx) = 0;
	virtual void printNode(StringBuffer* buff, int level, ThreadContext* ctx) = 0;
	virtual bool removeChild(IBTreeKey* key, ThreadContext* ctx) = 0;
	virtual bool isEmpty(ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw()  = 0;
	virtual FileStorage* getStorage(ThreadContext* ctx) throw()  = 0;
	virtual void setStorage(FileStorage* storage, ThreadContext* ctx) throw()  = 0;
	virtual long long getHashKey(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_IBTREENODE_H_ */
