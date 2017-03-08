#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"

namespace alinous {namespace compile {





bool IAlinousElement::__init_done = __init_static_variables();
bool IAlinousElement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IAlinousElement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IAlinousElement::IAlinousElement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSrcElement(ctx), ICommandData(ctx)
{
}
void IAlinousElement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IAlinousElement::~IAlinousElement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IAlinousElement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSrcElement::__releaseRegerences(true, ctx);
}
void IAlinousElement::__cleanUp(ThreadContext* ctx){
}
}}

