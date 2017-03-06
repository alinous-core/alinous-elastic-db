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





bool BinaryModule::__init_done = __init_static_variables();
bool BinaryModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BinaryModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BinaryModule::BinaryModule(String* path, File* file, ThreadContext* ctx) throw()  : IObject(ctx), AbstractWebModule(file->lastModified(ctx), ctx), file(nullptr)
{
	this->moduleType = AbstractWebModule::BINARY_MODULE;
	__GC_MV(this, &(this->file), file, File);
	__GC_MV(this, &(this->path), path, String);
}
void BinaryModule::__construct_impl(String* path, File* file, ThreadContext* ctx) throw() 
{
	this->moduleType = AbstractWebModule::BINARY_MODULE;
	__GC_MV(this, &(this->file), file, File);
	__GC_MV(this, &(this->path), path, String);
}
 BinaryModule::~BinaryModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BinaryModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BinaryModule", L"~BinaryModule");
	__e_obj1.add(this->file, this);
	file = nullptr;
	if(!prepare){
		return;
	}
	AbstractWebModule::__releaseRegerences(true, ctx);
}
IContentByteStream* BinaryModule::getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw() 
{
	return (new(ctx) BinaryModuleStream(httpRequest, this->file, ctx));
}
void BinaryModule::prepare(AlinousCore* core, ThreadContext* ctx) throw() 
{
}
bool BinaryModule::isDirty(ThreadContext* ctx) throw() 
{
	return this->file->lastModified(ctx) > this->timeStamp;
}
void BinaryModule::__cleanUp(ThreadContext* ctx){
}
}}}

