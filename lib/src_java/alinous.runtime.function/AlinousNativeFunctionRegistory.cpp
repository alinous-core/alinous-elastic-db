#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.runtime.function/AbstractNativeFunction.h"
#include "alinous.runtime.function.system/SystemPrintLn.h"
#include "alinous.runtime.function/AlinousNativeFunctionRegistory.h"

namespace alinous {namespace runtime {namespace function {





bool AlinousNativeFunctionRegistory::__init_done = __init_static_variables();
bool AlinousNativeFunctionRegistory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousNativeFunctionRegistory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousNativeFunctionRegistory::AlinousNativeFunctionRegistory(ThreadContext* ctx) throw()  : IObject(ctx), nativeFunctions(GCUtils<HashMap<String,AlinousNativeFunctionRegistory::FuncHolder> >::ins(this, (new(ctx) HashMap<String,AlinousNativeFunctionRegistory::FuncHolder>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	addFunction((new(ctx) SystemPrintLn(ctx)), ctx);
}
void AlinousNativeFunctionRegistory::__construct_impl(ThreadContext* ctx) throw() 
{
	addFunction((new(ctx) SystemPrintLn(ctx)), ctx);
}
 AlinousNativeFunctionRegistory::~AlinousNativeFunctionRegistory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousNativeFunctionRegistory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousNativeFunctionRegistory", L"~AlinousNativeFunctionRegistory");
	__e_obj1.add(this->nativeFunctions, this);
	nativeFunctions = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousNativeFunctionRegistory::isPrefix(String* prefix, ThreadContext* ctx) throw() 
{
	return this->nativeFunctions->get(prefix, ctx) != nullptr;
}
IAlinousNativeFunction* AlinousNativeFunctionRegistory::get(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	AlinousNativeFunctionRegistory::FuncHolder* holder = this->nativeFunctions->get(prefix, ctx);
	if(holder == nullptr)
	{
		return nullptr;
	}
	return holder->get(funcName, ctx);
}
void AlinousNativeFunctionRegistory::addFunction(IAlinousNativeFunction* func, ThreadContext* ctx) throw() 
{
	String* prefix = func->getPrefix(ctx);
	AlinousNativeFunctionRegistory::FuncHolder* holder = this->nativeFunctions->get(prefix, ctx);
	if(holder == nullptr)
	{
		holder = (new(ctx) AlinousNativeFunctionRegistory::FuncHolder(ctx));
		this->nativeFunctions->put(prefix, holder, ctx);
	}
	holder->add(func, ctx);
}
void AlinousNativeFunctionRegistory::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace runtime {namespace function {





bool AlinousNativeFunctionRegistory::FuncHolder::__init_done = __init_static_variables();
bool AlinousNativeFunctionRegistory::FuncHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousNativeFunctionRegistory::FuncHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousNativeFunctionRegistory::FuncHolder::FuncHolder(ThreadContext* ctx) throw()  : IObject(ctx), nativeFunctions(GCUtils<HashMap<String,IAlinousNativeFunction> >::ins(this, (new(ctx) HashMap<String,IAlinousNativeFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AlinousNativeFunctionRegistory::FuncHolder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousNativeFunctionRegistory::FuncHolder::~FuncHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousNativeFunctionRegistory::FuncHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FuncHolder", L"~FuncHolder");
	__e_obj1.add(this->nativeFunctions, this);
	nativeFunctions = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousNativeFunctionRegistory::FuncHolder::add(IAlinousNativeFunction* func, ThreadContext* ctx) throw() 
{
	this->nativeFunctions->put(func->getName(ctx), func, ctx);
}
IAlinousNativeFunction* AlinousNativeFunctionRegistory::FuncHolder::get(String* name, ThreadContext* ctx) throw() 
{
	return this->nativeFunctions->get(name, ctx);
}
void AlinousNativeFunctionRegistory::FuncHolder::__cleanUp(ThreadContext* ctx){
}
}}}

