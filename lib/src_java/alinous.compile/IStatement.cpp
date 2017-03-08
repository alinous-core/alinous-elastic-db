#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IStatement.h"

namespace alinous {namespace compile {



constexpr EnumBase __IStatement__StatementType::__DEFAULT_NULL;
constexpr EnumBase __IStatement__StatementType::ASSIGN;
constexpr EnumBase __IStatement__StatementType::EXPRESSION;
constexpr EnumBase __IStatement__StatementType::RETURN;
constexpr EnumBase __IStatement__StatementType::BLOCK;
constexpr EnumBase __IStatement__StatementType::STMT_LIST;
constexpr EnumBase __IStatement__StatementType::TYPED_VARIABLE_DECLARE;
constexpr EnumBase __IStatement__StatementType::FOR_STATEMENT;
constexpr EnumBase __IStatement__StatementType::FOR_UPDATE_STATEMENT_PART;
constexpr EnumBase __IStatement__StatementType::IF_STATEMENT;
constexpr EnumBase __IStatement__StatementType::LABELED_STATEMENT;
constexpr EnumBase __IStatement__StatementType::WHILE_STATEMENT;
constexpr EnumBase __IStatement__StatementType::DO_WHILE_STATEMENT;
constexpr EnumBase __IStatement__StatementType::SWITCH_STATEMENT;
constexpr EnumBase __IStatement__StatementType::SWITCH_CASE_PART;
constexpr EnumBase __IStatement__StatementType::CASE_STATEMENT;
constexpr EnumBase __IStatement__StatementType::DEFAULT_STATEMENT;
constexpr EnumBase __IStatement__StatementType::BREAK_STATEMENT;
constexpr EnumBase __IStatement__StatementType::CONTINUE_STATEMENT;
constexpr EnumBase __IStatement__StatementType::TRY_STATEMENT;
constexpr EnumBase __IStatement__StatementType::CATCH_STATEMENT;
constexpr EnumBase __IStatement__StatementType::THROW_STATEMENT;
constexpr EnumBase __IStatement__StatementType::FINALLY_STATEMENT;
constexpr EnumBase __IStatement__StatementType::BEGIN;
constexpr EnumBase __IStatement__StatementType::COMMIT;
constexpr EnumBase __IStatement__StatementType::CREATE_TABLE;
constexpr EnumBase __IStatement__StatementType::DELETE;
constexpr EnumBase __IStatement__StatementType::DROP_TABLE;
constexpr EnumBase __IStatement__StatementType::INSERT;
constexpr EnumBase __IStatement__StatementType::ROLLBACK;
constexpr EnumBase __IStatement__StatementType::SELECT;
constexpr EnumBase __IStatement__StatementType::UPDATE;
constexpr EnumBase __IStatement__StatementType::CREATE_INDEX;
constexpr EnumBase __IStatement__StatementType::DROP_INDEX;
constexpr EnumBase __IStatement__StatementType::JOIN_PART;


bool IStatement::__init_done = __init_static_variables();
bool IStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IStatement::IStatement(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx)
{
}
void IStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IStatement::~IStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void IStatement::__cleanUp(ThreadContext* ctx){
}
}}

