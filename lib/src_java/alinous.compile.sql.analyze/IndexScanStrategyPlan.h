#ifndef ALINOUS_COMPILE_SQL_ANALYZE_INDEXSCANSTRATEGYPLAN_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_INDEXSCANSTRATEGYPLAN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexColumnMatchCondition;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexScanStrategy;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexRangeScannerParam;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScannerParam;}}}}

namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnMetadata;}}}}

namespace alinous {namespace runtime {namespace engine {
class AlinousNullPointerException;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexScanStrategyPlan;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableIndex;
using ::alinous::db::table::scan::IndexListScannerParam;
using ::alinous::db::table::scan::IndexRangeScannerParam;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::AlinousNullPointerException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class IndexScanStrategyPlan final : public virtual IObject {
public:
	IndexScanStrategyPlan(const IndexScanStrategyPlan& base) = default;
public:
	IndexScanStrategyPlan(IndexColumnMatchCondition* matchingCondition, IndexScanStrategy* parentStrategy, ThreadContext* ctx) throw() ;
	void __construct_impl(IndexColumnMatchCondition* matchingCondition, IndexScanStrategy* parentStrategy, ThreadContext* ctx) throw() ;
	virtual ~IndexScanStrategyPlan() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IndexScanStrategy* parentStrategy;
	ArrayList<IndexColumnMatchCondition>* matchConditions;
	int indexType;
	int matchMode;
	int scanMode;
public:
	constexpr static const int SCAN_ALWAYS_FALSE{0};
	constexpr static const int SCAN_EQ{1};
	constexpr static const int SCAN_RANGE{2};
	constexpr static const int SCAN_LIST{3};
public:
	ScanResultIndexKey* getEqIndexKey(ScriptMachine* machine, ArrayList<TableColumnMetadata>* cols, bool debug, ThreadContext* ctx);
	IndexRangeScannerParam* getRamgeIndexKeyParam(ScriptMachine* machine, ArrayList<TableColumnMetadata>* cols, bool debug, ThreadContext* ctx);
	IndexListScannerParam* getListIndexKey(ScriptMachine* machine, ArrayList<TableColumnMetadata>* cols, bool debug, ThreadContext* ctx);
	int getEqKeyLength(ThreadContext* ctx) throw() ;
	TableIndex* getIndex(DatabaseTable* tableStore, ThreadContext* ctx) throw() ;
	int calcEfficience(ThreadContext* ctx) throw() ;
	bool indexIncludesColumns(ArrayList<ScanTableColumnIdentifier>* colOrder, ThreadContext* ctx) throw() ;
	void addEqColumn(IndexColumnMatchCondition* matchingCondition, ScanTableIndexMetadata* indexMetadata, bool debug, ThreadContext* ctx);
	IndexColumnMatchCondition* getFirstMatchCondition(ThreadContext* ctx) throw() ;
	bool sameColumns(IndexScanStrategyPlan* part, ThreadContext* ctx) throw() ;
	bool hasColumn(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() ;
	ArrayList<IndexColumnMatchCondition>* getMatchConditions(ThreadContext* ctx) throw() ;
	ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw() ;
	int getScanMode(ThreadContext* ctx) throw() ;
	int getMatchMode(ThreadContext* ctx) throw() ;
	void setMatchMode(int indexMode, ThreadContext* ctx) throw() ;
	int getIndexType(ThreadContext* ctx) throw() ;
private:
	IndexColumnMatchCondition* findColumnMatchingConditionByColumnMetadta(ScanTableColumnMetadata* columnMeta, ThreadContext* ctx) throw() ;
	bool checkIsVoid(IndexColumnMatchCondition* matchingCondition, bool debug, ThreadContext* ctx) throw() ;
	bool expressionValueIsNotAlwaysSame(IExpression* exp1, IExpression* exp2, bool debug, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_INDEXSCANSTRATEGYPLAN_H_ */
