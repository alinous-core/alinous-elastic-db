#include "includes.h"


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
}}}

