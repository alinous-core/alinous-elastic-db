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
#include "alinous.system.config.remote/Table.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool Table::__init_done = __init_static_variables();
bool Table::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Table", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Table::Table(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), name(nullptr), keys(GCUtils<List<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L"")), nodeRefs(GCUtils<List<RemoteNodeReference> >::ins(this, (new(ctx) ArrayList<RemoteNodeReference>(ctx)), ctx, __FILEW__, __LINE__, L"")), max(nullptr)
{
}
void Table::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Table::~Table() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Table::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Table", L"~Table");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->keys, this);
	keys = nullptr;
	__e_obj1.add(this->nodeRefs, this);
	nodeRefs = nullptr;
	__e_obj1.add(this->max, this);
	max = nullptr;
	if(!prepare){
		return;
	}
}
String* Table::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void Table::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
List<String>* Table::getKeys(ThreadContext* ctx) throw() 
{
	return keys;
}
void Table::addKey(String* key, ThreadContext* ctx) throw() 
{
	this->keys->add(key, ctx);
}
void Table::addNodeRef(RemoteNodeReference* node, ThreadContext* ctx) throw() 
{
	this->nodeRefs->add(node, ctx);
}
List<RemoteNodeReference>* Table::getNodeRefs(ThreadContext* ctx) throw() 
{
	return nodeRefs;
}
String* Table::getMax(ThreadContext* ctx) throw() 
{
	return max;
}
void Table::setMax(String* max, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->max), max, String);
}
Table* Table::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Table* tbl = (new(ctx) Table(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1122(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1290(), ctx));
	}
	tbl->setName(attr->toString(ctx)->trim(ctx), ctx);
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_1291(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1292(), ctx));
	}
	String* keysstr = attr->toString(ctx)->trim(ctx);
	IArrayObject<String>* keyar = keysstr->split(ConstStr::getCNST_STR_888(), ctx);
	int maxLoop = keyar->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = keyar->get(i);
		tbl->addKey(key, ctx);
	}
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_1293(), ctx);
	if(attr != nullptr)
	{
		tbl->setMax(attr->toString(ctx)->trim(ctx), ctx);
	}
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1294(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	Iterator<MatchCandidate>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		MatchCandidate* cnd = it->next(ctx);
		DomNode* domnode = cnd->getCandidateDom(ctx);
		RemoteNodeReference* noderef = RemoteNodeReference::parseInstance(domnode, document, matcher, ctx);
		tbl->addNodeRef(noderef, ctx);
	}
	return tbl;
}
void Table::__cleanUp(ThreadContext* ctx){
}
}}}}

