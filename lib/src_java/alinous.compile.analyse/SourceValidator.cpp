#include "includes.h"


namespace alinous {namespace compile {namespace analyse {





bool SourceValidator::__init_done = __init_static_variables();
bool SourceValidator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SourceValidator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SourceValidator::~SourceValidator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SourceValidator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SourceValidator", L"~SourceValidator");
	__e_obj1.add(this->errors, this);
	errors = nullptr;
	if(!prepare){
		return;
	}
}
bool SourceValidator::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<IStatement*>(element) != 0))
	{
		IStatement* stmt = static_cast<IStatement*>(element);
		stmt->validate(this, ctx);
	}
	return true;
}
void SourceValidator::addError(String* message, IAlinousElement* element, ThreadContext* ctx) throw() 
{
	SourceValidationError* error = (new(ctx) SourceValidationError(ctx));
	error->setType(SourceValidationError::ERROR, ctx);
	error->setMessage(message, ctx);
	error->setSrc(element, ctx);
	this->errors->add(error, ctx);
}
void SourceValidator::addWarning(String* message, IAlinousElement* element, ThreadContext* ctx) throw() 
{
	SourceValidationError* error = (new(ctx) SourceValidationError(ctx));
	error->setType(SourceValidationError::WARNING, ctx);
	error->setMessage(message, ctx);
	error->setSrc(element, ctx);
	this->errors->add(error, ctx);
}
void SourceValidator::addInfo(String* message, IAlinousElement* element, ThreadContext* ctx) throw() 
{
	SourceValidationError* error = (new(ctx) SourceValidationError(ctx));
	error->setType(SourceValidationError::INFO, ctx);
	error->setMessage(message, ctx);
	error->setSrc(element, ctx);
	this->errors->add(error, ctx);
}
ArrayList<SourceValidationError>* SourceValidator::getErrors(ThreadContext* ctx) throw() 
{
	return errors;
}
}}}

