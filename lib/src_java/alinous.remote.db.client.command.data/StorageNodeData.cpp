#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.db.client.command.data/TableClusterData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.db.client.command.data/StorageNodeData.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {





bool StorageNodeData::__init_done = __init_static_variables();
bool StorageNodeData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StorageNodeData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StorageNodeData::StorageNodeData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), host(nullptr), port(0), ipv6(0), metadata(nullptr)
{
}
void StorageNodeData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 StorageNodeData::StorageNodeData(String* host, int port, bool ipv6, TableMetadata* medatada, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), host(nullptr), port(0), ipv6(0), metadata(nullptr)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
	__GC_MV(this, &(this->metadata), medatada, TableMetadata);
}
void StorageNodeData::__construct_impl(String* host, int port, bool ipv6, TableMetadata* medatada, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
	__GC_MV(this, &(this->metadata), medatada, TableMetadata);
}
 StorageNodeData::~StorageNodeData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StorageNodeData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StorageNodeData", L"~StorageNodeData");
	__e_obj1.add(this->host, this);
	host = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
}
String* StorageNodeData::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
int StorageNodeData::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
bool StorageNodeData::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
bool StorageNodeData::equals(String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	return this->ipv6 == ipv6 && this->port == port && this->host->equals(host, ctx);
}
bool StorageNodeData::equals(StorageNodeData* another, ThreadContext* ctx) throw() 
{
	return equals(another->getHost(ctx), another->getPort(ctx), another->isIpv6(ctx), ctx);
}
void StorageNodeData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__GC_MV(this, &(this->host), buff->getString(ctx), String);
	this->port = buff->getInt(ctx);
	this->ipv6 = buff->getByte(ctx) == (char)1;
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->metadata), TableMetadata::fromNetwork(buff, ctx), TableMetadata);
	}
}
void StorageNodeData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putString(this->host, ctx);
	buff->putInt(this->port, ctx);
	char bl = ((char)(this->ipv6 ? 1 : 0));
	buff->putByte(bl, ctx);
	bool isnull = (this->metadata == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->metadata->writeData(buff, ctx);
	}
}
TableMetadata* StorageNodeData::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
void StorageNodeData::__cleanUp(ThreadContext* ctx){
}
}}}}}}

