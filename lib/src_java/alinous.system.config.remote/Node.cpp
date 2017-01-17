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
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	if(!prepare){
		return;
	}
}
int Node::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void Node::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
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
int Node::getMaxCon(ThreadContext* ctx) throw() 
{
	return maxCon;
}
void Node::setMaxCon(int maxCon, ThreadContext* ctx) throw() 
{
	this->maxCon = maxCon;
}
Node* Node::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, String* alinousHome, ThreadContext* ctx)
{
	Node* node = (new(ctx) Node(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1258(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1263(), ctx));
	}
	{
		try
		{
			int port = Integer::parseInt(attr->toString(ctx)->trim(ctx), ctx);
			node->setPort(port, ctx);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1264(), ctx));
		}
	}
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_1265(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1266(), ctx));
	}
	String* dir = attr->toString(ctx)->trim(ctx);
	dir = ConfigPathUtils::getAbsDirPath(alinousHome, dir, ctx);
	node->setDataDir(dir, ctx);
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1267(), ctx);
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

