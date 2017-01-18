#include "includes.h"


namespace alinous {namespace system {namespace config {namespace remote {





bool NodeRef::__init_done = __init_static_variables();
bool NodeRef::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRef", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRef::~NodeRef() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRef::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRef", L"~NodeRef");
	__e_obj1.add(this->url, this);
	url = nullptr;
	if(!prepare){
		return;
	}
}
String* NodeRef::getUrl(ThreadContext* ctx) throw() 
{
	return url;
}
void NodeRef::setUrl(String* url, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), url, String);
}
bool NodeRef::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
void NodeRef::setIpv6(bool ipv6, ThreadContext* ctx) throw() 
{
	this->ipv6 = ipv6;
}
NodeRef* NodeRef::parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	NodeRef* noderef = (new(ctx) NodeRef(ctx));
	IVariableValue* attr = dom->getAttributeValue(ConstStr::getCNST_STR_1261(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1262(), ctx));
	}
	noderef->setUrl(attr->toString(ctx)->trim(ctx), ctx);
	attr = dom->getAttributeValue(ConstStr::getCNST_STR_1263(), ctx);
	if(attr != nullptr)
	{
		String* ipv6 = attr->toString(ctx)->trim(ctx);
		noderef->setIpv6(!ipv6->equalsIgnoreCase(ConstStr::getCNST_STR_1136(), ctx), ctx);
	}
	return noderef;
}
}}}}

