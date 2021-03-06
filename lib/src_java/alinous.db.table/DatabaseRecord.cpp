#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/DatabaseRecord.h"

namespace alinous {namespace db {namespace table {





bool DatabaseRecord::__init_done = __init_static_variables();
bool DatabaseRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseRecord::DatabaseRecord(long long oid, int numColumn, long long CommitId, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseRecord(ctx), position(0), oid(0), lastUpdateCommitId(0), insertedCommitId(0), deletedCommitId(0), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L"")), storageForCache(nullptr), hashcode(0)
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
void DatabaseRecord::__construct_impl(long long oid, int numColumn, long long CommitId, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
 DatabaseRecord::DatabaseRecord(long long oid, int numColumn, long long CommitId, IDatabaseRecord* data, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseRecord(ctx), position(0), oid(0), lastUpdateCommitId(0), insertedCommitId(0), deletedCommitId(0), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L"")), storageForCache(nullptr), hashcode(0)
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add(data->getColumnValue(i, ctx), ctx);
	}
}
void DatabaseRecord::__construct_impl(long long oid, int numColumn, long long CommitId, IDatabaseRecord* data, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	this->lastUpdateCommitId = 0;
	this->insertedCommitId = CommitId;
	this->deletedCommitId = 0;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add(data->getColumnValue(i, ctx), ctx);
	}
}
 DatabaseRecord::~DatabaseRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseRecord", L"~DatabaseRecord");
	__e_obj1.add(this->values, this);
	values = nullptr;
	__e_obj1.add(this->storageForCache, this);
	storageForCache = nullptr;
	if(!prepare){
		return;
	}
}
int DatabaseRecord::getNumValues(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
VariantValue* DatabaseRecord::getColumnValue(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
void DatabaseRecord::setValue(int index, VariantValue* value, ThreadContext* ctx) throw() 
{
	this->values->set(index, value, ctx);
}
void DatabaseRecord::addValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
	this->values->add(vv, ctx);
}
void DatabaseRecord::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_DATABASE_RECORD, ctx);
	builder->putLong(this->oid, ctx);
	builder->putLong(this->lastUpdateCommitId, ctx);
	builder->putLong(this->insertedCommitId, ctx);
	builder->putLong(this->deletedCommitId, ctx);
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = this->values->get(i, ctx);
		variant->appendToEntry(builder, ctx);
	}
}
int DatabaseRecord::diskSize(ThreadContext* ctx)
{
	int total = 4 + 8;
	total += 8 * 3;
	int maxLoop = this->values->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* val = this->values->get(i, ctx);
		total += val->bufferSize(ctx);
	}
	return total;
}
IValueFetcher* DatabaseRecord::getFetcher(ThreadContext* ctx) throw() 
{
	return (new(ctx) DatabaseRecord::ValueFetcher(ctx));
}
long long DatabaseRecord::getOid(ThreadContext* ctx) throw() 
{
	return oid;
}
void DatabaseRecord::setOid(long long oid, ThreadContext* ctx) throw() 
{
	this->oid = oid;
}
long long DatabaseRecord::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return lastUpdateCommitId;
}
void DatabaseRecord::setLastUpdateCommitId(long long lastUpdateCommitId, ThreadContext* ctx) throw() 
{
	this->lastUpdateCommitId = lastUpdateCommitId;
}
long long DatabaseRecord::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return insertedCommitId;
}
void DatabaseRecord::setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw() 
{
	this->insertedCommitId = insertedCommitId;
}
long long DatabaseRecord::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return deletedCommitId;
}
void DatabaseRecord::setDeletedCommitId(long long deletedCommitId, ThreadContext* ctx) throw() 
{
	this->deletedCommitId = deletedCommitId;
}
long long DatabaseRecord::getMaxCommitId(ThreadContext* ctx) throw() 
{
	return this->insertedCommitId < this->lastUpdateCommitId ? this->lastUpdateCommitId : this->insertedCommitId;
}
String* DatabaseRecord::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = this->values->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(variant->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
long long DatabaseRecord::getPosition(ThreadContext* ctx) throw() 
{
	return position;
}
void DatabaseRecord::setPosition(long long position, ThreadContext* ctx) throw() 
{
	this->position = position;
}
bool DatabaseRecord::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this == obj;
}
int DatabaseRecord::getHashKey(ThreadContext* ctx) throw() 
{
	return this->hashcode;
}
IDatabaseTable* DatabaseRecord::getStorageForCache(ThreadContext* ctx) throw() 
{
	return storageForCache;
}
void DatabaseRecord::setStorageForCache(IDatabaseTable* storageForCache, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->storageForCache), storageForCache, IDatabaseTable);
	this->hashcode = ((int)(((unsigned long long)((this->position + this->storageForCache->getTableId(ctx)->intValue(ctx)) * 2654404609L))>> 32));
}
ArrayList<VariantValue>* DatabaseRecord::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
int DatabaseRecord::getKind(ThreadContext* ctx) throw() 
{
	return IDatabaseRecord::NORMAL_RECORD;
}
int DatabaseRecord::getNumColumn(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
int DatabaseRecord::getLockMode(ThreadContext* ctx) throw() 
{
	return -1;
}
void DatabaseRecord::setLockMode(int lockMode, ThreadContext* ctx) throw() 
{
}
DatabaseRecord* DatabaseRecord::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	long long oid = fetcher->fetchLong(ctx);
	long long uid = fetcher->fetchLong(ctx);
	long long iid = fetcher->fetchLong(ctx);
	long long did = fetcher->fetchLong(ctx);
	int maxLoop = fetcher->fetchInt(ctx);
	DatabaseRecord* rec = (new(ctx) DatabaseRecord(oid, maxLoop, 0, ctx));
	rec->setPosition(fetcher->getPosition(ctx), ctx);
	rec->lastUpdateCommitId = uid;
	rec->setInsertedCommitId(iid, ctx);
	rec->setDeletedCommitId(did, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = VariantValue::valueFromFetcher(fetcher, ctx);
		rec->setValue(i, variant, ctx);
	}
	return rec;
}
void DatabaseRecord::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace db {namespace table {





bool DatabaseRecord::ValueFetcher::__init_done = __init_static_variables();
bool DatabaseRecord::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseRecord::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseRecord::ValueFetcher::ValueFetcher(ThreadContext* ctx) throw()  : IObject(ctx), IValueFetcher(ctx)
{
}
void DatabaseRecord::ValueFetcher::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DatabaseRecord::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseRecord::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* DatabaseRecord::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	return CachedRecord::valueFromFetcher(fetcher, ctx);
}
void DatabaseRecord::ValueFetcher::__cleanUp(ThreadContext* ctx){
}
}}}

