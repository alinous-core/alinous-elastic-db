#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool RegionShardPart::__init_done = __init_static_variables();
bool RegionShardPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionShardPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionShardPart::RegionShardPart(NodeTableReference* nodeRef, ThreadContext* ctx) throw()  : IObject(ctx), maxValue(nullptr), nodeAccessRef(nullptr)
{
	__GC_MV(this, &(this->maxValue), nodeRef->getMaxValue(ctx), TablePartitionMaxValue);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
void RegionShardPart::__construct_impl(NodeTableReference* nodeRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->maxValue), nodeRef->getMaxValue(ctx), TablePartitionMaxValue);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
 RegionShardPart::~RegionShardPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionShardPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionShardPart", L"~RegionShardPart");
	__e_obj1.add(this->maxValue, this);
	maxValue = nullptr;
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	if(!prepare){
		return;
	}
}
TablePartitionMaxValue* RegionShardPart::getMaxValue(ThreadContext* ctx) throw() 
{
	return maxValue;
}
NodeReference* RegionShardPart::getNodeAccessRef(ThreadContext* ctx) throw() 
{
	return nodeAccessRef;
}
}}}

