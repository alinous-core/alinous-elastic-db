#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema/NodeTableReference.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.region.server.schema/NodeCluster.h"
#include "alinous.remote.region.server.schema/NodeTableClaster.h"
#include "alinous.remote.region.server.schema/RegionShardPart.h"
#include "alinous.remote.region.server.schema/RegionShardTable.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.server.schema/NodeRegionSchema.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.remote.region.server.schema/NodeReferenceManager.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {





bool NodeTableReference::__init_done = __init_static_variables();
bool NodeTableReference::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeTableReference", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeTableReference::NodeTableReference(String* host, int port, bool ipv6, NodeReference* nodeAccessRef, TablePartitionRangeCollection* range, ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0), ipv6(0), range(nullptr), nodeAccessRef(nullptr)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
	__GC_MV(this, &(this->nodeAccessRef), nodeAccessRef, NodeReference);
	__GC_MV(this, &(this->range), range, TablePartitionRangeCollection);
}
void NodeTableReference::__construct_impl(String* host, int port, bool ipv6, NodeReference* nodeAccessRef, TablePartitionRangeCollection* range, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
	__GC_MV(this, &(this->nodeAccessRef), nodeAccessRef, NodeReference);
	__GC_MV(this, &(this->range), range, TablePartitionRangeCollection);
}
 NodeTableReference::~NodeTableReference() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeTableReference::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeTableReference", L"~NodeTableReference");
	__e_obj1.add(this->host, this);
	host = nullptr;
	__e_obj1.add(this->range, this);
	range = nullptr;
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	if(!prepare){
		return;
	}
}
String* NodeTableReference::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
int NodeTableReference::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
bool NodeTableReference::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
TablePartitionRangeCollection* NodeTableReference::getRange(ThreadContext* ctx) throw() 
{
	return range;
}
void NodeTableReference::setRange(TablePartitionRangeCollection* range, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->range), range, TablePartitionRangeCollection);
}
NodeReference* NodeTableReference::getNodeAccessRef(ThreadContext* ctx) throw() 
{
	return nodeAccessRef;
}
bool NodeTableReference::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	NodeReference* ref = dynamic_cast<NodeReference*>(obj);
	return this->port == ref->getPort(ctx) && this->host->equals(ref->getHost(ctx), ctx);
}
bool NodeTableReference::equals(NodeTableReference* ref, ThreadContext* ctx) throw() 
{
	return this->port == ref->getPort(ctx) && this->host->equals(ref->getHost(ctx), ctx);
}
void NodeTableReference::dispose(ThreadContext* ctx) throw() 
{
}
void NodeTableReference::__cleanUp(ThreadContext* ctx){
}
}}}}}

