#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool StringValue::__init_done = __init_static_variables();
bool StringValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringValue::StringValue(String* v, ThreadContext* ctx) throw()  : IObject(ctx), IVariableValue(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), v, String);
}
void StringValue::__construct_impl(String* v, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), v, String);
}
 StringValue::~StringValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringValue", L"~StringValue");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
String* StringValue::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
String* StringValue::toString(ThreadContext* ctx) throw() 
{
	return this->value;
}
}}}

