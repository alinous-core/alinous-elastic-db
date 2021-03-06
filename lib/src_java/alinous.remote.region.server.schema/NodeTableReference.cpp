#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema/NodeTableReference.h"

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

