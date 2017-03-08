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
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"

namespace alinous {namespace compile {namespace sql {





bool AbstractSQLStatement::__init_done = __init_static_variables();
bool AbstractSQLStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLStatement::AbstractSQLStatement(ThreadContext* ctx) throw()  : IObject(ctx), ISqlStatement(ctx)
{
}
void AbstractSQLStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractSQLStatement::~AbstractSQLStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ISqlStatement::__releaseRegerences(true, ctx);
}
int AbstractSQLStatement::getLine(ThreadContext* ctx) throw() 
{
	return ISqlStatement::getLine(ctx);
}
int AbstractSQLStatement::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISqlStatement::getStartPosition(ctx);
}
int AbstractSQLStatement::getEndLine(ThreadContext* ctx) throw() 
{
	return ISqlStatement::getEndLine(ctx);
}
int AbstractSQLStatement::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISqlStatement::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLStatement::getParent(ThreadContext* ctx) throw() 
{
	return ISqlStatement::getParent(ctx);
}
void AbstractSQLStatement::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISqlStatement::setParent(parent, ctx);
}
void AbstractSQLStatement::__cleanUp(ThreadContext* ctx){
}
}}}

