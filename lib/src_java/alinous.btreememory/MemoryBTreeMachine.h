#ifndef ALINOUS_BTREEMEMORY_MEMORYBTREEMACHINE_H_
#define ALINOUS_BTREEMEMORY_MEMORYBTREEMACHINE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace btreememory {
class MBTreeLeafNode;}}

namespace alinous {namespace btreememory {
class MBTreeMaxNode;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

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
using ::java::util::Stack;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::system::AlinousException;
using ::alinous::util::Builtin;



class MemoryBTreeMachine final : public virtual IObject {
public:
	MemoryBTreeMachine(const MemoryBTreeMachine& base) = default;
public:
	MemoryBTreeMachine(IBTreeNode* rootNode, BTreeOnMemory* btree, ThreadContext* ctx);
	void __construct_impl(IBTreeNode* rootNode, BTreeOnMemory* btree, ThreadContext* ctx);
	virtual ~MemoryBTreeMachine() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Stack<IBTreeNode>* nodeStack;
	IBTreeNode* rootNode;
	BTreeOnMemory* btree;
public:
	void removeKey(IBTreeKey* key, ThreadContext* ctx);
	void insertLeaf(MBTreeLeafNode* newNode, ThreadContext* ctx);
	void push(IBTreeNode* node, ThreadContext* ctx) throw() ;
	IBTreeNode* pop(ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	void destroy(ThreadContext* ctx) throw() ;
private:
	void splitAndInsertLeaf2Root(IBTreeNode* root, IBTreeNode* newNode, ThreadContext* ctx);
	void splitAndInsertLeaf(IBTreeNode* node, IBTreeNode* newNode, ThreadContext* ctx);
	void splitAndInsertNode2Root(IBTreeNode* root, IBTreeNode* newNode, ThreadContext* ctx);
	void splitAndInsertNode(IBTreeNode* node, IBTreeNode* newNode, ThreadContext* ctx);
	IBTreeNode* getParent(IBTreeNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREEMEMORY_MEMORYBTREEMACHINE_H_ */
