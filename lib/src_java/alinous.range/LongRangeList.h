#ifndef ALINOUS_RANGE_LONGRANGELIST_H_
#define ALINOUS_RANGE_LONGRANGELIST_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace range {
class LongRange;}}

namespace alinous {namespace range {
class LongRangeIterator;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace range {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class LongRangeList final : public virtual IObject {
public:
	LongRangeList(const LongRangeList& base) = default;
public:
	LongRangeList(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~LongRangeList() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<LongRange>* list;
public:
	void addRange(long long value, ThreadContext* ctx) throw() ;
	void removeRange(long long value, ThreadContext* ctx) throw() ;
	LongRange* get(int listIndex, ThreadContext* ctx) throw() ;
	bool isEmpty(ThreadContext* ctx) throw() ;
	int size(ThreadContext* ctx) throw() ;
	LongRangeIterator* iterator(ThreadContext* ctx) throw() ;
private:
	void spiltByRemove(LongRange* range, long long value, int pos, ThreadContext* ctx) throw() ;
	void insertRange(int pos, LongRange* newRange, ThreadContext* ctx) throw() ;
	void insertOrExtend(int pos, long long value, ThreadContext* ctx) throw() ;
	void insertRange(int pos, long long value, ThreadContext* ctx) throw() ;
	int indexOfInsert(long long value, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_RANGE_LONGRANGELIST_H_ */
