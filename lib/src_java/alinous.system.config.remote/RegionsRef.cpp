#include "include/global.h"


#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RegionRef.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Table.h"
#include "alinous.system.config.remote/Tables.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/Node.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.system.config.remote/Regions.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config.remote/Nodes.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool RegionsRef::__init_done = __init_static_variables();
bool RegionsRef::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionsRef", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionsRef::RegionsRef(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), list(GCUtils<List<RegionRef> >::ins(this, (new(ctx) ArrayList<RegionRef>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void RegionsRef::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionsRef::~RegionsRef() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionsRef::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionsRef", L"~RegionsRef");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void RegionsRef::addRegionRef(RegionRef* ref, ThreadContext* ctx) throw() 
{
	this->list->add(ref, ctx);
}
List<RegionRef>* RegionsRef::getList(ThreadContext* ctx) throw() 
{
	return list;
}
RegionsRef* RegionsRef::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	RegionsRef* refs = (new(ctx) RegionsRef(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1301(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* cnd = it->next(ctx);
		DomNode* dom = cnd->getCandidateDom(ctx);
		RegionRef* ref = (new(ctx) RegionRef(ctx));
		IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1122(), ctx);
		if(attr == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1302(), ctx));
		}
		String* name = attr->toString(ctx)->trim(ctx);
		ref->setName(name, ctx);
		attr = dom->getAttributeValue(ConstStr::getCNST_STR_1278(), ctx);
		if(attr == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1303(), ctx));
		}
		ref->setUrl(attr->toString(ctx)->trim(ctx), ctx);
		refs->addRegionRef(ref, ctx);
	}
	return refs;
}
void RegionsRef::__cleanUp(ThreadContext* ctx){
}
}}}}

