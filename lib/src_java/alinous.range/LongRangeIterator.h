#ifndef ALINOUS_RANGE_LONGRANGEITERATOR_H_
#define ALINOUS_RANGE_LONGRANGEITERATOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace range {
class LongRangeList;}}

namespace alinous {namespace range {
class LongRange;}}

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



class LongRangeIterator final : public virtual IObject {
public:
	LongRangeIterator(const LongRangeIterator& base) = default;
public:
	LongRangeIterator(LongRangeList* list, ThreadContext* ctx) throw() ;
	void __construct_impl(LongRangeList* list, ThreadContext* ctx) throw() ;
	virtual ~LongRangeIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LongRangeList* list;
	int listIndex;
	long long current;
public:
	bool hasNext(ThreadContext* ctx) throw() ;
	long long next(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_RANGE_LONGRANGEITERATOR_H_ */
