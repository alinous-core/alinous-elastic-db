#include "includes.h"


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
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
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
}}}}}

