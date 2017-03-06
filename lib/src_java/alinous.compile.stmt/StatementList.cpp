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





bool StatementList::__init_done = __init_static_variables();
bool StatementList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StatementList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StatementList::StatementList(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), list(GCUtils<ArrayList<IStatement> >::ins(this, (new(ctx) ArrayList<IStatement>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void StatementList::__construct_impl(ThreadContext* ctx) throw() 
{
}
 StatementList::~StatementList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StatementList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StatementList", L"~StatementList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
IStatement* StatementList::getFirstStatement(ThreadContext* ctx) throw() 
{
	if(list->isEmpty(ctx))
	{
		return nullptr;
	}
	return this->list->get(0, ctx);
}
bool StatementList::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->list != nullptr)
	{
		int maxLoop = this->list->size(ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			if(!this->list->get(i, ctx)->visit(visitor, this, ctx))
			{
				return false;
			}
		}
	}
	return true;
}
bool StatementList::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->list != nullptr)
	{
		int maxLoop = this->list->size(ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			this->list->get(i, ctx)->analyse(context, leftValue, ctx);
		}
	}
	return true;
}
void StatementList::add(IStatement* stmt, ThreadContext* ctx) throw() 
{
	this->list->add(stmt, ctx);
}
ArrayList<IStatement>* StatementList::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void StatementList::setList(ArrayList<IStatement>* list, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<IStatement> >::mv(this, &(this->list), list, ctx);
}
IStatement::StatementType StatementList::getType(ThreadContext* ctx) throw() 
{
	return StatementType::STMT_LIST;
}
void StatementList::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void StatementList::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* element = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(element == nullptr || !((dynamic_cast<IStatement*>(element) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1099(), ctx));
		}
		this->list->add(static_cast<IStatement*>(element), ctx);
	}
}
void StatementList::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__StatementList, ctx);
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IStatement* stmt = this->list->get(i, ctx);
		stmt->writeData(buff, ctx);
	}
}
void StatementList::__cleanUp(ThreadContext* ctx){
}
}}}

