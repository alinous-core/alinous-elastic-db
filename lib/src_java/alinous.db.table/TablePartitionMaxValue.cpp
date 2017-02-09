#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TablePartitionMaxValue::__init_done = __init_static_variables();
bool TablePartitionMaxValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TablePartitionMaxValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TablePartitionMaxValue::~TablePartitionMaxValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TablePartitionMaxValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TablePartitionMaxValue", L"~TablePartitionMaxValue");
	__e_obj1.add(this->values, this);
	values = nullptr;
	__e_obj1.add(this->subvalues, this);
	subvalues = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionMaxValue::addValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	if(this->values == nullptr)
	{
		GCUtils<List<VariantValue> >::mv(this, &(this->values), (new(ctx) ArrayList<VariantValue>(ctx)), ctx);
	}
	this->values->add(value, ctx);
}
void TablePartitionMaxValue::addSubValue(VariantValue* value, ThreadContext* ctx) throw() 
{
	if(this->subvalues == nullptr)
	{
		GCUtils<List<VariantValue> >::mv(this, &(this->subvalues), (new(ctx) ArrayList<VariantValue>(ctx)), ctx);
	}
	this->subvalues->add(value, ctx);
}
int TablePartitionMaxValue::fileSize(ThreadContext* ctx)
{
	int total = 0;
	bool isnull = (this->values == nullptr);
	total += 1;
	if(!isnull)
	{
		int maxLoop = this->values->size(ctx);
		total += 4;
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = this->values->get(i, ctx);
			total += value->bufferSize(ctx);
		}
	}
	isnull = (this->subvalues == nullptr);
	total += 1;
	if(!isnull)
	{
		int maxLoop = this->subvalues->size(ctx);
		total += 4;
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = this->subvalues->get(i, ctx);
			total += value->bufferSize(ctx);
		}
	}
	return total;
}
void TablePartitionMaxValue::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	bool isnull = (this->values == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		int maxLoop = this->values->size(ctx);
		builder->putInt(maxLoop, ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = this->values->get(i, ctx);
			value->appendToEntry(builder, ctx);
		}
	}
	isnull = (this->subvalues == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		int maxLoop = this->subvalues->size(ctx);
		builder->putInt(maxLoop, ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = this->subvalues->get(i, ctx);
			value->appendToEntry(builder, ctx);
		}
	}
}
void TablePartitionMaxValue::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			IAlinousVariable* vl = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
			if(vl == nullptr || !((dynamic_cast<VariantValue*>(vl) != 0)))
			{
				throw (new(ctx) VariableException(ConstStr::getCNST_STR_1693(), ctx));
			}
			VariantValue* value = static_cast<VariantValue*>(vl);
			addValue(value, ctx);
		}
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = (new(ctx) VariantValue(ctx));
			value->readData(buff, ctx);
			addSubValue(value, ctx);
		}
	}
}
void TablePartitionMaxValue::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool isnull = (this->values == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		int maxLoop = this->values->size(ctx);
		buff->putInt(maxLoop, ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = this->values->get(i, ctx);
			value->writeData(buff, ctx);
		}
	}
	isnull = (this->subvalues == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		int maxLoop = this->subvalues->size(ctx);
		buff->putInt(maxLoop, ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = this->subvalues->get(i, ctx);
			value->writeData(buff, ctx);
		}
	}
}
TablePartitionMaxValue* TablePartitionMaxValue::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TablePartitionMaxValue* maxValue = (new(ctx) TablePartitionMaxValue(ctx));
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		int maxLoop = fetcher->fetchInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = VariantValue::valueFromFetcher(fetcher, ctx);
			maxValue->addValue(value, ctx);
		}
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		int maxLoop = fetcher->fetchInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			VariantValue* value = VariantValue::valueFromFetcher(fetcher, ctx);
			maxValue->addSubValue(value, ctx);
		}
	}
	return maxValue;
}
TablePartitionMaxValue* TablePartitionMaxValue::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TablePartitionMaxValue* value = (new(ctx) TablePartitionMaxValue(ctx));
	value->readData(buff, ctx);
	return value;
}
}}}

