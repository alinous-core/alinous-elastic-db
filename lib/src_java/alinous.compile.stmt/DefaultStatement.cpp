#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SourceValidator.h"
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
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"

namespace alinous {namespace compile {namespace stmt {





bool DefaultStatement::__init_done = __init_static_variables();
bool DefaultStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DefaultStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DefaultStatement::DefaultStatement(ThreadContext* ctx) throw()  : IObject(ctx), CaseStatement(ctx)
{
}
void DefaultStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DefaultStatement::~DefaultStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DefaultStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	CaseStatement::__releaseRegerences(true, ctx);
}
IStatement::StatementType DefaultStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::DEFAULT_STATEMENT;
}
void DefaultStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool DefaultStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
void DefaultStatement::__cleanUp(ThreadContext* ctx){
}
}}}

