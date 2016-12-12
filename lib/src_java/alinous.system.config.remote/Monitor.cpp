#include "includes.h"


namespace alinous {namespace system {namespace config {namespace remote {





bool Monitor::__init_done = __init_static_variables();
bool Monitor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Monitor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Monitor::~Monitor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Monitor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Monitor", L"~Monitor");
	__e_obj1.add(this->port, this);
	port = nullptr;
	if(!prepare){
		return;
	}
}
String* Monitor::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void Monitor::setPort(String* port, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->port), port, String);
}
int Monitor::getMaxConnection(ThreadContext* ctx) throw() 
{
	return maxConnection;
}
void Monitor::setMaxConnection(int maxConnection, ThreadContext* ctx) throw() 
{
	this->maxConnection = maxConnection;
}
Monitor* Monitor::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Monitor* ref = (new(ctx) Monitor(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	IVariableValue* attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1206(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1217(), ctx));
	}
	ref->setPort(attr->toString(ctx)->trim(ctx), ctx);
	attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1218(), ctx);
	if(attr != nullptr)
	{
		String* str = attr->toString(ctx)->trim(ctx);
		{
			try
			{
				int cons = Integer::parseInt(str, ctx);
				ref->setMaxConnection(cons, ctx);
			}
			catch(Throwable* e)
			{
				throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1219(), ctx));
			}
		}
	}
	return ref;
}
}}}}

