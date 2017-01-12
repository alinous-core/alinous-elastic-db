#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool ThrowStatement::__init_done = __init_static_variables();
bool ThrowStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ThrowStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ThrowStatement::~ThrowStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ThrowStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void ThrowStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool ThrowStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool ThrowStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType ThrowStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::THROW_STATEMENT;
}
void ThrowStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void ThrowStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ThrowStatement, ctx);
}
}}}

