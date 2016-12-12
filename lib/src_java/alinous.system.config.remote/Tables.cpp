#include "includes.h"


namespace alinous {namespace system {namespace config {namespace remote {





bool Tables::__init_done = __init_static_variables();
bool Tables::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Tables", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Tables::~Tables() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Tables::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Tables", L"~Tables");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void Tables::addTable(Table* table, ThreadContext* ctx) throw() 
{
	this->list->add(table, ctx);
}
List<Table>* Tables::getList(ThreadContext* ctx) throw() 
{
	return list;
}
Tables* Tables::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Tables* tables = (new(ctx) Tables(ctx));
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1220(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* cand = it->next(ctx);
		DomNode* tableDom = cand->getCandidateDom(ctx);
		Table* table = Table::parseInstance(tableDom, document, matcher, ctx);
		tables->addTable(table, ctx);
	}
	return tables;
}
}}}}

