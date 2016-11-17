#ifndef ALINOUS_BTREE_SCAN_INODEITERATOR_H_
#define ALINOUS_BTREE_SCAN_INODEITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

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

namespace alinous {namespace btree {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::runtime::dom::VariableException;



class INodeIterator : public virtual IObject {
public:
	INodeIterator(const INodeIterator& base) = default;
public:
	INodeIterator(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~INodeIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int IT_LEAF_CONTAINER{1};
	constexpr static const int IT_MAX_NODE{2};
	constexpr static const int IT_NODE{3};
public:
	virtual int getType(ThreadContext* ctx) throw()  = 0;
	virtual bool hasNext(ThreadContext* ctx) throw()  = 0;
	virtual IBTreeNode* next(ThreadContext* ctx) = 0;
	virtual bool isLeafContainer(ThreadContext* ctx) throw()  = 0;
	virtual void gotoNode(IBTreeKey* key, ThreadContext* ctx) = 0;
	virtual void incCurrent(ThreadContext* ctx) throw()  = 0;
	virtual void dispose(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BTREE_SCAN_INODEITERATOR_H_ */
