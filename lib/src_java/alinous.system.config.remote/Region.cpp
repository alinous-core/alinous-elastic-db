#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool Region::__init_done = __init_static_variables();
bool Region::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Region", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Region::Region(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), name(nullptr), nodeRefs(GCUtils<List<RemoteNodeReference> >::ins(this, (new(ctx) ArrayList<RemoteNodeReference>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void Region::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Region::~Region() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Region::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Region", L"~Region");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->nodeRefs, this);
	nodeRefs = nullptr;
	if(!prepare){
		return;
	}
}
void Region::addNodeRef(RemoteNodeReference* ref, ThreadContext* ctx) throw() 
{
	this->nodeRefs->add(ref, ctx);
}
List<RemoteNodeReference>* Region::getNodeRefs(ThreadContext* ctx) throw() 
{
	return nodeRefs;
}
String* Region::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void Region::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
Region* Region::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Region* reg = (new(ctx) Region(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_998(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1017(), ctx));
	}
	reg->setName(attr->toString(ctx)->trim(ctx), ctx);
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1004(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		MatchCandidate* cand = list->get(i, ctx);
		DomNode* noderefdom = cand->getCandidateDom(ctx);
		RemoteNodeReference* noderef = RemoteNodeReference::parseInstance(noderefdom, document, matcher, ctx);
		reg->addNodeRef(noderef, ctx);
	}
	return reg;
}
void Region::__cleanUp(ThreadContext* ctx){
}
}}}}

