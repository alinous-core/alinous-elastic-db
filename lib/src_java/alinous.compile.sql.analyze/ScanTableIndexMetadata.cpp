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





bool ScanTableIndexMetadata::__init_done = __init_static_variables();
bool ScanTableIndexMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanTableIndexMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanTableIndexMetadata::ScanTableIndexMetadata(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw()  : IObject(ctx), tableId(nullptr), columns(nullptr)
{
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	GCUtils<ArrayList<ScanTableColumnMetadata> >::mv(this, &(this->columns), columns, ctx);
}
void ScanTableIndexMetadata::__construct_impl(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	GCUtils<ArrayList<ScanTableColumnMetadata> >::mv(this, &(this->columns), columns, ctx);
}
 ScanTableIndexMetadata::~ScanTableIndexMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanTableIndexMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanTableIndexMetadata", L"~ScanTableIndexMetadata");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	if(!prepare){
		return;
	}
}
String* ScanTableIndexMetadata::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->tableId->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1000(), ctx);
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* col = this->columns->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(col->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_564(), ctx);
	return buff->toString(ctx);
}
void ScanTableIndexMetadata::setColumns(ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ScanTableColumnMetadata> >::mv(this, &(this->columns), columns, ctx);
}
ArrayList<ScanTableColumnMetadata>* ScanTableIndexMetadata::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
ArrayList<String>* ScanTableIndexMetadata::getColumnsStr(ThreadContext* ctx) throw() 
{
	ArrayList<String>* list = (new(ctx) ArrayList<String>(ctx));
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* meta = this->columns->get(i, ctx);
		list->add(meta->getName(ctx), ctx);
	}
	return list;
}
ArrayList<ScanTableColumnIdentifier>* ScanTableIndexMetadata::getColumnIds(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* meta = this->columns->get(i, ctx);
		list->add(meta->getColumnIdentifier(ctx), ctx);
	}
	return list;
}
bool ScanTableIndexMetadata::hasColumnsWithoutOrder(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* colId = columns->get(i, ctx);
		if(!hasColumn(colId, ctx))
		{
			return false;
		}
	}
	return true;
}
bool ScanTableIndexMetadata::hasColumn(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* colmeta = this->columns->get(i, ctx);
		if(colmeta->matchIdentigier(colId, ctx))
		{
			return true;
		}
	}
	return false;
}
ScanTableIndexMetadata* ScanTableIndexMetadata::copy(ThreadContext* ctx) throw() 
{
	ScanTableIndexMetadata* newObj = (new(ctx) ScanTableIndexMetadata(this->tableId, this->columns, ctx));
	return newObj;
}
ScanTableIdentifier* ScanTableIndexMetadata::getTableId(ThreadContext* ctx) throw() 
{
	return tableId;
}
void ScanTableIndexMetadata::__cleanUp(ThreadContext* ctx){
}
}}}}

