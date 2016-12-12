#include "includes.h"


namespace alinous {namespace btree {





bool KeyValueFactory::__init_done = __init_static_variables();
bool KeyValueFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"KeyValueFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 KeyValueFactory::~KeyValueFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void KeyValueFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
BTreeValues* KeyValueFactory::valuesFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	BTreeValues* values = (new(ctx) BTreeValues(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* val = valueFromFetcher(fetcher, ctx);
		values->addValue(val, ctx);
	}
	return values;
}
IBTreeValue* KeyValueFactory::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	IBTreeValue* value = nullptr;
	int valueType = fetcher->fetchInt(ctx);
	switch(valueType) {
	case IBTreeValue::TYPE_INT:
		value = (new(ctx) IntValue(fetcher->fetchInt(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_LONG:
		value = (new(ctx) LongValue(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_STRING:
		value = (new(ctx) StringValue(fetcher->fetchString(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_TIMESTAMP:
		value = (new(ctx) TimestampValue(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_DOUBLE:
		value = (new(ctx) DoubleValue(fetcher->fetchDouble(ctx), ctx));
		break ;
	case IBTreeValue::TYPE_SCHEME:
		{
			try
			{
				value = SchemaManager::valueFromFetcher(fetcher, ctx);
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) VariableException(ConstStr::getCNST_STR_1574(), e, ctx));
			}
		}
		break ;
	case IBTreeValue::TYPE_CACHE_RECORD:
		value = CachedRecord::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_DATABASE_RECORD:
		value = DatabaseRecord::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_SCAN_RESULT_RECORD:
		value = ScanResultRecord::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_DOM_VARIABLE_RECORD:
		value = DomVariable::valueFromFetcher(fetcher, ctx);
		break ;
	case IBTreeValue::TYPE_TABLE_INDEX_VALUE:
		value = TableIndexValue::fetcher->valueFromFetcher(fetcher, ctx);
		break ;
	}
	return value;
}
IBTreeKey* KeyValueFactory::keyFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int keyType = fetcher->fetchInt(ctx);
	IBTreeKey* key = 0;
	switch(keyType) {
	case IBTreeKey::TYPE_INT:
		key = (new(ctx) IntKey(fetcher->fetchInt(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_LONG:
		key = (new(ctx) LongKey(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_STRING:
		key = (new(ctx) StringKey(fetcher->fetchString(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_DOUBLE:
		key = (new(ctx) DoubleKey(fetcher->fetchDouble(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_TIMESTAMP:
		key = (new(ctx) TimestampKey(fetcher->fetchLong(ctx), ctx));
		break ;
	case IBTreeKey::TYPE_BTREE_INDEX_KEY:
		key = BTreeIndexKey::fetchFromEntry(fetcher, ctx);
		break ;
	default:
		key = nullptr;
		break ;
	}
	return key;
}
}}

