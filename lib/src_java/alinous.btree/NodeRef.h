#ifndef ALINOUS_BTREE_NODEREF_H_
#define ALINOUS_BTREE_NODEREF_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class NodeRef;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace java {namespace lang {
template <typename  T> class Comparable;}}

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



class NodeRef final : public Comparable<NodeRef>, public virtual IObject {
public:
	NodeRef(const NodeRef& base) = default;
public:
	NodeRef(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	NodeRef(long long filePointer, ThreadContext* ctx) throw() ;
	void __construct_impl(long long filePointer, ThreadContext* ctx) throw() ;
	virtual ~NodeRef() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long filePointer;
	IBTreeNode* node;
public:
	int compareTo(NodeRef* another, ThreadContext* ctx) throw() ;
	IBTreeNode* getNode(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (NodeRef* _this, NodeRef* another, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_BTREE_NODEREF_H_ */
