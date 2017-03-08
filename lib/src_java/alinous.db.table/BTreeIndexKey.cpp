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
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/BTreeIndexKey.h"

namespace alinous {namespace db {namespace table {





bool BTreeIndexKey::__init_done = __init_static_variables();
bool BTreeIndexKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeIndexKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeIndexKey::BTreeIndexKey(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void BTreeIndexKey::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BTreeIndexKey::BTreeIndexKey(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	int maxLoop = indexKeyValue->getNumCols(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = indexKeyValue->get(i, ctx);
		this->values->add(vv, ctx);
	}
}
void BTreeIndexKey::__construct_impl(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) throw() 
{
	int maxLoop = indexKeyValue->getNumCols(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* vv = indexKeyValue->get(i, ctx);
		this->values->add(vv, ctx);
	}
}
 BTreeIndexKey::BTreeIndexKey(IBtreeTableIndex* index, IDatabaseRecord* dbrecord, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	ArrayList<TableColumnMetadata>* list = index->getColumns(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = list->get(i, ctx);
		int colOrder = col->columnOrder;
		VariantValue* value = dbrecord->getColumnValue(colOrder, ctx);
		this->values->add(value, ctx);
	}
}
void BTreeIndexKey::__construct_impl(IBtreeTableIndex* index, IDatabaseRecord* dbrecord, ThreadContext* ctx) throw() 
{
	ArrayList<TableColumnMetadata>* list = index->getColumns(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = list->get(i, ctx);
		int colOrder = col->columnOrder;
		VariantValue* value = dbrecord->getColumnValue(colOrder, ctx);
		this->values->add(value, ctx);
	}
}
 BTreeIndexKey::~BTreeIndexKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeIndexKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeIndexKey", L"~BTreeIndexKey");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
int BTreeIndexKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	BTreeIndexKey* otherIndex = static_cast<BTreeIndexKey*>(another);
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
int BTreeIndexKey::getNumCols(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
bool BTreeIndexKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	BTreeIndexKey* otherIndex = dynamic_cast<BTreeIndexKey*>(obj);
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
void BTreeIndexKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeKey::TYPE_BTREE_INDEX_KEY, ctx);
	int maxLoop = this->values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* value = this->values->get(i, ctx);
		value->appendToEntry(builder, ctx);
	}
}
int BTreeIndexKey::size(ThreadContext* ctx)
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
BTreeIndexKey* BTreeIndexKey::fetchFromEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue::valueFromFetcher(fetcher, ctx);
	}
	return indexKey;
}
void BTreeIndexKey::__cleanUp(ThreadContext* ctx){
}
int BTreeIndexKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}}

