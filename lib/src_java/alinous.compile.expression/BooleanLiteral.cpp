#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool BooleanLiteral::__init_done = __init_static_variables();
bool BooleanLiteral::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BooleanLiteral", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BooleanLiteral::BooleanLiteral(ThreadContext* ctx) throw()  : IObject(ctx), Literal(Literal::literalTypes::BOOLEAN, ctx)
{
}
void BooleanLiteral::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BooleanLiteral::~BooleanLiteral() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BooleanLiteral::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Literal::__releaseRegerences(true, ctx);
}
int BooleanLiteral::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::booleanLiteral;
}
void BooleanLiteral::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void BooleanLiteral::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__BooleanLiteral, ctx);
	__writeData(buff, ctx);
}
void BooleanLiteral::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__BooleanLiteral, ctx);
	__toFileEntry(builder, ctx);
}
}}}

