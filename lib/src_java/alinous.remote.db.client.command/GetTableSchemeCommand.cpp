#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/GetTableSchemeCommand.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {





bool GetTableSchemeCommand::__init_done = __init_static_variables();
bool GetTableSchemeCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetTableSchemeCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetTableSchemeCommand::GetTableSchemeCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), data(__GC_INS(this, (new(ctx) SchemasStructureInfoData(ctx)), SchemasStructureInfoData)), region(nullptr), host(nullptr), port(0), ipv6(0)
{
	this->type = AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME;
}
void GetTableSchemeCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME;
}
 GetTableSchemeCommand::~GetTableSchemeCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetTableSchemeCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"GetTableSchemeCommand", L"~GetTableSchemeCommand");
	__e_obj1.add(this->data, this);
	data = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	__e_obj1.add(this->host, this);
	host = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
SchemasStructureInfoData* GetTableSchemeCommand::getData(ThreadContext* ctx) throw() 
{
	return data;
}
void GetTableSchemeCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	tableStorageServer->getSchemeInfo(this->data, this->region, this->host, this->port, this->ipv6, ctx);
	writeByteStream(outStream, ctx);
}
void GetTableSchemeCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->data->readData(buff, ctx);
	__GC_MV(this, &(this->region), buff->getString(ctx), String);
	__GC_MV(this, &(this->host), buff->getString(ctx), String);
	this->port = buff->getInt(ctx);
	this->ipv6 = buff->getBoolean(ctx);
}
String* GetTableSchemeCommand::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
void GetTableSchemeCommand::setRegion(String* region, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->region), region, String);
}
String* GetTableSchemeCommand::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
void GetTableSchemeCommand::setHost(String* host, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
}
int GetTableSchemeCommand::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void GetTableSchemeCommand::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
bool GetTableSchemeCommand::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
void GetTableSchemeCommand::setIpv6(bool ipv6, ThreadContext* ctx) throw() 
{
	this->ipv6 = ipv6;
}
void GetTableSchemeCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(256, ctx));
	buff->putInt(AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME, ctx);
	this->data->writeData(buff, ctx);
	buff->putString(this->region, ctx);
	buff->putString(this->host, ctx);
	buff->putInt(this->port, ctx);
	buff->putBoolean(this->ipv6, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
void GetTableSchemeCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

