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





bool ScanUnique::__init_done = __init_static_variables();
bool ScanUnique::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanUnique", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanUnique::ScanUnique(ThreadContext* ctx) throw()  : IObject(ctx), TableMetadataUnique(ctx), coveredKey(nullptr), matchLength(0), tableFullName(nullptr)
{
}
void ScanUnique::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanUnique::~ScanUnique() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanUnique::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanUnique", L"~ScanUnique");
	__e_obj1.add(this->coveredKey, this);
	coveredKey = nullptr;
	__e_obj1.add(this->tableFullName, this);
	tableFullName = nullptr;
	if(!prepare){
		return;
	}
	TableMetadataUnique::__releaseRegerences(true, ctx);
}
TablePartitionKey* ScanUnique::getCoveredKey(ThreadContext* ctx) throw() 
{
	return coveredKey;
}
void ScanUnique::setCoveredKey(TablePartitionKey* coveredKey, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->coveredKey), coveredKey, TablePartitionKey);
}
bool ScanUnique::isCovered(ThreadContext* ctx) throw() 
{
	return this->coveredKey != nullptr;
}
int ScanUnique::getMatchLength(ThreadContext* ctx) throw() 
{
	return matchLength;
}
void ScanUnique::calcCoverage(TablePartitionKey* key, ThreadContext* ctx) throw() 
{
	ArrayList<TableColumnMetadata>* keys = key->getKeys(ctx);
	int matchLength = 0;
	int maxLoop = keys->size(ctx) < this->uniqueColList->size(ctx) ? keys->size(ctx) : this->uniqueColList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = keys->get(i, ctx);
		TableColumnMetadata* ucol = this->uniqueColList->get(i, ctx);
		if(!col->name->equals(ucol->name, ctx))
		{
			break ;
		}
		matchLength ++ ;
	}
	if(matchLength > this->matchLength)
	{
		this->matchLength = matchLength;
		__GC_MV(this, &(this->coveredKey), key, TablePartitionKey);
	}
}
String* ScanUnique::getTableFullName(ThreadContext* ctx) throw() 
{
	return tableFullName;
}
void ScanUnique::setTableFullName(String* tableFullName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableFullName), tableFullName, String);
}
void ScanUnique::__cleanUp(ThreadContext* ctx){
}
}}}}

