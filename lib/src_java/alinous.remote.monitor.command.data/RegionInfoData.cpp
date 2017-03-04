#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"
#include "alinous.system.config.remote/Region.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.command.data/RegionInfoData.h"

namespace alinous {namespace remote {namespace monitor {namespace command {namespace data {





bool RegionInfoData::__init_done = __init_static_variables();
bool RegionInfoData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionInfoData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionInfoData::~RegionInfoData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionInfoData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionInfoData", L"~RegionInfoData");
	__e_obj1.add(this->nodeInfo, this);
	nodeInfo = nullptr;
	if(!prepare){
		return;
	}
}
void RegionInfoData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->nodeInfo), (new(ctx) RegionNodeInfo(ctx)), RegionNodeInfo);
		this->nodeInfo->readData(buff, ctx);
	}
}
void RegionInfoData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool isnull = (this->nodeInfo == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->nodeInfo->writeData(buff, ctx);
	}
}
RegionNodeInfo* RegionInfoData::getNodeInfo(ThreadContext* ctx) throw() 
{
	return nodeInfo;
}
void RegionInfoData::setNodeInfo(RegionNodeInfo* nodeInfo, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->nodeInfo), nodeInfo, RegionNodeInfo);
}
}}}}}

