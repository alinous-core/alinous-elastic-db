#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.runtime.function/AlinousNativeFunctionRegistory.h"
#include "alinous.system.functions/NativeFunctionManager.h"

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
 NativeFunctionManager::NativeFunctionManager(ThreadContext* ctx) throw()  : IObject(ctx), nativesRegistory(nullptr)
{
}
void NativeFunctionManager::__construct_impl(ThreadContext* ctx) throw() 
{
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
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1018()->clone(ctx)->append(funcName, ctx)->append(ConstStr::getCNST_STR_1019(), ctx), ctx));
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
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1018()->clone(ctx)->append(func->getName(ctx), ctx)->append(ConstStr::getCNST_STR_1019(), ctx), ctx));
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
void NativeFunctionManager::__cleanUp(ThreadContext* ctx){
}
}}}

