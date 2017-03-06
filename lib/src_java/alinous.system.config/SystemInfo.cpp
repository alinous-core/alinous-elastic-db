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





bool SystemInfo::__init_done = __init_static_variables();
bool SystemInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SystemInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SystemInfo::SystemInfo(String* alinousHome, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), moduleDir(nullptr), systemDatastore(nullptr), defaultDatastore(nullptr), alinousHome(nullptr)
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
void SystemInfo::__construct_impl(String* alinousHome, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
 SystemInfo::~SystemInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SystemInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SystemInfo", L"~SystemInfo");
	__e_obj1.add(this->moduleDir, this);
	moduleDir = nullptr;
	__e_obj1.add(this->systemDatastore, this);
	systemDatastore = nullptr;
	__e_obj1.add(this->defaultDatastore, this);
	defaultDatastore = nullptr;
	__e_obj1.add(this->alinousHome, this);
	alinousHome = nullptr;
	if(!prepare){
		return;
	}
}
String* SystemInfo::getModuleDir(ThreadContext* ctx) throw() 
{
	return moduleDir;
}
void SystemInfo::setModuleDir(String* moduleDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->moduleDir), ConfigPathUtils::getAbsDirPath(this->alinousHome, moduleDir, ctx), String);
}
String* SystemInfo::getSystemDatastore(ThreadContext* ctx) throw() 
{
	return systemDatastore;
}
void SystemInfo::setSystemDatastore(String* systemDatastore, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->systemDatastore), systemDatastore, String);
}
String* SystemInfo::getDefaultDatastore(ThreadContext* ctx) throw() 
{
	return defaultDatastore;
}
void SystemInfo::setDefaultDatastore(String* defaultDatastore, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->defaultDatastore), defaultDatastore, String);
}
void SystemInfo::__cleanUp(ThreadContext* ctx){
}
}}}

