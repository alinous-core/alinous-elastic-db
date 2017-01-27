#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace ddl {





bool RegionCreateSchemaCommand::__init_done = __init_static_variables();
bool RegionCreateSchemaCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionCreateSchemaCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionCreateSchemaCommand::RegionCreateSchemaCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), schemaName(nullptr)
{
	this->type = AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA;
}
void RegionCreateSchemaCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA;
}
 RegionCreateSchemaCommand::~RegionCreateSchemaCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionCreateSchemaCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionCreateSchemaCommand", L"~RegionCreateSchemaCommand");
	__e_obj1.add(this->schemaName, this);
	schemaName = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void RegionCreateSchemaCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			nodeRegionServer->createSchema(this->schemaName, ctx);
		}
		catch(AlinousException* e)
		{
			handleError(e, ctx);
			nodeRegionServer->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void RegionCreateSchemaCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	__GC_MV(this, &(this->schemaName), buff->getString(ctx), String);
	readErrorFromStream(buff, ctx);
}
String* RegionCreateSchemaCommand::getSchemaName(ThreadContext* ctx) throw() 
{
	return schemaName;
}
void RegionCreateSchemaCommand::setSchemaName(String* schemaName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemaName), schemaName, String);
}
void RegionCreateSchemaCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(256, ctx));
	buff->putInt(NodeRegionConnectCommand::TYPE_CREATE_SCHEMA, ctx);
	buff->putString(this->schemaName, ctx);
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}}

