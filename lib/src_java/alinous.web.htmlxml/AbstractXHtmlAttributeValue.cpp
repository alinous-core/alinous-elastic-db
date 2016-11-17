#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





bool AbstractXHtmlAttributeValue::__init_done = __init_static_variables();
bool AbstractXHtmlAttributeValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractXHtmlAttributeValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractXHtmlAttributeValue::~AbstractXHtmlAttributeValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractXHtmlAttributeValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractXHtmlAttributeValue", L"~AbstractXHtmlAttributeValue");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractXHtmlElement::__releaseRegerences(true, ctx);
}
String* AbstractXHtmlAttributeValue::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void AbstractXHtmlAttributeValue::setValue(String* value, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), value, String);
	GCUtils<ArrayList<IHtmlStringPart> >::mv(this, &(this->parts), InnerStringParser::parse(this->value, ctx), ctx);
	this->isDynamic = false;
	int maxLoop = this->parts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IHtmlStringPart* part = this->parts->get(i, ctx);
		if(part->isDynamic)
		{
			this->isDynamic = true;
			return;
		}
	}
}
}}}

