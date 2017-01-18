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
	__e_obj1.add(this->regions, this);
	regions = nullptr;
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
Regions* Monitor::getRegions(ThreadContext* ctx) throw() 
{
	return regions;
}
void Monitor::setRegions(Regions* regions, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->regions), regions, Regions);
}
Monitor* Monitor::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	Monitor* ref = (new(ctx) Monitor(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	IVariableValue* attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1259(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1279(), ctx));
	}
	ref->setPort(attr->toString(ctx)->trim(ctx), ctx);
	attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_1271(), ctx);
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
				throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1280(), ctx));
			}
		}
	}
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_1281(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1282(), ctx));
	}
		else 
	{
		if(list->size(ctx) != 1)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_1283(), ctx));
		}
	}
	MatchCandidate* regionsCandidate = list->get(0, ctx);
	Regions* regions = Regions::parseInstance(regionsCandidate, document, matcher, ctx);
	ref->setRegions(regions, ctx);
	return ref;
}
}}}}

