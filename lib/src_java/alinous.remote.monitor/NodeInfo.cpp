#include "includes.h"


namespace alinous {namespace remote {namespace monitor {





bool NodeInfo::__init_done = __init_static_variables();
bool NodeInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeInfo::~NodeInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeInfo", L"~NodeInfo");
	__e_obj1.add(this->host, this);
	host = nullptr;
	if(!prepare){
		return;
	}
}
String* NodeInfo::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
void NodeInfo::setHost(String* host, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
}
int NodeInfo::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void NodeInfo::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
bool NodeInfo::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
void NodeInfo::setIpv6(bool ipv6, ThreadContext* ctx) throw() 
{
	this->ipv6 = ipv6;
}
NodeInfo* NodeInfo::copy(ThreadContext* ctx) throw() 
{
	NodeInfo* info = (new(ctx) NodeInfo(ctx));
	info->setHost(this->host, ctx);
	info->setPort(this->port, ctx);
	return info;
}
void NodeInfo::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), buff->getString(ctx), String);
	this->port = buff->getInt(ctx);
}
void NodeInfo::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putString(this->host, ctx);
	buff->putInt(this->port, ctx);
}
NodeInfo* NodeInfo::parseUrl(String* url, bool ipv6, ThreadContext* ctx)
{
	NodeInfo* info = (new(ctx) NodeInfo(ctx));
	IArrayObject<String>* segs = url->split(ConstStr::getCNST_STR_381(), ctx);
	if(segs->length != 2)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3559(), ctx));
	}
	info->setHost(segs->get(0), ctx);
	{
		try
		{
			int port = Integer::parseInt(segs->get(1), ctx);
			info->setPort(port, ctx);
		}
		catch(NumberFormatException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3559(), ctx));
		}
	}
	info->setIpv6(ipv6, ctx);
	return info;
}
}}}

