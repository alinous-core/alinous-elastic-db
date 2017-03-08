#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
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
#include "alinous.compile.sql/RollbackStatement.h"

namespace alinous {namespace compile {namespace sql {





bool RollbackStatement::__init_done = __init_static_variables();
bool RollbackStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RollbackStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RollbackStatement::RollbackStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLStatement(ctx)
{
}
void RollbackStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RollbackStatement::~RollbackStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RollbackStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
void RollbackStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool RollbackStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool RollbackStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType RollbackStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::ROLLBACK;
}
void RollbackStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw() 
{
}
void RollbackStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void RollbackStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__RollbackStatement, ctx);
}
void RollbackStatement::__cleanUp(ThreadContext* ctx){
}
}}}

