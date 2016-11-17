#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {namespace module {





constexpr const int AbstractSerializedHtmlPart::TYPE_DYNAMIC_BODY;
constexpr const int AbstractSerializedHtmlPart::TYPE_DYNAMIC_TAG;
constexpr const int AbstractSerializedHtmlPart::TYPE_STATIC_PART;
bool AbstractSerializedHtmlPart::__init_done = __init_static_variables();
bool AbstractSerializedHtmlPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSerializedHtmlPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSerializedHtmlPart::~AbstractSerializedHtmlPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSerializedHtmlPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSerializedHtmlPart", L"~AbstractSerializedHtmlPart");
	if(!prepare){
		return;
	}
}
}}}}

