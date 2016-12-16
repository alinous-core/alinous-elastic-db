#include "includes.h"


namespace alinous {namespace db {namespace table {namespace cache {





bool DbRecordCache::__init_done = __init_static_variables();
bool DbRecordCache::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbRecordCache", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbRecordCache::~DbRecordCache() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbRecordCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbRecordCache", L"~DbRecordCache");
	__e_obj1.add(this->fifo, this);
	fifo = nullptr;
	__e_obj1.add(this->mainList, this);
	mainList = nullptr;
	__e_obj1.add(this->spin, this);
	spin = nullptr;
	if(!prepare){
		return;
	}
}
DbRecordCache* DbRecordCache::init(int MAX_HASH, ThreadContext* ctx)
{
	__GC_MV(this, &(this->mainList), (new(ctx) DbRecordHashMainList(ctx))->init(MAX_HASH, ctx), DbRecordHashMainList);
	this->MAX_HASH = MAX_HASH;
	return this;
}
void DbRecordCache::addCachedRecord(IDatabaseTable* table, DatabaseRecord* record, ThreadContext* ctx)
{
	record->setStorageForCache(table, ctx);
	spin->lock(ctx);
	this->fifo->add(record, ctx);
	this->mainList->addElement(record, ctx);
	this->num ++ ;
	if(this->num > this->MAX_HASH)
	{
		DatabaseRecord* delrecord = this->fifo->remove(0, ctx);
		this->mainList->removeByObj(delrecord, ctx);
		this->num -- ;
	}
	spin->unlock(ctx);
}
DatabaseRecord* DbRecordCache::loadRecord(DataTableStorageSupport* table, long long position, ThreadContext* ctx)
{
	spin->lock(ctx);
	DatabaseRecord* record = this->mainList->search(table, position, ctx);
	spin->unlock(ctx);
	return record;
}
}}}}

