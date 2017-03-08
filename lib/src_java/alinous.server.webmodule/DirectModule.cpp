#include "include/global.h"


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
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server.webmodule/DirectModuleStream.h"
#include "alinous.server.webmodule/AbstractWebModule.h"
#include "alinous.server.webmodule/DirectModule.h"

namespace alinous {namespace server {namespace webmodule {





bool DirectModule::__init_done = __init_static_variables();
bool DirectModule::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DirectModule", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DirectModule::DirectModule(AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw()  : IObject(ctx), AbstractWebModule(alnsModule->getFile(ctx)->lastModified(ctx), ctx), alnsModule(nullptr)
{
	this->moduleType = AbstractWebModule::DIRECT_MODULE;
	__GC_MV(this, &(this->alnsModule), alnsModule, AlinousModule);
	__GC_MV(this, &(this->path), path, String);
}
void DirectModule::__construct_impl(AlinousModule* alnsModule, String* path, ThreadContext* ctx) throw() 
{
	this->moduleType = AbstractWebModule::DIRECT_MODULE;
	__GC_MV(this, &(this->alnsModule), alnsModule, AlinousModule);
	__GC_MV(this, &(this->path), path, String);
}
 DirectModule::~DirectModule() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DirectModule::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DirectModule", L"~DirectModule");
	__e_obj1.add(this->alnsModule, this);
	alnsModule = nullptr;
	if(!prepare){
		return;
	}
	AbstractWebModule::__releaseRegerences(true, ctx);
}
IContentByteStream* DirectModule::getContentStream(HttpHeaderProcessor* httpRequest, ThreadContext* ctx) throw() 
{
	return (new(ctx) DirectModuleStream(httpRequest, alnsModule, ctx));
}
void DirectModule::prepare(AlinousCore* core, ThreadContext* ctx) throw() 
{
}
bool DirectModule::isDirty(ThreadContext* ctx) throw() 
{
	return alnsModule->getFile(ctx)->lastModified(ctx) > this->timeStamp;
}
void DirectModule::__cleanUp(ThreadContext* ctx){
}
}}}

