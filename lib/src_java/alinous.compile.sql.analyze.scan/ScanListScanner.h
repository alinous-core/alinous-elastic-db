#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCAN_SCANLISTSCANNER_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCAN_SCANLISTSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::util::ArrayList;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class ScanListScanner final : public ITableTargetScanner, public virtual IObject {
public:
	ScanListScanner(const ScanListScanner& base) = default;
public:
	ScanListScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ScanListScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ITableTargetScanner>* scanners;
	int current;
	ITableTargetScanner* scanner;
	ScanResultIndexKey* indexKeyValue;
public:
	void addScanner(ITableTargetScanner* scanner, ThreadContext* ctx) throw() ;
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCAN_SCANLISTSCANNER_H_ */
