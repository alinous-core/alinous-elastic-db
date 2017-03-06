#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/CatchBlock.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/ThrowStatement.h"
#include "alinous.compile.stmt/TryBlock.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"

namespace alinous {namespace compile {namespace stmt {





bool SwitchCasePart::__init_done = __init_static_variables();
bool SwitchCasePart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SwitchCasePart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SwitchCasePart::SwitchCasePart(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), casesList(GCUtils<ArrayList<CaseStatement> >::ins(this, (new(ctx) ArrayList<CaseStatement>(ctx)), ctx, __FILEW__, __LINE__, L"")), stmtlist(nullptr)
{
}
void SwitchCasePart::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SwitchCasePart::~SwitchCasePart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SwitchCasePart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SwitchCasePart", L"~SwitchCasePart");
	__e_obj1.add(this->casesList, this);
	casesList = nullptr;
	__e_obj1.add(this->stmtlist, this);
	stmtlist = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
IStatement::StatementType SwitchCasePart::getType(ThreadContext* ctx) throw() 
{
	return StatementType::SWITCH_CASE_PART;
}
void SwitchCasePart::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool SwitchCasePart::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->casesList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		CaseStatement* stmt = this->casesList->get(i, ctx);
		if(stmt != nullptr && !stmt->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	if(this->stmtlist != nullptr && !this->stmtlist->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SwitchCasePart::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->casesList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->casesList->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	if(this->stmtlist != nullptr)
	{
		this->stmtlist->analyse(context, leftValue, ctx);
	}
	return true;
}
ArrayList<CaseStatement>* SwitchCasePart::getCasesList(ThreadContext* ctx) throw() 
{
	return casesList;
}
void SwitchCasePart::addCase(CaseStatement* caseStmt, ThreadContext* ctx) throw() 
{
	this->casesList->add(caseStmt, ctx);
}
StatementList* SwitchCasePart::getStmtlist(ThreadContext* ctx) throw() 
{
	return stmtlist;
}
void SwitchCasePart::setStmtlist(StatementList* stmtlist, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->stmtlist), stmtlist, StatementList);
}
void SwitchCasePart::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<CaseStatement*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1103(), ctx));
		}
		this->casesList->add(static_cast<CaseStatement*>(el), ctx);
	}
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<StatementList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1101(), ctx));
		}
		__GC_MV(this, &(this->stmtlist), static_cast<StatementList*>(el), StatementList);
	}
}
void SwitchCasePart::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SwitchCasePart, ctx);
	int maxLoop = this->casesList->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		CaseStatement* exp = this->casesList->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	bool isnull = (this->stmtlist == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->stmtlist->writeData(buff, ctx);
	}
}
void SwitchCasePart::__cleanUp(ThreadContext* ctx){
}
}}}

