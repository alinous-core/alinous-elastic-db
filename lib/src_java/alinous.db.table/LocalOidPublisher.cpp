#include "includes.h"


namespace alinous {namespace db {namespace table {





bool LocalOidPublisher::__init_done = __init_static_variables();
bool LocalOidPublisher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LocalOidPublisher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LocalOidPublisher::LocalOidPublisher(int nextOid, ThreadContext* ctx) throw()  : IObject(ctx), IOidPublisher(ctx), nextOid(0)
{
	this->nextOid = nextOid;
}
void LocalOidPublisher::__construct_impl(int nextOid, ThreadContext* ctx) throw() 
{
	this->nextOid = nextOid;
}
 LocalOidPublisher::~LocalOidPublisher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LocalOidPublisher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LocalOidPublisher", L"~LocalOidPublisher");
	if(!prepare){
		return;
	}
}
long long LocalOidPublisher::newOid(ThreadContext* ctx) throw() 
{
	long long oid = this->nextOid;
	this->nextOid ++ ;
	return oid;
}
}}}

