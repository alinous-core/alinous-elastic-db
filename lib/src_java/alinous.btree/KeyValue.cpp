#include "includes.h"


namespace alinous {namespace btree {





bool KeyValue::__init_done = __init_static_variables();
bool KeyValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"KeyValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 KeyValue::KeyValue(IBTreeKey* key, BTreeValues* values, ThreadContext* ctx) throw()  : IObject(ctx), key(nullptr), values(nullptr)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
	__GC_MV(this, &(this->values), values, BTreeValues);
}
void KeyValue::__construct_impl(IBTreeKey* key, BTreeValues* values, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
	__GC_MV(this, &(this->values), values, BTreeValues);
}
 KeyValue::KeyValue(IBTreeKey* key, ThreadContext* ctx) throw()  : IObject(ctx), key(nullptr), values(nullptr)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
	__GC_MV(this, &(values), (new(ctx) BTreeValues(ctx)), BTreeValues);
}
void KeyValue::__construct_impl(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
	__GC_MV(this, &(values), (new(ctx) BTreeValues(ctx)), BTreeValues);
}
 KeyValue::~KeyValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void KeyValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"KeyValue", L"~KeyValue");
	__e_obj1.add(this->key, this);
	key = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void KeyValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	this->key->appendToEntry(builder, ctx);
	this->values->appendToEntry(builder, ctx);
}
int KeyValue::keySize(ThreadContext* ctx)
{
	return this->key->size(ctx);
}
int KeyValue::valueSize(ThreadContext* ctx)
{
	return this->values->size(ctx);
}
IBTreeKey* KeyValue::getKey(ThreadContext* ctx) throw() 
{
	return key;
}
void KeyValue::setKey(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
BTreeValues* KeyValue::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
void KeyValue::setValues(BTreeValues* values, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->values), values, BTreeValues);
}
KeyValue* KeyValue::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	IBTreeKey* theKey = KeyValueFactory::keyFromFetcher(fetcher, ctx);
	BTreeValues* values = KeyValueFactory::valuesFromFetcher(fetcher, ctx);
	KeyValue* keyValue = (new(ctx) KeyValue(theKey, values, ctx));
	return keyValue;
}
}}

