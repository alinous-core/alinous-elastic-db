#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {





bool GetRegionNodeInfoCommand::__init_done = __init_static_variables();
bool GetRegionNodeInfoCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetRegionNodeInfoCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetRegionNodeInfoCommand::GetRegionNodeInfoCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), regionData(__GC_INS(this, (new(ctx) RegionInfoData(ctx)), RegionInfoData)), nodeClusterRevision(0), region(nullptr)
{
	this->type = AbstractMonitorCommand::TYPE_GET_REGION_INFO;
}
void GetRegionNodeInfoCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_GET_REGION_INFO;
}
 GetRegionNodeInfoCommand::~GetRegionNodeInfoCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetRegionNodeInfoCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"GetRegionNodeInfoCommand", L"~GetRegionNodeInfoCommand");
	__e_obj1.add(this->regionData, this);
	regionData = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void GetRegionNodeInfoCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	monitorServer->getRegionInfo(this->regionData, this->region, ctx);
	this->nodeClusterRevision = monitorServer->updateNodeClusterVersion(this->nodeClusterRevision, ctx);
	writeByteStream(outStream, ctx);
}
void GetRegionNodeInfoCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->nodeClusterRevision = buff->getLong(ctx);
	this->regionData->readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->region), buff->getString(ctx), String);
	}
}
RegionInfoData* GetRegionNodeInfoCommand::getRegionData(ThreadContext* ctx) throw() 
{
	return regionData;
}
long long GetRegionNodeInfoCommand::getNodeClusterRevision(ThreadContext* ctx) throw() 
{
	return nodeClusterRevision;
}
void GetRegionNodeInfoCommand::setNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() 
{
	this->nodeClusterRevision = nodeClusterRevision;
}
String* GetRegionNodeInfoCommand::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
void GetRegionNodeInfoCommand::setRegion(String* region, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->region), region, String);
}
void GetRegionNodeInfoCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_GET_REGION_INFO, ctx);
	buff->putLong(this->nodeClusterRevision, ctx);
	this->regionData->writeData(buff, ctx);
	bool isnull = (this->region == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->region, ctx);
	}
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}

