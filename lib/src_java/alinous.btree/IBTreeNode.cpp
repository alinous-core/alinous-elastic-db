#include "includes.h"


namespace alinous {namespace btree {




constexpr const char IBTreeNode::BTREE_TYPE_LEAF;
constexpr const char IBTreeNode::BTREE_TYPE_NODE;
constexpr const char IBTreeNode::BTREE_TYPE_LEAF_CONTAINER;
constexpr const char IBTreeNode::BTREE_TYPE_MAX_NODE;
constexpr const char IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER;
bool IBTreeNode::__init_done = __init_static_variables();
bool IBTreeNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IBTreeNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IBTreeNode::~IBTreeNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IBTreeNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Comparable<IBTreeNode>::__releaseRegerences(true, ctx);
}
}}

