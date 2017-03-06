#include "include/global.h"


#include "alinous.system.utils/FileUtils.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.utils/ConfigFileUtiles.h"
#include "alinous.compile/Token.h"

namespace alinous {namespace system {namespace utils {





bool ConfigFileUtiles::__init_done = __init_static_variables();
bool ConfigFileUtiles::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConfigFileUtiles", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConfigFileUtiles::ConfigFileUtiles(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ConfigFileUtiles::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ConfigFileUtiles::~ConfigFileUtiles() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConfigFileUtiles::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* ConfigFileUtiles::getAttribute(DomDocument* document, DomNode* start, Matcher* matcher, String* xpath, String* name, ThreadContext* ctx)
{
	MatchCandidatesCollection* res = matcher->match(document, start, xpath, ctx);
	if(!res->getCandidatesList(ctx)->isEmpty(ctx))
	{
		DomNode* node = res->getFirstCandidate(ctx)->getCandidateDom(ctx);
		IVariableValue* attr = node->getAttributeValue(name, ctx);
		if(attr != nullptr)
		{
			return attr->toString(ctx);
		}
	}
	return nullptr;
}
String* ConfigFileUtiles::getText(DomDocument* document, DomNode* start, Matcher* matcher, String* xpath, ThreadContext* ctx)
{
	MatchCandidatesCollection* res = matcher->match(document, start, xpath, ctx);
	if(!res->getCandidatesList(ctx)->isEmpty(ctx))
	{
		DomNode* node = res->getFirstCandidate(ctx)->getCandidateDom(ctx);
		return node->getInnerHtml(ctx);
	}
	return nullptr;
}
void ConfigFileUtiles::__cleanUp(ThreadContext* ctx){
}
}}}

