#include "includes.h"


namespace alinous {namespace btree {





bool NodeRef::__init_done = __init_static_variables();
bool NodeRef::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRef", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRef::NodeRef(ThreadContext* ctx) throw()  : IObject(ctx), Comparable<NodeRef>(ctx), filePointer(0), node(nullptr)
{
	this->filePointer = 0;
	__GC_MV(this, &(this->node), nullptr, IBTreeNode);
}
void NodeRef::__construct_impl(ThreadContext* ctx) throw() 
{
	this->filePointer = 0;
	__GC_MV(this, &(this->node), nullptr, IBTreeNode);
}
 NodeRef::NodeRef(long long filePointer, ThreadContext* ctx) throw()  : IObject(ctx), Comparable<NodeRef>(ctx), filePointer(0), node(nullptr)
{
	this->filePointer = filePointer;
	__GC_MV(this, &(this->node), nullptr, IBTreeNode);
}
void NodeRef::__construct_impl(long long filePointer, ThreadContext* ctx) throw() 
{
	this->filePointer = filePointer;
	__GC_MV(this, &(this->node), nullptr, IBTreeNode);
}
 NodeRef::~NodeRef() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRef::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRef", L"~NodeRef");
	__e_obj1.add(this->node, this);
	node = nullptr;
	if(!prepare){
		return;
	}
}
int NodeRef::compareTo(NodeRef* another, ThreadContext* ctx) throw() 
{
	return this->node->getKey(ctx)->compareTo(another->node->getKey(ctx), ctx);
}
IBTreeNode* NodeRef::getNode(ThreadContext* ctx) throw() 
{
	return node;
}
int NodeRef::ValueCompare::operator() (NodeRef* _this, NodeRef* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

