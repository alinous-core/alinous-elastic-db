#include "include/global.h"


#include "alinous.btree/IBTree.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.remote.db.server.commit/DeleteStore.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {





bool DeleteStore::__init_done = __init_static_variables();
bool DeleteStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DeleteStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DeleteStore::DeleteStore(ThreadContext* ctx) throw()  : IObject(ctx), store(nullptr)
{
}
void DeleteStore::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DeleteStore::~DeleteStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DeleteStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DeleteStore", L"~DeleteStore");
	__e_obj1.add(this->store, this);
	store = nullptr;
	if(!prepare){
		return;
	}
}
DeleteStore* DeleteStore::init(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->store), (new(ctx) BTreeOnMemory(8, ctx)), IBTree);
	return this;
}
IBTree* DeleteStore::getStore(ThreadContext* ctx) throw() 
{
	return store;
}
void DeleteStore::__cleanUp(ThreadContext* ctx){
}
}}}}}

