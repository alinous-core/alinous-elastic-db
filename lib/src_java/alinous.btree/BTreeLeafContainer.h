#ifndef ALINOUS_BTREE_BTREELEAFCONTAINER_H_
#define ALINOUS_BTREE_BTREELEAFCONTAINER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeKey;}}

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

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class BTreeLeafContainer;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class AbstractBTreeLeafContainer;}}

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
using ::alinous::buffer::FifoElement;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class BTreeLeafContainer final : public AbstractBTreeLeafContainer {
public:
	BTreeLeafContainer(const BTreeLeafContainer& base) = default;
public:
	BTreeLeafContainer(IBTreeKey* key, int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	void __construct_impl(IBTreeKey* key, int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() ;
	virtual ~BTreeLeafContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IBTreeKey* key;
public:
	int nodeSize(ThreadContext* ctx) final;
	FileStorageEntry* toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx) final;
	IBTreeKey* getKey(ThreadContext* ctx) throw()  final;
	void addNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	char getNodeType(ThreadContext* ctx) throw()  final;
	void printNode(StringBuffer* buff, int level, ThreadContext* ctx) final;
	bool removeChild(IBTreeKey* key, ThreadContext* ctx) final;
	bool isEmpty(ThreadContext* ctx) throw()  final;
	void setKey(IBTreeKey* key, ThreadContext* ctx) throw()  final;
	bool hasMaxNode(ThreadContext* ctx) throw()  final;
	ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw()  final;
	void save(ThreadContext* ctx) throw()  final;
public:
	static IBTreeNode* fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BTREE_BTREELEAFCONTAINER_H_ */
