#include "includes.h"


namespace alinous {namespace lock {namespace unique {





bool UniqueExclusiveLockManager::__init_done = __init_static_variables();
bool UniqueExclusiveLockManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLockManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueExclusiveLockManager::~UniqueExclusiveLockManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueExclusiveLockManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLockManager", L"~UniqueExclusiveLockManager");
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
UniqueExclusiveLock* UniqueExclusiveLockManager::findLock(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	TableUniqueCollections* tableUnique = getTableUnique(unique->getTableFullName(ctx), ctx);
	if(tableUnique == nullptr)
	{
		return nullptr;
	}
	return tableUnique->findLock(unique, value, ctx);
}
void UniqueExclusiveLockManager::dispose(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		TableUniqueCollections* tableLock = this->tables->get(tableName, ctx);
		tableLock->dispose(ctx);
	}
	this->tables->clear(ctx);
}
TableUniqueCollections* UniqueExclusiveLockManager::getTableUnique(String* fullName, ThreadContext* ctx) throw() 
{
	return this->tables->get(fullName, ctx);
}
}}}

