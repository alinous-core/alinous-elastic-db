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
	__e_obj1.add(this->url, this);
	url = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
String* Node::getUrl(ThreadContext* ctx) throw() 
{
	return url;
}
void Node::setUrl(String* url, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), url, String);
}
Tables* Node::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
void Node::setTables(Tables* tables, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tables), tables, Tables);
}
Node* Node::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Node* node = (new(ctx) Node(ctx));
	return node;
}
}}}}

