#ifndef ALINOUS_DB_TRX_SCAN_GROUPEDSCANRESULTRECORD_H_
#define ALINOUS_DB_TRX_SCAN_GROUPEDSCANRESULTRECORD_H_
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class GroupedScanREsultRecord final : public ScanResultRecord {
public:
	GroupedScanREsultRecord(const GroupedScanREsultRecord& base) = default;
public:
	GroupedScanREsultRecord(ThreadContext* ctx) throw()  : IObject(ctx), ScanResultRecord(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~GroupedScanREsultRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_GROUPEDSCANRESULTRECORD_H_ */
