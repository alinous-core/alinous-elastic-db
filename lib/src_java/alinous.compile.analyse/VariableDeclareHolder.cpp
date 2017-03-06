#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.analyse/SubVariableDeclareHolder.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.compile.analyse/ClassDeclareHolder.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/TableColumnIdentifier.h"

namespace alinous {namespace compile {namespace analyse {





bool VariableDeclareHolder::__init_done = __init_static_variables();
bool VariableDeclareHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableDeclareHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableDeclareHolder::VariableDeclareHolder(ThreadContext* ctx) throw()  : IObject(ctx), variableDeclares(GCUtils<Stack<SubVariableDeclareHolder> >::ins(this, (new(ctx) Stack<SubVariableDeclareHolder>(ctx)), ctx, __FILEW__, __LINE__, L"")), domDeclare(GCUtils<HashMap<String,DomVariableDeclareSource> >::ins(this, (new(ctx) HashMap<String,DomVariableDeclareSource>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void VariableDeclareHolder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableDeclareHolder::~VariableDeclareHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableDeclareHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"VariableDeclareHolder", L"~VariableDeclareHolder");
	__e_obj1.add(this->variableDeclares, this);
	variableDeclares = nullptr;
	__e_obj1.add(this->domDeclare, this);
	domDeclare = nullptr;
	if(!prepare){
		return;
	}
}
HashMap<String,DomVariableDeclareSource>* VariableDeclareHolder::getDomDeclare(ThreadContext* ctx) throw() 
{
	return domDeclare;
}
void VariableDeclareHolder::newSubStack(ThreadContext* ctx) throw() 
{
	SubVariableDeclareHolder* holder = (new(ctx) SubVariableDeclareHolder(ctx));
	variableDeclares->push(holder, ctx);
}
void VariableDeclareHolder::endSubStack(ThreadContext* ctx) throw() 
{
	this->variableDeclares->pop(ctx);
}
SubVariableDeclareHolder* VariableDeclareHolder::getCurrentSubStack(ThreadContext* ctx) throw() 
{
	return this->variableDeclares->peek(ctx);
}
void VariableDeclareHolder::addTypeVariableDeclare(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() 
{
	SubVariableDeclareHolder* sub = this->variableDeclares->peek(ctx);
	sub->addFunctionArgumentDefine(argumentDefine, ctx);
}
void VariableDeclareHolder::addTypeVariableDeclare(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() 
{
	SubVariableDeclareHolder* sub = this->variableDeclares->peek(ctx);
	sub->addTypedVariableDeclare(typedVariableDeclare, ctx);
}
TypedVariableDeclareSource* VariableDeclareHolder::getTypedVariableDeclare(String* name, ThreadContext* ctx) throw() 
{
	TypedVariableDeclareSource* ret = nullptr;
	int maxLoop = this->variableDeclares->size(ctx) - 1;
	for(int i = maxLoop; i != -1; --i)
	{
		SubVariableDeclareHolder* sub = this->variableDeclares->get(i, ctx);
		ret = sub->getTypedVariableDeclareSource(name, ctx);
		if(ret != nullptr)
		{
			return ret;
		}
	}
	return nullptr;
}
void VariableDeclareHolder::__cleanUp(ThreadContext* ctx){
}
}}}

