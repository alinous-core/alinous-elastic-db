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
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.system.config.remote/Regions.h"
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





bool RegionNodeInfoManager::__init_done = __init_static_variables();
bool RegionNodeInfoManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionNodeInfoManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionNodeInfoManager::RegionNodeInfoManager(ThreadContext* ctx) throw()  : IObject(ctx), regionsMap(GCUtils<Map<String,RegionNodeInfo> >::ins(this, (new(ctx) HashMap<String,RegionNodeInfo>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), nodeClusterRevision(1)
{
}
void RegionNodeInfoManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionNodeInfoManager::~RegionNodeInfoManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionNodeInfoManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionNodeInfoManager", L"~RegionNodeInfoManager");
	__e_obj1.add(this->regionsMap, this);
	regionsMap = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
void RegionNodeInfoManager::getRegionInfoData(RegionInfoData* data, String* region, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		RegionNodeInfo* info = this->regionsMap->get(region, ctx);
		data->setNodeInfo(info, ctx);
	}
}
RegionNodeInfoManager* RegionNodeInfoManager::init(Monitor* monitorConf, ThreadContext* ctx)
{
	Regions* regions = monitorConf->getRegions(ctx);
	List<Region>* list = regions->getList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		Region* reg = list->get(i, ctx);
		RegionNodeInfo* info = RegionNodeInfo::fromConfig(reg, ctx);
		if(this->regionsMap->get(info->getName(ctx), ctx) != nullptr)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3579(), ctx));
		}
		this->regionsMap->put(info->getName(ctx), info, ctx);
	}
	return this;
}
long long RegionNodeInfoManager::updateNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		if(this->nodeClusterRevision < nodeClusterRevision)
		{
			this->nodeClusterRevision = nodeClusterRevision;
		}
		return this->nodeClusterRevision;
	}
}
long long RegionNodeInfoManager::getNodeClusterRevision(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		return nodeClusterRevision;
	}
}
void RegionNodeInfoManager::setNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->nodeClusterRevision = nodeClusterRevision;
	}
}
void RegionNodeInfoManager::__cleanUp(ThreadContext* ctx){
}
}}}

