#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {





bool RemoteClientRepeatableReadTrx::__init_done = __init_static_variables();
bool RemoteClientRepeatableReadTrx::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteClientRepeatableReadTrx", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteClientRepeatableReadTrx::RemoteClientRepeatableReadTrx(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteClientTransaction(mgr, tmpDir, database, core, commitId, ctx)
{
}
void RemoteClientRepeatableReadTrx::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() 
{
}
 RemoteClientRepeatableReadTrx::~RemoteClientRepeatableReadTrx() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteClientRepeatableReadTrx::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteClientTransaction::__releaseRegerences(true, ctx);
}
bool RemoteClientRepeatableReadTrx::isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx)
{
	return false;
}
}}}}}

