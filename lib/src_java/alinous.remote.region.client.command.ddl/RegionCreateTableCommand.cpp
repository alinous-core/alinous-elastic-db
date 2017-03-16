#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command/NodeRegionConnectCommand.h"
#include "alinous.remote.region.client.command.ddl/RegionCreateTableCommand.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace ddl {





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
			AlinousCore* core = nodeRegionServer->getCore(ctx);
			core->logError(e, ctx);
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
				throw (new(ctx) IOException(ConstStr::getCNST_STR_3602(), e, ctx));
			}
		}
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
void RegionCreateTableCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(256, ctx));
	buff->putInt(NodeRegionConnectCommand::TYPE_CREATE_TABLE, ctx);
	bool isnull = (this->metadata == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->metadata->writeData(buff, ctx);
	}
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void RegionCreateTableCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

