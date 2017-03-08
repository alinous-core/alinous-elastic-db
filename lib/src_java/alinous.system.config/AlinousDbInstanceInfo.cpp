#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsRef.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/MailInfo.h"
#include "alinous.system.config/SystemInfo.h"
#include "alinous.system.config/ConfigPathUtils.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.system.config/DataSourceInfo.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.system.config/AlinousConfig.h"

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
 AlinousDbInstanceInfo::AlinousDbInstanceInfo(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), id(nullptr), dataDir(nullptr), trxTmpDir(nullptr), maxConnections(16), regionsRef(nullptr), monitorRef(nullptr)
{
}
void AlinousDbInstanceInfo::__construct_impl(ThreadContext* ctx) throw() 
{
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
void AlinousDbInstanceInfo::__cleanUp(ThreadContext* ctx){
}
}}}

