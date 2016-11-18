#include "includes.h"


namespace alinous {namespace db {namespace table {





bool DataTableStorageSupport::__init_done = __init_static_variables();
bool DataTableStorageSupport::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DataTableStorageSupport", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DataTableStorageSupport::DataTableStorageSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw()  : IObject(ctx), AbstractDatabaseTable(schema, name, baseDir, ctx), cacheEngine(nullptr)
{
}
void DataTableStorageSupport::__construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() 
{
}
 DataTableStorageSupport::~DataTableStorageSupport() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DataTableStorageSupport::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DataTableStorageSupport", L"~DataTableStorageSupport");
	__e_obj1.add(this->cacheEngine, this);
	cacheEngine = nullptr;
	if(!prepare){
		return;
	}
	AbstractDatabaseTable::__releaseRegerences(true, ctx);
}
IDatabaseRecord* DataTableStorageSupport::loadRecord(long long filePointer, ThreadContext* ctx)
{
	return this->cacheEngine->loadRecord(this, filePointer, ctx);
}
bool DataTableStorageSupport::hasLaterVersionBefore(long long oid, long long commitId, long long currentCommitId, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	indexKey->values->add((new(ctx) VariantValue(oid, ctx)), ctx);
	ArrayList<IBTreeValue>* values = nullptr;
	this->oidIndex->gate->enter(ctx);
	{
		try
		{
			BTreeLeafNode* lnode = this->oidIndex->findByKey(indexKey, ctx);
			values = lnode->getValues(ctx);
		}
		catch(Throwable* e)
		{
			this->oidIndex->gate->exit(ctx);
			throw e;
		}
	}
	this->oidIndex->gate->exit(ctx);
	int maxIndex = values->size(ctx) - 1;
	int i = 0;
	IDatabaseRecord* lastRecord = nullptr;
	for(i = maxIndex; i != -1; --i)
	{
		LongValue* positionValue = static_cast<LongValue*>(values->get(i, ctx));
		lastRecord = this->cacheEngine->loadRecord(this, positionValue->value, ctx);
		long long maxCommitId = lastRecord->getMaxCommitId(ctx);
		if(maxCommitId <= currentCommitId)
		{
			break ;
		}
	}
	if(i == -1)
	{
		return false;
	}
	long long maxCommitId = lastRecord->getMaxCommitId(ctx);
	return maxCommitId != commitId;
}
bool DataTableStorageSupport::hasLaterVersion(long long oid, long long commitId, ThreadContext* ctx)
{
	return !isLatest(oid, commitId, ctx);
}
bool DataTableStorageSupport::isDeleted(long long oid, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	indexKey->values->add((new(ctx) VariantValue(oid, ctx)), ctx);
	ArrayList<IBTreeValue>* values = nullptr;
	this->oidIndex->gate->enter(ctx);
	{
		try
		{
			BTreeLeafNode* lnode = this->oidIndex->findByKey(indexKey, ctx);
			values = lnode->getValues(ctx);
		}
		catch(Throwable* e)
		{
			this->oidIndex->gate->exit(ctx);
			throw e;
		}
	}
	this->oidIndex->gate->exit(ctx);
	int maxIndex = values->size(ctx) - 1;
	LongValue* positionValue = static_cast<LongValue*>(values->get(maxIndex, ctx));
	IDatabaseRecord* lastRecord = this->cacheEngine->loadRecord(this, positionValue->value, ctx);
	return lastRecord->getDeletedCommitId(ctx) != (long long)0;
}
bool DataTableStorageSupport::isLatest(long long oid, long long commitId, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	indexKey->values->add((new(ctx) VariantValue(oid, ctx)), ctx);
	ArrayList<IBTreeValue>* values = nullptr;
	this->oidIndex->gate->enter(ctx);
	{
		try
		{
			BTreeLeafNode* lnode = this->oidIndex->findByKey(indexKey, ctx);
			values = lnode->getValues(ctx);
		}
		catch(Throwable* e)
		{
			this->oidIndex->gate->exit(ctx);
			throw e;
		}
	}
	this->oidIndex->gate->exit(ctx);
	int maxIndex = values->size(ctx) - 1;
	LongValue* positionValue = static_cast<LongValue*>(values->get(maxIndex, ctx));
	IDatabaseRecord* lastRecord = this->cacheEngine->loadRecord(this, positionValue->value, ctx);
	return lastRecord->getMaxCommitId(ctx) == commitId;
}
IDatabaseRecord* DataTableStorageSupport::getLastRecord(long long oid, long long commitId, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	indexKey->values->add((new(ctx) VariantValue(oid, ctx)), ctx);
	ArrayList<IBTreeValue>* values = nullptr;
	this->oidIndex->gate->enter(ctx);
	{
		try
		{
			BTreeLeafNode* lnode = this->oidIndex->findByKey(indexKey, ctx);
			values = lnode->getValues(ctx);
		}
		catch(Throwable* e)
		{
			this->oidIndex->gate->exit(ctx);
			throw e;
		}
	}
	this->oidIndex->gate->exit(ctx);
	int maxIndex = values->size(ctx) - 1;
	for(int i = maxIndex; i != -1; --i)
	{
		LongValue* positionValue = static_cast<LongValue*>(values->get(i, ctx));
		IDatabaseRecord* lastRecord = this->cacheEngine->loadRecord(this, positionValue->value, ctx);
		if(lastRecord->getLastUpdateCommitId(ctx) < commitId)
		{
			return lastRecord;
		}
	}
	return nullptr;
}
}}}

