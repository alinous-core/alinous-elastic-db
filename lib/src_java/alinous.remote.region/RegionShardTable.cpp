#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool RegionShardTable::__init_done = __init_static_variables();
bool RegionShardTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionShardTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionShardTable::RegionShardTable(NodeTableClaster* table, ThreadContext* ctx) throw()  : IObject(ctx), metadata(nullptr), shardParts(GCUtils<List<RegionShardPart> >::ins(this, (new(ctx) ArrayList<RegionShardPart>(ctx)), ctx, __FILEW__, __LINE__, L"")), commitId(0)
{
	__GC_MV(this, &(this->metadata), table->getMetadata(ctx), TableMetadata);
	List<NodeTableReference>* list = table->getNodes(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeTableReference* nodeRef = list->get(i, ctx);
		RegionShardPart* part = (new(ctx) RegionShardPart(nodeRef, ctx));
		this->shardParts->add(part, ctx);
	}
}
void RegionShardTable::__construct_impl(NodeTableClaster* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), table->getMetadata(ctx), TableMetadata);
	List<NodeTableReference>* list = table->getNodes(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeTableReference* nodeRef = list->get(i, ctx);
		RegionShardPart* part = (new(ctx) RegionShardPart(nodeRef, ctx));
		this->shardParts->add(part, ctx);
	}
}
 RegionShardTable::~RegionShardTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionShardTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionShardTable", L"~RegionShardTable");
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->shardParts, this);
	shardParts = nullptr;
	if(!prepare){
		return;
	}
}
long long RegionShardTable::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void RegionShardTable::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
void RegionShardTable::putRecords(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx) throw() 
{
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = list->get(i, ctx);
		handleRecord(record, ctx);
	}
}
void RegionShardTable::handleRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() 
{
}
}}}

