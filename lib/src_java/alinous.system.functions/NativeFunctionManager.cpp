#include "includes.h"


namespace alinous {namespace system {namespace functions {





bool NativeFunctionManager::__init_done = __init_static_variables();
bool NativeFunctionManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NativeFunctionManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NativeFunctionManager::~NativeFunctionManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NativeFunctionManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NativeFunctionManager", L"~NativeFunctionManager");
	__e_obj1.add(this->nativesRegistory, this);
	nativesRegistory = nullptr;
	if(!prepare){
		return;
	}
}
void NativeFunctionManager::init(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->nativesRegistory), (new(ctx) AlinousNativeFunctionRegistory(ctx)), AlinousNativeFunctionRegistory);
}
bool NativeFunctionManager::isNativeFunctionPrefix(String* prefix, ThreadContext* ctx) throw() 
{
	return this->nativesRegistory->isPrefix(prefix, ctx);
}
bool NativeFunctionManager::isNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	IAlinousNativeFunction* func = this->nativesRegistory->get(prefix, funcName, ctx);
	return func != nullptr;
}
IAlinousNativeFunction* NativeFunctionManager::getNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->nativesRegistory->get(prefix, funcName, ctx);
}
bool NativeFunctionManager::invoke(String* prefix, String* funcName, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousNativeFunction* func = this->nativesRegistory->get(prefix, funcName, ctx);
	if(func == nullptr)
	{
		return false;
	}
	ArrayList<AlinousType>* list = func->getArgumentMetadata(ctx);
	int maxLoop = list->size(ctx);
	if(maxLoop != arguments->getArgumentSize(ctx))
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1231()->clone(ctx)->append(funcName, ctx)->append(ConstStr::getCNST_STR_1232(), ctx), ctx));
	}
	ArrayList<IAlinousVariable>* funcArgs = (new(ctx) ArrayList<IAlinousVariable>(ctx));
	ArrayList<IExpression>* actualArgs = arguments->arguments;
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = actualArgs->get(i, ctx);
		IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
		funcArgs->add(val, ctx);
	}
	func->execute(funcArgs, machine, ctx);
	return true;
}
bool NativeFunctionManager::invoke(IAlinousNativeFunction* func, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<AlinousType>* list = func->getArgumentMetadata(ctx);
	int maxLoop = list->size(ctx);
	if(maxLoop != arguments->getArgumentSize(ctx))
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1231()->clone(ctx)->append(func->getName(ctx), ctx)->append(ConstStr::getCNST_STR_1232(), ctx), ctx));
	}
	ArrayList<IAlinousVariable>* funcArgs = (new(ctx) ArrayList<IAlinousVariable>(ctx));
	ArrayList<IExpression>* actualArgs = arguments->arguments;
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = actualArgs->get(i, ctx);
		IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
		funcArgs->add(val, ctx);
	}
	func->execute(funcArgs, machine, ctx);
	return true;
}
}}}

