#ifndef ALINOUS_BTREE_SCAN_LEAFCONTAINERITERATOR_H_
#define ALINOUS_BTREE_SCAN_LEAFCONTAINERITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {namespace scan {
class LeafContainerIterator;}}}

namespace alinous {namespace btree {
class AbstractBTreeLeafContainer;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {namespace scan {
class AbstractNodeIterator;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::AbstractBTreeLeafContainer;
using ::alinous::btree::BTreeNodeLoader;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::runtime::dom::VariableException;



class LeafContainerIterator final : public AbstractNodeIterator {
public:
	LeafContainerIterator(const LeafContainerIterator& base) = default;
public:
	LeafContainerIterator(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw() ;
	void __construct_impl(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw() ;
	virtual ~LeafContainerIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AbstractBTreeLeafContainer* container;
	int length;
	int current;
public:
	LeafContainerIterator* init(bool endStart, ThreadContext* ctx);
	void gotoNode(IBTreeKey* key, ThreadContext* ctx) final;
	void incCurrent(ThreadContext* ctx) throw()  final;
	bool hasNext(ThreadContext* ctx) throw()  final;
	IBTreeNode* next(ThreadContext* ctx) final;
	bool isLeafContainer(ThreadContext* ctx) throw()  final;
	void dispose(ThreadContext* ctx) final;
	int getType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_BTREE_SCAN_LEAFCONTAINERITERATOR_H_ */
