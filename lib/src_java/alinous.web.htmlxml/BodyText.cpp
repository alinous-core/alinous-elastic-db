#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





bool BodyText::__init_done = __init_static_variables();
bool BodyText::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BodyText", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BodyText::BodyText(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlElement(ctx), body(nullptr)
{
	__GC_MV(this, &(this->body), (new(ctx) StringBuffer(ctx)), StringBuffer);
}
void BodyText::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->body), (new(ctx) StringBuffer(ctx)), StringBuffer);
}
 BodyText::~BodyText() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BodyText::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BodyText", L"~BodyText");
	__e_obj1.add(this->body, this);
	body = nullptr;
	if(!prepare){
		return;
	}
	AbstractXHtmlElement::__releaseRegerences(true, ctx);
}
bool BodyText::isDinamicAll(ThreadContext* ctx) throw() 
{
	return this->isDynamic;
}
void BodyText::serialize(SerializeContext* context, ThreadContext* ctx)
{
	ArrayList<IHtmlStringPart>* parts = this->parts;
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
}
String* BodyText::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	ArrayList<IHtmlStringPart>* parts = this->parts;
	int maxLoop = parts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IHtmlStringPart* part = parts->get(i, ctx);
		String* code = part->execute(machine, debug, ctx);
		buff->append(code, ctx);
	}
	return buff->toString(ctx);
}
void BodyText::addString(Token* token, ThreadContext* ctx) throw() 
{
	this->body->append(token->image, ctx);
	this->endLine = token->endLine;
	this->_endPosition = token->endColumn;
}
void BodyText::finishAdd(ThreadContext* ctx)
{
	GCUtils<ArrayList<IHtmlStringPart> >::mv(this, &(this->parts), InnerStringParser::parse(this->body->toString(ctx), ctx), ctx);
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
String* BodyText::getBody(ThreadContext* ctx) throw() 
{
	return body->toString(ctx);
}
String* BodyText::toString(ThreadContext* ctx) throw() 
{
	return this->body->toString(ctx);
}
AbstractXHtmlElement::ElementType BodyText::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::BodyText;
}
}}}

