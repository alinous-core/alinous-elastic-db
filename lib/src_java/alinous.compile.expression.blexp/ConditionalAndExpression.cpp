#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





bool ConditionalAndExpression::__init_done = __init_static_variables();
bool ConditionalAndExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConditionalAndExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConditionalAndExpression::~ConditionalAndExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConditionalAndExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractBooleanCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ConditionalAndExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = machine->resolveExpression(this->first, debug, ctx);
	if(!val->isTrue(ctx))
	{
		return val;
	}
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->expressions->get(i, ctx);
		val = machine->resolveExpression(exp, debug, ctx);
		if(!val->isTrue(ctx))
		{
			return val;
		}
	}
	return val;
}
int ConditionalAndExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::conditionalAndExpression;
}
void ConditionalAndExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void ConditionalAndExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ConditionalAndExpression, ctx);
	__writeData(buff, ctx);
}
void ConditionalAndExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ConditionalAndExpression, ctx);
	__toFileEntry(builder, ctx);
}
}}}}

