#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {





bool DatabaseTableClient::__init_done = __init_static_variables();
bool DatabaseTableClient::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseTableClient", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseTableClient::~DatabaseTableClient() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseTableClient::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
Integer* DatabaseTableClient::getTableId(ThreadContext* ctx) throw() 
{
	return nullptr;
}
int DatabaseTableClient::getColumnCount(ThreadContext* ctx) throw() 
{
	return 0;
}
IScannableIndex* DatabaseTableClient::getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw() 
{
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getPrimaryIndex(ThreadContext* ctx) throw() 
{
	return nullptr;
}
TableMetadata* DatabaseTableClient::getMetadata(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IDatabaseRecord* DatabaseTableClient::loadRecord(long long position, ThreadContext* ctx)
{
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getAbailableIndex(ArrayList<String>* columnsStr, ThreadContext* ctx) throw() 
{
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw() 
{
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	return nullptr;
}
IThreadLocker* DatabaseTableClient::newThreadLocker(String* fullName, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DatabaseTableClient::updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
bool DatabaseTableClient::hasLaterVersion(long long oid, long long currentId, ThreadContext* ctx)
{
	return false;
}
bool DatabaseTableClient::hasLaterVersionBefore(long long oid, long long maxCommitId, long long currentCommitId, ThreadContext* ctx)
{
	return false;
}
String* DatabaseTableClient::getName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DatabaseTableClient::open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::lockStorage(ThreadContext* ctx)
{
}
void DatabaseTableClient::unlockStorage(ThreadContext* ctx)
{
}
ArrayList<IScannableIndex>* DatabaseTableClient::getIndexes(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DatabaseTableClient::insertData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
}
void DatabaseTableClient::createIndex(String* getindexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::close(ThreadContext* ctx) throw() 
{
}
String* DatabaseTableClient::getFullName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
}}}}

