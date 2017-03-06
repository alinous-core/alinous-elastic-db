#include "include/global.h"


#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoList.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"
#include "java.util/BitSet.h"
#include "alinous.server.webmodule/AbstractWebModule.h"
#include "alinous.server.webmodule/WebModuleList.h"
#include "alinous.server.webmodule/WebModuleHashList.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server.webmodule/DirectModuleStream.h"
#include "alinous.server.webmodule/DirectModule.h"
#include "alinous.server.webmodule/StaticHtmlModuleStream.h"
#include "alinous.server.webmodule/StaticHtmlModule.h"
#include "alinous.server.webmodule/DynamicWebPageModuleStream.h"
#include "alinous.server.webmodule/DynamicWebPageModule.h"
#include "alinous.server.webmodule/WebModuleManager.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.server.webmodule/BinaryModuleStream.h"
#include "alinous.server.webmodule/BinaryModule.h"

namespace alinous {namespace server {namespace webmodule {





bool BinaryModuleStream::__init_done = __init_static_variables();
bool BinaryModuleStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BinaryModuleStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BinaryModuleStream::BinaryModuleStream(HttpHeaderProcessor* httpRequest, File* file, ThreadContext* ctx) throw()  : IObject(ctx), IContentByteStream(ctx), filesize(0), file(nullptr)
{
	this->filesize = file->length(ctx);
	__GC_MV(this, &(this->file), file, File);
}
void BinaryModuleStream::__construct_impl(HttpHeaderProcessor* httpRequest, File* file, ThreadContext* ctx) throw() 
{
	this->filesize = file->length(ctx);
	__GC_MV(this, &(this->file), file, File);
}
 BinaryModuleStream::~BinaryModuleStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BinaryModuleStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BinaryModuleStream", L"~BinaryModuleStream");
	__e_obj1.add(this->file, this);
	file = nullptr;
	if(!prepare){
		return;
	}
}
int BinaryModuleStream::length(ThreadContext* ctx) throw() 
{
	return ((int)this->filesize);
}
void BinaryModuleStream::output(OutputStream* outStream, ThreadContext* ctx)
{
	FileInputStream* stream = (new(ctx) FileInputStream(this->file, ctx));
	IArrayObjectPrimitive<char>* buff = ArrayAllocatorPrimitive<char>::allocatep(ctx, 4096);
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			stream->close(ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			int n = stream->read(buff, ctx);
			while(n > 0)
			{
				outStream->write(buff, 0, n, ctx);
				n = stream->read(buff, ctx);
			}
		}
		catch(...){throw;}
	}
}
void BinaryModuleStream::prepare(AlinousCore* core, bool debug, ThreadContext* ctx) throw() 
{
}
String* BinaryModuleStream::getContentType(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BinaryModuleStream::__cleanUp(ThreadContext* ctx){
}
}}}

