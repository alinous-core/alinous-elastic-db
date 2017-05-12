#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool ScanWorkerResult::__init_done = __init_static_variables();
bool ScanWorkerResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanWorkerResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanWorkerResult::ScanWorkerResult(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), finished(false), records(GCUtils<List<ClientNetworkRecord> >::ins(this, (new(ctx) ArrayList<ClientNetworkRecord>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ScanWorkerResult::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanWorkerResult::~ScanWorkerResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanWorkerResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanWorkerResult", L"~ScanWorkerResult");
	__e_obj1.add(this->records, this);
	records = nullptr;
	if(!prepare){
		return;
	}
}
void ScanWorkerResult::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->finished = buff->getBoolean(ctx);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* rec = ClientNetworkRecord::fromNetwork(buff, ctx);
		this->records->add(rec, ctx);
	}
}
void ScanWorkerResult::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putBoolean(this->finished, ctx);
	int maxLoop = this->records->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* rec = this->records->get(i, ctx);
		rec->writeData(buff, ctx);
	}
}
bool ScanWorkerResult::isFinished(ThreadContext* ctx) throw() 
{
	return finished;
}
void ScanWorkerResult::setFinished(bool finished, ThreadContext* ctx) throw() 
{
	this->finished = finished;
}
void ScanWorkerResult::setRecords(List<ClientNetworkRecord>* records, ThreadContext* ctx) throw() 
{
	GCUtils<List<ClientNetworkRecord> >::mv(this, &(this->records), records, ctx);
}
List<ClientNetworkRecord>* ScanWorkerResult::getRecords(ThreadContext* ctx) throw() 
{
	return records;
}
void ScanWorkerResult::addRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() 
{
	this->records->add(record, ctx);
}
ScanWorkerResult* ScanWorkerResult::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	ScanWorkerResult* result = (new(ctx) ScanWorkerResult(ctx));
	result->readData(buff, ctx);
	return result;
}
void ScanWorkerResult::__cleanUp(ThreadContext* ctx){
}
}}}}}

