#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool NodeReferenceManager::__init_done = __init_static_variables();
bool NodeReferenceManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeReferenceManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeReferenceManager::~NodeReferenceManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeReferenceManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeReferenceManager", L"~NodeReferenceManager");
	__e_obj1.add(this->tablesDictinary, this);
	tablesDictinary = nullptr;
	__e_obj1.add(this->nodeReferences, this);
	nodeReferences = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
void NodeReferenceManager::syncSchemeTables(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		doSyncSchemeTables(ctx);
	}
}
void NodeReferenceManager::syncNodeReference(RegionInfoData* data, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Map<String,RegionNodeInfo>* regionsMap = data->getRegionsMap(ctx);
		doSyncRegionNodes(regionsMap, ctx);
	}
}
void NodeReferenceManager::dispose(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->nodeReferences->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		NodeCluster* cluster = this->nodeReferences->get(key, ctx);
		cluster->dispose(ctx);
	}
}
Map<String,NodeTableClaster>* NodeReferenceManager::getTablesDictinary(ThreadContext* ctx) throw() 
{
	return tablesDictinary;
}
long long NodeReferenceManager::getRevision(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		return revision;
	}
}
void NodeReferenceManager::doSyncSchemeTables(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->nodeReferences->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* regionName = it->next(ctx);
		NodeCluster* region = this->nodeReferences->get(regionName, ctx);
		region->getSchemeInfo(ctx);
	}
}
void NodeReferenceManager::doSyncRegionNodes(Map<String,RegionNodeInfo>* regionsMap, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = regionsMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* regName = it->next(ctx);
		RegionNodeInfo* refinfo = regionsMap->get(regName, ctx);
		NodeCluster* last = this->nodeReferences->get(regName, ctx);
		if(last == nullptr)
		{
			last = (new(ctx) NodeCluster(ctx));
			this->nodeReferences->put(regName, last, ctx);
		}
		last->update(refinfo, ctx);
	}
	List<String>* delList = (new(ctx) ArrayList<String>(ctx));
	it = this->nodeReferences->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* regName = it->next(ctx);
		RegionNodeInfo* reginfo = regionsMap->get(regName, ctx);
		if(reginfo == nullptr)
		{
			delList->add(regName, ctx);
		}
	}
	int maxLoop = delList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* regName = delList->get(i, ctx);
		this->nodeReferences->remove(regName, ctx);
	}
}
}}}

