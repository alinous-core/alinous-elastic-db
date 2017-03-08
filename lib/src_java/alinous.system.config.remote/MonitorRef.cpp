#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool MonitorRef::__init_done = __init_static_variables();
bool MonitorRef::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorRef", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorRef::MonitorRef(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), url(nullptr), host(nullptr), port(0), ipv6(false)
{
}
void MonitorRef::__construct_impl(ThreadContext* ctx) throw() 
{
}
 MonitorRef::~MonitorRef() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorRef::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorRef", L"~MonitorRef");
	__e_obj1.add(this->url, this);
	url = nullptr;
	__e_obj1.add(this->host, this);
	host = nullptr;
	if(!prepare){
		return;
	}
}
void MonitorRef::parseUrl(ThreadContext* ctx)
{
	IArrayObject<String>* segs = this->url->split(ConstStr::getCNST_STR_381(), ctx);
	if(segs->length != 2)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1306(), ctx));
	}
	__GC_MV(this, &(this->host), segs->get(0), String);
	{
		try
		{
			this->port = Integer::parseInt(segs->get(1)->trim(ctx), ctx);
		}
		catch(NumberFormatException* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1306(), ctx));
		}
	}
}
String* MonitorRef::getUrl(ThreadContext* ctx) throw() 
{
	return url;
}
void MonitorRef::setUrl(String* url, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), url, String);
}
String* MonitorRef::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
void MonitorRef::setHost(String* host, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
}
int MonitorRef::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void MonitorRef::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
bool MonitorRef::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
void MonitorRef::setIpv6(bool ipv6, ThreadContext* ctx) throw() 
{
	this->ipv6 = ipv6;
}
MonitorRef* MonitorRef::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	MonitorRef* monitorRef = (new(ctx) MonitorRef(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	IVariableValue* attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1278(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1305(), ctx));
	}
	monitorRef->setUrl(attr->toString(ctx)->trim(ctx), ctx);
	monitorRef->parseUrl(ctx);
	attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1280(), ctx);
	if(attr != nullptr)
	{
		String* ipv6 = attr->toString(ctx)->trim(ctx);
		if(!ipv6->equals(ConstStr::getCNST_STR_1144(), ctx))
		{
			monitorRef->setIpv6(true, ctx);
		}
	}
	return monitorRef;
}
void MonitorRef::__cleanUp(ThreadContext* ctx){
}
}}}}

