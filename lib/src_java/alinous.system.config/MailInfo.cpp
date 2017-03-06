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





bool MailInfo::__init_done = __init_static_variables();
bool MailInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MailInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MailInfo::MailInfo(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx)
{
}
void MailInfo::__construct_impl(ThreadContext* ctx) throw() 
{
}
 MailInfo::~MailInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MailInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void MailInfo::__cleanUp(ThreadContext* ctx){
}
}}}

