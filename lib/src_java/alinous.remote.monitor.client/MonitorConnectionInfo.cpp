#include "include/global.h"


#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.monitor.client/MonitorConnectionInfo.h"
#include "alinous.remote.monitor.client/MonitorConnection.h"
#include "alinous.remote.monitor.client/MonitorClientConnectionFactory.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath.match/MatchCursor.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.remote.monitor.client/RemoteCommitIdPublisher.h"

namespace alinous {namespace remote {namespace monitor {namespace client {





bool MonitorConnectionInfo::__init_done = __init_static_variables();
bool MonitorConnectionInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorConnectionInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorConnectionInfo::MonitorConnectionInfo(String* host, int port, ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
void MonitorConnectionInfo::__construct_impl(String* host, int port, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
 MonitorConnectionInfo::~MonitorConnectionInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorConnectionInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorConnectionInfo", L"~MonitorConnectionInfo");
	__e_obj1.add(this->host, this);
	host = nullptr;
	if(!prepare){
		return;
	}
}
String* MonitorConnectionInfo::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
void MonitorConnectionInfo::setHost(String* host, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
}
int MonitorConnectionInfo::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void MonitorConnectionInfo::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
}}}}

