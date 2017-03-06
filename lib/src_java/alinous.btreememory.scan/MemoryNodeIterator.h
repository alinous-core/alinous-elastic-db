#ifndef ALINOUS_BTREEMEMORY_SCAN_MEMORYNODEITERATOR_H_
#define ALINOUS_BTREEMEMORY_SCAN_MEMORYNODEITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btreememory {
class MBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

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

namespace alinous {namespace btreememory {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::btreememory::MBTreeNode;
using ::alinous::runtime::dom::VariableException;



class MemoryNodeIterator final : public INodeIterator, public virtual IObject {
public:
	MemoryNodeIterator(const MemoryNodeIterator& base) = default;
public:
	MemoryNodeIterator(bool endStart, MBTreeNode* node, ThreadContext* ctx) throw() ;
	void __construct_impl(bool endStart, MBTreeNode* node, ThreadContext* ctx) throw() ;
	virtual ~MemoryNodeIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int current;
	int length;
	MBTreeNode* node;
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
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_BTREEMEMORY_SCAN_MEMORYNODEITERATOR_H_ */
