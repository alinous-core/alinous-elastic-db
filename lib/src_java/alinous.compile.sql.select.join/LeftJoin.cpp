#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.select.join.scan/JoinedCollectionScanner.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool LeftJoin::__init_done = __init_static_variables();
bool LeftJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LeftJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LeftJoin::LeftJoin(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLJoin(ctx)
{
}
void LeftJoin::__construct_impl(ThreadContext* ctx) throw() 
{
}
 LeftJoin::~LeftJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LeftJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLJoin::__releaseRegerences(true, ctx);
}
ITableTargetScanner* LeftJoin::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	if(this->crossjoin)
	{
		return getCrossJoinsScanner(trx, machine, joinRequest, debug, ctx);
	}
	if(this->bestParts->size(ctx) == 1)
	{
		JoinStrategyPart* part = this->bestParts->get(0, ctx);
		ITableTargetScanner* scanner = getJoinStrategyScanner(trx, machine, part, this->joinStrategy->isInner(ctx), debug, ctx);
		if(joinRequest != nullptr)
		{
			return toResultScanner(trx, scanner, joinRequest, this->scanMetadata, debug, ctx);
		}
		return scanner;
	}
	ArrayList<ITableTargetScanner>* scanners = (new(ctx) ArrayList<ITableTargetScanner>(ctx));
	int maxLoop = this->bestParts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		JoinStrategyPart* part = this->bestParts->get(i, ctx);
		ITableTargetScanner* scanner = getJoinStrategyScanner(trx, machine, part, this->joinStrategy->isInner(ctx), debug, ctx);
		scanners->add(scanner, ctx);
	}
	JoinedCollectionScanner* collectionScanner = (new(ctx) JoinedCollectionScanner(scanners, ctx));
	if(joinRequest != nullptr)
	{
		return toResultScanner(trx, collectionScanner, joinRequest, this->scanMetadata, debug, ctx);
	}
	return collectionScanner;
}
IStatement::StatementType LeftJoin::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void LeftJoin::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void LeftJoin::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void LeftJoin::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__LeftJoin, ctx);
	__writeData(buff, ctx);
}
void LeftJoin::__cleanUp(ThreadContext* ctx){
}
}}}}}

