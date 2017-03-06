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
 Tables::Tables(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), list(GCUtils<List<Table> >::ins(this, (new(ctx) ArrayList<Table>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void Tables::__construct_impl(ThreadContext* ctx) throw() 
{
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
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1300(), ctx);
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
void Tables::__cleanUp(ThreadContext* ctx){
}
}}}}

