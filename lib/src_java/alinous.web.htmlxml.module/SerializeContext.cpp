#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {namespace module {





bool SerializeContext::__init_done = __init_static_variables();
bool SerializeContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SerializeContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SerializeContext::~SerializeContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SerializeContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SerializeContext", L"~SerializeContext");
	__e_obj1.add(this->stack, this);
	stack = nullptr;
	if(!prepare){
		return;
	}
}
void SerializeContext::addDynamicTag(XMLTagBase* tagbase, ThreadContext* ctx)
{
	this->stack->push((new(ctx) DynamicTag(tagbase, ctx)), ctx);
}
void SerializeContext::addParts(ArrayList<IHtmlStringPart>* parts, ThreadContext* ctx)
{
	int maxLoop = parts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IHtmlStringPart* part = parts->get(i, ctx);
		if(part->isDynamic)
		{
			addProgramBodyPart(part->toString(ctx), ctx);
		}
				else 
		{
			addStaticString(part->toString(ctx), ctx);
		}
	}
}
void SerializeContext::addStaticString(String* str, ThreadContext* ctx) throw() 
{
	if(this->stack->isEmpty(ctx) || this->stack->peek(ctx)->type != AbstractSerializedHtmlPart::TYPE_STATIC_PART)
	{
		this->stack->push((new(ctx) StaticHtmlPart(ctx)), ctx);
	}
	StaticHtmlPart* staticPart = static_cast<StaticHtmlPart*>(this->stack->peek(ctx));
	staticPart->add(str, ctx);
}
void SerializeContext::addProgramBodyPart(String* htmlCode, ThreadContext* ctx)
{
	this->stack->push((new(ctx) DynamicBodyPart(htmlCode, ctx)), ctx);
}
}}}}

