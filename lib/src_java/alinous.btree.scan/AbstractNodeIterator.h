#ifndef ALINOUS_BTREE_SCAN_ABSTRACTNODEITERATOR_H_
#define ALINOUS_BTREE_SCAN_ABSTRACTNODEITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTreeNodeLoader;}}

namespace alinous {namespace btree {namespace scan {
class INodeIterator;}}}

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
using ::alinous::btree::BTreeNodeLoader;



class AbstractNodeIterator : public INodeIterator, public virtual IObject {
public:
	AbstractNodeIterator(const AbstractNodeIterator& base) = default;
public:
	AbstractNodeIterator(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw() ;
	void __construct_impl(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw() ;
	virtual ~AbstractNodeIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	BTreeNodeLoader* loader;
	long long filePointer;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_BTREE_SCAN_ABSTRACTNODEITERATOR_H_ */
