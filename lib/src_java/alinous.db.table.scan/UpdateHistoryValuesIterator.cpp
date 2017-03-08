#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table.scan/UpdateHistoryValuesIterator.h"

namespace alinous {namespace db {namespace table {namespace scan {





bool UpdateHistoryValuesIterator::__init_done = __init_static_variables();
bool UpdateHistoryValuesIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UpdateHistoryValuesIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UpdateHistoryValuesIterator::UpdateHistoryValuesIterator(ArrayList<IBTreeValue>* values, long long commitId, ThreadContext* ctx) throw()  : IObject(ctx), commitId(0), values(nullptr), maxCount(0), current(0)
{
	this->commitId = commitId;
	GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), values, ctx);
	this->current = 0;
	int maxLoop = this->values->size(ctx);
	this->maxCount = maxLoop;
	for(int i = 0; i != maxLoop; ++i)
	{
		DatabaseRecord* record = static_cast<DatabaseRecord*>(this->values->get(i, ctx));
		if(record->getLastUpdateCommitId(ctx) > this->commitId)
		{
			this->current = i;
			break ;
		}
	}
}
void UpdateHistoryValuesIterator::__construct_impl(ArrayList<IBTreeValue>* values, long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
	GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), values, ctx);
	this->current = 0;
	int maxLoop = this->values->size(ctx);
	this->maxCount = maxLoop;
	for(int i = 0; i != maxLoop; ++i)
	{
		DatabaseRecord* record = static_cast<DatabaseRecord*>(this->values->get(i, ctx));
		if(record->getLastUpdateCommitId(ctx) > this->commitId)
		{
			this->current = i;
			break ;
		}
	}
}
 UpdateHistoryValuesIterator::~UpdateHistoryValuesIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UpdateHistoryValuesIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UpdateHistoryValuesIterator", L"~UpdateHistoryValuesIterator");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
DatabaseRecord* UpdateHistoryValuesIterator::next(ThreadContext* ctx) throw() 
{
	return static_cast<DatabaseRecord*>(this->values->get(this->current++, ctx));
}
bool UpdateHistoryValuesIterator::hasNext(ThreadContext* ctx) throw() 
{
	return this->current != this->maxCount;
}
void UpdateHistoryValuesIterator::__cleanUp(ThreadContext* ctx){
}
}}}}

