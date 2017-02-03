#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {namespace dml {





bool ClientInsertDataCommand::__init_done = __init_static_variables();
bool ClientInsertDataCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientInsertDataCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientInsertDataCommand::ClientInsertDataCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), list(GCUtils<ArrayList<ClientNetworkRecord> >::ins(this, (new(ctx) ArrayList<ClientNetworkRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), commitId(0)
{
	this->type = AbstractNodeRegionCommand::TYPE_INSERT_DATA;
}
void ClientInsertDataCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_INSERT_DATA;
}
 ClientInsertDataCommand::~ClientInsertDataCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientInsertDataCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientInsertDataCommand", L"~ClientInsertDataCommand");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientInsertDataCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	this->list->clear(ctx);
	writeByteStream(outStream, ctx);
}
void ClientInsertDataCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	this->commitId = buff->getLong(ctx);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = (new(ctx) ClientNetworkRecord(ctx));
		record->readData(buff, ctx);
		this->list->add(record, ctx);
	}
}
ArrayList<ClientNetworkRecord>* ClientInsertDataCommand::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void ClientInsertDataCommand::setList(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ClientNetworkRecord> >::mv(this, &(this->list), list, ctx);
}
long long ClientInsertDataCommand::getCommitId(ThreadContext* ctx) throw() 
{
	return commitId;
}
void ClientInsertDataCommand::setCommitId(long long commitId, ThreadContext* ctx) throw() 
{
	this->commitId = commitId;
}
void ClientInsertDataCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(this->type, ctx);
	buff->putLong(this->commitId, ctx);
	int maxLoop = this->list->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = this->list->get(i, ctx);
		record->writeData(buff, ctx);
	}
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
}}}}}

