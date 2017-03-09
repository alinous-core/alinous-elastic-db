#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
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
void ScanUnique::__cleanUp(ThreadContext* ctx){
}
}}}}

