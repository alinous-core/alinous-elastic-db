#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {





bool RemoteClientSerializableTrx::__init_done = __init_static_variables();
bool RemoteClientSerializableTrx::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteClientSerializableTrx", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteClientSerializableTrx::RemoteClientSerializableTrx(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteClientTransaction(mgr, tmpDir, database, core, commitId, ctx)
{
}
void RemoteClientSerializableTrx::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() 
{
}
 RemoteClientSerializableTrx::~RemoteClientSerializableTrx() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteClientSerializableTrx::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteClientTransaction::__releaseRegerences(true, ctx);
}
bool RemoteClientSerializableTrx::isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx)
{
	return false;
}
}}}}}

