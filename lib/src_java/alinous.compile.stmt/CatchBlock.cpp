#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool CatchBlock::__init_done = __init_static_variables();
bool CatchBlock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CatchBlock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CatchBlock::~CatchBlock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CatchBlock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void CatchBlock::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool CatchBlock::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool CatchBlock::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType CatchBlock::getType(ThreadContext* ctx) throw() 
{
	return StatementType::CATCH_STATEMENT;
}
void CatchBlock::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void CatchBlock::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__CatchBlock, ctx);
}
}}}

