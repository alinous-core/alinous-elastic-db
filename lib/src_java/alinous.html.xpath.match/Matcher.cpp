#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "java.io/StringReader.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/XpathString.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.parser.xpath/AlinousXpathParserConstants.h"
#include "alinous.parser.xpath/AlinousXpathParserTokenManager.h"
#include "alinous.parser.xpath/AlinousXpathParser.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/ParseException.h"

namespace alinous {namespace html {namespace xpath {namespace match {





bool Matcher::__init_done = __init_static_variables();
bool Matcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Matcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Matcher::Matcher(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void Matcher::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Matcher::~Matcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Matcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
MatchCandidatesCollection* Matcher::match(DomDocument* document, DomNode* start, Xpath* path, ThreadContext* ctx)
{
	MatchCandidatesCollection* collection = (new(ctx) MatchCandidatesCollection(ctx));
	collection->addCandidate((new(ctx) MatchCandidate(start, ctx)), ctx);
	ArrayList<XpathContext>* contexts = path->getContexts(ctx);
	Iterator<XpathContext>* it = contexts->iterator(ctx);
	while(it->hasNext(ctx))
	{
		XpathContext* context = it->next(ctx);
		collection = applyContext(document, collection, context, ctx);
	}
	return collection;
}
MatchCandidatesCollection* Matcher::match(DomDocument* document, DomNode* start, String* xpath, ThreadContext* ctx)
{
	StringReader* reader = (new(ctx) StringReader(xpath, ctx));
	AlinousXpathParser* parser = (new(ctx) AlinousXpathParser(reader, ctx));
	Xpath* path = nullptr;
	path = parser->xpath(ctx);
	return match(document, start, path, ctx);
}
MatchCandidatesCollection* Matcher::applyContext(DomDocument* document, MatchCandidatesCollection* collection, XpathContext* context, ThreadContext* ctx)
{
	MatchCandidatesCollection* destCollection = (new(ctx) MatchCandidatesCollection(ctx));
	Iterator<MatchCandidate>* it = collection->getCandidatesList(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* candidate = it->next(ctx);
		applyContext4Candidate(document, candidate, context, destCollection, ctx);
	}
	IXpathStatement* indexStmt = context->getIndex(ctx);
	return destCollection->filterByIndex(indexStmt, document, ctx);
}
void Matcher::applyContext4Candidate(DomDocument* document, MatchCandidate* candidate, XpathContext* context, MatchCandidatesCollection* destCollection, ThreadContext* ctx)
{
	MatchCursor* cursor = candidate->getCursor(ctx);
	context->setupCurserLocationPolicy(cursor, ctx);
	DomNode* node = cursor->getNext(ctx);
	while(node != nullptr)
	{
		if(!checkNodeNameOrAttribute(node, context, ctx))
		{
			node = cursor->getNext(ctx);
			continue;
		}
		if(!checkFilter(document, node, context, ctx))
		{
			node = cursor->getNext(ctx);
			continue;
		}
		destCollection->addCandidate((new(ctx) MatchCandidate(node, ctx)), ctx);
		node = cursor->getNext(ctx);
	}
}
bool Matcher::checkNodeNameOrAttribute(DomNode* node, XpathContext* context, ThreadContext* ctx) throw() 
{
	if(node->isXmlHeader(ctx))
	{
		return false;
	}
	return context->matchPath(node, ctx);
}
bool Matcher::checkFilter(DomDocument* document, DomNode* node, XpathContext* context, ThreadContext* ctx)
{
	XpathFilter* filter = context->getConditionFilter(ctx);
	if(filter == nullptr)
	{
		return true;
	}
	return filter->getCondition(ctx)->getBooleanValue(document, node, ctx);
}
void Matcher::__cleanUp(ThreadContext* ctx){
}
}}}}

