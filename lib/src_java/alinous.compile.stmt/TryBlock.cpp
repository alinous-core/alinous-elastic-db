#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool TryBlock::__init_done = __init_static_variables();
bool TryBlock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TryBlock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TryBlock::~TryBlock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TryBlock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void TryBlock::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool TryBlock::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool TryBlock::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType TryBlock::getType(ThreadContext* ctx) throw() 
{
	return StatementType::TRY_STATEMENT;
}
void TryBlock::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void TryBlock::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__TryBlock, ctx);
}
}}}

