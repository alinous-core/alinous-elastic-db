#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool NodeTableClaster::__init_done = __init_static_variables();
bool NodeTableClaster::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeTableClaster", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeTableClaster::~NodeTableClaster() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeTableClaster::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeTableClaster", L"~NodeTableClaster");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	if(!prepare){
		return;
	}
}
void NodeTableClaster::addNode(NodeTableReference* nodeRef, ThreadContext* ctx) throw() 
{
	this->nodes->add(nodeRef, ctx);
}
List<NodeTableReference>* NodeTableClaster::getNodes(ThreadContext* ctx) throw() 
{
	return nodes;
}
}}}

