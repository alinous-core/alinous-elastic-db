#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression/BooleanLiteral.h"

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
void BooleanLiteral::includes(IExpressionFactory* arg0, ThreadContext* ctx) throw() 
{
}
void BooleanLiteral::__cleanUp(ThreadContext* ctx){
}
}}}

