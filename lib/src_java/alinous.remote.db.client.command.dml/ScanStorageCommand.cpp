#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command.dml/ScanStorageCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {





bool ScanStorageCommand::__init_done = __init_static_variables();
bool ScanStorageCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanStorageCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanStorageCommand::ScanStorageCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), data(nullptr), vctx(nullptr), result(nullptr)
{
	this->type = AbstractRemoteStorageCommand::TYPE_SCAN_STORAGE;
}
void ScanStorageCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_SCAN_STORAGE;
}
 ScanStorageCommand::~ScanStorageCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanStorageCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanStorageCommand", L"~ScanStorageCommand");
	__e_obj1.add(this->data, this);
	data = nullptr;
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	__e_obj1.add(this->result, this);
	result = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
void ScanStorageCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(this->result), tableStorageServer->scan(this->vctx, this->data, ctx), ScanWorkerResult);
		}
		catch(Throwable* e)
		{
			AlinousCore* core = tableStorageServer->getCore(ctx);
			core->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void ScanStorageCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->vctx), DbVersionContext::fromNetwork(buff, ctx), DbVersionContext);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->data), ClientScanCommandData::fromNetwork(buff, ctx), ClientScanCommandData);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->result), ScanWorkerResult::fromNetwork(buff, ctx), ScanWorkerResult);
	}
	readErrorFromStream(buff, ctx);
}
ClientScanCommandData* ScanStorageCommand::getData(ThreadContext* ctx) throw() 
{
	return data;
}
void ScanStorageCommand::setData(ClientScanCommandData* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->data), data, ClientScanCommandData);
}
DbVersionContext* ScanStorageCommand::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void ScanStorageCommand::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
ScanWorkerResult* ScanStorageCommand::getResult(ThreadContext* ctx) throw() 
{
	return result;
}
void ScanStorageCommand::setResult(ScanWorkerResult* result, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->result), result, ScanWorkerResult);
}
void ScanStorageCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(1024 * 2, ctx));
	buff->putInt(this->type, ctx);
	bool isnull = (this->vctx == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->vctx->writeData(buff, ctx);
	}
	isnull = (this->data == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->data->writeData(buff, ctx);
	}
	isnull = (this->result == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->result->writeData(buff, ctx);
	}
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void ScanStorageCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

