#ifndef ALINOUS_DB_TRX_SCAN_IFILTERSCANNER_H_
#define ALINOUS_DB_TRX_SCAN_IFILTERSCANNER_H_
namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IFilterScanner : public virtual IObject, public ITableTargetScanner {
public:
	IFilterScanner(const IFilterScanner& base) = default;
public:
	IFilterScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IFilterScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_IFILTERSCANNER_H_ */
