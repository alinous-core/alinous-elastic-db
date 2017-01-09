#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {namespace data {





bool SchemaData::__init_done = __init_static_variables();
bool SchemaData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SchemaData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SchemaData::~SchemaData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SchemaData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SchemaData", L"~SchemaData");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->tablesMap, this);
	tablesMap = nullptr;
	if(!prepare){
		return;
	}
}
void SchemaData::addTable(TableClusterData* value, ThreadContext* ctx) throw() 
{
	this->tablesMap->put(value->getName(ctx), value, ctx);
}
String* SchemaData::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void SchemaData::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
void SchemaData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), buff->getString(ctx), String);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableClusterData* data = (new(ctx) TableClusterData(ctx));
		data->readData(buff, ctx);
		addTable(data, ctx);
	}
}
void SchemaData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putString(this->name, ctx);
	int size = this->tablesMap->size(ctx);
	buff->putInt(size, ctx);
	Iterator<String>* it = this->tablesMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		TableClusterData* table = this->tablesMap->get(tableName, ctx);
		table->writeData(buff, ctx);
	}
}
}}}}}

