#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





bool XMLTagBase::__init_done = __init_static_variables();
bool XMLTagBase::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XMLTagBase", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XMLTagBase::XMLTagBase(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlElement(ctx), attributes(GCUtils<ArrayList<XHtmlAttribute> >::ins(this, (new(ctx) ArrayList<XHtmlAttribute>(ctx)), ctx, __FILEW__, __LINE__, L"")), innerElements(GCUtils<ArrayList<AbstractXHtmlElement> >::ins(this, (new(ctx) ArrayList<AbstractXHtmlElement>(ctx)), ctx, __FILEW__, __LINE__, L"")), tagName(nullptr), isDynamicTagName(0)
{
	this->isDynamic = false;
}
void XMLTagBase::__construct_impl(ThreadContext* ctx) throw() 
{
	this->isDynamic = false;
}
 XMLTagBase::~XMLTagBase() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XMLTagBase::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XMLTagBase", L"~XMLTagBase");
	__e_obj1.add(this->attributes, this);
	attributes = nullptr;
	__e_obj1.add(this->innerElements, this);
	innerElements = nullptr;
	__e_obj1.add(this->tagName, this);
	tagName = nullptr;
	if(!prepare){
		return;
	}
	AbstractXHtmlElement::__releaseRegerences(true, ctx);
}
bool XMLTagBase::isDinamicAll(ThreadContext* ctx) throw() 
{
	if(this->isDynamic)
	{
		return true;
	}
	ArrayList<XHtmlAttribute>* attributes = this->attributes;
	int maxLoop = attributes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		XHtmlAttribute* attr = attributes->get(i, ctx);
		if(attr->isDynamic)
		{
			return true;
		}
	}
	ArrayList<AbstractXHtmlElement>* innerElements = this->innerElements;
	maxLoop = innerElements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* elm = innerElements->get(i, ctx);
		if(elm->isDinamicAll(ctx))
		{
			return true;
		}
	}
	return false;
}
void XMLTagBase::serialize(SerializeContext* context, ThreadContext* ctx)
{
	ArrayList<XHtmlAttribute>* attributes = this->attributes;
	if(!isDinamicAll(ctx))
	{
		context->addStaticString(toString(ctx), ctx);
		return;
	}
	if(this->isDynamic)
	{
		context->addDynamicTag(this, ctx);
		return;
	}
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(!this->isDynamicTagName)
	{
		buff->append(ConstStr::getCNST_STR_1010(), ctx)->append(this->tagName, ctx);
		context->addStaticString(buff->toString(ctx), ctx);
		buff->setLength(0, ctx);
	}
		else 
	{
		context->addParts(this->parts, ctx);
	}
	int maxLoop = attributes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		XHtmlAttribute* attr = attributes->get(i, ctx);
		if(attr->isDynamic)
		{
			context->addStaticString(ConstStr::getCNST_STR_380(), ctx);
			attr->serialize(context, ctx);
		}
				else 
		{
			buff->append(ConstStr::getCNST_STR_380(), ctx)->append(attr->toString(ctx), ctx);
			context->addStaticString(buff->toString(ctx), ctx);
			buff->setLength(0, ctx);
		}
	}
	if(isSingleEnd(ctx))
	{
		context->addStaticString(ConstStr::getCNST_STR_1814(), ctx);
		return;
	}
		else 
	{
		context->addStaticString(ConstStr::getCNST_STR_82(), ctx);
	}
	ArrayList<AbstractXHtmlElement>* innerElements = this->innerElements;
	maxLoop = innerElements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* element = innerElements->get(i, ctx);
		element->serialize(context, ctx);
	}
	if(!this->isDynamicTagName)
	{
		buff->append(ConstStr::getCNST_STR_1750(), ctx)->append(this->tagName, ctx)->append(ConstStr::getCNST_STR_82(), ctx);
		context->addStaticString(buff->toString(ctx), ctx);
		buff->setLength(0, ctx);
	}
		else 
	{
		context->addStaticString(ConstStr::getCNST_STR_1750(), ctx);
		context->addParts(this->parts, ctx);
		context->addStaticString(ConstStr::getCNST_STR_82(), ctx);
	}
}
String* XMLTagBase::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void XMLTagBase::addInnerElement(AbstractXHtmlElement* element, ThreadContext* ctx) throw() 
{
	this->innerElements->add(element, ctx);
}
ArrayList<AbstractXHtmlElement>* XMLTagBase::getInnerElements(ThreadContext* ctx) throw() 
{
	return innerElements;
}
void XMLTagBase::addAttribute(XHtmlAttribute* attr, ThreadContext* ctx) throw() 
{
	this->isDynamic = AlinousAttrs::isAlinousAttr(attr->getName(ctx), ctx) || attr->isDynamic;
	this->attributes->add(attr, ctx);
}
ArrayList<XHtmlAttribute>* XMLTagBase::getAttributes(ThreadContext* ctx) throw() 
{
	return attributes;
}
String* XMLTagBase::getTagName(ThreadContext* ctx) throw() 
{
	return tagName;
}
void XMLTagBase::setTagName(String* tagName, ThreadContext* ctx)
{
	__GC_MV(this, &(this->tagName), tagName, String);
	GCUtils<ArrayList<IHtmlStringPart> >::mv(this, &(this->parts), InnerStringParser::parse(tagName, ctx), ctx);
	int maxLoop = this->parts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IHtmlStringPart* part = this->parts->get(i, ctx);
		if(part->isDynamic)
		{
			this->isDynamicTagName = true;
			return;
		}
	}
}
String* XMLTagBase::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_1010(), ctx)->append(this->tagName, ctx);
	int maxLoop = this->attributes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		XHtmlAttribute* attr = this->attributes->get(i, ctx);
		buff->append(ConstStr::getCNST_STR_380(), ctx)->append(attr->toString(ctx), ctx);
	}
	if(this->innerElements->isEmpty(ctx))
	{
		buff->append(ConstStr::getCNST_STR_1749(), ctx);
		return buff->toString(ctx);
	}
	buff->append(ConstStr::getCNST_STR_82(), ctx);
	maxLoop = this->innerElements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* innerObject = this->innerElements->get(i, ctx);
		buff->append(innerObject->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_1750(), ctx)->append(this->tagName, ctx)->append(ConstStr::getCNST_STR_82(), ctx);
	return buff->toString(ctx);
}
AbstractXHtmlElement::ElementType XMLTagBase::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::Tag;
}
bool XMLTagBase::isSingleEnd(ThreadContext* ctx) throw() 
{
	return this->innerElements->isEmpty(ctx);
}
}}}

