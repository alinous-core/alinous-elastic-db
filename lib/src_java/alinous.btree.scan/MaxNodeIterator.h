#ifndef ALINOUS_BTREE_SCAN_MAXNODEITERATOR_H_
#define ALINOUS_BTREE_SCAN_MAXNODEITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {
class BTreeMaxNode;}}

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
using ::alinous::btree::BTreeMaxNode;
using ::alinous::btree::BTreeNodeLoader;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::runtime::dom::VariableException;



class MaxNodeIterator final : public AbstractNodeIterator {
public:
	MaxNodeIterator(const MaxNodeIterator& base) = default;
public:
	MaxNodeIterator(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx);
	void __construct_impl(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx);
	virtual ~MaxNodeIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	BTreeMaxNode* node;
	int length;
	int current;
public:
	void gotoNode(IBTreeKey* key, ThreadContext* ctx) final;
	void incCurrent(ThreadContext* ctx) throw()  final;
	bool hasNext(ThreadContext* ctx) throw()  final;
	IBTreeNode* next(ThreadContext* ctx) throw()  final;
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

#endif /* end of ALINOUS_BTREE_SCAN_MAXNODEITERATOR_H_ */
