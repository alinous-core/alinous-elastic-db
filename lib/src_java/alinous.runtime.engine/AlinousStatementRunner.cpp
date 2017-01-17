#include "includes.h"


namespace alinous {namespace runtime {namespace engine {





bool AlinousStatementRunner::__init_done = __init_static_variables();
bool AlinousStatementRunner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousStatementRunner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousStatementRunner::~AlinousStatementRunner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousStatementRunner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
bool AlinousStatementRunner::assignStatement(AssignmentStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IExpression* left = stmt->getLeft(ctx);
	IExpression* right = stmt->getRight(ctx);
	IAlinousVariable* value = machine->resolveExpression(right, debug, ctx);
	if(value == nullptr)
	{
		value = (new(ctx) VariantValue(ctx));
	}
	if((dynamic_cast<DomVariableDescriptor*>(left) != 0))
	{
		if(value->getVariableClass(ctx) != IAlinousVariable::CLASS_DOM)
		{
			value = value->toDomVariable(ctx);
		}
		machine->putVariable(static_cast<DomVariableDescriptor*>(left), static_cast<IDomVariable*>(value), debug, ctx);
		return false;
	}
	IAlinousVariable* leftValue = nullptr;
	machine->setLeftValue(true, ctx);
	{
		try
		{
			leftValue = left->resolveExpression(machine, debug, ctx);
		}
		catch(Throwable* e)
		{
			machine->setLeftValue(false, ctx);
			throw e;
		}
	}
	machine->setLeftValue(false, ctx);
	if((dynamic_cast<IdentifierVariable*>(leftValue) != 0))
	{
		IdentifierVariable* idVal = static_cast<IdentifierVariable*>(leftValue);
		if(idVal->isDomDescriptor(ctx))
		{
			machine->putVariable(idVal->getDomDescriptor(ctx), value->toDomVariable(ctx), debug, ctx);
		}
				else 
		{
			substituteLocalVariableByIdenifier(machine, idVal, value, debug, ctx);
		}
		return false;
	}
	if((dynamic_cast<IAlinousVariable*>(leftValue) != 0))
	{
		leftValue->substitute(value, ctx);
		return false;
	}
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool AlinousStatementRunner::returnStatement(ReturnStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IExpression* exp = stmt->getExp(ctx);
	IAlinousVariable* returnedValue = machine->resolveExpression(exp, debug, ctx);
	machine->setReturnedValue(returnedValue, ctx);
	return false;
}
bool AlinousStatementRunner::expressionStatement(ExpressionStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IExpression* exp = stmt->getExp(ctx);
	if(debug)
	{
		machine->getCore(ctx)->getDebugger(ctx)->notifyBeforeExpression(exp, machine, ctx);
	}
	machine->resolveExpression(exp, debug, ctx);
	return false;
}
bool AlinousStatementRunner::statementBlock(StatementBlock* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	StatementList* stmtlist = stmt->getList(ctx);
	statementList(stmtlist, machine, debug, ctx);
	return false;
}
bool AlinousStatementRunner::typedVariableDeclare(TypedVariableDeclare* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ITypedVariable* variable = nullptr;
	IExpression* initExp = stmt->getInitExp(ctx);
	if(initExp != nullptr)
	{
		IAlinousVariable* initVal = initExp->resolveExpression(machine, debug, ctx);
		if((dynamic_cast<ITypedVariable*>(initVal) != 0))
		{
			variable = static_cast<ITypedVariable*>(initVal);
		}
				else 
		{
			switch(stmt->getTypeEnum(ctx)) {
			case TypedVariableDeclare::VariableType::BOOL_TYPE:
			case TypedVariableDeclare::VariableType::BYTE_TYPE:
				variable = initVal->toByteVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::SHORT_TYPE:
				variable = initVal->toShortVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::CHAR_TYPE:
				variable = initVal->toCharVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::INT_TYPE:
				variable = initVal->toIntVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::LONG_TYPE:
				variable = initVal->toLongVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::FLOAT_TYPE:
				variable = initVal->toFloatVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
				variable = initVal->toDoubleVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::STRING_TYPE:
				variable = initVal->toStringVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::TIMESTAMP:
				variable = initVal->toTimestampVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::TIME:
				variable = initVal->toTimeVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::BIGDECIMAL:
				variable = initVal->toBigDecimalVariable(ctx);
				break ;
			case TypedVariableDeclare::VariableType::OBJECT_TYPE:
				variable = static_cast<ITypedVariable*>(initVal);
				break ;
			default:
				break ;
			}
		}
	}
		else 
	{
		switch(stmt->getTypeEnum(ctx)) {
		case TypedVariableDeclare::VariableType::BOOL_TYPE:
			variable = (new(ctx) ByteVariable(((char)0), ctx));
			break ;
		case TypedVariableDeclare::VariableType::BYTE_TYPE:
			variable = (new(ctx) ByteVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::SHORT_TYPE:
			variable = (new(ctx) ShortVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::CHAR_TYPE:
			variable = (new(ctx) CharVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::INT_TYPE:
			variable = (new(ctx) IntegerVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::LONG_TYPE:
			variable = (new(ctx) LongVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::FLOAT_TYPE:
			variable = (new(ctx) FloatVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
			variable = (new(ctx) DoubleVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::STRING_TYPE:
			variable = (new(ctx) StringVariable(ctx));
			break ;
		case TypedVariableDeclare::VariableType::TIMESTAMP:
			variable = (new(ctx) TimestampVariable((new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), ctx));
			break ;
		case TypedVariableDeclare::VariableType::TIME:
			variable = (new(ctx) TimeVariable((new(ctx) TimeOnlyTimestamp(System::currentTimeMillis(ctx), ctx)), ctx));
			break ;
		case TypedVariableDeclare::VariableType::BIGDECIMAL:
			variable = (new(ctx) BigDecimalVariable((new(ctx) BigDecimal(0, ctx)), ctx));
			break ;
		case TypedVariableDeclare::VariableType::OBJECT_TYPE:
			variable = (new(ctx) AlinousClassVariable(stmt->getAnalysedType(ctx)->getClazz(ctx), ctx));
			break ;
		default:
			break ;
		}
	}
	AlinousName* aname = stmt->getName(ctx);
	String* name = aname->toString(ctx);
	machine->putTypedVariable(name, variable, ctx);
	return false;
}
bool AlinousStatementRunner::statementList(StatementList* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<IStatement>* list = stmt->getList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IStatement* s = list->get(i, ctx);
		bool controled = ScriptRunner::executeStatement(s, machine, debug, ctx);
		if(controled)
		{
			return true;
		}
	}
	return false;
}
void AlinousStatementRunner::substituteLocalVariableByIdenifier(ScriptMachine* machine, IdentifierVariable* leftId, IAlinousVariable* value, bool debug, ThreadContext* ctx)
{
	String* idStr = leftId->getId(ctx);
	ITypedVariable* leftTypedValue = machine->getTypedVariable(idStr, ctx);
	ArrayList<IExpression>* arrayIdxList = leftId->getArrayIndexes(ctx);
	if(arrayIdxList == nullptr)
	{
		leftTypedValue->substitute(value, ctx);
		return;
	}
	int maxLoop = arrayIdxList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(leftTypedValue->getTypedType(ctx) != ITypedVariable::TYPE_ARRAY)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1154(), ctx));
		}
		IExpression* exp = arrayIdxList->get(i, ctx);
		IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
		int index = val->getIntValue(ctx);
		leftTypedValue = (static_cast<TypedVariableArray*>(leftTypedValue))->get(index, ctx);
	}
	leftTypedValue->substitute(value, ctx);
}
}}}

