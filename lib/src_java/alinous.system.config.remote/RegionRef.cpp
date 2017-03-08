#include "include/global.h"


#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RegionRef.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool RegionRef::__init_done = __init_static_variables();
bool RegionRef::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionRef", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionRef::RegionRef(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), name(nullptr), url(nullptr)
{
}
void RegionRef::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionRef::~RegionRef() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionRef::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionRef", L"~RegionRef");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->url, this);
	url = nullptr;
	if(!prepare){
		return;
	}
}
String* RegionRef::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void RegionRef::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
String* RegionRef::getUrl(ThreadContext* ctx) throw() 
{
	return url;
}
void RegionRef::setUrl(String* url, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), url, String);
}
void RegionRef::__cleanUp(ThreadContext* ctx){
}
}}}}

