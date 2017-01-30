#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





bool GetSchemaFromRegionCommand::__init_done = __init_static_variables();
bool GetSchemaFromRegionCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GetSchemaFromRegionCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GetSchemaFromRegionCommand::GetSchemaFromRegionCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), schemeVersion(0), data(__GC_INS(this, (new(ctx) ClientStructureMetadata(ctx)), ClientStructureMetadata))
{
	this->type = AbstractNodeRegionCommand::TYPE_GET_SCHEMA_FROM_REGION;
}
void GetSchemaFromRegionCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_GET_SCHEMA_FROM_REGION;
}
 GetSchemaFromRegionCommand::~GetSchemaFromRegionCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GetSchemaFromRegionCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"GetSchemaFromRegionCommand", L"~GetSchemaFromRegionCommand");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void GetSchemaFromRegionCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			this->schemeVersion = nodeRegionServer->getClientData(this->data, ctx);
		}
		catch(AlinousException* e)
		{
			handleError(e, ctx);
			nodeRegionServer->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void GetSchemaFromRegionCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->schemeVersion = buff->getLong(ctx);
	this->data->readData(buff, ctx);
	readErrorFromStream(buff, ctx);
}
long long GetSchemaFromRegionCommand::getSchemeVersion(ThreadContext* ctx) throw() 
{
	return schemeVersion;
}
void GetSchemaFromRegionCommand::setSchemeVersion(long long schemeVersion, ThreadContext* ctx) throw() 
{
	this->schemeVersion = schemeVersion;
}
ClientStructureMetadata* GetSchemaFromRegionCommand::getData(ThreadContext* ctx) throw() 
{
	return data;
}
void GetSchemaFromRegionCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(256, ctx));
	buff->putInt(NodeRegionConnectCommand::TYPE_GET_SCHEMA_FROM_REGION, ctx);
	buff->putLong(this->schemeVersion, ctx);
	this->data->writeData(buff, ctx);
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}

