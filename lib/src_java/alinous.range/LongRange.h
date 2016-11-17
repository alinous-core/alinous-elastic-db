#ifndef ALINOUS_RANGE_LONGRANGE_H_
#define ALINOUS_RANGE_LONGRANGE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
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



class LongRange final : public virtual IObject {
public:
	LongRange(const LongRange& base) = default;
public:
	LongRange(long long min, long long max, ThreadContext* ctx) throw() ;
	void __construct_impl(long long min, long long max, ThreadContext* ctx) throw() ;
	virtual ~LongRange() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long min;
	long long max;
public:
	long long width(ThreadContext* ctx) throw() ;
	bool hasNext(long long value, ThreadContext* ctx) throw() ;
	long long getMin(ThreadContext* ctx) throw() ;
	void setMin(long long min, ThreadContext* ctx) throw() ;
	long long getMax(ThreadContext* ctx) throw() ;
	void setMax(long long max, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_RANGE_LONGRANGE_H_ */
