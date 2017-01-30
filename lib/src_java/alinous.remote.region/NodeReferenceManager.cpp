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
	__e_obj1.add(this->schemaDictinary, this);
	schemaDictinary = nullptr;
	__e_obj1.add(this->nodeReferences, this);
	nodeReferences = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
long long NodeReferenceManager::getClientData(ClientStructureMetadata* data, ThreadContext* ctx)
{
	if(this->nodeReferences == nullptr)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3572(), ctx));
	}
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Iterator<String>* it = this->schemaDictinary->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* schemeName = it->next(ctx);
			NodeRegionSchema* scheme = this->schemaDictinary->get(schemeName, ctx);
			ClientSchemaData* schemadata = scheme->toClientData(ctx);
			data->addSchema(schemeName, schemadata, ctx);
		}
		return this->schemaVersion;
	}
}
void NodeReferenceManager::syncSchemeTables(String* regionName, ThreadContext* ctx)
{
	if(this->nodeReferences == nullptr)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3572(), ctx));
	}
	SchemasStructureInfoData* data = this->nodeReferences->getSchemeInfo(regionName, ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->schemaDictinary->clear(ctx);
		doSyncScmema(data, ctx);
		this->schemaVersion = data->getSchemaVersion(ctx);
	}
}
void NodeReferenceManager::syncNodeReference(RegionInfoData* data, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		doSyncRegionNodes(data->getNodeInfo(ctx), ctx);
	}
}
void NodeReferenceManager::dispose(ThreadContext* ctx) throw() 
{
	if(this->nodeReferences != nullptr)
	{
		this->nodeReferences->dispose(ctx);
	}
}
long long NodeReferenceManager::getSchemaVersion(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		return this->schemaVersion;
	}
}
void NodeReferenceManager::createSchema(String* schemaName, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		NodeRegionSchema* schema = this->schemaDictinary->get(schemaName, ctx);
		if(schema != nullptr)
		{
			return;
		}
		schema = (new(ctx) NodeRegionSchema(schemaName, ctx));
		this->schemaDictinary->put(schemaName, schema, ctx);
		List<NodeReference>* list = this->nodeReferences->getNodes(ctx);
		int maxLoop = list->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			NodeReference* node = list->get(i, ctx);
			node->createSchema(schemaName, ctx);
		}
	}
}
void NodeReferenceManager::createTable(TableMetadata* meta, ThreadContext* ctx)
{
	List<NodeReference>* list = this->nodeReferences->getNodes(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3573(), ctx));
	}
	NodeReference* nodeRef = list->get(0, ctx);
	nodeRef->createTable(meta, ctx);
}
void NodeReferenceManager::doSyncScmema(SchemasStructureInfoData* data, ThreadContext* ctx) throw() 
{
	Map<String,SchemaData>* schemaMap = data->getSchemas(ctx);
	Iterator<String>* it = schemaMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* schemaName = it->next(ctx);
		SchemaData* scdata = schemaMap->get(schemaName, ctx);
		NodeRegionSchema* sc = getNodeRegionSchema(schemaName, ctx);
		sc->updateTableClusters(scdata, this->nodeReferences, ctx);
	}
}
NodeRegionSchema* NodeReferenceManager::getNodeRegionSchema(String* schemaName, ThreadContext* ctx) throw() 
{
	NodeRegionSchema* sc = this->schemaDictinary->get(schemaName, ctx);
	if(sc == nullptr)
	{
		sc = (new(ctx) NodeRegionSchema(schemaName, ctx));
		this->schemaDictinary->put(schemaName, sc, ctx);
	}
	return sc;
}
void NodeReferenceManager::doSyncRegionNodes(RegionNodeInfo* nodeInfo, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->nodeReferences), (new(ctx) NodeCluster(ctx)), NodeCluster);
	this->nodeReferences->update(nodeInfo, ctx);
}
}}}

