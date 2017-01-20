#include "includes.h"


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

