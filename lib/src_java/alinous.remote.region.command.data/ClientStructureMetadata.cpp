#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace data {





bool ClientStructureMetadata::__init_done = __init_static_variables();
bool ClientStructureMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientStructureMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientStructureMetadata::~ClientStructureMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientStructureMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientStructureMetadata", L"~ClientStructureMetadata");
	__e_obj1.add(this->map, this);
	map = nullptr;
	if(!prepare){
		return;
	}
}
void ClientStructureMetadata::addSchema(String* name, ClientSchemaData* data, ThreadContext* ctx) throw() 
{
	this->map->put(name, data, ctx);
}
Map<String,ClientSchemaData>* ClientStructureMetadata::getMap(ThreadContext* ctx) throw() 
{
	return map;
}
void ClientStructureMetadata::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* schemeName = buff->getString(ctx);
		ClientSchemaData* data = (new(ctx) ClientSchemaData(ctx));
		data->readData(buff, ctx);
		this->map->put(schemeName, data, ctx);
	}
}
void ClientStructureMetadata::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int size = this->map->size(ctx);
	buff->putInt(size, ctx);
	Iterator<String>* it = this->map->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* schemeName = it->next(ctx);
		ClientSchemaData* data = this->map->get(schemeName, ctx);
		buff->putString(schemeName, ctx);
		data->writeData(buff, ctx);
	}
}
}}}}}

