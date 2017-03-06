#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/IExpression.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.analyze/IndexScanStrategyPlan.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.compile.sql.analyze/BooleanFilterConditionUtil.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.compile.sql.analyze/IndexConditionDetector.h"
#include "alinous.compile.sql.analyze/IndexSelectionUtils.h"
#include "alinous.compile.sql.analyze/IScanStrategy.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/SingleTableIndexScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.analyze/JoinConditionDetector.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





constexpr const int IndexColumnMatchCondition::INDEX_NONE;
constexpr const int IndexColumnMatchCondition::INDEX_NORMAL;
constexpr const int IndexColumnMatchCondition::INDEX_FULL_TEXT;
constexpr const int IndexColumnMatchCondition::FULL_SCAN;
constexpr const int IndexColumnMatchCondition::INDEX_EQUALS;
constexpr const int IndexColumnMatchCondition::INDEX_BEFORE;
constexpr const int IndexColumnMatchCondition::INDEX_AFTER;
constexpr const int IndexColumnMatchCondition::INDEX_RANGE;
constexpr const int IndexColumnMatchCondition::INDEX_IN;
bool IndexColumnMatchCondition::__init_done = __init_static_variables();
bool IndexColumnMatchCondition::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexColumnMatchCondition", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexColumnMatchCondition::IndexColumnMatchCondition(ScanTableColumnIdentifier* columnIdentifier, int matchMode, ISQLExpression* start, ISQLExpression* end, ThreadContext* ctx) throw()  : IObject(ctx), indexType(0), matchMode(0), columnIdentifier(nullptr), start(nullptr), startEq(0), end(nullptr), endEq(0), explist(nullptr), indexMetadata(nullptr)
{
	this->indexType = INDEX_NORMAL;
	__GC_MV(this, &(this->columnIdentifier), columnIdentifier, ScanTableColumnIdentifier);
	this->matchMode = matchMode;
	__GC_MV(this, &(this->start), start, ISQLExpression);
	this->startEq = false;
	__GC_MV(this, &(this->end), end, ISQLExpression);
	this->endEq = false;
}
void IndexColumnMatchCondition::__construct_impl(ScanTableColumnIdentifier* columnIdentifier, int matchMode, ISQLExpression* start, ISQLExpression* end, ThreadContext* ctx) throw() 
{
	this->indexType = INDEX_NORMAL;
	__GC_MV(this, &(this->columnIdentifier), columnIdentifier, ScanTableColumnIdentifier);
	this->matchMode = matchMode;
	__GC_MV(this, &(this->start), start, ISQLExpression);
	this->startEq = false;
	__GC_MV(this, &(this->end), end, ISQLExpression);
	this->endEq = false;
}
 IndexColumnMatchCondition::IndexColumnMatchCondition(ScanTableColumnIdentifier* columnIdentifier, ArrayList<ISQLExpression>* explist, ThreadContext* ctx) throw()  : IObject(ctx), indexType(0), matchMode(0), columnIdentifier(nullptr), start(nullptr), startEq(0), end(nullptr), endEq(0), explist(nullptr), indexMetadata(nullptr)
{
	this->indexType = INDEX_NORMAL;
	__GC_MV(this, &(this->columnIdentifier), columnIdentifier, ScanTableColumnIdentifier);
	this->matchMode = INDEX_IN;
	GCUtils<ArrayList<ISQLExpression> >::mv(this, &(this->explist), explist, ctx);
}
void IndexColumnMatchCondition::__construct_impl(ScanTableColumnIdentifier* columnIdentifier, ArrayList<ISQLExpression>* explist, ThreadContext* ctx) throw() 
{
	this->indexType = INDEX_NORMAL;
	__GC_MV(this, &(this->columnIdentifier), columnIdentifier, ScanTableColumnIdentifier);
	this->matchMode = INDEX_IN;
	GCUtils<ArrayList<ISQLExpression> >::mv(this, &(this->explist), explist, ctx);
}
 IndexColumnMatchCondition::~IndexColumnMatchCondition() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexColumnMatchCondition::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IndexColumnMatchCondition", L"~IndexColumnMatchCondition");
	__e_obj1.add(this->columnIdentifier, this);
	columnIdentifier = nullptr;
	__e_obj1.add(this->start, this);
	start = nullptr;
	__e_obj1.add(this->end, this);
	end = nullptr;
	__e_obj1.add(this->explist, this);
	explist = nullptr;
	__e_obj1.add(this->indexMetadata, this);
	indexMetadata = nullptr;
	if(!prepare){
		return;
	}
}
int IndexColumnMatchCondition::indexEficience(ThreadContext* ctx) throw() 
{
	switch(this->matchMode) {
	case INDEX_EQUALS:
		return 100;
	case INDEX_BEFORE:
	case INDEX_AFTER:
		return 5;
	case INDEX_RANGE:
		return 10;
	case INDEX_IN:
		return 50;
	case FULL_SCAN:
	default:
		break ;
	}
	return 0;
}
int IndexColumnMatchCondition::getMatchMode(ThreadContext* ctx) throw() 
{
	return matchMode;
}
void IndexColumnMatchCondition::setMatchMode(int matchMode, ThreadContext* ctx) throw() 
{
	this->matchMode = matchMode;
}
ISQLExpression* IndexColumnMatchCondition::getStart(ThreadContext* ctx) throw() 
{
	return start;
}
void IndexColumnMatchCondition::setStart(ISQLExpression* start, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->start), start, ISQLExpression);
}
bool IndexColumnMatchCondition::isStartEq(ThreadContext* ctx) throw() 
{
	return startEq;
}
void IndexColumnMatchCondition::setStartEq(bool startEq, ThreadContext* ctx) throw() 
{
	this->startEq = startEq;
}
ISQLExpression* IndexColumnMatchCondition::getEnd(ThreadContext* ctx) throw() 
{
	return end;
}
void IndexColumnMatchCondition::setEnd(ISQLExpression* end, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->end), end, ISQLExpression);
}
bool IndexColumnMatchCondition::isEndEq(ThreadContext* ctx) throw() 
{
	return endEq;
}
void IndexColumnMatchCondition::setEndEq(bool endEq, ThreadContext* ctx) throw() 
{
	this->endEq = endEq;
}
ArrayList<ISQLExpression>* IndexColumnMatchCondition::getExplist(ThreadContext* ctx) throw() 
{
	return explist;
}
void IndexColumnMatchCondition::setExplist(ArrayList<ISQLExpression>* explist, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ISQLExpression> >::mv(this, &(this->explist), explist, ctx);
}
int IndexColumnMatchCondition::getIndexType(ThreadContext* ctx) throw() 
{
	return indexType;
}
ScanTableColumnIdentifier* IndexColumnMatchCondition::getColumnIdentifier(ThreadContext* ctx) throw() 
{
	return columnIdentifier;
}
bool IndexColumnMatchCondition::validateStrategy(ScanTableMetadata* metadata, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* columns = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	columns->add(this->columnIdentifier, ctx);
	ArrayList<ScanTableIndexMetadata>* availableIndexes = metadata->getAbailableIndexes(metadata->getFirstTableId(ctx), columns, ctx);
	if(availableIndexes->isEmpty(ctx))
	{
		return false;
	}
	__GC_MV(this, &(this->indexMetadata), IndexSelectionUtils::getMinimumColumnIndexMetadata(availableIndexes, ctx), ScanTableIndexMetadata);
	return true;
}
ScanTableIndexMetadata* IndexColumnMatchCondition::getIndexMetadata(ThreadContext* ctx) throw() 
{
	return indexMetadata;
}
void IndexColumnMatchCondition::setIndexMetadata(ScanTableIndexMetadata* indexMetadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->indexMetadata), indexMetadata, ScanTableIndexMetadata);
}
void IndexColumnMatchCondition::__cleanUp(ThreadContext* ctx){
}
}}}}

