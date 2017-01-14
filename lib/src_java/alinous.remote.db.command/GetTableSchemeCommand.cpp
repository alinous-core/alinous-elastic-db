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
}
void GetTableSchemeCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
}
void GetTableSchemeCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
}
}}}}

