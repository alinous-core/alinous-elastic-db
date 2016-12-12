#include "includes.h"


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
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1221(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* cnd = it->next(ctx);
		DomNode* dom = cnd->getCandidateDom(ctx);
		RegionRef* ref = (new(ctx) RegionRef(ctx));
		IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1061(), ctx);
		if(attr == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1222(), ctx));
		}
		String* name = attr->toString(ctx)->trim(ctx);
		ref->setName(name, ctx);
		attr = dom->getAttributeValue(ConstStr::getCNST_STR_1204(), ctx);
		if(attr == nullptr)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1223(), ctx));
		}
		ref->setUrl(attr->toString(ctx)->trim(ctx), ctx);
		refs->addRegionRef(ref, ctx);
	}
	return refs;
}
}}}}

