#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLIsNullExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLLikeExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLNotExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLRelationalExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.sql.expression.blexp/SQLBooleanLiteral.h"

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLOrExpression::__init_done = __init_static_variables();
bool SQLOrExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLOrExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLOrExpression::SQLOrExpression(ArrayList<ISQLExpression>* result, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanCollectionExpression(result, ConstStr::getCNST_STR_1076(), ctx)
{
}
void SQLOrExpression::__construct_impl(ArrayList<ISQLExpression>* result, ThreadContext* ctx) throw() 
{
}
 SQLOrExpression::SQLOrExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanCollectionExpression(ctx)
{
}
void SQLOrExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLOrExpression::~SQLOrExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLOrExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLBooleanCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* SQLOrExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->first->resolveExpression(machine, debug, ctx);
	if(val->isTrue(ctx))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* sub = this->expressions->get(i, ctx);
		val = sub->resolveExpression(machine, debug, ctx);
		if(val->isTrue(ctx))
		{
			return (new(ctx) VariantValue(((char)1), ctx));
		}
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
VariantValue* SQLOrExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	if(val->isTrue(ctx))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* sub = this->expressions->get(i, ctx);
		val = sub->resolveSQLExpression(record, machine, debug, ctx);
		if(val->isTrue(ctx))
		{
			return (new(ctx) VariantValue(((char)1), ctx));
		}
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
int SQLOrExpression::getContainerType(ThreadContext* ctx) throw() 
{
	return AbstractSQLBooleanCollectionExpression::OR_EXP;
}
bool SQLOrExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLOrExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLOrExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLOrExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLOrExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLOrExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
int SQLOrExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLOrExpression;
}
void SQLOrExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void SQLOrExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLOrExpression, ctx);
	__writeData(buff, ctx);
}
void SQLOrExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLOrExpression, ctx);
	__toFileEntry(builder, ctx);
}
void SQLOrExpression::__cleanUp(ThreadContext* ctx){
}
}}}}}

