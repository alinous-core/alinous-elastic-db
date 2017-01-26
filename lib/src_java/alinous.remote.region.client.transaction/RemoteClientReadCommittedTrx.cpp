#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {





bool RemoteClientReadCommittedTrx::__init_done = __init_static_variables();
bool RemoteClientReadCommittedTrx::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteClientReadCommittedTrx", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteClientReadCommittedTrx::RemoteClientReadCommittedTrx(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteClientTransaction(mgr, tmpDir, database, core, commitId, ctx)
{
}
void RemoteClientReadCommittedTrx::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() 
{
}
 RemoteClientReadCommittedTrx::~RemoteClientReadCommittedTrx() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteClientReadCommittedTrx::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteClientTransaction::__releaseRegerences(true, ctx);
}
bool RemoteClientReadCommittedTrx::isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx)
{
	return false;
}
}}}}}

