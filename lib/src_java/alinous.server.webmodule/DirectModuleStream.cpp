#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
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





bool DirectModuleStream::__init_done = __init_static_variables();
bool DirectModuleStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DirectModuleStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DirectModuleStream::DirectModuleStream(HttpHeaderProcessor* httpRequest, AlinousModule* alnsModule, ThreadContext* ctx) throw()  : IObject(ctx), IContentByteStream(ctx), alnsModule(nullptr), buffer(nullptr)
{
}
void DirectModuleStream::__construct_impl(HttpHeaderProcessor* httpRequest, AlinousModule* alnsModule, ThreadContext* ctx) throw() 
{
}
 DirectModuleStream::~DirectModuleStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DirectModuleStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DirectModuleStream", L"~DirectModuleStream");
	__e_obj1.add(this->alnsModule, this);
	alnsModule = nullptr;
	__e_obj1.add(this->buffer, this);
	buffer = nullptr;
	if(!prepare){
		return;
	}
}
int DirectModuleStream::length(ThreadContext* ctx) throw() 
{
	return this->buffer->length;
}
void DirectModuleStream::output(OutputStream* outStream, ThreadContext* ctx)
{
	outStream->write(this->buffer, ctx);
}
void DirectModuleStream::prepare(AlinousCore* core, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->alnsModule->execute(debug, ctx);
	String* str = val->getStringValue(ctx);
	{
		try
		{
			__GC_MV(this, &(this->buffer), str->getBytes(ConstStr::getCNST_STR_1106(), ctx), IArrayObjectPrimitive<char>);
		}
		catch(UnsupportedEncodingException* e)
		{
			core->logError(e, ctx);
		}
	}
}
String* DirectModuleStream::getContentType(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DirectModuleStream::__cleanUp(ThreadContext* ctx){
}
}}}

