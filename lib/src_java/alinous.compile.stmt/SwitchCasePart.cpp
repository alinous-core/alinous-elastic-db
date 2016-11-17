#include "includes.h"


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
}}}

