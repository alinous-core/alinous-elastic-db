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
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.system.functions/NativeFunctionManager.h"
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/ExpressionStreamResult.h"
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





bool SrcAnalyseContext::__init_done = __init_static_variables();
bool SrcAnalyseContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SrcAnalyseContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SrcAnalyseContext::SrcAnalyseContext(AlinousModule* module, AlinousFunctionManager* functionManager, SQLFunctionManager* sqlFunctionManager, ThreadContext* ctx) throw()  : IObject(ctx), sqlFunctionManager(nullptr), variableDeclares(GCUtils<Stack<VariableDeclareHolder> >::ins(this, (new(ctx) Stack<VariableDeclareHolder>(ctx)), ctx, __FILEW__, __LINE__, L"")), classDeclareHolder(__GC_INS(this, (new(ctx) ClassDeclareHolder(ctx)), ClassDeclareHolder)), sourceValidator(nullptr), module(nullptr), functionManager(nullptr), expStreamStack(GCUtils<Stack<ExpressionStreamResult> >::ins(this, (new(ctx) Stack<ExpressionStreamResult>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	__GC_MV(this, &(this->sourceValidator), (new(ctx) SourceValidator(ctx)), SourceValidator);
	__GC_MV(this, &(this->functionManager), functionManager, AlinousFunctionManager);
	__GC_MV(this, &(this->sqlFunctionManager), sqlFunctionManager, SQLFunctionManager);
}
void SrcAnalyseContext::__construct_impl(AlinousModule* module, AlinousFunctionManager* functionManager, SQLFunctionManager* sqlFunctionManager, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->module), module, AlinousModule);
	__GC_MV(this, &(this->sourceValidator), (new(ctx) SourceValidator(ctx)), SourceValidator);
	__GC_MV(this, &(this->functionManager), functionManager, AlinousFunctionManager);
	__GC_MV(this, &(this->sqlFunctionManager), sqlFunctionManager, SQLFunctionManager);
}
 SrcAnalyseContext::~SrcAnalyseContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SrcAnalyseContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SrcAnalyseContext", L"~SrcAnalyseContext");
	__e_obj1.add(this->sqlFunctionManager, this);
	sqlFunctionManager = nullptr;
	__e_obj1.add(this->variableDeclares, this);
	variableDeclares = nullptr;
	__e_obj1.add(this->classDeclareHolder, this);
	classDeclareHolder = nullptr;
	__e_obj1.add(this->sourceValidator, this);
	sourceValidator = nullptr;
	__e_obj1.add(this->module, this);
	module = nullptr;
	__e_obj1.add(this->functionManager, this);
	functionManager = nullptr;
	__e_obj1.add(this->expStreamStack, this);
	expStreamStack = nullptr;
	if(!prepare){
		return;
	}
}
AlinousType* SrcAnalyseContext::getFunctionReturnType(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	AlinousType* type = this->functionManager->getFunctionReturnType(prefix, name, ctx);
	if(type != nullptr)
	{
		return type;
	}
	type = this->module->getFunctionReturnType(prefix, name, ctx);
	if(type != nullptr)
	{
		return type;
	}
	return nullptr;
}
IAlinousNativeFunction* SrcAnalyseContext::getNativeFuncion(String* prefix, String* name, ThreadContext* ctx) throw() 
{
	return this->functionManager->getNativeFunction(prefix, name, ctx);
}
bool SrcAnalyseContext::isJavaFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->functionManager->isJavaFunction(prefix, funcName, ctx);
}
bool SrcAnalyseContext::isNativeFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	return this->functionManager->isNativeFunction(prefix, funcName, ctx);
}
bool SrcAnalyseContext::isSourceFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(prefix, ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(funcName, ctx);
	AlinousFunction* func = this->module->findFunction(buff->toString(ctx), ctx);
	return func != nullptr;
}
AlinousFunction* SrcAnalyseContext::getSourceFunction(String* prefix, String* funcName, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(prefix, ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(funcName, ctx);
	return this->module->findFunction(buff->toString(ctx), ctx);
}
bool SrcAnalyseContext::isFunctionPrefix(String* name, ThreadContext* ctx) throw() 
{
	bool bl = this->functionManager->isFunctionPrefix(name, ctx);
	if(bl)
	{
		return true;
	}
	bl = this->module->isfunctionPrefix(name, ctx);
	if(bl)
	{
		return true;
	}
	return false;
}
ExpressionStreamResult* SrcAnalyseContext::getExpressionStreamResult(ThreadContext* ctx) throw() 
{
	return this->expStreamStack->peek(ctx);
}
void SrcAnalyseContext::newExpressionStream(ThreadContext* ctx) throw() 
{
	ExpressionStreamResult* result = (new(ctx) ExpressionStreamResult(ctx));
	this->expStreamStack->push(result, ctx);
}
ExpressionStreamResult* SrcAnalyseContext::endExpressionStream(ThreadContext* ctx) throw() 
{
	return this->expStreamStack->pop(ctx);
}
AlinousClass* SrcAnalyseContext::findClassDeclare(AlinousName* className, ThreadContext* ctx) throw() 
{
	return this->classDeclareHolder->fincClassDeclare(className, this->module->getPackageName(ctx), ctx);
}
void SrcAnalyseContext::addClassDeclare(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	this->classDeclareHolder->addClassDeclare(clazz, ctx);
}
void SrcAnalyseContext::newStack(ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* holder = (new(ctx) VariableDeclareHolder(ctx));
	holder->newSubStack(ctx);
	variableDeclares->push(holder, ctx);
}
void SrcAnalyseContext::endStack(ThreadContext* ctx) throw() 
{
	this->variableDeclares->pop(ctx);
}
VariableDeclareHolder* SrcAnalyseContext::getCurrentStack(ThreadContext* ctx) throw() 
{
	return this->variableDeclares->peek(ctx);
}
SourceValidator* SrcAnalyseContext::getSourceValidator(ThreadContext* ctx) throw() 
{
	return sourceValidator;
}
void SrcAnalyseContext::addError(String* message, IAlinousElement* element, ThreadContext* ctx) throw() 
{
	this->sourceValidator->addError(message, element, ctx);
}
void SrcAnalyseContext::__cleanUp(ThreadContext* ctx){
}
}}}

