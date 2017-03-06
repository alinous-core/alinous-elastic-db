#include "include/global.h"


#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpUploadParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/ParamFactory.h"

namespace alinous {namespace server {namespace http {namespace params {





bool HttpUploadParameter::__init_done = __init_static_variables();
bool HttpUploadParameter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpUploadParameter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpUploadParameter::HttpUploadParameter(String* name, ThreadContext* ctx) throw()  : IObject(ctx), AbstractHttpParameter(ctx), name(nullptr)
{
	this->paramType = AbstractHttpParameter::TYPE_FILE_PARAM;
	__GC_MV(this, &(this->name), name, String);
}
void HttpUploadParameter::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
	this->paramType = AbstractHttpParameter::TYPE_FILE_PARAM;
	__GC_MV(this, &(this->name), name, String);
}
 HttpUploadParameter::~HttpUploadParameter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpUploadParameter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HttpUploadParameter", L"~HttpUploadParameter");
	__e_obj1.add(this->name, this);
	name = nullptr;
	if(!prepare){
		return;
	}
	AbstractHttpParameter::__releaseRegerences(true, ctx);
}
String* HttpUploadParameter::getName(ThreadContext* ctx) throw() 
{
	return this->name;
}
String* HttpUploadParameter::getStringValue(ThreadContext* ctx) throw() 
{
	return this->name;
}
void HttpUploadParameter::__cleanUp(ThreadContext* ctx){
}
}}}}

