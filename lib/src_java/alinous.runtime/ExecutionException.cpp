#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.runtime/ModuleNotFoundException.h"
#include "alinous.runtime/CompileErrorException.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime/ExecutionException.h"

namespace alinous {namespace runtime {





constexpr const long long ExecutionException::serialVersionUID;
bool ExecutionException::__init_done = __init_static_variables();
bool ExecutionException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExecutionException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExecutionException::ExecutionException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, ctx)
{
}
void ExecutionException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 ExecutionException::ExecutionException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, e, ctx)
{
}
void ExecutionException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 ExecutionException::ExecutionException(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, element, ctx)
{
}
void ExecutionException::__construct_impl(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() 
{
}
 ExecutionException::ExecutionException(Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(e, ctx)
{
}
void ExecutionException::__construct_impl(Throwable* e, ThreadContext* ctx) throw() 
{
}
 ExecutionException::~ExecutionException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExecutionException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
void ExecutionException::__cleanUp(ThreadContext* ctx){
}
}}

