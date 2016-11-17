#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace result {





bool FunctionResult::__init_done = __init_static_variables();
bool FunctionResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionResult::FunctionResult(SQLExpressionStream* sqlexp, ThreadContext* ctx) throw()  : IObject(ctx), AbstructSelectResult(ctx), sqlexp(nullptr)
{
	__GC_MV(this, &(this->sqlexp), sqlexp, SQLExpressionStream);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), sqlexp->toString(ctx), String);
	}
}
void FunctionResult::__construct_impl(SQLExpressionStream* sqlexp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->sqlexp), sqlexp, SQLExpressionStream);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), sqlexp->toString(ctx), String);
	}
}
 FunctionResult::~FunctionResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionResult", L"~FunctionResult");
	__e_obj1.add(this->sqlexp, this);
	sqlexp = nullptr;
	if(!prepare){
		return;
	}
	AbstructSelectResult::__releaseRegerences(true, ctx);
}
void FunctionResult::fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* value = this->sqlexp->resolveSQLExpression(srecord, machine, debug, ctx);
	domVariable->setProperty(this->outputName, (new(ctx) DomVariable(value, ctx)), ctx);
}
int FunctionResult::getType(ThreadContext* ctx) throw() 
{
	return AbstructSelectResult::FUNCTION;
}
}}}}

