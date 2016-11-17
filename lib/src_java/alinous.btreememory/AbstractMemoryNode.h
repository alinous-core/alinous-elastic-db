#ifndef ALINOUS_BTREEMEMORY_ABSTRACTMEMORYNODE_H_
#define ALINOUS_BTREEMEMORY_ABSTRACTMEMORYNODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btreememory {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::btree::IBTreeNode;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::runtime::dom::VariableException;



class AbstractMemoryNode : public IBTreeNode, public virtual IObject {
public:
	AbstractMemoryNode(const AbstractMemoryNode& base) = default;
public:
	AbstractMemoryNode(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeNode(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractMemoryNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long getFilePointer(ThreadContext* ctx) throw()  final;
	int nodeSize(ThreadContext* ctx) final;
	void use(ThreadContext* ctx) final;
	void endUse(ThreadContext* ctx) final;
	FileStorageEntry* toFileStorageEntry(FileStorageEntryBuilder* buffBuilder, FileStorageEntry* buffEntry, ThreadContext* ctx) final;
	void setFilePointer(long long position, ThreadContext* ctx) throw()  final;
	bool isDeletable(ThreadContext* ctx) throw()  final;
	void incCount(ThreadContext* ctx) throw()  final;
	int getUseGCRefCount(ThreadContext* ctx) throw()  final;
	long long getHashKey(ThreadContext* ctx) throw()  final;
	int compareTo(IBTreeNode* another, ThreadContext* ctx) throw() ;
	void printTab(StringBuffer* buff, int level, ThreadContext* ctx) throw() ;
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

#endif /* end of ALINOUS_BTREEMEMORY_ABSTRACTMEMORYNODE_H_ */
