#ifndef ALINOUS_BTREE_BTREEMACHINE_H_
#define ALINOUS_BTREE_BTREEMACHINE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {
class BTreeLeafNode;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T> class Stack;}}

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
using ::java::util::Iterator;
using ::java::util::Stack;
using ::alinous::system::AlinousException;



class BTreeMachine final : public virtual IObject {
public:
	BTreeMachine(const BTreeMachine& base) = default;
public:
	BTreeMachine(IBTreeNode* rootNode, BTree* btree, ThreadContext* ctx);
	void __construct_impl(IBTreeNode* rootNode, BTree* btree, ThreadContext* ctx);
	virtual ~BTreeMachine() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Stack<IBTreeNode>* nodeStack;
	IBTreeNode* rootNode;
	BTree* btree;
public:
	void removeKey(IBTreeKey* key, ThreadContext* ctx);
	void insertLeaf(BTreeLeafNode* newNode, ThreadContext* ctx);
	void push(IBTreeNode* node, ThreadContext* ctx);
	IBTreeNode* pop(ThreadContext* ctx) throw() ;
	void destroy(ThreadContext* ctx);
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
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BTREE_BTREEMACHINE_H_ */
