#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
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
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.system.config.remote/Nodes.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.system.config/AlinousConfig.h"

namespace alinous {namespace system {namespace config {





bool AlinousDbInfo::__init_done = __init_static_variables();
bool AlinousDbInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDbInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDbInfo::AlinousDbInfo(String* alinousHome, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), instances(GCUtils<HashMap<String,AlinousDbInstanceInfo> >::ins(this, (new(ctx) HashMap<String,AlinousDbInstanceInfo>(ctx)), ctx, __FILEW__, __LINE__, L"")), alinousHome(nullptr)
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
void AlinousDbInfo::__construct_impl(String* alinousHome, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
 AlinousDbInfo::~AlinousDbInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDbInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDbInfo", L"~AlinousDbInfo");
	__e_obj1.add(this->instances, this);
	instances = nullptr;
	__e_obj1.add(this->alinousHome, this);
	alinousHome = nullptr;
	if(!prepare){
		return;
	}
}
AlinousDbInstanceInfo* AlinousDbInfo::addInstance(String* id, String* dataDir, ThreadContext* ctx) throw() 
{
	AlinousDbInstanceInfo* info = (new(ctx) AlinousDbInstanceInfo(ctx));
	info->setId(id, ctx);
	info->setDataDir(ConfigPathUtils::getAbsDirPath(this->alinousHome, dataDir, ctx), ctx);
	this->instances->put(id, info, ctx);
	return info;
}
AlinousDbInstanceInfo* AlinousDbInfo::getInstance(String* id, ThreadContext* ctx) throw() 
{
	return this->instances->get(id, ctx);
}
Set<String>* AlinousDbInfo::idSet(ThreadContext* ctx) throw() 
{
	Set<String>* idSet = this->instances->keySet(ctx);
	return idSet;
}
void AlinousDbInfo::__cleanUp(ThreadContext* ctx){
}
}}}

