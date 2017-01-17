#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {





bool GetTableSchemeCommand::__init_done = __init_static_variables();
bool GetTableSchemeCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetTableSchemeCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetTableSchemeCommand::GetTableSchemeCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteStorageCommand(ctx), data(__GC_INS(this, (new(ctx) SchemasStructureInfoData(ctx)), SchemasStructureInfoData)), region(nullptr)
{
	this->type = AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME;
}
void GetTableSchemeCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME;
}
 GetTableSchemeCommand::~GetTableSchemeCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetTableSchemeCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"GetTableSchemeCommand", L"~GetTableSchemeCommand");
	__e_obj1.add(this->data, this);
	data = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	if(!prepare){
		return;
	}
	AbstractRemoteStorageCommand::__releaseRegerences(true, ctx);
}
SchemasStructureInfoData* GetTableSchemeCommand::getData(ThreadContext* ctx) throw() 
{
	return data;
}
void GetTableSchemeCommand::executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	tableStorageServer->getSchemeInfo(this->data, this->region, ctx);
	writeByteStream(outStream, ctx);
}
void GetTableSchemeCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->data->readData(buff, ctx);
	__GC_MV(this, &(this->region), buff->getString(ctx), String);
}
String* GetTableSchemeCommand::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
void GetTableSchemeCommand::setRegion(String* region, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->region), region, String);
}
void GetTableSchemeCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(256, ctx));
	buff->putInt(AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME, ctx);
	this->data->writeData(buff, ctx);
	buff->putString(this->region, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}

