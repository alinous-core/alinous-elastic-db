#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TablePartitionRange::__init_done = __init_static_variables();
bool TablePartitionRange::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TablePartitionRange", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TablePartitionRange::TablePartitionRange(TablePartitionKey* key, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), key(nullptr), max(GCUtils<List<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L"")), min(GCUtils<List<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->key), key, TablePartitionKey);
}
void TablePartitionRange::__construct_impl(TablePartitionKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, TablePartitionKey);
}
 TablePartitionRange::~TablePartitionRange() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TablePartitionRange::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TablePartitionRange", L"~TablePartitionRange");
	__e_obj1.add(this->key, this);
	key = nullptr;
	__e_obj1.add(this->max, this);
	max = nullptr;
	__e_obj1.add(this->min, this);
	min = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionRange::addMaxKeyValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	this->max->add(value, ctx);
}
void TablePartitionRange::addMinKeyValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	this->min->add(value, ctx);
}
TablePartitionKey* TablePartitionRange::getKey(ThreadContext* ctx) throw() 
{
	return key;
}
List<VariantValue>* TablePartitionRange::getMax(ThreadContext* ctx) throw() 
{
	return max;
}
List<VariantValue>* TablePartitionRange::getMin(ThreadContext* ctx) throw() 
{
	return min;
}
int TablePartitionRange::fileSize(ThreadContext* ctx)
{
	int total = this->key->fileSize(ctx);
	int maxLoop = this->max->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->max->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	maxLoop = this->min->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->min->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	return total;
}
void TablePartitionRange::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	this->key->toFileEntry(builder, ctx);
	int maxLoop = this->max->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->max->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
	maxLoop = this->min->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->min->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
}
void TablePartitionRange::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__GC_MV(this, &(this->key), TablePartitionKey::fromNetwork(buff, ctx), TablePartitionKey);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = (new(ctx) VariantValue(ctx));
		vv->readData(buff, ctx);
		this->max->add(vv, ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = (new(ctx) VariantValue(ctx));
		vv->readData(buff, ctx);
		this->min->add(vv, ctx);
	}
}
void TablePartitionRange::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->key->writeData(buff, ctx);
	int maxLoop = this->max->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = this->max->get(i, ctx);
		vv->writeData(buff, ctx);
	}
	maxLoop = this->min->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = this->min->get(i, ctx);
		vv->writeData(buff, ctx);
	}
}
TablePartitionRange* TablePartitionRange::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TablePartitionRange* range = (new(ctx) TablePartitionRange(ctx));
	__GC_MV(range, &(range->key), TablePartitionKey::loadFromFetcher(fetcher, ctx), TablePartitionKey);
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = VariantValue::valueFromFetcher(fetcher, ctx);
		range->max->add(vv, ctx);
	}
	maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = VariantValue::valueFromFetcher(fetcher, ctx);
		range->min->add(vv, ctx);
	}
	return range;
}
TablePartitionRange* TablePartitionRange::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TablePartitionRange* range = (new(ctx) TablePartitionRange(ctx));
	range->readData(buff, ctx);
	return range;
}
}}}

