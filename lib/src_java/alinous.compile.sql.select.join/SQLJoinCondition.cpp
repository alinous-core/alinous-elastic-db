#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
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
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze.scan/VoidScanner.h"
#include "alinous.compile.sql.select.join.scan/JoinedCollectionScanner.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.compile.sql.select.join.scan/CrossJoinScanner.h"
#include "alinous.compile.sql.select.join.scan/ReverseIndexScanner.h"
#include "alinous.compile.sql.select.join.scan/RightindexJoinScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/InnerJoin.h"
#include "alinous.compile.sql.select.join/CrossJoin.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"
#include "alinous.compile.sql.select.join/DomVariableJoinTarget.h"
#include "alinous.compile.sql.select.join/JoinSubQueryTarget.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"
#include "alinous.compile.sql.select.join/NaturalJoin.h"
#include "alinous.compile.sql.select.join/RightJoin.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.select.join/TableJoinTarget.h"
#include "alinous.compile.sql.select.join/WrappedJoinTarget.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.select.join/TableList.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool SQLJoinCondition::__init_done = __init_static_variables();
bool SQLJoinCondition::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLJoinCondition", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLJoinCondition::SQLJoinCondition(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanExpression(ctx), condition(nullptr)
{
}
void SQLJoinCondition::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLJoinCondition::~SQLJoinCondition() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLJoinCondition::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLJoinCondition", L"~SQLJoinCondition");
	__e_obj1.add(this->condition, this);
	condition = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLJoinCondition::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->condition != nullptr && !this->condition->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLJoinCondition::isConstant(ThreadContext* ctx) throw() 
{
	if(this->condition != nullptr && !this->condition->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLJoinCondition::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->condition != nullptr)
	{
		this->condition->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLJoinCondition::getCondition(ThreadContext* ctx) throw() 
{
	return condition;
}
void SQLJoinCondition::setCondition(ISQLExpression* condition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->condition), condition, ISQLExpression);
}
IAlinousVariable* SQLJoinCondition::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* SQLJoinCondition::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool SQLJoinCondition::hasSubExp(ThreadContext* ctx) throw() 
{
	if(this->condition != nullptr)
	{
		this->condition->hasSubExp(ctx);
	}
	return false;
}
bool SQLJoinCondition::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->condition != nullptr)
	{
		this->condition->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLJoinCondition::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->condition != nullptr)
	{
		this->condition->hasTable(table, ctx);
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLJoinCondition::getColumns(ThreadContext* ctx) throw() 
{
	if(this->condition != nullptr)
	{
		this->condition->getColumns(ctx);
	}
	return nullptr;
}
bool SQLJoinCondition::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLJoinCondition::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
	this->condition->collectJoinCondition(list, ctx);
}
bool SQLJoinCondition::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLJoinCondition::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IndexColumnMatchCondition* SQLJoinCondition::getIndexScanPart(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ScanTableColumnIdentifier* SQLJoinCondition::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLJoinCondition::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
bool SQLJoinCondition::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLJoinCondition::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
String* SQLJoinCondition::getAsName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void SQLJoinCondition::setAsName(String* name, ThreadContext* ctx) throw() 
{
}
int SQLJoinCondition::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLJoinCondition;
}
void SQLJoinCondition::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->condition), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLJoinCondition::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLJoinCondition, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->condition == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->condition->writeData(buff, ctx);
	}
}
int SQLJoinCondition::fileSize(ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ConstStr::getCNST_STR_1088(), ctx));
}
void SQLJoinCondition::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ConstStr::getCNST_STR_1088(), ctx));
}
void SQLJoinCondition::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ConstStr::getCNST_STR_1088(), ctx));
}
void SQLJoinCondition::__cleanUp(ThreadContext* ctx){
}
}}}}}

