#ifndef ALINOUS_BTREE_BTREECACHEARRAY_H_
#define ALINOUS_BTREE_BTREECACHEARRAY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

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
using ::java::util::ArrayList;



class BTreeCacheArray final : public virtual IObject {
public:
	BTreeCacheArray(const BTreeCacheArray& base) = default;
public:
	BTreeCacheArray(int i, ThreadContext* ctx) throw() ;
	void __construct_impl(int i, ThreadContext* ctx) throw() ;
	virtual ~BTreeCacheArray() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<IBTreeNode>* list;
public:
	void add(IBTreeNode* ptr, ThreadContext* ctx) throw() ;
	bool removeByObj(IBTreeNode* obj, ThreadContext* ctx) throw() ;
	int size(ThreadContext* ctx) throw() ;
	IBTreeNode* search(IBTreeNode* value, ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	IBTreeNode* get(int i, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_BTREE_BTREECACHEARRAY_H_ */
