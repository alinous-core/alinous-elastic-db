#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/DomTokenizer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html/DocType.h"
#include "alinous.html/DomComment.h"
#include "alinous.html/DomText.h"
#include "alinous.html/AlinousDomEventHandler.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/Test.h"

namespace alinous {namespace html {




bool IReplacer::__init_done = __init_static_variables();
bool IReplacer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IReplacer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IReplacer::IReplacer(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IReplacer::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IReplacer::~IReplacer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IReplacer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IReplacer::__cleanUp(ThreadContext* ctx){
}
}}

