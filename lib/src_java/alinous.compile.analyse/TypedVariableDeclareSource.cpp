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





constexpr const int TypedVariableDeclareSource::DOM_VARIABLE;
constexpr const int TypedVariableDeclareSource::DOM_ARRAY_VARIABLE;
constexpr const int TypedVariableDeclareSource::BOOL_TYPE;
constexpr const int TypedVariableDeclareSource::BYTE_TYPE;
constexpr const int TypedVariableDeclareSource::SHORT_TYPE;
constexpr const int TypedVariableDeclareSource::CHAR_TYPE;
constexpr const int TypedVariableDeclareSource::INT_TYPE;
constexpr const int TypedVariableDeclareSource::LONG_TYPE;
constexpr const int TypedVariableDeclareSource::FLOAT_TYPE;
constexpr const int TypedVariableDeclareSource::DOUBLE_TYPE;
constexpr const int TypedVariableDeclareSource::STRING_TYPE;
constexpr const int TypedVariableDeclareSource::TIMESTAMP;
constexpr const int TypedVariableDeclareSource::TIME;
constexpr const int TypedVariableDeclareSource::BIGDECIMAL;
constexpr const int TypedVariableDeclareSource::OBJECT_TYPE;
bool TypedVariableDeclareSource::__init_done = __init_static_variables();
bool TypedVariableDeclareSource::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclareSource", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TypedVariableDeclareSource::TypedVariableDeclareSource(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw()  : IObject(ctx), argumentDefine(nullptr), typedVariableDeclare(nullptr), variableType(0)
{
	__GC_MV(this, &(this->argumentDefine), argumentDefine, FunctionArgumentDefine);
	argumentsTypedVriable(ctx);
}
void TypedVariableDeclareSource::__construct_impl(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->argumentDefine), argumentDefine, FunctionArgumentDefine);
	argumentsTypedVriable(ctx);
}
 TypedVariableDeclareSource::TypedVariableDeclareSource(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw()  : IObject(ctx), argumentDefine(nullptr), typedVariableDeclare(nullptr), variableType(0)
{
	__GC_MV(this, &(this->typedVariableDeclare), typedVariableDeclare, TypedVariableDeclare);
	initTypedVriable(ctx);
}
void TypedVariableDeclareSource::__construct_impl(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->typedVariableDeclare), typedVariableDeclare, TypedVariableDeclare);
	initTypedVriable(ctx);
}
 TypedVariableDeclareSource::~TypedVariableDeclareSource() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TypedVariableDeclareSource::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclareSource", L"~TypedVariableDeclareSource");
	__e_obj1.add(this->argumentDefine, this);
	argumentDefine = nullptr;
	__e_obj1.add(this->typedVariableDeclare, this);
	typedVariableDeclare = nullptr;
	if(!prepare){
		return;
	}
}
int TypedVariableDeclareSource::getVariableType(ThreadContext* ctx) throw() 
{
	return variableType;
}
String* TypedVariableDeclareSource::getSearchId(ThreadContext* ctx) throw() 
{
	if(this->argumentDefine != nullptr)
	{
		return this->argumentDefine->getName(ctx)->toString(ctx);
	}
	return this->typedVariableDeclare->getName(ctx)->toString(ctx);
}
TypedVariableDeclare* TypedVariableDeclareSource::getTypedVariableDeclare(ThreadContext* ctx) throw() 
{
	return typedVariableDeclare;
}
FunctionArgumentDefine* TypedVariableDeclareSource::getArgumentDefine(ThreadContext* ctx) throw() 
{
	return argumentDefine;
}
void TypedVariableDeclareSource::argumentsTypedVriable(ThreadContext* ctx) throw() 
{
	switch(this->argumentDefine->getVariableType(ctx)) {
	case FunctionArgumentDefine::FunctionArgumentType::DOM_VARIABLE:
		this->variableType = TypedVariableDeclareSource::DOM_VARIABLE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::DOM_ARRAY_VARIABLE:
		this->variableType = TypedVariableDeclareSource::DOM_ARRAY_VARIABLE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BOOL_TYPE:
		this->variableType = TypedVariableDeclareSource::BOOL_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BYTE_TYPE:
		this->variableType = TypedVariableDeclareSource::BYTE_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::SHORT_TYPE:
		this->variableType = TypedVariableDeclareSource::SHORT_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::CHAR_TYPE:
		this->variableType = TypedVariableDeclareSource::CHAR_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::INT_TYPE:
		this->variableType = TypedVariableDeclareSource::INT_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::LONG_TYPE:
		this->variableType = TypedVariableDeclareSource::LONG_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::FLOAT_TYPE:
		this->variableType = TypedVariableDeclareSource::FLOAT_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::DOUBLE_TYPE:
		this->variableType = TypedVariableDeclareSource::DOUBLE_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::STRING_TYPE:
		this->variableType = TypedVariableDeclareSource::STRING_TYPE;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::TIMESTAMP:
		this->variableType = TypedVariableDeclareSource::TIMESTAMP;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::TIME:
		this->variableType = TypedVariableDeclareSource::TIME;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BIGDECIMAL:
		this->variableType = TypedVariableDeclareSource::BIGDECIMAL;
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::OBJECT_TYPE:
	default:
		this->variableType = TypedVariableDeclareSource::OBJECT_TYPE;
		break ;
	}
}
void TypedVariableDeclareSource::initTypedVriable(ThreadContext* ctx) throw() 
{
	switch(this->typedVariableDeclare->getTypeEnum(ctx)) {
	case TypedVariableDeclare::VariableType::BOOL_TYPE:
		this->variableType = TypedVariableDeclareSource::BOOL_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::BYTE_TYPE:
		this->variableType = TypedVariableDeclareSource::BYTE_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::SHORT_TYPE:
		this->variableType = TypedVariableDeclareSource::SHORT_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::CHAR_TYPE:
		this->variableType = TypedVariableDeclareSource::CHAR_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::INT_TYPE:
		this->variableType = TypedVariableDeclareSource::INT_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::LONG_TYPE:
		this->variableType = TypedVariableDeclareSource::LONG_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::FLOAT_TYPE:
		this->variableType = TypedVariableDeclareSource::FLOAT_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
		this->variableType = TypedVariableDeclareSource::DOUBLE_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::STRING_TYPE:
		this->variableType = TypedVariableDeclareSource::STRING_TYPE;
		break ;
	case TypedVariableDeclare::VariableType::TIMESTAMP:
		this->variableType = TypedVariableDeclareSource::TIMESTAMP;
		break ;
	case TypedVariableDeclare::VariableType::TIME:
		this->variableType = TypedVariableDeclareSource::TIME;
		break ;
	case TypedVariableDeclare::VariableType::BIGDECIMAL:
		this->variableType = TypedVariableDeclareSource::BIGDECIMAL;
		break ;
	case TypedVariableDeclare::VariableType::OBJECT_TYPE:
	default:
		this->variableType = TypedVariableDeclareSource::OBJECT_TYPE;
		break ;
	}
}
void TypedVariableDeclareSource::__cleanUp(ThreadContext* ctx){
}
}}}

