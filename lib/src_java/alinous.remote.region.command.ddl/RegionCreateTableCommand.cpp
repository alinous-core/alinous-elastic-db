#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace ddl {





bool RegionCreateTableCommand::__init_done = __init_static_variables();
bool RegionCreateTableCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionCreateTableCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionCreateTableCommand::RegionCreateTableCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), metadata(nullptr)
{
	this->type = RegionCreateTableCommand::TYPE_CREATE_TABLE;
}
void RegionCreateTableCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = RegionCreateTableCommand::TYPE_CREATE_TABLE;
}
 RegionCreateTableCommand::~RegionCreateTableCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionCreateTableCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionCreateTableCommand", L"~RegionCreateTableCommand");
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void RegionCreateTableCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			nodeRegionServer->createTable(this->metadata, ctx);
		}
		catch(AlinousException* e)
		{
			nodeRegionServer->getCore(ctx)->getLogger(ctx)->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void RegionCreateTableCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	bool isnull = (this->metadata == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->metadata->writeData(buff, ctx);
	}
	readErrorFromStream(buff, ctx);
}
TableMetadata* RegionCreateTableCommand::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
void RegionCreateTableCommand::setMetadata(TableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
}
void RegionCreateTableCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(256, ctx));
	buff->putInt(NodeRegionConnectCommand::TYPE_CREATE_TABLE, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		{
			try
			{
				__GC_MV(this, &(this->metadata), TableMetadata::fromNetwork(buff, ctx), TableMetadata);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) IOException(e, ctx));
			}
		}
	}
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	out->write(b, 0, pos, ctx);
	out->flush(ctx);
}
}}}}}

