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
	__e_obj1.add(this->regionsMap, this);
	regionsMap = nullptr;
	if(!prepare){
		return;
	}
}
void RegionInfoData::putNodeInfo(String* key, RegionNodeInfo* info, ThreadContext* ctx) throw() 
{
	this->regionsMap->put(key, info, ctx);
}
void RegionInfoData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = buff->getString(ctx);
		RegionNodeInfo* info = (new(ctx) RegionNodeInfo(ctx));
		info->readData(buff, ctx);
		this->regionsMap->put(key, info, ctx);
	}
}
void RegionInfoData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	int size = this->regionsMap->size(ctx);
	buff->putInt(size, ctx);
	Iterator<String>* it = this->regionsMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		RegionNodeInfo* node = (new(ctx) RegionNodeInfo(ctx));
		buff->putString(key, ctx);
		node->writeData(buff, ctx);
	}
}
}}}}}

