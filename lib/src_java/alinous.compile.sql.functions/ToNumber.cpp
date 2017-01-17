#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace functions {





bool ToNumber::__init_done = __init_static_variables();
bool ToNumber::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ToNumber", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ToNumber::~ToNumber() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ToNumber::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* ToNumber::getName(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1074();
}
VariantValue* ToNumber::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, FunctionArguments* args, bool debug, ThreadContext* ctx)
{
	ArrayList<IExpression>* arglist = args->arguments;
	int maxLoop = arglist->size(ctx);
	if(maxLoop < 1)
	{
		throw (new(ctx) AlinousException(ctx));
	}
	IExpression* exp = arglist->get(0, ctx);
	VariantValue* value = nullptr;
	if(!exp->isSQLExp(ctx))
	{
		value = static_cast<VariantValue*>(exp->resolveExpression(machine, debug, ctx));
	}
		else 
	{
		ISQLExpression* sqlExp = static_cast<ISQLExpression*>(exp);
		value = sqlExp->resolveSQLExpression(record, machine, debug, ctx);
	}
	return (new(ctx) VariantValue(value->getInt(ctx), ctx));
}
}}}}

