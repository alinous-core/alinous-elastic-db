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





bool WebHandlerInfo::__init_done = __init_static_variables();
bool WebHandlerInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WebHandlerInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WebHandlerInfo::WebHandlerInfo(String* alinousHome, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), documentRoot(nullptr), alinousHome(nullptr), port(0)
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
void WebHandlerInfo::__construct_impl(String* alinousHome, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->alinousHome), alinousHome, String);
}
 WebHandlerInfo::~WebHandlerInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WebHandlerInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WebHandlerInfo", L"~WebHandlerInfo");
	__e_obj1.add(this->documentRoot, this);
	documentRoot = nullptr;
	__e_obj1.add(this->alinousHome, this);
	alinousHome = nullptr;
	if(!prepare){
		return;
	}
}
String* WebHandlerInfo::getDocumentRoot(ThreadContext* ctx) throw() 
{
	return documentRoot;
}
void WebHandlerInfo::setDocumentRoot(String* documentRoot, ThreadContext* ctx) throw() 
{
	String* documentAbsRoot = ConfigPathUtils::getAbsDirPath(this->alinousHome, documentRoot, ctx);
	if(documentAbsRoot->endsWith(ConstStr::getCNST_STR_949(), ctx))
	{
		__GC_MV(this, &(this->documentRoot), documentAbsRoot->substring(0, documentAbsRoot->length(ctx) - 1, ctx), String);
		return;
	}
	__GC_MV(this, &(this->documentRoot), documentAbsRoot, String);
}
int WebHandlerInfo::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void WebHandlerInfo::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
void WebHandlerInfo::__cleanUp(ThreadContext* ctx){
}
}}}

