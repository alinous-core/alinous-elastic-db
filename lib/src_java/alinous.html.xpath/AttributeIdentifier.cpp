#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool AttributeIdentifier::__init_done = __init_static_variables();
bool AttributeIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AttributeIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AttributeIdentifier::AttributeIdentifier(String* id, ThreadContext* ctx) throw()  : IObject(ctx), XpathIdentifier(id, ctx)
{
}
void AttributeIdentifier::__construct_impl(String* id, ThreadContext* ctx) throw() 
{
}
 AttributeIdentifier::~AttributeIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AttributeIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	XpathIdentifier::__releaseRegerences(true, ctx);
}
String* AttributeIdentifier::toString(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1309()->clone(ctx)->append(this->id, ctx);
}
}}}

