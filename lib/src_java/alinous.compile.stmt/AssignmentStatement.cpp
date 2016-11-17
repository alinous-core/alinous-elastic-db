#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool AssignmentStatement::__init_done = __init_static_variables();
bool AssignmentStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AssignmentStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AssignmentStatement::~AssignmentStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AssignmentStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AssignmentStatement", L"~AssignmentStatement");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	__e_obj1.add(this->ope, this);
	ope = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void AssignmentStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool AssignmentStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->left != nullptr && !this->left->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool AssignmentStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr)
	{
		this->left->analyse(context, true, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyse(context, false, ctx);
	}
	return true;
}
IExpression* AssignmentStatement::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void AssignmentStatement::setLeft(IExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, IExpression);
}
IExpression* AssignmentStatement::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void AssignmentStatement::setRight(IExpression* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, IExpression);
}
String* AssignmentStatement::getOpe(ThreadContext* ctx) throw() 
{
	return ope;
}
void AssignmentStatement::setOpe(String* ope, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->ope), ope, String);
}
IStatement::StatementType AssignmentStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::ASSIGN;
}
}}}

