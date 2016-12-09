#include "includes.h"


namespace alinous {namespace remote {namespace monitor {





bool TransactionMonitorServer::__init_done = __init_static_variables();
bool TransactionMonitorServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TransactionMonitorServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TransactionMonitorServer::TransactionMonitorServer(int port, ThreadContext* ctx) throw()  : IObject(ctx), port(0), lastCommitId(0), lastOid(0)
{
	this->port = port;
}
void TransactionMonitorServer::__construct_impl(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
 TransactionMonitorServer::~TransactionMonitorServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TransactionMonitorServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TransactionMonitorServer", L"~TransactionMonitorServer");
	if(!prepare){
		return;
	}
}
void TransactionMonitorServer::start(ThreadContext* ctx) throw() 
{
}
void TransactionMonitorServer::dispose(ThreadContext* ctx) throw() 
{
}
int TransactionMonitorServer::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
long long TransactionMonitorServer::getNextCommitId(ThreadContext* ctx) throw() 
{
	this->lastCommitId ++ ;
	return lastCommitId;
}
long long TransactionMonitorServer::getNextOid(ThreadContext* ctx) throw() 
{
	this->lastOid ++ ;
	return lastOid;
}
}}}

