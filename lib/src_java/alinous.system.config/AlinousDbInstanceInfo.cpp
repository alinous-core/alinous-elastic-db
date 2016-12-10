#include "includes.h"


namespace alinous {namespace system {namespace config {





bool AlinousDbInstanceInfo::__init_done = __init_static_variables();
bool AlinousDbInstanceInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDbInstanceInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDbInstanceInfo::~AlinousDbInstanceInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDbInstanceInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDbInstanceInfo", L"~AlinousDbInstanceInfo");
	__e_obj1.add(this->id, this);
	id = nullptr;
	__e_obj1.add(this->dataDir, this);
	dataDir = nullptr;
	__e_obj1.add(this->trxTmpDir, this);
	trxTmpDir = nullptr;
	__e_obj1.add(this->regionsRef, this);
	regionsRef = nullptr;
	__e_obj1.add(this->monitorRef, this);
	monitorRef = nullptr;
	if(!prepare){
		return;
	}
}
String* AlinousDbInstanceInfo::getId(ThreadContext* ctx) throw() 
{
	return id;
}
void AlinousDbInstanceInfo::setId(String* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, String);
}
String* AlinousDbInstanceInfo::getDataDir(ThreadContext* ctx) throw() 
{
	return dataDir;
}
void AlinousDbInstanceInfo::setDataDir(String* dataDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->dataDir), dataDir, String);
}
String* AlinousDbInstanceInfo::getTrxTmpDir(ThreadContext* ctx) throw() 
{
	return trxTmpDir;
}
void AlinousDbInstanceInfo::setTrxTmpDir(String* trxTmpDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trxTmpDir), trxTmpDir, String);
}
int AlinousDbInstanceInfo::getMaxConnections(ThreadContext* ctx) throw() 
{
	return maxConnections;
}
void AlinousDbInstanceInfo::setMaxConnections(int maxConnections, ThreadContext* ctx) throw() 
{
	this->maxConnections = maxConnections;
}
RegionsRef* AlinousDbInstanceInfo::getRegionsRef(ThreadContext* ctx) throw() 
{
	return regionsRef;
}
void AlinousDbInstanceInfo::setRegionsRef(RegionsRef* regionsRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->regionsRef), regionsRef, RegionsRef);
}
MonitorRef* AlinousDbInstanceInfo::getMonitorRef(ThreadContext* ctx) throw() 
{
	return monitorRef;
}
void AlinousDbInstanceInfo::setMonitorRef(MonitorRef* monitorRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitorRef), monitorRef, MonitorRef);
}
}}}

