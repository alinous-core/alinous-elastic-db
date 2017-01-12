#include "includes.h"


namespace alinous {namespace compile {namespace analyse {





bool SrcAnalyseContext::__init_done = __init_static_variables();
bool SrcAnalyseContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SrcAnalyseContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SrcAnalyseContext::SrcAnalyseContext(AlinousModule* module, AlinousFunctionManager* functionManager, SQLFunctionManager* sqlFunctionManager, ThreadContext* ctx) throw()  : IObject(ctx), sqlFunctionManager(nullptr), variableDeclares(GCUtils<Stack<VariableDeclareHolder> >::ins(this, (new(ctx) Stack<VariableDeclareHolder>(ctx)), ctx, __FILEW__, __LINE__, L"")), classDeclareHolder(__GC_INS(this, (new(ctx) ClassDeclareHolder(ctx)), ClassDeclareHolder)), sourceValidator(nullptr), module(nullptr), functionManager(nullptr), expStreamStack(GCUtils<Stack<ExpressionStreamResult> >::ins(this, (new(ctx) Stack<ExpressionStreamResult>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	__GC_MV(this, &(this->sourceValidator), (new(ctx) SourceValidator(ctx)), SourceValidator);
	__GC_MV(this, &(this->functionManager), functionManager, AlinousFunctionManager);
	__GC_MV(this, &(this->sqlFunctionManager), sqlFunctionManager, SQLFunctionManager);
}
void SrcAnalyseContext::__construct_impl(AlinousModule* module, AlinousFunctionManager* functionManager, SQLFunctionManager* sqlFunctionManager, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	__GC_MV(this, &(this->sourceValidator), (new(ctx) SourceValidator(ctx)), SourceValidator);
	__GC_MV(this, &(this->functionManager), functionManager, AlinousFunctionManager);
	__GC_MV(this, &(this->sqlFunctionManager), sqlFunctionManager, SQLFunctionManager);
}
 SrcAnalyseContext::~SrcAnalyseContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SrcAnalyseContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SrcAnalyseContext", L"~SrcAnalyseContext");
	__e_obj1.add(this->sqlFunctionManager, this);
	sqlFunctionManager = nullptr;
	__e_obj1.add(this->variableDeclares, this);
	variableDeclares = nullptr;
	__e_obj1.add(this->classDeclareHolder, this);
	classDeclareHolder = nullptr;
	__e_obj1.add(this->sourceValidator, this);
	sourceValidator = nullptr;
	__e_obj1.add(this->module, this);
	module = nullptr;
	__e_obj1.add(this->functionManager, this);
	functionManager = nullptr;
	__e_obj1.add(this->expStreamStack, this);
	expStreamStack = nullptr;
	if(!prepare){
		return;
	}
}
AlinousType* SrcAnalyseContext::getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	AlinousType* type = this->functionManager->getFunctionReturnType(prefix, name, ctx);
	if(type != nullptr)
	{
		return type;
	}
	type = this->module->getFunctionReturnType(prefix, name, ctx);
	if(type != nullptr)
	{
		return type;
	}
	return nullptr;
}
IAlinousNativeFunction* SrcAnalyseContext::getNativeFuncion(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	return this->functionManager->getNativeFunction(prefix, name, ctx);
}
bool SrcAnalyseContext::isJavaFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->functionManager->isJavaFunction(prefix, funcName, ctx);
}
bool SrcAnalyseContext::isNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->functionManager->isNativeFunction(prefix, funcName, ctx);
}
bool SrcAnalyseContext::isSourceFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(prefix, ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(funcName, ctx);
	AlinousFunction* func = this->module->findFunction(buff->toString(ctx), ctx);
	return func != nullptr;
}
AlinousFunction* SrcAnalyseContext::getSourceFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(prefix, ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(funcName, ctx);
	return this->module->findFunction(buff->toString(ctx), ctx);
}
bool SrcAnalyseContext::isFunctionPrefix(String* name, ThreadContext* ctx) throw() 
{
	bool bl = this->functionManager->isFunctionPrefix(name, ctx);
	if(bl)
	{
		return true;
	}
	bl = this->module->isfunctionPrefix(name, ctx);
	if(bl)
	{
		return true;
	}
	return false;
}
ExpressionStreamResult* SrcAnalyseContext::getExpressionStreamResult(ThreadContext* ctx) throw() 
{
	return this->expStreamStack->peek(ctx);
}
void SrcAnalyseContext::newExpressionStream(ThreadContext* ctx) throw() 
{
	ExpressionStreamResult* result = (new(ctx) ExpressionStreamResult(ctx));
	this->expStreamStack->push(result, ctx);
}
ExpressionStreamResult* SrcAnalyseContext::endExpressionStream(ThreadContext* ctx) throw() 
{
	return this->expStreamStack->pop(ctx);
}
AlinousClass* SrcAnalyseContext::findClassDeclare(AlinousName* className, ThreadContext* ctx) throw() 
{
	return this->classDeclareHolder->fincClassDeclare(className, this->module->getPackageName(ctx), ctx);
}
void SrcAnalyseContext::addClassDeclare(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	this->classDeclareHolder->addClassDeclare(clazz, ctx);
}
void SrcAnalyseContext::newStack(ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* holder = (new(ctx) VariableDeclareHolder(ctx));
	holder->newSubStack(ctx);
	variableDeclares->push(holder, ctx);
}
void SrcAnalyseContext::endStack(ThreadContext* ctx) throw() 
{
	this->variableDeclares->pop(ctx);
}
VariableDeclareHolder* SrcAnalyseContext::getCurrentStack(ThreadContext* ctx) throw() 
{
	return this->variableDeclares->peek(ctx);
}
SourceValidator* SrcAnalyseContext::getSourceValidator(ThreadContext* ctx) throw() 
{
	return sourceValidator;
}
}}}

