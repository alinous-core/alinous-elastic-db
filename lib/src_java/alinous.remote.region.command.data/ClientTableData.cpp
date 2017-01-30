#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace data {





bool ClientTableData::__init_done = __init_static_variables();
bool ClientTableData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientTableData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientTableData::ClientTableData(String* name, TableMetadata* metadata, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), metadata(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
}
void ClientTableData::__construct_impl(String* name, TableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
}
 ClientTableData::~ClientTableData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientTableData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientTableData", L"~ClientTableData");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
}
void ClientTableData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__GC_MV(this, &(this->name), buff->getString(ctx), String);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->metadata), TableMetadata::fromNetwork(buff, ctx), TableMetadata);
	}
}
void ClientTableData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putString(this->name, ctx);
	bool isnull = (this->metadata == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->metadata->writeData(buff, ctx);
	}
}
String* ClientTableData::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void ClientTableData::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
TableMetadata* ClientTableData::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
void ClientTableData::setMetadata(TableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
}
}}}}}

