#ifndef ALINOUS_BTREE_SCAN_NODEITERATOR_H_
#define ALINOUS_BTREE_SCAN_NODEITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {
class BTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {namespace scan {
class AbstractNodeIterator;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace btree {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::BTreeNode;
using ::alinous::btree::BTreeNodeLoader;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::system::AlinousException;



class NodeIterator final : public AbstractNodeIterator {
public:
	NodeIterator(const NodeIterator& base) = default;
public:
	NodeIterator(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx);
	void __construct_impl(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx);
	virtual ~NodeIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	BTreeNode* node;
	int length;
	int current;
public:
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

#endif /* end of ALINOUS_BTREE_SCAN_NODEITERATOR_H_ */
