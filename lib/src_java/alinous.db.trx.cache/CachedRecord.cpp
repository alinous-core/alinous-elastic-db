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

namespace alinous {namespace db {namespace trx {namespace cache {





const CachedRecord::ValueFetcher CachedRecord:: __fetcher = (CachedRecord::ValueFetcher(nullptr));
bool CachedRecord::__init_done = __init_static_variables();
bool CachedRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CachedRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CachedRecord::CachedRecord(long long oid, int numColumn, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseRecord(ctx), oid(0), lastUpdateCommitId(0), insertedCommitId(0), deletedCommitId(0), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->oid = oid;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
void CachedRecord::__construct_impl(long long oid, int numColumn, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
 CachedRecord::~CachedRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CachedRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CachedRecord", L"~CachedRecord");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
long long CachedRecord::getOid(ThreadContext* ctx) throw() 
{
	return oid;
}
void CachedRecord::setValue(int index, VariantValue* value, ThreadContext* ctx) throw() 
{
	this->values->set(index, value, ctx);
}
int CachedRecord::getNumColumn(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
VariantValue* CachedRecord::getColumnValue(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
void CachedRecord::set(int index, VariantValue* vv, ThreadContext* ctx) throw() 
{
	this->values->set(index, vv, ctx);
}
void CachedRecord::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_CACHE_RECORD, ctx);
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
int CachedRecord::diskSize(ThreadContext* ctx)
{
	int total = 8;
	total += 8 * 2;
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* val = this->values->get(i, ctx);
		total += val->bufferSize(ctx);
	}
	return total;
}
IValueFetcher* CachedRecord::getFetcher(ThreadContext* ctx) throw() 
{
	return fetcher;
}
bool CachedRecord::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->oid == (dynamic_cast<CachedRecord*>(obj))->oid;
}
int CachedRecord::getNumValues(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
String* CachedRecord::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = this->values->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(vv->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
long long CachedRecord::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return lastUpdateCommitId;
}
long long CachedRecord::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return insertedCommitId;
}
long long CachedRecord::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return deletedCommitId;
}
void CachedRecord::setLastUpdateCommitId(long long lastUpdateCommitId, ThreadContext* ctx) throw() 
{
	this->lastUpdateCommitId = lastUpdateCommitId;
}
void CachedRecord::setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw() 
{
	this->insertedCommitId = insertedCommitId;
}
void CachedRecord::setDeletedCommitId(long long deletedCommitId, ThreadContext* ctx) throw() 
{
	this->deletedCommitId = deletedCommitId;
}
ArrayList<VariantValue>* CachedRecord::getValues(ThreadContext* ctx) throw() 
{
	return this->values;
}
int CachedRecord::getKind(ThreadContext* ctx) throw() 
{
	return IDatabaseRecord::TRX_CACHE;
}
void CachedRecord::addValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
	this->values->add(vv, ctx);
}
long long CachedRecord::getMaxCommitId(ThreadContext* ctx) throw() 
{
	long long commitId = this->lastUpdateCommitId < this->insertedCommitId ? this->insertedCommitId : this->lastUpdateCommitId;
	return commitId > this->deletedCommitId ? commitId : this->deletedCommitId;
}
void CachedRecord::setOid(long long oid, ThreadContext* ctx) throw() 
{
	this->oid = oid;
}
long long CachedRecord::getPosition(ThreadContext* ctx) throw() 
{
	return -1;
}
CachedRecord* CachedRecord::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	long long oid = fetcher->fetchLong(ctx);
	int maxLoop = fetcher->fetchInt(ctx);
	CachedRecord* rec = (new(ctx) CachedRecord(oid, maxLoop, ctx));
	long long uid = fetcher->fetchLong(ctx);
	long long iid = fetcher->fetchLong(ctx);
	rec->lastUpdateCommitId = uid;
	rec->setInsertedCommitId(iid, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = VariantValue::valueFromFetcher(fetcher, ctx);
		rec->setValue(i, variant, ctx);
	}
	return rec;
}
void CachedRecord::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace db {namespace trx {namespace cache {





bool CachedRecord::ValueFetcher::__init_done = __init_static_variables();
bool CachedRecord::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CachedRecord::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CachedRecord::ValueFetcher::ValueFetcher(ThreadContext* ctx) throw()  : IObject(ctx), IValueFetcher(ctx)
{
}
void CachedRecord::ValueFetcher::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CachedRecord::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CachedRecord::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* CachedRecord::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	return CachedRecord::valueFromFetcher(fetcher, ctx);
}
void CachedRecord::ValueFetcher::__cleanUp(ThreadContext* ctx){
}
}}}}

