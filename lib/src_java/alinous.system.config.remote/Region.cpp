#include "includes.h"


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
void Region::addNodeRef(NodeRef* ref, ThreadContext* ctx) throw() 
{
	this->nodeRefs->add(ref, ctx);
}
List<NodeRef>* Region::getNodeRefs(ThreadContext* ctx) throw() 
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
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1115(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1295(), ctx));
	}
	reg->setName(attr->toString(ctx)->trim(ctx), ctx);
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1282(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		MatchCandidate* cand = list->get(i, ctx);
		DomNode* noderefdom = cand->getCandidateDom(ctx);
		NodeRef* noderef = NodeRef::parseInstance(noderefdom, document, matcher, ctx);
		reg->addNodeRef(noderef, ctx);
	}
	return reg;
}
}}}}

