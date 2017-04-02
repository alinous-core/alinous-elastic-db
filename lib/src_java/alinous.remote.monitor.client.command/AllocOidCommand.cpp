#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command/AllocOidCommand.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {





bool AllocOidCommand::__init_done = __init_static_variables();
bool AllocOidCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AllocOidCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AllocOidCommand::AllocOidCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractMonitorCommand(ctx), nextOid(0), length(0), tableFullName(nullptr)
{
	this->type = AbstractMonitorCommand::TYPE_ALLOC_OID;
}
void AllocOidCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractMonitorCommand::TYPE_ALLOC_OID;
}
 AllocOidCommand::~AllocOidCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AllocOidCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AllocOidCommand", L"~AllocOidCommand");
	__e_obj1.add(this->tableFullName, this);
	tableFullName = nullptr;
	if(!prepare){
		return;
	}
	AbstractMonitorCommand::__releaseRegerences(true, ctx);
}
void AllocOidCommand::executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->nextOid = monitorServer->getNextOid(this->tableFullName, this->length, ctx);
	writeByteStream(outStream, ctx);
}
void AllocOidCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->nextOid = buff->getLong(ctx);
	this->length = buff->getInt(ctx);
	__GC_MV(this, &(this->tableFullName), buff->getString(ctx), String);
}
long long AllocOidCommand::getNextOid(ThreadContext* ctx) throw() 
{
	return nextOid;
}
void AllocOidCommand::setNextOid(long long nextOid, ThreadContext* ctx) throw() 
{
	this->nextOid = nextOid;
}
int AllocOidCommand::getLength(ThreadContext* ctx) throw() 
{
	return length;
}
void AllocOidCommand::setLength(int length, ThreadContext* ctx) throw() 
{
	this->length = length;
}
String* AllocOidCommand::getTableFullName(ThreadContext* ctx) throw() 
{
	return tableFullName;
}
void AllocOidCommand::setTableFullName(String* tableFullName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableFullName), tableFullName, String);
}
void AllocOidCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(64, ctx));
	buff->putInt(this->type, ctx);
	buff->putLong(this->nextOid, ctx);
	buff->putInt(this->length, ctx);
	buff->putString(this->tableFullName, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void AllocOidCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

