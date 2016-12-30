#include "includes.h"


namespace alinous {namespace system {namespace functions {





bool AlinousFunctionManager::__init_done = __init_static_variables();
bool AlinousFunctionManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousFunctionManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousFunctionManager::AlinousFunctionManager(AlinousCore* core, ThreadContext* ctx) throw()  : IObject(ctx), core(nullptr), javaFunctionManager(nullptr), nativeFunctions(nullptr)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->javaFunctionManager), (new(ctx) JavaFunctionManager(this->core, ctx)), JavaFunctionManager);
	__GC_MV(this, &(this->nativeFunctions), (new(ctx) NativeFunctionManager(ctx)), NativeFunctionManager);
}
void AlinousFunctionManager::__construct_impl(AlinousCore* core, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->javaFunctionManager), (new(ctx) JavaFunctionManager(this->core, ctx)), JavaFunctionManager);
	__GC_MV(this, &(this->nativeFunctions), (new(ctx) NativeFunctionManager(ctx)), NativeFunctionManager);
}
 AlinousFunctionManager::~AlinousFunctionManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousFunctionManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousFunctionManager", L"~AlinousFunctionManager");
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->javaFunctionManager, this);
	javaFunctionManager = nullptr;
	__e_obj1.add(this->nativeFunctions, this);
	nativeFunctions = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousFunctionManager::isFunctionPrefix(String* name, ThreadContext* ctx) throw() 
{
	bool bl = this->javaFunctionManager->isFunctionPrefix(name, ctx);
	if(bl)
	{
		return true;
	}
	bl = this->nativeFunctions->isNativeFunctionPrefix(name, ctx);
	if(bl)
	{
		return true;
	}
	return false;
}
bool AlinousFunctionManager::isJavaFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->javaFunctionManager->isJavaFunction(prefix, funcName, ctx);
}
bool AlinousFunctionManager::isNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->nativeFunctions->isNativeFunction(prefix, funcName, ctx);
}
bool AlinousFunctionManager::invokeNativeFunction(IAlinousNativeFunction* func, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->nativeFunctions->invoke(func, arguments, machine, debug, ctx);
}
IAlinousNativeFunction* AlinousFunctionManager::getNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->nativeFunctions->getNativeFunction(prefix, funcName, ctx);
}
bool AlinousFunctionManager::invokeFunction(String* prefix, String* funcName, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(executeJavaConnector(prefix, funcName, arguments, machine, debug, ctx))
	{
		return true;
	}
	if(this->nativeFunctions->invoke(prefix, funcName, arguments, machine, debug, ctx))
	{
		return true;
	}
	return false;
}
AlinousType* AlinousFunctionManager::getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	IAlinousNativeFunction* func = this->nativeFunctions->getNativeFunction(prefix, name, ctx);
	if(func != nullptr)
	{
		return func->getReturnType(ctx);
	}
	return this->javaFunctionManager->getFunctionReturnType(prefix, name, ctx);
}
AlinousCore* AlinousFunctionManager::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
void AlinousFunctionManager::init(ThreadContext* ctx) throw() 
{
	this->javaFunctionManager->init(ctx);
	this->nativeFunctions->init(ctx);
}
void AlinousFunctionManager::dispose(ThreadContext* ctx) throw() 
{
	this->javaFunctionManager->dispose(ctx);
}
bool AlinousFunctionManager::executeJavaConnector(String* prefix, String* funcName, FunctionArguments* expArguments, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* ret = nullptr;
	{
		try
		{
			ArrayList<IDomVariable>* arguments = (new(ctx) ArrayList<IDomVariable>(ctx));
			ArrayList<IExpression>* list = expArguments->arguments;
			int maxLoop = list->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IExpression* exp = list->get(i, ctx);
				IAlinousVariable* val = machine->resolveExpression(exp, debug, ctx);
				arguments->add(val->toDomVariable(ctx), ctx);
			}
			ret = this->javaFunctionManager->invoke(prefix, funcName, arguments, ctx);
			if(ret == nullptr)
			{
				return false;
			}
			machine->setReturnedValue(ret, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1237(), e, ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1237(), e, ctx));
		}
	}
	return true;
}
}}}

