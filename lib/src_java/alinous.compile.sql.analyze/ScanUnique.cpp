#include "includes.h"


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
void ScanUnique::calcCoverage(TablePartitionKey* key, ThreadContext* ctx) throw() 
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
}
String* ScanUnique::getTableFullName(ThreadContext* ctx) throw() 
{
	return tableFullName;
}
void ScanUnique::setTableFullName(String* tableFullName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableFullName), tableFullName, String);
}
}}}}

