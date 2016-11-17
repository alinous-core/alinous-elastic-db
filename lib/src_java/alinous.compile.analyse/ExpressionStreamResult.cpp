#include "includes.h"


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
}}}

