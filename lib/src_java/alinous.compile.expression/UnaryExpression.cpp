#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"

namespace alinous {namespace compile {namespace expression {





bool UnaryExpression::__init_done = __init_static_variables();
bool UnaryExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UnaryExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UnaryExpression::UnaryExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx)
{
}
void UnaryExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UnaryExpression::~UnaryExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UnaryExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool UnaryExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool UnaryExpression::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool UnaryExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IAlinousVariable* UnaryExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return machine->resolveExpression(this, debug, ctx);
}
ExpressionSourceId* UnaryExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool UnaryExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int UnaryExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::unaryExpression;
}
void UnaryExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void UnaryExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__UnaryExpression, ctx);
}
int UnaryExpression::fileSize(ThreadContext* ctx)
{
	return 4;
}
void UnaryExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__UnaryExpression, ctx);
}
void UnaryExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
}
void UnaryExpression::includes(IExpressionFactory* arg0, ThreadContext* ctx) throw() 
{
}
void UnaryExpression::__cleanUp(ThreadContext* ctx){
}
}}}

