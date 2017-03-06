#include "include/global.h"


#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.lock/LockObject.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor/MonitorResponceAction.h"
#include "alinous.remote.monitor/MonitorResponseActionFactory.h"

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
 RegionNodeInfo::RegionNodeInfo(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), nodes(GCUtils<List<NodeInfo> >::ins(this, (new(ctx) ArrayList<NodeInfo>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void RegionNodeInfo::__construct_impl(ThreadContext* ctx) throw() 
{
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
bool RegionNodeInfo::containsNode(String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	int maxLoop = this->nodes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeInfo* node = this->nodes->get(i, ctx);
		if(node->getHost(ctx)->equals(host, ctx) && node->getPort(ctx) == port && node->isIpv6(ctx) == ipv6)
		{
			return true;
		}
	}
	return false;
}
RegionNodeInfo* RegionNodeInfo::copy(ThreadContext* ctx) throw() 
{
	RegionNodeInfo* info = (new(ctx) RegionNodeInfo(ctx));
	info->setName(this->name, ctx);
	int maxLoop = this->nodes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeInfo* node = this->nodes->get(i, ctx);
		NodeInfo* cnode = node->copy(ctx);
		info->addNode(cnode, ctx);
	}
	return info;
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
void RegionNodeInfo::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), buff->getString(ctx), String);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeInfo* info = (new(ctx) NodeInfo(ctx));
		info->readData(buff, ctx);
		this->nodes->add(info, ctx);
	}
}
void RegionNodeInfo::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putString(this->name, ctx);
	int maxLoop = this->nodes->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeInfo* info = this->nodes->get(i, ctx);
		info->writeData(buff, ctx);
	}
}
RegionNodeInfo* RegionNodeInfo::fromConfig(Region* reg, ThreadContext* ctx)
{
	RegionNodeInfo* info = (new(ctx) RegionNodeInfo(ctx));
	info->setName(reg->getName(ctx), ctx);
	List<RemoteNodeReference>* list = reg->getNodeRefs(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		RemoteNodeReference* n = list->get(i, ctx);
		NodeInfo* nodeInfo = NodeInfo::parseUrl(n->getUrl(ctx), n->isIpv6(ctx), ctx);
		info->addNode(nodeInfo, ctx);
	}
	return info;
}
void RegionNodeInfo::__cleanUp(ThreadContext* ctx){
}
}}}

