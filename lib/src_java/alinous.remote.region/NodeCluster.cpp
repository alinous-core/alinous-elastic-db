#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool NodeCluster::__init_done = __init_static_variables();
bool NodeCluster::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeCluster", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeCluster::~NodeCluster() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeCluster::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeCluster", L"~NodeCluster");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	if(!prepare){
		return;
	}
}
void NodeCluster::addNode(NodeReference* nodeRef, ThreadContext* ctx) throw() 
{
	this->nodes->add(nodeRef, ctx);
}
List<NodeReference>* NodeCluster::getNodes(ThreadContext* ctx) throw() 
{
	return nodes;
}
}}}

