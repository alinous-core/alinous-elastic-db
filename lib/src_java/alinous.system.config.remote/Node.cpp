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
	__e_obj1.add(this->monitorRef, this);
	monitorRef = nullptr;
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
MonitorRef* Node::getMonitorRef(ThreadContext* ctx) throw() 
{
	return monitorRef;
}
void Node::setMonitorRef(MonitorRef* monitorRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitorRef), monitorRef, MonitorRef);
}
Node* Node::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, String* alinousHome, ThreadContext* ctx)
{
	Node* node = (new(ctx) Node(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1267(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1272(), ctx));
	}
	{
		try
		{
			int port = Integer::parseInt(attr->toString(ctx)->trim(ctx), ctx);
			node->setPort(port, ctx);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1273(), ctx));
		}
	}
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_1274(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1275(), ctx));
	}
	String* dir = attr->toString(ctx)->trim(ctx);
	dir = ConfigPathUtils::getAbsDirPath(alinousHome, dir, ctx);
	node->setDataDir(dir, ctx);
	MatchCandidatesCollection* result = matcher->match(document, dom, ConstStr::getCNST_STR_1276(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(!list->isEmpty(ctx))
	{
		MatchCandidate* candidate = list->get(0, ctx);
		DomNode* tablesdom = candidate->getCandidateDom(ctx);
		Tables* tables = Tables::parseInstance(tablesdom, document, matcher, ctx);
		node->setTables(tables, ctx);
	}
	result = matcher->match(document, dom, ConstStr::getCNST_STR_1266(), ctx);
	list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1277(), ctx));
	}
	if(list->size(ctx) != 1)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1278(), ctx));
	}
	MatchCandidate* candidate = list->get(0, ctx);
	__GC_MV(node, &(node->monitorRef), MonitorRef::parseInstance(candidate, document, matcher, ctx), MonitorRef);
	return node;
}
}}}}

