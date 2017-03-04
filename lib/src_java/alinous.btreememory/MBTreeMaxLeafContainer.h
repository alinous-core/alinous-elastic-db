#ifndef ALINOUS_BTREEMEMORY_MBTREEMAXLEAFCONTAINER_H_
#define ALINOUS_BTREEMEMORY_MBTREEMAXLEAFCONTAINER_H_
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

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace btreememory {
class AbstractMemoryBTreeLeafContainer;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace util {
class Builtin;}}

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
using ::alinous::buffer::storage::FileStorage;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;
using ::alinous::util::Builtin;



class MBTreeMaxLeafContainer final : public AbstractMemoryBTreeLeafContainer {
public:
	MBTreeMaxLeafContainer(const MBTreeMaxLeafContainer& base) = default;
public:
	MBTreeMaxLeafContainer(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() ;
	void __construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() ;
	virtual ~MBTreeMaxLeafContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IBTreeKey* getKey(ThreadContext* ctx) throw()  final;
	void addNode(IBTreeNode* newNode, ThreadContext* ctx) final;
	char getNodeType(ThreadContext* ctx) throw()  final;
	bool removeChild(IBTreeKey* key, ThreadContext* ctx) final;
	IBTreeNode* removeNode(IBTreeKey* key, ThreadContext* ctx);
	int indexOf(IBTreeKey* value, ThreadContext* ctx) throw() ;
	void removeNode(int index, int count, ThreadContext* ctx) final;
	void printNode(StringBuffer* buff, int level, ThreadContext* ctx) final;
	bool isEmpty(ThreadContext* ctx) throw()  final;
	void setKey(IBTreeKey* key, ThreadContext* ctx) final;
	bool hasMaxNode(ThreadContext* ctx) throw()  final;
	void loadChildren(ThreadContext* ctx) final;
	ArrayList<IBTreeValue>* getValues(ThreadContext* ctx) throw()  final;
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

#endif /* end of ALINOUS_BTREEMEMORY_MBTREEMAXLEAFCONTAINER_H_ */
