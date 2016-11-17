#ifndef ALINOUS_BTREE_BTREENODEHANDLER_H_
#define ALINOUS_BTREE_BTREENODEHANDLER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class NodeRef;}}

namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {
class AbstractNode;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;



class BTreeNodeHandler final : public virtual IObject {
public:
	BTreeNodeHandler(const BTreeNodeHandler& base) = default;
public:
	BTreeNodeHandler(IArrayObject<NodeRef>* nodes, int nodeUsed, int length, BTreeNodeLoader* loader, AbstractNode* theNode, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObject<NodeRef>* nodes, int nodeUsed, int length, BTreeNodeLoader* loader, AbstractNode* theNode, ThreadContext* ctx) throw() ;
	virtual ~BTreeNodeHandler() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IArrayObject<NodeRef>* nodes;
	int nodeUsed;
	int length;
	BTreeNodeLoader* loader;
	IBTreeNode* theNode;
	bool loaded;
	bool sorted;
	LockObject* childLock;
public:
	bool putNode(IBTreeNode* btNode, bool ignoreOverflow, bool move, ThreadContext* ctx);
	IBTreeNode* removeNode(IBTreeKey* key, ThreadContext* ctx);
	void removeNode(int index, int count, ThreadContext* ctx);
	void load(ThreadContext* ctx);
	void unload(ThreadContext* ctx);
	int nodeToGoDown(IBTreeKey* key, ThreadContext* ctx) throw() ;
	int indexOf(NodeRef* value, ThreadContext* ctx) throw() ;
	int indexOf(IBTreeKey* value, ThreadContext* ctx) throw() ;
	void sort(ThreadContext* ctx) throw() ;
	void swap(int i, int j, ThreadContext* ctx) throw() ;
	void setNodeUsed(int nodeUsed, ThreadContext* ctx) throw() ;
	bool isLoaded(ThreadContext* ctx) throw() ;
private:
	int indexOfInsert(NodeRef* value, ThreadContext* ctx) throw() ;
	void downheap(int rootDefault, int leaf, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREENODEHANDLER_H_ */
