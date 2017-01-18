#include "includes.h"


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
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1291(), ctx);
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
}}}}

