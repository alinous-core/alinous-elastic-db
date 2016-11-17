#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool NumberValue::__init_done = __init_static_variables();
bool NumberValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NumberValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NumberValue::NumberValue(int v, ThreadContext* ctx) throw()  : IObject(ctx), IVariableValue(ctx), value(0)
{
	this->value = v;
}
void NumberValue::__construct_impl(int v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 NumberValue::~NumberValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NumberValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NumberValue", L"~NumberValue");
	if(!prepare){
		return;
	}
}
int NumberValue::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
String* NumberValue::toString(ThreadContext* ctx) throw() 
{
	return Integer::toString(value, ctx);
}
}}}

