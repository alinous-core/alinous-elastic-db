#include "includes.h"


namespace alinous {namespace system {namespace config {namespace remote {





bool Node::__init_done = __init_static_variables();
bool Node::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Node", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Node::~Node() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Node::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Node", L"~Node");
	__e_obj1.add(this->port, this);
	port = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	if(!prepare){
		return;
	}
}
String* Node::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void Node::setPort(String* port, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->port), port, String);
}
Tables* Node::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
void Node::setTables(Tables* tables, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tables), tables, Tables);
}
String* Node::getDataDir(ThreadContext* ctx) throw() 
{
	return dataDir;
}
void Node::setDataDir(String* dataDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
}
Node* Node::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Node* node = (new(ctx) Node(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1205(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1206(), ctx));
	}
	node->setPort(attr->toString(ctx)->trim(ctx), ctx);
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_1207(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1208(), ctx));
	}
	node->setDataDir(attr->toString(ctx)->trim(ctx), ctx);
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1209(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		DomNode* tablesdom = candidate->getCandidateDom(ctx);
		Tables* tables = Tables::parseInstance(tablesdom, document, matcher, ctx);
		node->setTables(tables, ctx);
	}
	return node;
}
}}}}

