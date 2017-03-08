#include "include/global.h"


#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpParameter.h"

namespace alinous {namespace server {namespace http {namespace params {





bool HttpParameter::__init_done = __init_static_variables();
bool HttpParameter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpParameter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpParameter::HttpParameter(String* name, String* value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractHttpParameter(ctx), name(nullptr), value(nullptr)
{
	this->paramType = AbstractHttpParameter::TYPE_NORMAL_PARAM;
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->value), value, String);
}
void HttpParameter::__construct_impl(String* name, String* value, ThreadContext* ctx) throw() 
{
	this->paramType = AbstractHttpParameter::TYPE_NORMAL_PARAM;
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->value), value, String);
}
 HttpParameter::~HttpParameter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpParameter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HttpParameter", L"~HttpParameter");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractHttpParameter::__releaseRegerences(true, ctx);
}
String* HttpParameter::getName(ThreadContext* ctx) throw() 
{
	return this->name;
}
String* HttpParameter::getStringValue(ThreadContext* ctx) throw() 
{
	return this->value;
}
void HttpParameter::__cleanUp(ThreadContext* ctx){
}
}}}}

