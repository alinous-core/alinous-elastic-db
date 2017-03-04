#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath.match/Matcher.h"

namespace alinous {namespace html {namespace xpath {namespace match {





bool MatchCandidate::__init_done = __init_static_variables();
bool MatchCandidate::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MatchCandidate", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MatchCandidate::MatchCandidate(DomNode* candidateDom, ThreadContext* ctx) throw()  : IObject(ctx), candidateDom(nullptr)
{
	__GC_MV(this, &(this->candidateDom), candidateDom, DomNode);
}
void MatchCandidate::__construct_impl(DomNode* candidateDom, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->candidateDom), candidateDom, DomNode);
}
 MatchCandidate::~MatchCandidate() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MatchCandidate::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MatchCandidate", L"~MatchCandidate");
	__e_obj1.add(this->candidateDom, this);
	candidateDom = nullptr;
	if(!prepare){
		return;
	}
}
MatchCursor* MatchCandidate::getCursor(ThreadContext* ctx) throw() 
{
	MatchCursor* curser = (new(ctx) MatchCursor(this->candidateDom, ctx));
	return curser;
}
DomNode* MatchCandidate::getCandidateDom(ThreadContext* ctx) throw() 
{
	return candidateDom;
}
String* MatchCandidate::toString(ThreadContext* ctx) throw() 
{
	return this->candidateDom->getPathString(ctx);
}
}}}}

