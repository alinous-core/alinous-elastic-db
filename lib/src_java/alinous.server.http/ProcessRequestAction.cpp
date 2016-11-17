#include "includes.h"


namespace alinous {namespace server {namespace http {





String* ProcessRequestAction::endStr = ConstStr::getCNST_STR_3430();
bool ProcessRequestAction::__init_done = __init_static_variables();
bool ProcessRequestAction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ProcessRequestAction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ProcessRequestAction::ProcessRequestAction(Socket* socket, AlinousWebContentProcessor* webProcessor, AlinousHttpServer* server, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), socket(nullptr), header(nullptr), webProcessor(nullptr), server(nullptr)
{
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->webProcessor), webProcessor, AlinousWebContentProcessor);
	__GC_MV(this, &(this->server), server, AlinousHttpServer);
}
void ProcessRequestAction::__construct_impl(Socket* socket, AlinousWebContentProcessor* webProcessor, AlinousHttpServer* server, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->webProcessor), webProcessor, AlinousWebContentProcessor);
	__GC_MV(this, &(this->server), server, AlinousHttpServer);
}
 ProcessRequestAction::~ProcessRequestAction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ProcessRequestAction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ProcessRequestAction", L"~ProcessRequestAction");
	__e_obj1.add(this->socket, this);
	socket = nullptr;
	__e_obj1.add(this->header, this);
	header = nullptr;
	__e_obj1.add(this->webProcessor, this);
	webProcessor = nullptr;
	__e_obj1.add(this->server, this);
	server = nullptr;
	if(!prepare){
		return;
	}
}
void ProcessRequestAction::execute(ThreadContext* ctx)
{
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ProcessRequestAction", L"execute");
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->server->dec(ctx);
			this->socket->close(ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			InputStream* sockstream = this->socket->getInputStream(ctx);
			BufferedInputStream* stream = (new(ctx) BufferedInputStream(sockstream, ctx));
			__GC_MV(this, &(this->header), (new(ctx) HttpHeaderProcessor(stream, ctx)), HttpHeaderProcessor);
			this->header->process(ctx);
			OutputStream* sockStream = socket->getOutputStream(ctx);
			BufferedOutputStream* outStream = (new(ctx) BufferedOutputStream(sockStream, ctx));
			ContentResult* result = this->webProcessor->proccess(this->header, ctx);
			if(result == nullptr || result->byteDataStream == nullptr)
			{
				out404ResponceHeader(result, outStream, ctx);
				this->socket->close(ctx);
				return;
			}
			AlinousCore* core = this->webProcessor->getCore(ctx);
			result->byteDataStream->prepare(core, core->debug, ctx);
			outCodeResult(result, outStream, ctx);
			outStream->close(ctx);
		}
		catch(Throwable* e)
		{
			this->socket->close(ctx);
			e->printStackTrace(ctx);
			return;
		}
	}
}
void ProcessRequestAction::outCodeResult(ContentResult* result, OutputStream* outStream, ThreadContext* ctx)
{
	IContentByteStream* byteContent = result->byteDataStream;
	outResponse(byteContent->length(ctx), outStream, ctx);
	if(!result->head)
	{
		byteContent->output(outStream, ctx);
	}
}
void ProcessRequestAction::outResponse(int contentLength, OutputStream* outStream, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_3425(), ctx);
	buff->append(ConstStr::getCNST_STR_3426(), ctx);
	if(contentLength > 0)
	{
		buff->append(ConstStr::getCNST_STR_3427(), ctx)->append(contentLength, ctx)->append(ConstStr::getCNST_STR_1755(), ctx);
	}
	buff->append(ConstStr::getCNST_STR_3428(), ctx);
	buff->append(ConstStr::getCNST_STR_1755(), ctx);
	String* byteStr = buff->toString(ctx);
	IArrayObjectPrimitive<char>* byteData = byteStr->getBytes(ConstStr::getCNST_STR_1047(), ctx);
	outStream->write(byteData, ctx);
}
void ProcessRequestAction::out404ResponceHeader(ContentResult* result, OutputStream* outStream, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_3429(), ctx);
	buff->append(ConstStr::getCNST_STR_3426(), ctx);
	buff->append(ConstStr::getCNST_STR_3428(), ctx);
	buff->append(ConstStr::getCNST_STR_1755(), ctx);
	if(!result->head)
	{
	}
	String* byteStr = buff->toString(ctx);
	IArrayObjectPrimitive<char>* byteData = byteStr->getBytes(ConstStr::getCNST_STR_1047(), ctx);
	outStream->write(byteData, ctx);
}
}}}

