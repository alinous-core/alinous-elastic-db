#include "includes.h"


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
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
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
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->condition), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLJoinCondition::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
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
}}}}}

