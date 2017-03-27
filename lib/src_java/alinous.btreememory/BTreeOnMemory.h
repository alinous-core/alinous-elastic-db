#ifndef ALINOUS_BTREEMEMORY_BTREEONMEMORY_H_
#define ALINOUS_BTREEMEMORY_BTREEONMEMORY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btreememory {
class MemoryBTreeMachine;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btreememory {
class MBTreeLeafNode;}}

namespace alinous {namespace btreememory {
class MBTreeMaxLeafContainer;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace util {
class Builtin;}}

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
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;
using ::alinous::util::Builtin;



class BTreeOnMemory final : public IBTree, public virtual IObject {
public:
	BTreeOnMemory(const BTreeOnMemory& base) = default;
public:
	BTreeOnMemory(int nodeCapacity, ThreadContext* ctx) throw() ;
	void __construct_impl(int nodeCapacity, ThreadContext* ctx) throw() ;
	virtual ~BTreeOnMemory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTreeNode* rootNode;
	int nodeCapacity;
public:
	IBTreeNode* getRootNode(ThreadContext* ctx) final;
	MemoryBTreeMachine* newMachine(ThreadContext* ctx);
	void putKey(IBTreeKey* key, MemoryBTreeMachine* machine, ThreadContext* ctx);
	ArrayList<IBTreeValue>* getValues(IBTreeKey* key, ThreadContext* ctx);
	IBTreeNode* findByKey(IBTreeKey* key, ThreadContext* ctx) final;
	void setRoot(IBTreeNode* newRoot, ThreadContext* ctx) throw() ;
	int getNodeCapacity(ThreadContext* ctx) throw() ;
	bool isEmpty(ThreadContext* ctx) throw()  final;
	void initTreeStorage(int nodeCapacity, int keyType, int valueType, long long capacity, long long BLOCK_SIZE, ThreadContext* ctx) final;
	void open(ThreadContext* ctx) final;
	void close(ThreadContext* ctx) final;
	bool isOpened(ThreadContext* ctx) throw()  final;
	void putKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx) final;
	void putKey(IBTreeKey* key, ThreadContext* ctx) final;
	void appendKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx) final;
	void closeGate(ThreadContext* ctx) final;
	void openGate(ThreadContext* ctx) final;
	void enterGate(ThreadContext* ctx) final;
	void exitGate(ThreadContext* ctx) throw()  final;
private:
	void putRooNode(ThreadContext* ctx);
	MBTreeLeafNode* internalPutKey(IBTreeKey* key, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BTREEMEMORY_BTREEONMEMORY_H_ */
