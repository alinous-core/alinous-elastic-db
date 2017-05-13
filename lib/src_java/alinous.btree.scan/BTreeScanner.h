#ifndef ALINOUS_BTREE_SCAN_BTREESCANNER_H_
#define ALINOUS_BTREE_SCAN_BTREESCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

namespace alinous {namespace btree {
class IBTreeKey;}}

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

namespace java {namespace util {
template <typename  T> class Stack;}}

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
using ::java::util::Iterator;
using ::java::util::Stack;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class BTreeScanner final : public virtual IObject {
public:
	BTreeScanner(const BTreeScanner& base) = default;
public:
	BTreeScanner(IBTree* btree, ThreadContext* ctx) throw() ;
	void __construct_impl(IBTree* btree, ThreadContext* ctx) throw() ;
	virtual ~BTreeScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* btree;
	Stack<INodeIterator>* stack;
public:
	void startScan(bool endStart, ThreadContext* ctx);
	void startScan(IBTreeKey* key, ThreadContext* ctx);
	IBTreeNode* next(ThreadContext* ctx);
	bool hasNext(ThreadContext* ctx);
	void endScan(ThreadContext* ctx);
	void endScan(bool closeGate, ThreadContext* ctx);
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

#endif /* end of ALINOUS_BTREE_SCAN_BTREESCANNER_H_ */
