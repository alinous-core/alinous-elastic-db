#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScanResultIndexKey::__init_done = __init_static_variables();
bool ScanResultIndexKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanResultIndexKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanResultIndexKey::ScanResultIndexKey(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ScanResultIndexKey::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanResultIndexKey::~ScanResultIndexKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanResultIndexKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanResultIndexKey", L"~ScanResultIndexKey");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void ScanResultIndexKey::addKeyValue(VariantValue* vv, ThreadContext* ctx) throw() 
{
	this->values->add(vv, ctx);
}
int ScanResultIndexKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	ScanResultIndexKey* otherIndex = static_cast<ScanResultIndexKey*>(another);
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		VariantValue* other = otherIndex->values->get(i, ctx);
		int result = value->compareTo(other, ctx);
		if(result != 0)
		{
			return result;
		}
	}
	return 0;
}
int ScanResultIndexKey::getNumCols(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
VariantValue* ScanResultIndexKey::get(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
bool ScanResultIndexKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	ScanResultIndexKey* otherIndex = dynamic_cast<ScanResultIndexKey*>(obj);
	int maxLoop = this->values->size(ctx);
	if(otherIndex->getNumCols(ctx) != maxLoop)
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		VariantValue* other = otherIndex->values->get(i, ctx);
		int result = value->compareTo(other, ctx);
		if(result != 0)
		{
			return false;
		}
	}
	return true;
}
void ScanResultIndexKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeKey::TYPE_SCAN_RESULT_INDEX_KEY, ctx);
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
}
int ScanResultIndexKey::size(ThreadContext* ctx)
{
	int total = 4 + 4;
	int maxLoop = this->values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		total += value->bufferSize(ctx);
	}
	return total;
}
BTreeIndexKey* ScanResultIndexKey::fetchFromEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue::valueFromFetcher(fetcher, ctx);
	}
	return indexKey;
}
void ScanResultIndexKey::__cleanUp(ThreadContext* ctx){
}
int ScanResultIndexKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}}}

