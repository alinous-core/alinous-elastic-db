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





bool ScanTableColumnMetadata::__init_done = __init_static_variables();
bool ScanTableColumnMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanTableColumnMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanTableColumnMetadata::ScanTableColumnMetadata(ScanTableIdentifier* table, String* name, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), name(nullptr), columnIdentifier(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->table), table, ScanTableIdentifier);
	__GC_MV(this, &(this->columnIdentifier), (new(ctx) ScanTableColumnIdentifier(this->table, this->name, ctx)), ScanTableColumnIdentifier);
}
void ScanTableColumnMetadata::__construct_impl(ScanTableIdentifier* table, String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->table), table, ScanTableIdentifier);
	__GC_MV(this, &(this->columnIdentifier), (new(ctx) ScanTableColumnIdentifier(this->table, this->name, ctx)), ScanTableColumnIdentifier);
}
 ScanTableColumnMetadata::~ScanTableColumnMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanTableColumnMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanTableColumnMetadata", L"~ScanTableColumnMetadata");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->columnIdentifier, this);
	columnIdentifier = nullptr;
	if(!prepare){
		return;
	}
}
String* ScanTableColumnMetadata::getName(ThreadContext* ctx) throw() 
{
	return name;
}
bool ScanTableColumnMetadata::matchIdentigier(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	ScanTableIdentifier* tableId = colId->getTable(ctx);
	if(tableId == nullptr)
	{
		return name->equals(colId->getColumn(ctx), ctx);
	}
	return this->table != nullptr && this->table->equals(tableId, ctx) && this->name->equals(colId->getColumn(ctx), ctx);
}
ScanTableColumnIdentifier* ScanTableColumnMetadata::getColumnIdentifier(ThreadContext* ctx) throw() 
{
	return columnIdentifier;
}
bool ScanTableColumnMetadata::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	ScanTableColumnMetadata* other = dynamic_cast<ScanTableColumnMetadata*>(obj);
	return this->table->equals(other->table, ctx) && this->name->equals(other->name, ctx);
}
String* ScanTableColumnMetadata::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->table->toString(ctx), ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(this->name, ctx);
	return buff->toString(ctx);
}
void ScanTableColumnMetadata::__cleanUp(ThreadContext* ctx){
}
}}}}

