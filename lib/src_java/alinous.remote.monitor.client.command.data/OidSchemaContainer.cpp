#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor.client.command.data/OidSchema.h"
#include "alinous.remote.monitor.client.command.data/OidSchemaContainer.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {





bool OidSchemaContainer::__init_done = __init_static_variables();
bool OidSchemaContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"OidSchemaContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 OidSchemaContainer::OidSchemaContainer(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), schemas(GCUtils<Map<String,OidSchema> >::ins(this, (new(ctx) HashMap<String,OidSchema>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void OidSchemaContainer::__construct_impl(ThreadContext* ctx) throw() 
{
}
 OidSchemaContainer::~OidSchemaContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void OidSchemaContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"OidSchemaContainer", L"~OidSchemaContainer");
	__e_obj1.add(this->schemas, this);
	schemas = nullptr;
	if(!prepare){
		return;
	}
}
void OidSchemaContainer::addOid(String* schemaName, String* tableName, long long nextOid, ThreadContext* ctx) throw() 
{
	OidSchema* schema = this->schemas->get(schemaName, ctx);
	if(schema == nullptr)
	{
		schema = (new(ctx) OidSchema(ctx));
		this->schemas->put(schemaName, schema, ctx);
	}
}
void OidSchemaContainer::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* tableName = buff->getString(ctx);
		OidSchema* sc = OidSchema::fromNetwork(buff, ctx);
		this->schemas->put(tableName, sc, ctx);
	}
}
void OidSchemaContainer::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->schemas->size(ctx);
	buff->putInt(maxLoop, ctx);
	Iterator<String>* it = this->schemas->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		OidSchema* sc = this->schemas->get(tableName, ctx);
		buff->putString(tableName, ctx);
		sc->writeData(buff, ctx);
	}
}
OidSchemaContainer* OidSchemaContainer::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	OidSchemaContainer* container = (new(ctx) OidSchemaContainer(ctx));
	container->readData(buff, ctx);
	return container;
}
void OidSchemaContainer::__cleanUp(ThreadContext* ctx){
}
}}}}}}

