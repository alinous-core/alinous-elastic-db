#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/AndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"
#include "alinous.compile.sql.expression/SQLLiteral.h"
#include "alinous.compile.sql.expression/SQLMultiplicativeExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression/SQLSubqueryExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLIsNullExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLLikeExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLNotExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLRelationalExpression.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.expression.blexp/SQLBooleanLiteral.h"

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLBooleanLiteral::__init_done = __init_static_variables();
bool SQLBooleanLiteral::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLBooleanLiteral", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLBooleanLiteral::SQLBooleanLiteral(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanExpression(ctx), value(0)
{
}
void SQLBooleanLiteral::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLBooleanLiteral::~SQLBooleanLiteral() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLBooleanLiteral::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLBooleanLiteral", L"~SQLBooleanLiteral");
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLBooleanLiteral::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool SQLBooleanLiteral::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
bool SQLBooleanLiteral::isConstant(ThreadContext* ctx) throw() 
{
	return true;
}
bool SQLBooleanLiteral::isValue(ThreadContext* ctx) throw() 
{
	return value;
}
void SQLBooleanLiteral::setValue(bool value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
IAlinousVariable* SQLBooleanLiteral::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(value)
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
ExpressionSourceId* SQLBooleanLiteral::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLBooleanLiteral::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) throw() 
{
	return true;
}
bool SQLBooleanLiteral::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLBooleanLiteral::getColumns(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLBooleanLiteral::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLBooleanLiteral::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLBooleanLiteral::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLBooleanLiteral::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLBooleanLiteral::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IndexColumnMatchCondition* SQLBooleanLiteral::getIndexScanPart(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ScanTableColumnIdentifier* SQLBooleanLiteral::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLBooleanLiteral::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return resolveExpression(machine, debug, ctx)->toVariantValue(ctx);
}
bool SQLBooleanLiteral::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLBooleanLiteral::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
int SQLBooleanLiteral::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLBooleanLiteral;
}
void SQLBooleanLiteral::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	this->value = buff->getBoolean(ctx);
}
void SQLBooleanLiteral::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLBooleanLiteral, ctx);
	__writeData(buff, ctx);
	buff->putBoolean(this->value, ctx);
}
int SQLBooleanLiteral::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	total += 1;
	return total;
}
void SQLBooleanLiteral::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__BooleanLiteral, ctx);
	__toFileEntry(builder, ctx);
	builder->putBoolean(this->value, ctx);
}
void SQLBooleanLiteral::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	this->value = fetcher->fetchBoolean(ctx);
}
void SQLBooleanLiteral::__cleanUp(ThreadContext* ctx){
}
}}}}}

