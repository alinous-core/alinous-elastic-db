#ifndef ALINOUS_BUFFER_HASHARRAYLISTITERATOR_H_
#define ALINOUS_BUFFER_HASHARRAYLISTITERATOR_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace btree {
class BTreeCacheArray;}}

namespace java {namespace util {
class BitSet;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace buffer {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::BitSet;
using ::alinous::btree::BTreeCacheArray;
using ::alinous::btree::IBTreeNode;



class HashArrayListIterator final : public virtual IObject {
public:
	HashArrayListIterator(const HashArrayListIterator& base) = default;
public:
	HashArrayListIterator(IArrayObject<BTreeCacheArray>* ptr, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObject<BTreeCacheArray>* ptr, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw() ;
	virtual ~HashArrayListIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long MAX_HASH;
	int hashCode;
	int index;
	IArrayObject<BTreeCacheArray>* arrays;
	BitSet* bitset;
public:
	bool hasNext(ThreadContext* ctx) throw() ;
	IBTreeNode* next(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BUFFER_HASHARRAYLISTITERATOR_H_ */
