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





bool SQLAndExpression::__init_done = __init_static_variables();
bool SQLAndExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLAndExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLAndExpression::SQLAndExpression(ArrayList<ISQLExpression>* result, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanCollectionExpression(result, ConstStr::getCNST_STR_1077(), ctx)
{
}
void SQLAndExpression::__construct_impl(ArrayList<ISQLExpression>* result, ThreadContext* ctx) throw() 
{
}
 SQLAndExpression::SQLAndExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanCollectionExpression(ctx)
{
}
void SQLAndExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLAndExpression::~SQLAndExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLAndExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLBooleanCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* SQLAndExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->first->resolveExpression(machine, debug, ctx);
	if(!val->isTrue(ctx))
	{
		return (new(ctx) VariantValue(((char)0), ctx));
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* sub = this->expressions->get(i, ctx);
		val = sub->resolveExpression(machine, debug, ctx);
		if(!val->isTrue(ctx))
		{
			return (new(ctx) VariantValue(((char)0), ctx));
		}
	}
	return (new(ctx) VariantValue(((char)1), ctx));
}
VariantValue* SQLAndExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	if(!val->isTrue(ctx))
	{
		return (new(ctx) VariantValue(((char)0), ctx));
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* sub = this->expressions->get(i, ctx);
		val = sub->resolveSQLExpression(record, machine, debug, ctx);
		if(!val->isTrue(ctx))
		{
			return (new(ctx) VariantValue(((char)0), ctx));
		}
	}
	return (new(ctx) VariantValue(((char)1), ctx));
}
int SQLAndExpression::getContainerType(ThreadContext* ctx) throw() 
{
	return AbstractSQLBooleanCollectionExpression::AND_EXP;
}
bool SQLAndExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLAndExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
	this->first->collectJoinCondition(list, ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* sub = this->expressions->get(i, ctx);
		sub->collectJoinCondition(list, ctx);
	}
}
bool SQLAndExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLAndExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLAndExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLAndExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
int SQLAndExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLAndExpression;
}
void SQLAndExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void SQLAndExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLAdditiveExpression, ctx);
	__writeData(buff, ctx);
}
void SQLAndExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLAndExpression, ctx);
	__toFileEntry(builder, ctx);
}
void SQLAndExpression::__cleanUp(ThreadContext* ctx){
}
}}}}}

