#include "includes.h"


namespace alinous {namespace system {namespace config {namespace remote {





bool RegionsServer::__init_done = __init_static_variables();
bool RegionsServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionsServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionsServer::~RegionsServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionsServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionsServer", L"~RegionsServer");
	__e_obj1.add(this->monitorRef, this);
	monitorRef = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	if(!prepare){
		return;
	}
}
int RegionsServer::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void RegionsServer::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
int RegionsServer::getMaxCon(ThreadContext* ctx) throw() 
{
	return maxCon;
}
void RegionsServer::setMaxCon(int maxCon, ThreadContext* ctx) throw() 
{
	this->maxCon = maxCon;
}
MonitorRef* RegionsServer::getMonitorRef(ThreadContext* ctx) throw() 
{
	return monitorRef;
}
void RegionsServer::setMonitorRef(MonitorRef* monitorRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitorRef), monitorRef, MonitorRef);
}
String* RegionsServer::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
RegionsServer* RegionsServer::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	RegionsServer* regions = (new(ctx) RegionsServer(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	IVariableValue* attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1259(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1269(), ctx));
	}
	{
		try
		{
			int port = Integer::parseInt(attr->toString(ctx)->trim(ctx), ctx);
			regions->setPort(port, ctx);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1270(), ctx));
		}
	}
	attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1271(), ctx);
	if(attr != nullptr)
	{
		{
			try
			{
				int n = Integer::parseInt(attr->toString(ctx)->trim(ctx), ctx);
				regions->setMaxCon(n, ctx);
			}
			catch(Throwable* e)
			{
				throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1270(), ctx));
			}
		}
	}
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1258(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1272(), ctx));
	}
		else 
	{
		if(list->size(ctx) != 1)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1273(), ctx));
		}
	}
	MatchCandidate* moncandidate = list->get(0, ctx);
	MonitorRef* monitorRef = MonitorRef::parseInstance(moncandidate, document, matcher, ctx);
	regions->setMonitorRef(monitorRef, ctx);
	result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1274(), ctx);
	list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1275(), ctx));
	}
		else 
	{
		if(list->size(ctx) != 1)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1276(), ctx));
		}
	}
	moncandidate = list->get(0, ctx);
	DomNode* regionDom = moncandidate->getCandidateDom(ctx);
	attr = regionDom->getAttributeValue(ConstStr::getCNST_STR_1115(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1277(), ctx));
	}
	__GC_MV(regions, &(regions->region), attr->toString(ctx)->trim(ctx), String);
	return regions;
}
}}}}

