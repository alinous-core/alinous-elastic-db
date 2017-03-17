#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanUnique::__init_done = __init_static_variables();
bool ScanUnique::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanUnique", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanUnique::ScanUnique(ThreadContext* ctx) throw()  : IObject(ctx), TableMetadataUnique(ctx), coveredKey(nullptr), matchLength(0), tableFullName(nullptr)
{
}
void ScanUnique::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanUnique::~ScanUnique() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanUnique::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanUnique", L"~ScanUnique");
	__e_obj1.add(this->coveredKey, this);
	coveredKey = nullptr;
	__e_obj1.add(this->tableFullName, this);
	tableFullName = nullptr;
	if(!prepare){
		return;
	}
	TableMetadataUnique::__releaseRegerences(true, ctx);
}
List<VariantValue>* ScanUnique::makeValues(IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	List<VariantValue>* values = (new(ctx) ArrayList<VariantValue>(ctx));
	int maxLoop = this->uniqueColList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->uniqueColList->get(i, ctx);
		int colOrder = col->columnOrder;
		VariantValue* vv = record->getColumnValue(colOrder, ctx);
		values->add(vv, ctx);
	}
	return values;
}
int ScanUnique::fileSize(ThreadContext* ctx)
{
	int total = TableMetadataUnique::fileSize(ctx);
	total += this->coveredKey->fileSize(ctx);
	total += 4;
	total += this->tableFullName->length(ctx) * 2 + 4;
	return total;
}
void ScanUnique::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	TableMetadataUnique::toFileEntry(builder, ctx);
	this->coveredKey->toFileEntry(builder, ctx);
	builder->putInt(this->matchLength, ctx);
	builder->putString(this->tableFullName, ctx);
}
void ScanUnique::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TableMetadataUnique::readData(buff, ctx);
	__GC_MV(this, &(this->coveredKey), TablePartitionKey::fromNetwork(buff, ctx), TablePartitionKey);
	this->matchLength = buff->getInt(ctx);
	__GC_MV(this, &(this->tableFullName), buff->getString(ctx), String);
}
void ScanUnique::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TableMetadataUnique::writeData(buff, ctx);
	this->coveredKey->writeData(buff, ctx);
	buff->putInt(this->matchLength, ctx);
	buff->putString(this->tableFullName, ctx);
}
TablePartitionKey* ScanUnique::getCoveredKey(ThreadContext* ctx) throw() 
{
	return coveredKey;
}
void ScanUnique::setCoveredKey(TablePartitionKey* coveredKey, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->coveredKey), coveredKey, TablePartitionKey);
}
bool ScanUnique::isCovered(ThreadContext* ctx) throw() 
{
	return this->coveredKey != nullptr;
}
int ScanUnique::getMatchLength(ThreadContext* ctx) throw() 
{
	return matchLength;
}
bool ScanUnique::calcCoverage(TablePartitionKey* key, ThreadContext* ctx) throw() 
{
	ArrayList<TableColumnMetadata>* keys = key->getKeys(ctx);
	int matchLength = 0;
	int maxLoop = keys->size(ctx) < this->uniqueColList->size(ctx) ? keys->size(ctx) : this->uniqueColList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = keys->get(i, ctx);
		TableColumnMetadata* ucol = this->uniqueColList->get(i, ctx);
		if(!col->name->equals(ucol->name, ctx))
		{
			break ;
		}
		matchLength ++ ;
	}
	if(matchLength > this->matchLength)
	{
		this->matchLength = matchLength;
		__GC_MV(this, &(this->coveredKey), key, TablePartitionKey);
	}
	return this->coveredKey != nullptr;
}
String* ScanUnique::getTableFullName(ThreadContext* ctx) throw() 
{
	return tableFullName;
}
void ScanUnique::setTableFullName(String* tableFullName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableFullName), tableFullName, String);
}
ScanUnique* ScanUnique::loadScannerFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	ScanUnique* unique = (new(ctx) ScanUnique(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::loadFromFetcher(fetcher, ctx);
		unique->addUnique(col, ctx);
	}
	__GC_MV(unique, &(unique->coveredKey), TablePartitionKey::loadFromFetcher(fetcher, ctx), TablePartitionKey);
	unique->matchLength = fetcher->fetchInt(ctx);
	__GC_MV(unique, &(unique->tableFullName), fetcher->fetchString(ctx), String);
	return unique;
}
ScanUnique* ScanUnique::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	ScanUnique* unique = (new(ctx) ScanUnique(ctx));
	unique->readData(buff, ctx);
	return unique;
}
void ScanUnique::__cleanUp(ThreadContext* ctx){
}
}}}}

