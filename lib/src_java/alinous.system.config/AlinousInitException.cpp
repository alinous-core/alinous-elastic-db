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





constexpr const long long AlinousInitException::serialVersionUID;
bool AlinousInitException::__init_done = __init_static_variables();
bool AlinousInitException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousInitException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousInitException::AlinousInitException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, ctx)
{
}
void AlinousInitException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 AlinousInitException::AlinousInitException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, e, ctx)
{
}
void AlinousInitException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 AlinousInitException::~AlinousInitException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousInitException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
void AlinousInitException::__cleanUp(ThreadContext* ctx){
}
}}}

