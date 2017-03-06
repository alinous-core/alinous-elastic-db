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





bool Regions::__init_done = __init_static_variables();
bool Regions::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Regions", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Regions::Regions(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), list(GCUtils<List<Region> >::ins(this, (new(ctx) ArrayList<Region>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void Regions::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Regions::~Regions() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Regions::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Regions", L"~Regions");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void Regions::addRegionRef(Region* ref, ThreadContext* ctx) throw() 
{
	this->list->add(ref, ctx);
}
List<Region>* Regions::getList(ThreadContext* ctx) throw() 
{
	return list;
}
Regions* Regions::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Regions* regions = (new(ctx) Regions(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1286(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* cnd = it->next(ctx);
		DomNode* dom = cnd->getCandidateDom(ctx);
		Region* region = Region::parseInstance(dom, document, matcher, ctx);
		regions->addRegionRef(region, ctx);
	}
	return regions;
}
void Regions::__cleanUp(ThreadContext* ctx){
}
}}}}

