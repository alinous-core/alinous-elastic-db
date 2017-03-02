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
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
UniqueExclusiveLock* TableUniqueCollections::lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx)
{
	TablePartitionKey* coverKey = unique->getCoveredKey(ctx);
	String* colsstr = coverKey->toString(ctx);
	ColumnsUniqueCollections* col = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		col = this->uniqueLocks->get(colsstr, ctx);
		if(col == nullptr)
		{
			col = (new(ctx) ColumnsUniqueCollections(ctx));
			this->uniqueLocks->put(colsstr, col, ctx);
		}
	}
	return col->lockWithCheck(unique, record, throwex, ctx);
}
bool TableUniqueCollections::unlock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	TablePartitionKey* coverKey = unique->getCoveredKey(ctx);
	String* colsstr = coverKey->toString(ctx);
	ColumnsUniqueCollections* col = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		col = this->uniqueLocks->get(colsstr, ctx);
		if(col == nullptr)
		{
			return this->uniqueLocks->isEmpty(ctx);
		}
		bool isEmpty = col->unlock(unique, record, ctx);
		if(isEmpty)
		{
			this->uniqueLocks->remove(colsstr, ctx);
		}
		return this->uniqueLocks->isEmpty(ctx);
	}
}
UniqueExclusiveLock* TableUniqueCollections::findLock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx)
{
	TablePartitionKey* coverKey = unique->getCoveredKey(ctx);
	String* colsstr = coverKey->toString(ctx);
	ColumnsUniqueCollections* col = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		col = this->uniqueLocks->get(colsstr, ctx);
	}
	if(col == nullptr)
	{
		return nullptr;
	}
	return col->getLock(unique, record, ctx);
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

