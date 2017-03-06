#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCAN_VOIDSCANNER_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCAN_VOIDSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::system::ISystemLog;



class VoidScanner final : public ITableTargetScanner, public virtual IObject {
public:
	VoidScanner(const VoidScanner& base) = default;
public:
	VoidScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~VoidScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void startScan(ScanResultIndexKey* indexValue, ThreadContext* ctx) throw()  final;
	void endScan(ThreadContext* ctx) throw()  final;
	bool hasNext(bool debug, ThreadContext* ctx) throw()  final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) throw()  final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCAN_VOIDSCANNER_H_ */
