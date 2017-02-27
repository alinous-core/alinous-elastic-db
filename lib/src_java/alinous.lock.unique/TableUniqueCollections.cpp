#include "includes.h"


namespace alinous {namespace lock {namespace unique {





bool TableUniqueCollections::__init_done = __init_static_variables();
bool TableUniqueCollections::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableUniqueCollections", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableUniqueCollections::~TableUniqueCollections() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableUniqueCollections::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableUniqueCollections", L"~TableUniqueCollections");
	__e_obj1.add(this->uniqueLocks, this);
	uniqueLocks = nullptr;
	if(!prepare){
		return;
	}
}
UniqueExclusiveLock* TableUniqueCollections::findLock(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	TablePartitionKey* coverKey = unique->getCoveredKey(ctx);
	String* colsstr = coverKey->toString(ctx);
	ColumnsUniqueCollections* col = this->uniqueLocks->get(colsstr, ctx);
	if(col == nullptr)
	{
		return nullptr;
	}
	return col->getLock(unique, value, ctx);
}
void TableUniqueCollections::dispose(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->uniqueLocks->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* columnName = it->next(ctx);
		ColumnsUniqueCollections* column = this->uniqueLocks->get(columnName, ctx);
		column->dispose(ctx);
	}
}
}}}

