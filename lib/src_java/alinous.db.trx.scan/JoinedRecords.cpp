#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.trx.scan/JoinedRecords.h"

namespace alinous {namespace db {namespace trx {namespace scan {





bool JoinedRecords::__init_done = __init_static_variables();
bool JoinedRecords::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinedRecords", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinedRecords::JoinedRecords(ThreadContext* ctx) throw()  : IObject(ctx), oid(0), lockingMode(0), tableId(nullptr)
{
}
void JoinedRecords::__construct_impl(ThreadContext* ctx) throw() 
{
}
 JoinedRecords::JoinedRecords(ScanTableIdentifier* tableId, long long oid, int lockingMode, ThreadContext* ctx) throw()  : IObject(ctx), oid(0), lockingMode(0), tableId(nullptr)
{
	this->oid = oid;
	this->lockingMode = lockingMode;
}
void JoinedRecords::__construct_impl(ScanTableIdentifier* tableId, long long oid, int lockingMode, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	this->lockingMode = lockingMode;
}
 JoinedRecords::~JoinedRecords() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinedRecords::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinedRecords", L"~JoinedRecords");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	if(!prepare){
		return;
	}
}
JoinedRecords* JoinedRecords::copy(ThreadContext* ctx) throw() 
{
	JoinedRecords* newRec = (new(ctx) JoinedRecords(ctx));
	newRec->oid = this->oid;
	newRec->lockingMode = this->lockingMode;
	__GC_MV(newRec, &(newRec->tableId), this->tableId, ScanTableIdentifier);
	return newRec;
}
int JoinedRecords::getArchiveSize(ThreadContext* ctx) throw() 
{
	return 8 + 4 + tableId->getArchiveSize(ctx);
}
void JoinedRecords::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putLong(this->oid, ctx);
	builder->putInt(this->lockingMode, ctx);
	this->tableId->appendToEntry(builder, ctx);
}
long long JoinedRecords::getOid(ThreadContext* ctx) throw() 
{
	return oid;
}
void JoinedRecords::setOid(long long oid, ThreadContext* ctx) throw() 
{
	this->oid = oid;
}
int JoinedRecords::getLockingMode(ThreadContext* ctx) throw() 
{
	return lockingMode;
}
void JoinedRecords::setLockingMode(int lockingMode, ThreadContext* ctx) throw() 
{
	this->lockingMode = lockingMode;
}
ScanTableIdentifier* JoinedRecords::getTableId(ThreadContext* ctx) throw() 
{
	return tableId;
}
JoinedRecords* JoinedRecords::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	JoinedRecords* rec = (new(ctx) JoinedRecords(ctx));
	rec->oid = fetcher->fetchLong(ctx);
	rec->lockingMode = fetcher->fetchInt(ctx);
	__GC_MV(rec, &(rec->tableId), ScanTableIdentifier::valueFromFetcher(fetcher, ctx), ScanTableIdentifier);
	return rec;
}
void JoinedRecords::__cleanUp(ThreadContext* ctx){
}
}}}}

