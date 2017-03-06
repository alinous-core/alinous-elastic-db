#ifndef ALINOUS_BTREEMEMORY_SCAN_MEMORYBTREESCANNER_H_
#define ALINOUS_BTREEMEMORY_SCAN_MEMORYBTREESCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace btreememory {
class MBTreeLeafNode;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

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
using ::java::util::Iterator;
using ::java::util::Stack;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::scan::INodeIterator;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::btreememory::MBTreeLeafNode;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class MemoryBTreeScanner final : public virtual IObject {
public:
	MemoryBTreeScanner(const MemoryBTreeScanner& base) = default;
public:
	MemoryBTreeScanner(BTreeOnMemory* btree, ThreadContext* ctx) throw() ;
	void __construct_impl(BTreeOnMemory* btree, ThreadContext* ctx) throw() ;
	virtual ~MemoryBTreeScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	BTreeOnMemory* btree;
	Stack<INodeIterator>* stack;
public:
	void startScan(bool endStart, ThreadContext* ctx);
	void startScan(IBTreeKey* key, ThreadContext* ctx);
	IBTreeNode* next(ThreadContext* ctx);
	bool hasNext(ThreadContext* ctx);
	void endScan(ThreadContext* ctx);
private:
	void gotoKey(IBTreeKey* key, IBTreeNode* rootNode, ThreadContext* ctx);
	void gotoNextLeafContainer(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_BTREEMEMORY_SCAN_MEMORYBTREESCANNER_H_ */
