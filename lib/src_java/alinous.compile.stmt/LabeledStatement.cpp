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
#include "alinous.compile.stmt/LabeledStatement.h"

namespace alinous {namespace compile {namespace stmt {





bool LabeledStatement::__init_done = __init_static_variables();
bool LabeledStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LabeledStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LabeledStatement::LabeledStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), label(nullptr)
{
}
void LabeledStatement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 LabeledStatement::~LabeledStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LabeledStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LabeledStatement", L"~LabeledStatement");
	__e_obj1.add(this->label, this);
	label = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void LabeledStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool LabeledStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool LabeledStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType LabeledStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::LABELED_STATEMENT;
}
String* LabeledStatement::getLabel(ThreadContext* ctx) throw() 
{
	return label;
}
void LabeledStatement::setLabel(String* label, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->label), label, String);
}
void LabeledStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->label), buff->getString(ctx), String);
	}
}
void LabeledStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__LabeledStatement, ctx);
	bool isnull = (this->label == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->label, ctx);
	}
}
void LabeledStatement::__cleanUp(ThreadContext* ctx){
}
}}}

