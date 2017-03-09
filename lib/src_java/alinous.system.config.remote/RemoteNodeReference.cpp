#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/RemoteNodeReference.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool RemoteNodeReference::__init_done = __init_static_variables();
bool RemoteNodeReference::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteNodeReference", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteNodeReference::RemoteNodeReference(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), url(nullptr), ipv6(false)
{
}
void RemoteNodeReference::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteNodeReference::~RemoteNodeReference() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteNodeReference::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteNodeReference", L"~RemoteNodeReference");
	__e_obj1.add(this->url, this);
	url = nullptr;
	if(!prepare){
		return;
	}
}
String* RemoteNodeReference::getUrl(ThreadContext* ctx) throw() 
{
	return url;
}
void RemoteNodeReference::setUrl(String* url, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), url, String);
}
bool RemoteNodeReference::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
void RemoteNodeReference::setIpv6(bool ipv6, ThreadContext* ctx) throw() 
{
	this->ipv6 = ipv6;
}
RemoteNodeReference* RemoteNodeReference::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	RemoteNodeReference* noderef = (new(ctx) RemoteNodeReference(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_986(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_987(), ctx));
	}
	noderef->setUrl(attr->toString(ctx)->trim(ctx), ctx);
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_988(), ctx);
	if(attr != nullptr)
	{
		String* ipv6 = attr->toString(ctx)->trim(ctx);
		noderef->setIpv6(!ipv6->equalsIgnoreCase(ConstStr::getCNST_STR_989(), ctx), ctx);
	}
	return noderef;
}
void RemoteNodeReference::__cleanUp(ThreadContext* ctx){
}
}}}}

