#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





bool XHtmlAttribute::__init_done = __init_static_variables();
bool XHtmlAttribute::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XHtmlAttribute", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XHtmlAttribute::XHtmlAttribute(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlElement(ctx), isAlinousAttr(false), name(nullptr), value(nullptr)
{
	this->isDynamic = false;
}
void XHtmlAttribute::__construct_impl(ThreadContext* ctx) throw() 
{
	this->isDynamic = false;
}
 XHtmlAttribute::~XHtmlAttribute() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XHtmlAttribute::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XHtmlAttribute", L"~XHtmlAttribute");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractXHtmlElement::__releaseRegerences(true, ctx);
}
bool XHtmlAttribute::isDinamicAll(ThreadContext* ctx) throw() 
{
	if(this->isDynamic)
	{
		return true;
	}
	return this->value->isDynamic;
}
void XHtmlAttribute::serialize(SerializeContext* context, ThreadContext* ctx)
{
	int maxLoop = parts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IHtmlStringPart* part = parts->get(i, ctx);
		if(part->isDynamic)
		{
			context->addProgramBodyPart(part->toString(ctx), ctx);
		}
				else 
		{
			context->addStaticString(part->toString(ctx), ctx);
		}
	}
	if(this->value != nullptr)
	{
		context->addStaticString(ConstStr::getCNST_STR_1079(), ctx);
		this->value->serialize(context, ctx);
	}
}
String* XHtmlAttribute::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->parts != nullptr)
	{
		int maxLoop = parts->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			IHtmlStringPart* part = parts->get(i, ctx);
			buff->append(part->execute(machine, debug, ctx), ctx);
		}
	}
	if(this->value == nullptr)
	{
		return buff->toString(ctx);
	}
	if(this->parts != nullptr)
	{
		buff->append(ConstStr::getCNST_STR_1079(), ctx);
	}
	buff->append(this->value->execute(machine, debug, ctx), ctx);
	return buff->toString(ctx);
}
String* XHtmlAttribute::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void XHtmlAttribute::setName(String* name, ThreadContext* ctx)
{
	__GC_MV(this, &(this->name), name, String);
	GCUtils<ArrayList<IHtmlStringPart> >::mv(this, &(this->parts), InnerStringParser::parse(this->name->toString(ctx), ctx), ctx);
	this->isAlinousAttr = AlinousAttrs::isAlinousAttr(name, ctx);
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
AbstractXHtmlAttributeValue* XHtmlAttribute::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void XHtmlAttribute::setValue(AbstractXHtmlAttributeValue* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, AbstractXHtmlAttributeValue);
	if(value->isDynamic)
	{
		this->isDynamic = true;
	}
}
String* XHtmlAttribute::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->name, ctx);
	if(this->value != nullptr)
	{
		buff->append(ConstStr::getCNST_STR_1079(), ctx)->append(this->value->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
AbstractXHtmlElement::ElementType XHtmlAttribute::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::Attribute;
}
}}}

