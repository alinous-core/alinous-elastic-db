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





bool JoinStrategyPart::__init_done = __init_static_variables();
bool JoinStrategyPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinStrategyPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinStrategyPart::JoinStrategyPart(ThreadContext* ctx) throw()  : IObject(ctx), andexpressions(GCUtils<ArrayList<JoinMatchExpression> >::ins(this, (new(ctx) ArrayList<JoinMatchExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), bestExp(nullptr), indexStatus(-1)
{
}
void JoinStrategyPart::__construct_impl(ThreadContext* ctx) throw() 
{
}
 JoinStrategyPart::~JoinStrategyPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinStrategyPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinStrategyPart", L"~JoinStrategyPart");
	__e_obj1.add(this->andexpressions, this);
	andexpressions = nullptr;
	__e_obj1.add(this->bestExp, this);
	bestExp = nullptr;
	if(!prepare){
		return;
	}
}
void JoinStrategyPart::calcIindexStatus(ThreadContext* ctx) throw() 
{
	int maxLoop = this->andexpressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		JoinMatchExpression* match = this->andexpressions->get(i, ctx);
		int status = match->getIndexStatus(ctx);
		if(status > this->indexStatus)
		{
			this->indexStatus = status;
			__GC_MV(this, &(this->bestExp), match, JoinMatchExpression);
		}
	}
}
JoinMatchExpression* JoinStrategyPart::getBestExp(ThreadContext* ctx) throw() 
{
	return bestExp;
}
void JoinStrategyPart::addExpression(JoinMatchExpression* matchExp, ThreadContext* ctx) throw() 
{
	this->andexpressions->add(matchExp, ctx);
	return;
}
ArrayList<JoinMatchExpression>* JoinStrategyPart::getExpressions(ThreadContext* ctx) throw() 
{
	return andexpressions;
}
bool JoinStrategyPart::requireFullScan(ThreadContext* ctx) throw() 
{
	return this->andexpressions->isEmpty(ctx);
}
void JoinStrategyPart::__cleanUp(ThreadContext* ctx){
}
}}}}

