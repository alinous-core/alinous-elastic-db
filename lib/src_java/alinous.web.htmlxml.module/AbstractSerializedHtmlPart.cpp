#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"
#include "alinous.web.htmlxml.module/StaticHtmlPart.h"
#include "alinous.web.htmlxml.module/DynamicBodyPart.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/DynamicExecutableAttributeValue.h"
#include "alinous.web.htmlxml.module/DynamicTag.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml.module/AlinousWebHtmlXmlModule.h"

namespace alinous {namespace web {namespace htmlxml {namespace module {





constexpr const int AbstractSerializedHtmlPart::TYPE_DYNAMIC_BODY;
constexpr const int AbstractSerializedHtmlPart::TYPE_DYNAMIC_TAG;
constexpr const int AbstractSerializedHtmlPart::TYPE_STATIC_PART;
bool AbstractSerializedHtmlPart::__init_done = __init_static_variables();
bool AbstractSerializedHtmlPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSerializedHtmlPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSerializedHtmlPart::AbstractSerializedHtmlPart(ThreadContext* ctx) throw()  : IObject(ctx), type(0)
{
}
void AbstractSerializedHtmlPart::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractSerializedHtmlPart::~AbstractSerializedHtmlPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSerializedHtmlPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSerializedHtmlPart", L"~AbstractSerializedHtmlPart");
	if(!prepare){
		return;
	}
}
void AbstractSerializedHtmlPart::__cleanUp(ThreadContext* ctx){
}
}}}}

