#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
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
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SourceValidationError.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression/IExpressionFactory.h"

namespace alinous {namespace compile {namespace expression {





constexpr const int AllocationExpression::NEW_CLASS;
constexpr const int AllocationExpression::NEW_ARRAY;
bool AllocationExpression::__init_done = __init_static_variables();
bool AllocationExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AllocationExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AllocationExpression::AllocationExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), objectClassName(nullptr), arguments(nullptr), arrayCapacity(GCUtils<ArrayList<IExpression> >::ins(this, (new(ctx) ArrayList<IExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), newType(0), analysedType(nullptr), constructor(nullptr)
{
}
void AllocationExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AllocationExpression::~AllocationExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AllocationExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AllocationExpression", L"~AllocationExpression");
	__e_obj1.add(this->objectClassName, this);
	objectClassName = nullptr;
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	__e_obj1.add(this->arrayCapacity, this);
	arrayCapacity = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	__e_obj1.add(this->constructor, this);
	constructor = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* AllocationExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->newType == AllocationExpression::NEW_ARRAY)
	{
		return newArrayObject(machine, debug, ctx);
	}
	IAlinousVariable* returnValue = nullptr;
	switch(this->analysedType->getTypeClass(ctx)) {
	case AlinousType::TYPE_STANDARD_OBJ:
		returnValue = newStandardType(machine, debug, ctx);
		break ;
	case AlinousType::TYPE_CLASS_OBJ:
		returnValue = newClassObject(machine, debug, ctx);
		break ;
	case AlinousType::TYPE_PRIMITIVE:
	default:
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_996(), ctx));
		break;
	}
	return returnValue;
}
bool AllocationExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(arrayCapacity->isEmpty(ctx))
	{
		this->newType = AllocationExpression::NEW_CLASS;
	}
		else 
	{
		this->newType = AllocationExpression::NEW_ARRAY;
	}
	SourceValidator* srcValidator = context->getSourceValidator(ctx);
	__GC_MV(this, &(this->analysedType), this->objectClassName->toAlinousType(context, ctx), AlinousType);
	if(this->analysedType == nullptr)
	{
		srcValidator->addError(this->objectClassName->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_969(), ctx), this, ctx);
		return false;
	}
	switch(this->analysedType->getTypeClass(ctx)) {
	case AlinousType::TYPE_STANDARD_OBJ:
		switch(this->analysedType->getType(ctx)) {
		case AlinousType::STRING_TYPE:
			if(this->arguments->getArgumentSize(ctx) != 1)
			{
				srcValidator->addError(ConstStr::getCNST_STR_997(), this, ctx);
			}
			break ;
		case AlinousType::TIME:
			if(this->arguments->getArgumentSize(ctx) != 1)
			{
				srcValidator->addError(ConstStr::getCNST_STR_997(), this, ctx);
			}
			break ;
		case AlinousType::TIMESTAMP:
			if(this->arguments->getArgumentSize(ctx) != 1)
			{
				srcValidator->addError(ConstStr::getCNST_STR_997(), this, ctx);
			}
			break ;
		case AlinousType::BIGDECIMAL:
			if(this->arguments->getArgumentSize(ctx) != 1)
			{
				srcValidator->addError(ConstStr::getCNST_STR_997(), this, ctx);
			}
			break ;
		default:
			break ;
		}
		break ;
	case AlinousType::TYPE_CLASS_OBJ:
		if(!analyseConstructors(context, ctx))
		{
			return false;
		}
		break ;
	case AlinousType::TYPE_PRIMITIVE:
	default:
		srcValidator->addError(ConstStr::getCNST_STR_996(), this, ctx);
		break;
	}
	return true;
}
bool AllocationExpression::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool AllocationExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->objectClassName != nullptr && !this->objectClassName->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->arrayCapacity->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* arrayCap = this->arrayCapacity->get(i, ctx);
		if(arrayCap != nullptr && !arrayCap->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
AlinousName* AllocationExpression::getObjectClassName(ThreadContext* ctx) throw() 
{
	return objectClassName;
}
void AllocationExpression::setObjectClassName(AlinousName* objectClassName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->objectClassName), objectClassName, AlinousName);
}
ArrayList<IExpression>* AllocationExpression::getArrayCapacity(ThreadContext* ctx) throw() 
{
	return arrayCapacity;
}
void AllocationExpression::addArrayCapacity(IExpression* arrayCapacity, ThreadContext* ctx) throw() 
{
	this->arrayCapacity->add(arrayCapacity, ctx);
}
ExpressionSourceId* AllocationExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->analysedType, ctx));
}
FunctionArguments* AllocationExpression::getArguments(ThreadContext* ctx) throw() 
{
	return arguments;
}
void AllocationExpression::setArguments(FunctionArguments* arguments, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->arguments), arguments, FunctionArguments);
}
AlinousType* AllocationExpression::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
bool AllocationExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int AllocationExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::allocationExpressionType;
}
void AllocationExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->objectClassName), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<FunctionArguments*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_998(), ctx));
		}
		__GC_MV(this, &(this->arguments), static_cast<FunctionArguments*>(el), FunctionArguments);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		this->arrayCapacity->add(static_cast<IExpression*>(el), ctx);
	}
}
void AllocationExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AllocationExpression, ctx);
	bool isnull = (this->objectClassName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->objectClassName->writeData(buff, ctx);
	}
	isnull = (this->arguments == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->arguments->writeData(buff, ctx);
	}
	int maxLoop = this->arrayCapacity->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->arrayCapacity->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
int AllocationExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->objectClassName == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->objectClassName->fileSize(ctx);
	}
	isnull = (this->arguments == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->arguments->fileSize(ctx);
	}
	int maxLoop = this->arrayCapacity->size(ctx);
	total += 4;
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->arrayCapacity->get(i, ctx);
		total += exp->fileSize(ctx);
	}
	return total;
}
void AllocationExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__BitReverseExpression, ctx);
	bool isnull = (this->objectClassName == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->objectClassName->toFileEntry(builder, ctx);
	}
	isnull = (this->arguments == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->arguments->toFileEntry(builder, ctx);
	}
	int maxLoop = this->arrayCapacity->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->arrayCapacity->get(i, ctx);
		exp->toFileEntry(builder, ctx);
	}
}
void AllocationExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		AlinousName* el = AlinousName::fromFileEntry(fetcher, ctx);
		if(el == nullptr)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->objectClassName), el, AlinousName);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<FunctionArguments*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_998(), ctx));
		}
		__GC_MV(this, &(this->arguments), static_cast<FunctionArguments*>(el), FunctionArguments);
	}
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
		}
		this->arrayCapacity->add(static_cast<IExpression*>(el), ctx);
	}
}
IAlinousVariable* AllocationExpression::newClassObject(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	AlinousClass* clazz = this->analysedType->getClazz(ctx);
	AlinousClassVariable* obj = (new(ctx) AlinousClassVariable(clazz, ctx));
	if(this->constructor == nullptr)
	{
		return obj;
	}
	clazz->invokeConstructorMethod(obj, this->constructor, arguments, machine, debug, ctx);
	return obj;
}
IAlinousVariable* AllocationExpression::newStandardType(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = nullptr;
	IExpression* exp = nullptr;
	switch(this->analysedType->getType(ctx)) {
	case AlinousType::STRING_TYPE:
		exp = this->arguments->arguments->get(0, ctx);
		val = machine->resolveExpression(exp, debug, ctx);
		val = (new(ctx) StringVariable(val->getStringValue(ctx), ctx));
		break ;
	case AlinousType::TIME:
		exp = this->arguments->arguments->get(0, ctx);
		val = machine->resolveExpression(exp, debug, ctx);
		val = (new(ctx) StringVariable(val->getStringValue(ctx), ctx));
		break ;
	case AlinousType::TIMESTAMP:
		exp = this->arguments->arguments->get(0, ctx);
		val = machine->resolveExpression(exp, debug, ctx);
		val = (new(ctx) StringVariable(val->getStringValue(ctx), ctx));
		break ;
	case AlinousType::BIGDECIMAL:
		exp = this->arguments->arguments->get(0, ctx);
		val = machine->resolveExpression(exp, debug, ctx);
		val = (new(ctx) StringVariable(val->getStringValue(ctx), ctx));
		break ;
	default:
		break ;
	}
	return val;
}
IAlinousVariable* AllocationExpression::newArrayObject(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	TypedVariableArray* arratVar = (new(ctx) TypedVariableArray(ctx));
	AlinousType::fillArray(0, machine, arratVar, this->analysedType, this->arrayCapacity, debug, ctx);
	return arratVar;
}
bool AllocationExpression::analyseConstructors(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	AlinousClass* clazz = this->analysedType->getClazz(ctx);
	__GC_MV(this, &(this->constructor), clazz->getConstructorFunction(this->arguments, ctx), ClassMethodFunction);
	if(this->constructor == nullptr)
	{
		while(clazz->getExtendsClasses(ctx) != nullptr)
		{
			ClassExtends* classExtends = clazz->getExtendsClasses(ctx);
			clazz = classExtends->getAnalysedClazz(ctx);
			__GC_MV(this, &(this->constructor), clazz->getConstructorFunction(this->arguments, ctx), ClassMethodFunction);
			if(this->constructor != nullptr)
			{
				return true;
			}
		}
	}
	return true;
}
void AllocationExpression::__cleanUp(ThreadContext* ctx){
}
}}}

