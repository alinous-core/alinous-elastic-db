#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"

namespace alinous {namespace compile {namespace stmt {





bool FinallyBlock::__init_done = __init_static_variables();
bool FinallyBlock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FinallyBlock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FinallyBlock::FinallyBlock(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx)
{
}
void FinallyBlock::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FinallyBlock::~FinallyBlock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FinallyBlock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void FinallyBlock::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool FinallyBlock::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool FinallyBlock::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType FinallyBlock::getType(ThreadContext* ctx) throw() 
{
	return StatementType::FINALLY_STATEMENT;
}
void FinallyBlock::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void FinallyBlock::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__FinallyBlock, ctx);
}
void FinallyBlock::__cleanUp(ThreadContext* ctx){
}
}}}

