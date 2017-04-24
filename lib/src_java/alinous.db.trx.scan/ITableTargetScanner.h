#ifndef ALINOUS_DB_TRX_SCAN_ITABLETARGETSCANNER_H_
#define ALINOUS_DB_TRX_SCAN_ITABLETARGETSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class ITableTargetScanner : public virtual IObject {
public:
	ITableTargetScanner(const ITableTargetScanner& base) = default;
public:
	ITableTargetScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ITableTargetScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) = 0;
	virtual void endScan(ThreadContext* ctx) = 0;
	virtual bool hasNext(bool debug, ThreadContext* ctx) = 0;
	virtual ScanResultRecord* next(bool debug, ThreadContext* ctx) = 0;
	virtual void dispose(ISystemLog* logger, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_ITABLETARGETSCANNER_H_ */
