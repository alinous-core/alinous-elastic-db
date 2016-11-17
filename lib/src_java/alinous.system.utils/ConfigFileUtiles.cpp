#include "includes.h"


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
}}}

