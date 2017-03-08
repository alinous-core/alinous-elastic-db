#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"

namespace alinous {namespace web {namespace htmlxml {namespace inner {





bool IHtmlStringPart::__init_done = __init_static_variables();
bool IHtmlStringPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IHtmlStringPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IHtmlStringPart::IHtmlStringPart(ThreadContext* ctx) throw()  : IObject(ctx), isDynamic(0)
{
}
void IHtmlStringPart::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IHtmlStringPart::~IHtmlStringPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IHtmlStringPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IHtmlStringPart", L"~IHtmlStringPart");
	if(!prepare){
		return;
	}
}
void IHtmlStringPart::__cleanUp(ThreadContext* ctx){
}
}}}}

