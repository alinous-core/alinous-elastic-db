#include "include/global.h"


#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server.webmodule/AbstractWebModule.h"

namespace alinous {namespace server {namespace webmodule {





constexpr const int AbstractWebModule::DYNAMIC_MODULE;
constexpr const int AbstractWebModule::BINARY_MODULE;
constexpr const int AbstractWebModule::STATIC_HTML;
constexpr const int AbstractWebModule::DIRECT_MODULE;
bool AbstractWebModule::__init_done = __init_static_variables();
bool AbstractWebModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractWebModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractWebModule::AbstractWebModule(long long timeStamp, ThreadContext* ctx) throw()  : IObject(ctx), moduleType(0), path(nullptr), timeStamp(0)
{
	this->timeStamp = timeStamp;
}
void AbstractWebModule::__construct_impl(long long timeStamp, ThreadContext* ctx) throw() 
{
	this->timeStamp = timeStamp;
}
 AbstractWebModule::~AbstractWebModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractWebModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractWebModule", L"~AbstractWebModule");
	__e_obj1.add(this->path, this);
	path = nullptr;
	if(!prepare){
		return;
	}
}
int AbstractWebModule::getHashKey(ThreadContext* ctx) throw() 
{
	return this->path->hashCode(ctx);
}
void AbstractWebModule::__cleanUp(ThreadContext* ctx){
}
}}}

