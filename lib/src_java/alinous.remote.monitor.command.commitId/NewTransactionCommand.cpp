#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {





bool NewTransactionCommand::__init_done = __init_static_variables();
bool NewTransactionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NewTransactionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NewTransactionCommand::NewTransactionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), commitId(0), trxId(0), schemaVersion(0), nodeClusterVersion(0)
{
	this->type = AbstractMonitorCommand::TYPE_NEW_TRANSACTION;
}
void NewTransactionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_NEW_TRANSACTION;
}
 NewTransactionCommand::~NewTransactionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NewTransactionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NewTransactionCommand", L"~NewTransactionCommand");
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void NewTransactionCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->commitId = monitorServer->getCommitId(ctx);
	this->trxId = monitorServer->newTransactionId(ctx);
	this->schemaVersion = monitorServer->getSchemaVersion(ctx);
	this->nodeClusterVersion = monitorServer->getNodeClusterVersion(ctx);
	writeByteStream(outStream, ctx);
}
void NewTransactionCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->commitId = buff->getLong(ctx);
	this->trxId = buff->getLong(ctx);
	this->schemaVersion = buff->getLong(ctx);
	this->nodeClusterVersion = buff->getLong(ctx);
}
long long NewTransactionCommand::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void NewTransactionCommand::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
long long NewTransactionCommand::getTrxId(ThreadContext* ctx) throw() 
{
	return trxId;
}
void NewTransactionCommand::setTrxId(long long trxId, ThreadContext* ctx) throw() 
{
	this->trxId = trxId;
}
long long NewTransactionCommand::getSchemaVersion(ThreadContext* ctx) throw() 
{
	return schemaVersion;
}
void NewTransactionCommand::setSchemaVersion(long long schemaVersion, ThreadContext* ctx) throw() 
{
	this->schemaVersion = schemaVersion;
}
long long NewTransactionCommand::getNodeClusterVersion(ThreadContext* ctx) throw() 
{
	return nodeClusterVersion;
}
void NewTransactionCommand::setNodeClusterVersion(long long nodeClusterVersion, ThreadContext* ctx) throw() 
{
	this->nodeClusterVersion = nodeClusterVersion;
}
void NewTransactionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(AbstractMonitorCommand::TYPE_NEW_TRANSACTION, ctx);
	buff->putLong(this->commitId, ctx);
	buff->putLong(this->trxId, ctx);
	buff->putLong(this->schemaVersion, ctx);
	buff->putLong(this->nodeClusterVersion, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}}

