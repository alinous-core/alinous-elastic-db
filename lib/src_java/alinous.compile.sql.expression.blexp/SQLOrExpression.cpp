#include "includes.h"


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
 SQLOrExpression::SQLOrExpression(ArrayList<ISQLExpression>* result, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanCollectionExpression(result, ConstStr::getCNST_STR_1071(), ctx)
{
}
void SQLOrExpression::__construct_impl(ArrayList<ISQLExpression>* result, ThreadContext* ctx) throw() 
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
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
int SQLOrExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLOrExpression;
}
void SQLOrExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void SQLOrExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLOrExpression, ctx);
	__writeData(buff, ctx);
}
void SQLOrExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLOrExpression, ctx);
	__toFileEntry(builder, ctx);
}
}}}}}

