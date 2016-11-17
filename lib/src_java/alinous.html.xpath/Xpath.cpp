#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool Xpath::__init_done = __init_static_variables();
bool Xpath::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Xpath", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Xpath::~Xpath() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Xpath::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Xpath", L"~Xpath");
	__e_obj1.add(this->contexts, this);
	contexts = nullptr;
	if(!prepare){
		return;
	}
}
void Xpath::addContext(XpathContext* context, ThreadContext* ctx) throw() 
{
	context->setXpath(this, ctx);
	this->contexts->add(context, ctx);
}
ArrayList<XpathContext>* Xpath::getContexts(ThreadContext* ctx) throw() 
{
	return contexts;
}
IVariableValue* Xpath::getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	Matcher* matcher = (new(ctx) Matcher(ctx));
	MatchCandidatesCollection* result = matcher->match(document, currentNode, this, ctx);
	MatchCandidate* candidate = result->getFirstCandidate(ctx);
	if(candidate == nullptr)
	{
		return nullptr;
	}
	DomNode* node = candidate->getCandidateDom(ctx);
	XpathContext* lastContext = this->contexts->get(this->contexts->size(ctx) - 1, ctx);
	XpathContext::ScanTarget target = lastContext->getScanTarget(ctx);
	switch(target) {
	case XpathContext::ScanTarget::attribute:
		{
		String* attrName = lastContext->getAttributeName(ctx);
		return node->getAttributeValue(attrName, ctx);
		}
	default:
		break ;
	}
	return nullptr;
}
String* Xpath::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	Iterator<XpathContext>* it = this->contexts->iterator(ctx);
	while(it->hasNext(ctx))
	{
		XpathContext* context = it->next(ctx);
		buffer->append(context->toString(ctx), ctx);
	}
	return buffer->toString(ctx);
}
}}}

