#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command.dml/ClientScanEndCommand.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {





bool ClientScanEndCommand::__init_done = __init_static_variables();
bool ClientScanEndCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientScanEndCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientScanEndCommand::ClientScanEndCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), trxId(0)
{
	this->type = AbstractNodeRegionCommand::TYPE_SCAN_END;
}
void ClientScanEndCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_SCAN_END;
}
 ClientScanEndCommand::~ClientScanEndCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientScanEndCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientScanEndCommand", L"~ClientScanEndCommand");
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientScanEndCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	nodeRegionServer->endScan(this->trxId, ctx);
	writeByteStream(outStream, ctx);
}
void ClientScanEndCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->trxId = buff->getLong(ctx);
	readErrorFromStream(buff, ctx);
}
long long ClientScanEndCommand::getTrxId(ThreadContext* ctx) throw() 
{
	return trxId;
}
void ClientScanEndCommand::setTrxId(long long trxId, ThreadContext* ctx) throw() 
{
	this->trxId = trxId;
}
void ClientScanEndCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(this->type, ctx);
	buff->putLong(this->trxId, ctx);
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void ClientScanEndCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

