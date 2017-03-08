#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"

namespace alinous {namespace compile {namespace analyse {





bool ExpressionStreamResult::__init_done = __init_static_variables();
bool ExpressionStreamResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpressionStreamResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpressionStreamResult::ExpressionStreamResult(ThreadContext* ctx) throw()  : IObject(ctx), domPath(nullptr), type(nullptr), functionPrefix(nullptr), staticMember(0), maxCount(0), count(0)
{
}
void ExpressionStreamResult::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ExpressionStreamResult::~ExpressionStreamResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpressionStreamResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpressionStreamResult", L"~ExpressionStreamResult");
	__e_obj1.add(this->domPath, this);
	domPath = nullptr;
	__e_obj1.add(this->type, this);
	type = nullptr;
	__e_obj1.add(this->functionPrefix, this);
	functionPrefix = nullptr;
	if(!prepare){
		return;
	}
}
void ExpressionStreamResult::clear(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domPath), nullptr, DomVariableDescriptor);
	__GC_MV(this, &(this->type), nullptr, AlinousType);
	__GC_MV(this, &(this->functionPrefix), nullptr, String);
	this->staticMember = false;
}
bool ExpressionStreamResult::isLastSegment(ThreadContext* ctx) throw() 
{
	return this->maxCount == this->count;
}
void ExpressionStreamResult::setMaxCount(int maxCount, ThreadContext* ctx) throw() 
{
	this->maxCount = maxCount - 1;
}
void ExpressionStreamResult::setCount(int count, ThreadContext* ctx) throw() 
{
	this->count = count;
}
DomVariableDescriptor* ExpressionStreamResult::getDomPath(ThreadContext* ctx) throw() 
{
	return domPath;
}
void ExpressionStreamResult::setDomPath(DomVariableDescriptor* domPath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domPath), domPath, DomVariableDescriptor);
}
AlinousType* ExpressionStreamResult::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void ExpressionStreamResult::setType(AlinousType* type, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->type), type, AlinousType);
}
String* ExpressionStreamResult::getFunctionPrefix(ThreadContext* ctx) throw() 
{
	return functionPrefix;
}
void ExpressionStreamResult::setFunctionPrefix(String* functionPrefix, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->functionPrefix), functionPrefix, String);
}
bool ExpressionStreamResult::isStaticMember(ThreadContext* ctx) throw() 
{
	return staticMember;
}
void ExpressionStreamResult::setStaticMember(bool staticMethod, ThreadContext* ctx) throw() 
{
	this->staticMember = staticMethod;
}
void ExpressionStreamResult::__cleanUp(ThreadContext* ctx){
}
}}}

