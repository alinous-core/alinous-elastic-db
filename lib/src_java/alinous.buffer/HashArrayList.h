#ifndef ALINOUS_BUFFER_HASHARRAYLIST_H_
#define ALINOUS_BUFFER_HASHARRAYLIST_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {
class BTreeCacheArray;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace buffer {
class HashArrayListIterator;}}

namespace java {namespace util {
class BitSet;}}

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
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeNode;



class HashArrayList final : public virtual IObject {
public:
	HashArrayList(const HashArrayList& base) = default;
public:
	HashArrayList(int MAX_HASH, ThreadContext* ctx);
	void __construct_impl(int MAX_HASH, ThreadContext* ctx);
	virtual ~HashArrayList() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long MAX_HASH;
	long long MAX_HASH_MASK;
private:
	IArrayObject<BTreeCacheArray>* arrays;
	BitSet* bitset;
	int numElements;
public:
	int size(ThreadContext* ctx) throw() ;
	IBTreeNode* addElement(IBTreeNode* ptr, ThreadContext* ctx) throw() ;
	bool removeByObj(IBTreeNode* obj, ThreadContext* ctx) throw() ;
	IBTreeNode* search(IBTreeNode* value, ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	HashArrayListIterator* iterator(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_BUFFER_HASHARRAYLIST_H_ */
