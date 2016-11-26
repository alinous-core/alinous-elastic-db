#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_SCAN_RIGHTINDEXJOINSCANNER_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_SCAN_RIGHTINDEXJOINSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinMatchExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace db {namespace trx {
class TrxLockContext;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::sql::analyze::JoinMatchExpression;
using ::alinous::compile::sql::analyze::ScanTableIndexMetadata;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::compile::sql::select::join::SQLJoinCondition;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::TrxLockContext;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class RightindexJoinScanner final : public ITableTargetScanner, public virtual IObject {
public:
	RightindexJoinScanner(const RightindexJoinScanner& base) = default;
public:
	RightindexJoinScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	void __construct_impl(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	virtual ~RightindexJoinScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ITableTargetScanner* left;
	ITableTargetScanner* right;
	bool inner;
	ScanTableIndexMetadata* rightIndex;
	ScanTableMetadata* rightMetadata;
	int leftColumnIndex;
	int rightColumnIndex;
	ScanResultRecord* currentLeft;
	VariantValue* leftValue;
	int joinedCount;
	ISQLExpression* joinCondition;
	ScriptMachine* machine;
	ScanResultRecord* nextRightResult;
	ScanResultRecord* nextResult;
	TrxLockContext* locker;
	DbTransaction* trx;
public:
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
private:
	bool rightHasNext(bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_SCAN_RIGHTINDEXJOINSCANNER_H_ */
