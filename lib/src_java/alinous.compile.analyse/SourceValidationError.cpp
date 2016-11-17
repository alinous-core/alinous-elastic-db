#include "includes.h"


namespace alinous {namespace compile {namespace analyse {





constexpr const int SourceValidationError::ERROR;
constexpr const int SourceValidationError::WARNING;
constexpr const int SourceValidationError::INFO;
bool SourceValidationError::__init_done = __init_static_variables();
bool SourceValidationError::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SourceValidationError", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SourceValidationError::~SourceValidationError() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SourceValidationError::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SourceValidationError", L"~SourceValidationError");
	__e_obj1.add(this->message, this);
	message = nullptr;
	__e_obj1.add(this->src, this);
	src = nullptr;
	if(!prepare){
		return;
	}
}
int SourceValidationError::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void SourceValidationError::setType(int type, ThreadContext* ctx) throw() 
{
	this->type = type;
}
String* SourceValidationError::getMessage(ThreadContext* ctx) throw() 
{
	return message;
}
void SourceValidationError::setMessage(String* message, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->message), message, String);
}
IAlinousElement* SourceValidationError::getSrc(ThreadContext* ctx) throw() 
{
	return src;
}
void SourceValidationError::setSrc(IAlinousElement* src, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->src), src, IAlinousElement);
}
}}}

