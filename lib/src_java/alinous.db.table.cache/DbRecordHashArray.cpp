#include "includes.h"


namespace alinous {namespace db {namespace table {namespace cache {





bool DbRecordHashArray::__init_done = __init_static_variables();
bool DbRecordHashArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbRecordHashArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbRecordHashArray::DbRecordHashArray(int i, ThreadContext* ctx) throw()  : IObject(ctx), list(nullptr)
{
	GCUtils<ArrayList<DatabaseRecord> >::mv(this, &(this->list), (new(ctx) ArrayList<DatabaseRecord>(i, ctx)), ctx);
}
void DbRecordHashArray::__construct_impl(int i, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<DatabaseRecord> >::mv(this, &(this->list), (new(ctx) ArrayList<DatabaseRecord>(i, ctx)), ctx);
}
 DbRecordHashArray::~DbRecordHashArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbRecordHashArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbRecordHashArray", L"~DbRecordHashArray");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void DbRecordHashArray::add(DatabaseRecord* ptr, ThreadContext* ctx) throw() 
{
	list->add(ptr, ctx);
}
bool DbRecordHashArray::removeByObj(DatabaseRecord* obj, ThreadContext* ctx) throw() 
{
	bool ret = list->remove(obj, ctx);
	return ret;
}
int DbRecordHashArray::size(ThreadContext* ctx) throw() 
{
	return list->size(ctx);
}
DatabaseRecord* DbRecordHashArray::search(DataTableStorageSupport* table, long long position, ThreadContext* ctx) throw() 
{
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DatabaseRecord* n = list->get(i, ctx);
		if(n->getStorageForCache(ctx) == table && n->getPosition(ctx) == position)
		{
			return n;
		}
	}
	return nullptr;
}
void DbRecordHashArray::reset(ThreadContext* ctx) throw() 
{
	list->clear(ctx);
}
DatabaseRecord* DbRecordHashArray::get(int i, ThreadContext* ctx) throw() 
{
	return list->get(i, ctx);
}
}}}}

