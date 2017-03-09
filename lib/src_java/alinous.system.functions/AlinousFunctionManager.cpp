#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
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
#include "alinous.system.functions/NativeFunctionManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"

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
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1020(), e, ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1020(), e, ctx));
		}
	}
	return true;
}
void AlinousFunctionManager::__cleanUp(ThreadContext* ctx){
}
}}}

