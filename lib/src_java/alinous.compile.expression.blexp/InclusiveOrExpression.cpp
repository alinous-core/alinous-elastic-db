#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





bool InclusiveOrExpression::__init_done = __init_static_variables();
bool InclusiveOrExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InclusiveOrExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InclusiveOrExpression::~InclusiveOrExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InclusiveOrExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractBooleanCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* InclusiveOrExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = machine->resolveExpression(this->first, debug, ctx);
	val = val->copy(ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->expressions->get(i, ctx);
		IAlinousVariable* operand = machine->resolveExpression(exp, debug, ctx);
		val = val->bitOr(operand, ctx);
	}
	return val;
}
int InclusiveOrExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::inclusiveOrExpression;
}
void InclusiveOrExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void InclusiveOrExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__InclusiveOrExpression, ctx);
	__writeData(buff, ctx);
}
void InclusiveOrExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__InclusiveOrExpression, ctx);
	__toFileEntry(builder, ctx);
}
}}}}

