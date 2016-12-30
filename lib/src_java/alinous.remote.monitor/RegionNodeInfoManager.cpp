#include "includes.h"


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
	if(!prepare){
		return;
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
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3485(), ctx));
		}
		this->regionsMap->put(info->getName(ctx), info, ctx);
	}
	return this;
}
}}}

