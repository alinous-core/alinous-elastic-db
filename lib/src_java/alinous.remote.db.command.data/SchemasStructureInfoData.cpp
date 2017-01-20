#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {namespace data {





bool SchemasStructureInfoData::__init_done = __init_static_variables();
bool SchemasStructureInfoData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SchemasStructureInfoData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SchemasStructureInfoData::~SchemasStructureInfoData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SchemasStructureInfoData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SchemasStructureInfoData", L"~SchemasStructureInfoData");
	__e_obj1.add(this->schemas, this);
	schemas = nullptr;
	if(!prepare){
		return;
	}
}
void SchemasStructureInfoData::join(SchemasStructureInfoData* data, ThreadContext* ctx) throw() 
{
	Map<String,SchemaData>* dataSchemas = data->schemas;
	Iterator<String>* it = dataSchemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* name = it->next(ctx);
		SchemaData* schemaData = dataSchemas->get(name, ctx);
		SchemaData* lastSchemaData = findLocalSchema(name, schemaData, ctx);
		if(lastSchemaData == schemaData)
		{
			continue;
		}
		lastSchemaData->join(schemaData, ctx);
	}
}
bool SchemasStructureInfoData::hasSchema(String* name, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		if(key->equals(name, ctx))
		{
			return false;
		}
	}
	return false;
}
void SchemasStructureInfoData::addScheme(SchemaData* value, ThreadContext* ctx) throw() 
{
	this->schemas->put(value->getName(ctx), value, ctx);
}
Map<String,SchemaData>* SchemasStructureInfoData::getSchemas(ThreadContext* ctx) throw() 
{
	return schemas;
}
void SchemasStructureInfoData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SchemaData* data = (new(ctx) SchemaData(ctx));
		data->readData(buff, ctx);
		this->schemas->put(data->getName(ctx), data, ctx);
	}
}
void SchemasStructureInfoData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	int maxLoop = this->schemas->size(ctx);
	buff->putInt(maxLoop, ctx);
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* schemeName = it->next(ctx);
		SchemaData* data = this->schemas->get(schemeName, ctx);
		data->writeData(buff, ctx);
	}
}
SchemaData* SchemasStructureInfoData::findLocalSchema(String* name, SchemaData* schemaData, ThreadContext* ctx) throw() 
{
	SchemaData* data = this->schemas->get(name, ctx);
	if(data == nullptr)
	{
		data = schemaData;
		this->schemas->put(name, schemaData, ctx);
	}
	return data;
}
}}}}}

