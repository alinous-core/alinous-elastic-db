#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool TrxLockContext::__init_done = __init_static_variables();
bool TrxLockContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxLockContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxLockContext::~TrxLockContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxLockContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void TrxLockContext::shareLockTable(IDatabaseTable* tableStore, ThreadContext* ctx)
{
}
void TrxLockContext::shareUnlockTable(IDatabaseTable* tableStore, ThreadContext* ctx) throw() 
{
}
void TrxLockContext::shareUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() 
{
}
void TrxLockContext::updateUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() 
{
}
void TrxLockContext::shareLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() 
{
}
void TrxLockContext::updateLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx) throw() 
{
}
}}}

