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
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxLockContext", L"~TrxLockContext");
	__e_obj1.add(this->map, this);
	map = nullptr;
	if(!prepare){
		return;
	}
}
void TrxLockContext::reset(ThreadContext* ctx)
{
	Iterator<String>* it = this->map->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		IThreadLocker* locker = this->map->get(key, ctx);
		locker->dispose(ctx);
	}
	this->map->clear(ctx);
}
void TrxLockContext::shareLockTable(IDatabaseTable* tableStore, ThreadContext* ctx)
{
	IThreadLocker* locker = getLocker(tableStore, ctx);
	tableStore->shareLockTable(locker, ctx);
}
void TrxLockContext::shareUnlockTable(IDatabaseTable* tableStore, ThreadContext* ctx)
{
	IThreadLocker* locker = getLocker(tableStore, ctx);
	tableStore->shareUnlockTable(locker, ctx);
}
void TrxLockContext::shareUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx)
{
	IThreadLocker* locker = getLocker(tableStore, ctx);
	tableStore->shareUnlockRow(oid, locker, ctx);
}
void TrxLockContext::updateUnlockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx)
{
	IThreadLocker* locker = getLocker(tableStore, ctx);
	tableStore->updateUnlockRow(oid, locker, ctx);
}
void TrxLockContext::shareLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx)
{
	IThreadLocker* locker = getLocker(tableStore, ctx);
	tableStore->shareLockRow(oid, locker, ctx);
}
void TrxLockContext::updateLockRow(IDatabaseTable* tableStore, long long oid, ThreadContext* ctx)
{
	IThreadLocker* locker = getLocker(tableStore, ctx);
	tableStore->updateLockRow(oid, locker, ctx);
}
IThreadLocker* TrxLockContext::getLocker(IDatabaseTable* tableStore, ThreadContext* ctx) throw() 
{
	String* name = tableStore->getFullName(ctx);
	IThreadLocker* locker = this->map->get(name, ctx);
	if(locker != nullptr)
	{
		return locker;
	}
	locker = tableStore->newThreadLocker(name, ctx);
	this->map->put(name, locker, ctx);
	return locker;
}
}}}

