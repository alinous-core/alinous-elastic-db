#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer/FifoList.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"
#include "java.util/BitSet.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server.webmodule/AbstractWebModule.h"
#include "alinous.server.webmodule/WebModuleList.h"
#include "alinous.server.webmodule/WebModuleHashList.h"
#include "alinous.server.webmodule/DirectModuleStream.h"
#include "alinous.server.webmodule/DirectModule.h"
#include "alinous.server.webmodule/StaticHtmlModuleStream.h"
#include "alinous.server.webmodule/StaticHtmlModule.h"
#include "alinous.server.webmodule/DynamicWebPageModuleStream.h"
#include "alinous.server.webmodule/DynamicWebPageModule.h"
#include "alinous.server.webmodule/WebModuleManager.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.server.webmodule/BinaryModuleStream.h"
#include "alinous.server.webmodule/BinaryModule.h"

namespace alinous {namespace server {namespace webmodule {





bool StaticHtmlModuleStream::__init_done = __init_static_variables();
bool StaticHtmlModuleStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StaticHtmlModuleStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StaticHtmlModuleStream::StaticHtmlModuleStream(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, ThreadContext* ctx) throw()  : IObject(ctx), IContentByteStream(ctx), htmlModule(nullptr), buff(nullptr)
{
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	String* code = this->htmlModule->toStaticString(ctx);
	{
		try
		{
			__GC_MV(this, &(this->buff), code->getBytes(ConstStr::getCNST_STR_1106(), ctx), IArrayObjectPrimitive<char>);
		}
		catch(UnsupportedEncodingException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
void StaticHtmlModuleStream::__construct_impl(HttpHeaderProcessor* httpRequest, AlinousWebHtmlXmlModule* htmlModule, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->htmlModule), htmlModule, AlinousWebHtmlXmlModule);
	String* code = this->htmlModule->toStaticString(ctx);
	{
		try
		{
			__GC_MV(this, &(this->buff), code->getBytes(ConstStr::getCNST_STR_1106(), ctx), IArrayObjectPrimitive<char>);
		}
		catch(UnsupportedEncodingException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
 StaticHtmlModuleStream::~StaticHtmlModuleStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StaticHtmlModuleStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StaticHtmlModuleStream", L"~StaticHtmlModuleStream");
	__e_obj1.add(this->htmlModule, this);
	htmlModule = nullptr;
	__e_obj1.add(this->buff, this);
	buff = nullptr;
	if(!prepare){
		return;
	}
}
int StaticHtmlModuleStream::length(ThreadContext* ctx) throw() 
{
	return this->buff->length;
}
void StaticHtmlModuleStream::output(OutputStream* outStream, ThreadContext* ctx)
{
	outStream->write(this->buff, ctx);
}
void StaticHtmlModuleStream::prepare(AlinousCore* core, bool debug, ThreadContext* ctx)
{
}
String* StaticHtmlModuleStream::getContentType(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1894();
}
void StaticHtmlModuleStream::__cleanUp(ThreadContext* ctx){
}
}}}

