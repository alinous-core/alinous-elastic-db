#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor.client.command.data/OidTable.h"
#include "alinous.remote.monitor.client.command.data/OidSchema.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {





bool OidSchema::__init_done = __init_static_variables();
bool OidSchema::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"OidSchema", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 OidSchema::OidSchema(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), tables(GCUtils<Map<String,OidTable> >::ins(this, (new(ctx) HashMap<String,OidTable>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void OidSchema::__construct_impl(ThreadContext* ctx) throw() 
{
}
 OidSchema::~OidSchema() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void OidSchema::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"OidSchema", L"~OidSchema");
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	if(!prepare){
		return;
	}
}
void OidSchema::addOid(String* tableName, long long nextOid, ThreadContext* ctx) throw() 
{
	OidTable* table = this->tables->get(tableName, ctx);
	if(table == nullptr)
	{
		table = (new(ctx) OidTable(ctx));
	}
	table->setNextOid(nextOid, ctx);
	this->tables->put(tableName, table, ctx);
}
Map<String,OidTable>* OidSchema::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
void OidSchema::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* tableName = buff->getString(ctx);
		OidTable* table = OidTable::fromNetwork(buff, ctx);
		this->tables->put(tableName, table, ctx);
	}
}
void OidSchema::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->tables->size(ctx);
	buff->putInt(maxLoop, ctx);
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		OidTable* table = this->tables->get(tableName, ctx);
		buff->putString(tableName, ctx);
		table->writeData(buff, ctx);
	}
}
OidSchema* OidSchema::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	OidSchema* schema = (new(ctx) OidSchema(ctx));
	schema->readData(buff, ctx);
	return schema;
}
void OidSchema::__cleanUp(ThreadContext* ctx){
}
}}}}}}

