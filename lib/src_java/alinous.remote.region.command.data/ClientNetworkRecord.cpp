#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace data {





bool ClientNetworkRecord::__init_done = __init_static_variables();
bool ClientNetworkRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientNetworkRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientNetworkRecord::ClientNetworkRecord(long long oid, int numColumn, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseRecord(ctx), ICommandData(ctx), oid(0), lastUpdateCommitId(0), insertedCommitId(0), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->oid = oid;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
void ClientNetworkRecord::__construct_impl(long long oid, int numColumn, ThreadContext* ctx) throw() 
{
	this->oid = oid;
	for(int i = 0; i != numColumn; ++i)
	{
		this->values->add((new(ctx) VariantValue(ctx)), ctx);
	}
}
 ClientNetworkRecord::ClientNetworkRecord(IDatabaseRecord* databaseRecord, ThreadContext* ctx) : IObject(ctx), IDatabaseRecord(ctx), ICommandData(ctx), oid(0), lastUpdateCommitId(0), insertedCommitId(0), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->oid = databaseRecord->getOid(ctx);
	this->lastUpdateCommitId = databaseRecord->getLastUpdateCommitId(ctx);
	this->insertedCommitId = databaseRecord->getInsertedCommitId(ctx);
	ArrayList<VariantValue>* list = databaseRecord->getValues(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = list->get(i, ctx);
		this->values->add(static_cast<VariantValue*>(vv->copy(ctx)), ctx);
	}
}
void ClientNetworkRecord::__construct_impl(IDatabaseRecord* databaseRecord, ThreadContext* ctx)
{
	this->oid = databaseRecord->getOid(ctx);
	this->lastUpdateCommitId = databaseRecord->getLastUpdateCommitId(ctx);
	this->insertedCommitId = databaseRecord->getInsertedCommitId(ctx);
	ArrayList<VariantValue>* list = databaseRecord->getValues(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = list->get(i, ctx);
		this->values->add(static_cast<VariantValue*>(vv->copy(ctx)), ctx);
	}
}
 ClientNetworkRecord::~ClientNetworkRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientNetworkRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientNetworkRecord", L"~ClientNetworkRecord");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void ClientNetworkRecord::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeValue::TYPE_CACHE_RECORD, ctx);
	builder->putLong(this->oid, ctx);
	builder->putLong(this->lastUpdateCommitId, ctx);
	builder->putLong(this->insertedCommitId, ctx);
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* variant = this->values->get(i, ctx);
		variant->appendToEntry(builder, ctx);
	}
}
int ClientNetworkRecord::diskSize(ThreadContext* ctx)
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
IValueFetcher* ClientNetworkRecord::getFetcher(ThreadContext* ctx) throw() 
{
	return nullptr;
}
int ClientNetworkRecord::getKind(ThreadContext* ctx) throw() 
{
	return IDatabaseRecord::TRX_CACHE;
}
VariantValue* ClientNetworkRecord::getColumnValue(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
int ClientNetworkRecord::getNumValues(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
long long ClientNetworkRecord::getInsertedCommitId(ThreadContext* ctx) throw() 
{
	return this->insertedCommitId;
}
long long ClientNetworkRecord::getLastUpdateCommitId(ThreadContext* ctx) throw() 
{
	return this->lastUpdateCommitId;
}
long long ClientNetworkRecord::getDeletedCommitId(ThreadContext* ctx) throw() 
{
	return 0;
}
ArrayList<VariantValue>* ClientNetworkRecord::getValues(ThreadContext* ctx) throw() 
{
	return this->values;
}
void ClientNetworkRecord::setValue(int index, VariantValue* value, ThreadContext* ctx) throw() 
{
	this->values->set(index, value, ctx);
}
void ClientNetworkRecord::addValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
	this->values->add(vv, ctx);
}
long long ClientNetworkRecord::getOid(ThreadContext* ctx) throw() 
{
	return this->oid;
}
long long ClientNetworkRecord::getMaxCommitId(ThreadContext* ctx) throw() 
{
	long long commitId = this->lastUpdateCommitId < this->insertedCommitId ? this->insertedCommitId : this->lastUpdateCommitId;
	return commitId;
}
int ClientNetworkRecord::getNumColumn(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
void ClientNetworkRecord::setLastUpdateCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->lastUpdateCommitId = commitId;
}
void ClientNetworkRecord::setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw() 
{
	this->insertedCommitId = insertedCommitId;
}
void ClientNetworkRecord::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->oid = buff->getLong(ctx);
	this->lastUpdateCommitId = buff->getLong(ctx);
	this->insertedCommitId = buff->getLong(ctx);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		if(val == nullptr || !((dynamic_cast<VariantValue*>(val) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_3587(), ctx));
		}
		VariantValue* variant = static_cast<VariantValue*>(val);
		this->values->add(variant, ctx);
	}
}
void ClientNetworkRecord::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putLong(this->oid, ctx);
	buff->putLong(this->lastUpdateCommitId, ctx);
	buff->putLong(this->insertedCommitId, ctx);
	int maxLoop = this->values->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		VariantValue* variant = this->values->get(i, ctx);
		variant->writeData(buff, ctx);
	}
}
bool ClientNetworkRecord::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	long long oid = (dynamic_cast<ClientNetworkRecord*>(obj))->getOid(ctx);
	return this->oid == oid;
}
ClientNetworkRecord* ClientNetworkRecord::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	long long oid = fetcher->fetchLong(ctx);
	int maxLoop = fetcher->fetchInt(ctx);
	ClientNetworkRecord* rec = (new(ctx) ClientNetworkRecord(oid, maxLoop, ctx));
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
}}}}}

