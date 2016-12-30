#include "includes.h"


namespace alinous {namespace remote {namespace monitor {





bool RegionNodeInfo::__init_done = __init_static_variables();
bool RegionNodeInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionNodeInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionNodeInfo::~RegionNodeInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionNodeInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionNodeInfo", L"~RegionNodeInfo");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	if(!prepare){
		return;
	}
}
void RegionNodeInfo::addNode(NodeInfo* node, ThreadContext* ctx) throw() 
{
	this->nodes->add(node, ctx);
}
List<NodeInfo>* RegionNodeInfo::getNodes(ThreadContext* ctx) throw() 
{
	return nodes;
}
String* RegionNodeInfo::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void RegionNodeInfo::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
RegionNodeInfo* RegionNodeInfo::fromConfig(Region* reg, ThreadContext* ctx)
{
	RegionNodeInfo* info = (new(ctx) RegionNodeInfo(ctx));
	info->setName(reg->getName(ctx), ctx);
	List<NodeRef>* list = reg->getNodeRefs(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeRef* n = list->get(i, ctx);
		NodeInfo* nodeInfo = NodeInfo::parseUrl(n->getUrl(ctx), ctx);
		info->addNode(nodeInfo, ctx);
	}
	return info;
}
}}}

