#include "includes.h"


namespace alinous {namespace compile {





bool AlinousSrc::__init_done = __init_static_variables();
bool AlinousSrc::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousSrc", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousSrc::~AlinousSrc() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousSrc::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousSrc", L"~AlinousSrc");
	__e_obj1.add(this->includes, this);
	includes = nullptr;
	__e_obj1.add(this->statements, this);
	statements = nullptr;
	__e_obj1.add(this->declares, this);
	declares = nullptr;
	__e_obj1.add(this->functionDeclares, this);
	functionDeclares = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
void AlinousSrc::addInclude(IncludePreprocessor* inc, ThreadContext* ctx) throw() 
{
	this->includes->add(inc, ctx);
}
ArrayList<IncludePreprocessor>* AlinousSrc::getIncludes(ThreadContext* ctx) throw() 
{
	return this->includes;
}
void AlinousSrc::addDeclare(IDeclare* dec, ThreadContext* ctx) throw() 
{
	this->declares->add(dec, ctx);
	if((dynamic_cast<AlinousFunction*>(dec) != 0))
	{
		this->functionDeclares->add(static_cast<AlinousFunction*>(dec), ctx);
	}
}
ArrayList<IDeclare>* AlinousSrc::getDeclares(ThreadContext* ctx) throw() 
{
	return declares;
}
void AlinousSrc::addStatementList(StatementList* list, ThreadContext* ctx) throw() 
{
	this->statements->add(list, ctx);
}
ArrayList<StatementList>* AlinousSrc::getStatements(ThreadContext* ctx) throw() 
{
	return statements;
}
ArrayList<AlinousFunction>* AlinousSrc::getFunctionDeclares(ThreadContext* ctx) throw() 
{
	return functionDeclares;
}
bool AlinousSrc::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->includes->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->statements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->statements->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	maxLoop = this->declares->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->declares->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool AlinousSrc::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int maxLoop = this->includes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IncludePreprocessor* inc = this->includes->get(i, ctx);
		inc->analyse(context, leftValue, ctx);
	}
	maxLoop = this->declares->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->declares->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	maxLoop = this->statements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->statements->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
int AlinousSrc::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int AlinousSrc::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int AlinousSrc::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int AlinousSrc::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* AlinousSrc::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void AlinousSrc::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
}}

