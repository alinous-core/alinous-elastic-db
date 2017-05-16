#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.scan/ResultHolder.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool ResultHolder::__init_done = __init_static_variables();
bool ResultHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ResultHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ResultHolder::ResultHolder(List<ClientNetworkRecord>* resultList, ThreadContext* ctx) throw()  : IObject(ctx), resultList(nullptr), index(0)
{
	GCUtils<List<ClientNetworkRecord> >::mv(this, &(this->resultList), resultList, ctx);
	this->index = 0;
}
void ResultHolder::__construct_impl(List<ClientNetworkRecord>* resultList, ThreadContext* ctx) throw() 
{
	GCUtils<List<ClientNetworkRecord> >::mv(this, &(this->resultList), resultList, ctx);
	this->index = 0;
}
 ResultHolder::~ResultHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ResultHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ResultHolder", L"~ResultHolder");
	__e_obj1.add(this->resultList, this);
	resultList = nullptr;
	if(!prepare){
		return;
	}
}
ClientNetworkRecord* ResultHolder::getNextRecord(ThreadContext* ctx) throw() 
{
	if(this->index == this->resultList->size(ctx))
	{
		return nullptr;
	}
	ClientNetworkRecord* record = resultList->get(this->index, ctx);
	this->index ++ ;
	return record;
}
bool ResultHolder::hasNext(ThreadContext* ctx) throw() 
{
	return this->index <= this->resultList->size(ctx);
}
void ResultHolder::__cleanUp(ThreadContext* ctx){
}
}}}}}

