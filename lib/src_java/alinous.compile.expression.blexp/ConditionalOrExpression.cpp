#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





bool ConditionalOrExpression::__init_done = __init_static_variables();
bool ConditionalOrExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConditionalOrExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConditionalOrExpression::~ConditionalOrExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConditionalOrExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractBooleanCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ConditionalOrExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = machine->resolveExpression(this->first, debug, ctx);
	if(val->isTrue(ctx))
	{
		return val;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->expressions->get(i, ctx);
		val = machine->resolveExpression(exp, debug, ctx);
		if(val->isTrue(ctx))
		{
			return val;
		}
	}
	return val;
}
int ConditionalOrExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::andExpression;
}
void ConditionalOrExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void ConditionalOrExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ConditionalOrExpression, ctx);
	__writeData(buff, ctx);
}
void ConditionalOrExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ConditionalOrExpression, ctx);
	__toFileEntry(builder, ctx);
}
}}}}

