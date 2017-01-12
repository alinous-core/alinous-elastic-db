#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {namespace data {





bool TableClusterData::__init_done = __init_static_variables();
bool TableClusterData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableClusterData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableClusterData::TableClusterData(String* name, String* region, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), region(nullptr), nodesList(GCUtils<ArrayList<StorageNodeData> >::ins(this, (new(ctx) ArrayList<StorageNodeData>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->region), region, String);
}
void TableClusterData::__construct_impl(String* name, String* region, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->region), region, String);
}
 TableClusterData::~TableClusterData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableClusterData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableClusterData", L"~TableClusterData");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	__e_obj1.add(this->nodesList, this);
	nodesList = nullptr;
	if(!prepare){
		return;
	}
}
void TableClusterData::addNode(StorageNodeData* node, ThreadContext* ctx) throw() 
{
	this->nodesList->add(node, ctx);
}
ArrayList<StorageNodeData>* TableClusterData::getNodesList(ThreadContext* ctx) throw() 
{
	return nodesList;
}
String* TableClusterData::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void TableClusterData::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
String* TableClusterData::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
void TableClusterData::setRegion(String* region, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->region), region, String);
}
void TableClusterData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__GC_MV(this, &(this->name), buff->getString(ctx), String);
	__GC_MV(this, &(this->region), buff->getString(ctx), String);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		StorageNodeData* node = (new(ctx) StorageNodeData(ctx));
		node->readData(buff, ctx);
	}
}
void TableClusterData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putString(this->name, ctx);
	buff->putString(this->region, ctx);
	int maxLoop = this->nodesList->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		StorageNodeData* node = this->nodesList->get(i, ctx);
		node->writeData(buff, ctx);
	}
}
}}}}}

