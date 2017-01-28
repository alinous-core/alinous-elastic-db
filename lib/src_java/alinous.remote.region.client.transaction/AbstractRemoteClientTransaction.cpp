#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {





bool AbstractRemoteClientTransaction::__init_done = __init_static_variables();
bool AbstractRemoteClientTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractRemoteClientTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractRemoteClientTransaction::AbstractRemoteClientTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw()  : IObject(ctx), DbTransaction(mgr, tmpDir, database, core, commitId, ctx)
{
}
void AbstractRemoteClientTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() 
{
}
 AbstractRemoteClientTransaction::~AbstractRemoteClientTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractRemoteClientTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DbTransaction::__releaseRegerences(true, ctx);
}
void AbstractRemoteClientTransaction::createTable(TableSchema* schema, ThreadContext* ctx)
{
	if(schema->getregionName(ctx) == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3577(), ctx));
	}
	DbTransaction::createTable(schema, ctx);
}
}}}}}

