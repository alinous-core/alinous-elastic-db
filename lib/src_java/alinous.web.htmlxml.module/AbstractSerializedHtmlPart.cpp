#include "include/global.h"


#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"

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

