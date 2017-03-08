#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
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
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool AbstractJoinTarget::__init_done = __init_static_variables();
bool AbstractJoinTarget::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractJoinTarget", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractJoinTarget::AbstractJoinTarget(ThreadContext* ctx) throw()  : IObject(ctx), IJoinTarget(ctx)
{
}
void AbstractJoinTarget::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractJoinTarget::~AbstractJoinTarget() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractJoinTarget::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IJoinTarget::__releaseRegerences(true, ctx);
}
int AbstractJoinTarget::getLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getLine(ctx);
}
int AbstractJoinTarget::getStartPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getStartPosition(ctx);
}
int AbstractJoinTarget::getEndLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndLine(ctx);
}
int AbstractJoinTarget::getEndPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndPosition(ctx);
}
AbstractSrcElement* AbstractJoinTarget::getParent(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getParent(ctx);
}
void AbstractJoinTarget::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IJoinTarget::setParent(parent, ctx);
}
void AbstractJoinTarget::__cleanUp(ThreadContext* ctx){
}
}}}}}

