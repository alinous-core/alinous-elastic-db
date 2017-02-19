#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool BeginStatement::__init_done = __init_static_variables();
bool BeginStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BeginStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BeginStatement::~BeginStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BeginStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BeginStatement", L"~BeginStatement");
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
bool BeginStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool BeginStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
void BeginStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
IStatement::StatementType BeginStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::BEGIN;
}
void BeginStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw() 
{
}
void BeginStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void BeginStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__BeginStatement, ctx);
}
int BeginStatement::getIsolationLevel(ThreadContext* ctx) throw() 
{
	return isolationLevel;
}
void BeginStatement::setIsolationLevel(int isolationLevel, ThreadContext* ctx) throw() 
{
	this->isolationLevel = isolationLevel;
}
}}}

