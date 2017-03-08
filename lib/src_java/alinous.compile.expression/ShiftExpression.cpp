#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"

namespace alinous {namespace compile {namespace expression {





bool ShiftExpression::__init_done = __init_static_variables();
bool ShiftExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ShiftExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ShiftExpression::ShiftExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractCollectionExpression(ctx)
{
}
void ShiftExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ShiftExpression::~ShiftExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ShiftExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ShiftExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->first, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_999(), ctx));
	}
	if(variable->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	variable = variable->copy(ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubExpression* subexp = this->expressions->get(i, ctx);
		IAlinousVariable* operand = machine->resolveExpression(subexp->getExp(ctx), debug, ctx)->copy(ctx);
		switch(subexp->getOp(ctx)) {
		case AbstractExpression::SHIFT_LEFT:
			variable = variable->shiftLeft(operand, ctx);
			break ;
		case AbstractExpression::SHIFT_RIGHT:
			variable = variable->shiftRight(operand, ctx);
			break ;
		case AbstractExpression::SHIFT_RIGHT_UNSIGNED:
		default:
			variable = variable->shiftRightUnsigned(operand, ctx);
			break ;
		}
	}
	return variable;
}
bool ShiftExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int ShiftExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::shiftExpression;
}
void ShiftExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void ShiftExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ShiftExpression, ctx);
	__writeData(buff, ctx);
}
void ShiftExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ShiftExpression, ctx);
	__toFileEntry(builder, ctx);
}
void ShiftExpression::includes(IExpressionFactory* arg0, ThreadContext* ctx) throw() 
{
}
void ShiftExpression::__cleanUp(ThreadContext* ctx){
}
}}}

