#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"

namespace alinous {namespace compile {namespace stmt {





bool AbstractAlinousStatement::__init_done = __init_static_variables();
bool AbstractAlinousStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractAlinousStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractAlinousStatement::AbstractAlinousStatement(ThreadContext* ctx) throw()  : IObject(ctx), IStatement(ctx)
{
}
void AbstractAlinousStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractAlinousStatement::~AbstractAlinousStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractAlinousStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IStatement::__releaseRegerences(true, ctx);
}
int AbstractAlinousStatement::getLine(ThreadContext* ctx) throw() 
{
	return IStatement::getLine(ctx);
}
int AbstractAlinousStatement::getStartPosition(ThreadContext* ctx) throw() 
{
	return IStatement::getStartPosition(ctx);
}
int AbstractAlinousStatement::getEndLine(ThreadContext* ctx) throw() 
{
	return IStatement::getEndLine(ctx);
}
int AbstractAlinousStatement::getEndPosition(ThreadContext* ctx) throw() 
{
	return IStatement::getEndPosition(ctx);
}
AbstractSrcElement* AbstractAlinousStatement::getParent(ThreadContext* ctx) throw() 
{
	return IStatement::getParent(ctx);
}
void AbstractAlinousStatement::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IStatement::setParent(parent, ctx);
}
void AbstractAlinousStatement::__cleanUp(ThreadContext* ctx){
}
}}}

