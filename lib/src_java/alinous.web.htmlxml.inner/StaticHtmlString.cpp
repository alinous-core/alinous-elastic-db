#include "include/global.h"


#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.htmlxml.inner/StaticHtmlString.h"

namespace alinous {namespace web {namespace htmlxml {namespace inner {





bool StaticHtmlString::__init_done = __init_static_variables();
bool StaticHtmlString::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StaticHtmlString", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StaticHtmlString::StaticHtmlString(String* data, ThreadContext* ctx) throw()  : IObject(ctx), IHtmlStringPart(ctx), data(nullptr)
{
	__GC_MV(this, &(this->data), data, String);
	this->isDynamic = false;
}
void StaticHtmlString::__construct_impl(String* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->data), data, String);
	this->isDynamic = false;
}
 StaticHtmlString::~StaticHtmlString() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StaticHtmlString::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StaticHtmlString", L"~StaticHtmlString");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
	IHtmlStringPart::__releaseRegerences(true, ctx);
}
String* StaticHtmlString::toString(ThreadContext* ctx) throw() 
{
	return this->data;
}
String* StaticHtmlString::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	return this->data;
}
void StaticHtmlString::__cleanUp(ThreadContext* ctx){
}
}}}}

