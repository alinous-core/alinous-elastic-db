#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor.client.command.data/OidTable.h"

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {





bool OidTable::__init_done = __init_static_variables();
bool OidTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"OidTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 OidTable::OidTable(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), nextOid(0)
{
}
void OidTable::__construct_impl(ThreadContext* ctx) throw() 
{
}
 OidTable::~OidTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void OidTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"OidTable", L"~OidTable");
	if(!prepare){
		return;
	}
}
long long OidTable::getNextOid(ThreadContext* ctx) throw() 
{
	return nextOid;
}
void OidTable::setNextOid(long long nextOid, ThreadContext* ctx) throw() 
{
	this->nextOid = nextOid;
}
void OidTable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->nextOid = buff->getLong(ctx);
}
void OidTable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putLong(this->nextOid, ctx);
}
OidTable* OidTable::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	OidTable* table = (new(ctx) OidTable(ctx));
	table->readData(buff, ctx);
	return table;
}
void OidTable::__cleanUp(ThreadContext* ctx){
}
}}}}}}

