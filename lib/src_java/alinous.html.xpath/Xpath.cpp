#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/AbstractContainerStatement.h"
#include "alinous.html.xpath/XpathOrStatement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/XpathString.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath/NumberValue.h"
#include "alinous.html.xpath/XpathFunctionArgument.h"
#include "alinous.html.xpath/IXpathFunction.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/Xpath2Compare.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/XpathNotStatement.h"
#include "alinous.html.xpath/XpathAndStatement.h"
#include "alinous.html.xpath/XPathParser.h"

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
 Xpath::Xpath(ThreadContext* ctx) throw()  : IObject(ctx), IXpathStatement(ctx), contexts(GCUtils<ArrayList<XpathContext> >::ins(this, (new(ctx) ArrayList<XpathContext>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void Xpath::__construct_impl(ThreadContext* ctx) throw() 
{
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
void Xpath::__cleanUp(ThreadContext* ctx){
}
}}}

