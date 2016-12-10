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
	__e_obj1.add(this->port, this);
	port = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
String* Region::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void Region::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
String* Region::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void Region::setPort(String* port, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->port), port, String);
}
Tables* Region::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
void Region::setTables(Tables* tables, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tables), tables, Tables);
}
Region* Region::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Region* reg = (new(ctx) Region(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1061(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1226(), ctx));
	}
	reg->setName(attr->toString(ctx)->trim(ctx), ctx);
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_1206(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1227(), ctx));
	}
	reg->setPort(attr->toString(ctx)->trim(ctx), ctx);
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1225(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* cand = list->get(0, ctx);
		DomNode* tablesdom = cand->getCandidateDom(ctx);
		Tables* tables = Tables::parseInstance(tablesdom, document, matcher, ctx);
		reg->setTables(tables, ctx);
	}
	return reg;
}
}}}}

