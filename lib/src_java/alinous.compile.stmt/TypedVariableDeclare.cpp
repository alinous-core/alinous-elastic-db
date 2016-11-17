#include "includes.h"


namespace alinous {namespace compile {namespace stmt {



constexpr EnumBase __TypedVariableDeclare__VariableType::__DEFAULT_NULL;
constexpr EnumBase __TypedVariableDeclare__VariableType::BOOL_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::BYTE_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::SHORT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::CHAR_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::INT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::LONG_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::FLOAT_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::DOUBLE_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::STRING_TYPE;
constexpr EnumBase __TypedVariableDeclare__VariableType::TIMESTAMP;
constexpr EnumBase __TypedVariableDeclare__VariableType::TIME;
constexpr EnumBase __TypedVariableDeclare__VariableType::BIGDECIMAL;
constexpr EnumBase __TypedVariableDeclare__VariableType::OBJECT_TYPE;


bool TypedVariableDeclare::__init_done = __init_static_variables();
bool TypedVariableDeclare::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclare", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TypedVariableDeclare::~TypedVariableDeclare() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TypedVariableDeclare::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TypedVariableDeclare", L"~TypedVariableDeclare");
	__e_obj1.add(this->typeName, this);
	typeName = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->initExp, this);
	initExp = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void TypedVariableDeclare::setTypeName(AlinousName* typeName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->typeName), typeName, AlinousName);
	String* strName = this->typeName->toString(ctx);
	if(strName->equals(ConstStr::getCNST_STR_953(), ctx))
	{
		this->typeEnum = VariableType::BOOL_TYPE;
	}
		else 
	{
		if(strName->equals(ConstStr::getCNST_STR_957(), ctx))
		{
			this->typeEnum = VariableType::INT_TYPE;
		}
				else 
		{
			if(strName->equals(ConstStr::getCNST_STR_961(), ctx))
			{
				this->typeEnum = VariableType::STRING_TYPE;
			}
						else 
			{
				if(strName->equals(ConstStr::getCNST_STR_954(), ctx))
				{
					this->typeEnum = VariableType::BYTE_TYPE;
				}
								else 
				{
					if(strName->equals(ConstStr::getCNST_STR_955(), ctx))
					{
						this->typeEnum = VariableType::SHORT_TYPE;
					}
										else 
					{
						if(strName->equals(ConstStr::getCNST_STR_956(), ctx))
						{
							this->typeEnum = VariableType::CHAR_TYPE;
						}
												else 
						{
							if(strName->equals(ConstStr::getCNST_STR_958(), ctx))
							{
								this->typeEnum = VariableType::LONG_TYPE;
							}
														else 
							{
								if(strName->equals(ConstStr::getCNST_STR_960(), ctx))
								{
									this->typeEnum = VariableType::FLOAT_TYPE;
								}
																else 
								{
									if(strName->equals(ConstStr::getCNST_STR_959(), ctx))
									{
										this->typeEnum = VariableType::DOUBLE_TYPE;
									}
																		else 
									{
										if(strName->equals(ConstStr::getCNST_STR_963(), ctx))
										{
											this->typeEnum = VariableType::TIMESTAMP;
										}
																				else 
										{
											if(strName->equals(ConstStr::getCNST_STR_962(), ctx))
											{
												this->typeEnum = VariableType::TIME;
											}
																						else 
											{
												if(strName->equals(ConstStr::getCNST_STR_964(), ctx))
												{
													this->typeEnum = VariableType::BIGDECIMAL;
												}
																								else 
												{
													this->typeEnum = VariableType::OBJECT_TYPE;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void TypedVariableDeclare::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
IStatement::StatementType TypedVariableDeclare::getType(ThreadContext* ctx) throw() 
{
	return StatementType::TYPED_VARIABLE_DECLARE;
}
void TypedVariableDeclare::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(this->name->getSegments(ctx)->size(ctx) != 1)
	{
		validator->addError(ConstStr::getCNST_STR_1045(), this->name, ctx);
	}
}
bool TypedVariableDeclare::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->typeName != nullptr && !this->typeName->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->initExp != nullptr && !this->initExp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool TypedVariableDeclare::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* mainFrame = context->getCurrentStack(ctx);
	SubVariableDeclareHolder* subFrame = mainFrame->getCurrentSubStack(ctx);
	subFrame->addTypedVariableDeclare(this, ctx);
	AlinousClass* clazz = nullptr;
	switch(this->typeEnum) {
	case TypedVariableDeclare::VariableType::BOOL_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::INT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::INT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::BYTE_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BYTE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::SHORT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::SHORT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::CHAR_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::CHAR_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::LONG_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::LONG_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::FLOAT_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::FLOAT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::DOUBLE_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::DOUBLE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::STRING_TYPE:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::STRING_TYPE, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::TIMESTAMP:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::TIMESTAMP, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::TIME:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::TIME, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::BIGDECIMAL:
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::BIGDECIMAL, AlinousType::TYPE_STANDARD_OBJ, ctx)), AlinousType);
		break ;
	case TypedVariableDeclare::VariableType::OBJECT_TYPE:
	default:
		clazz = context->findClassDeclare(this->typeName, ctx);
		if(clazz == nullptr)
		{
			context->getSourceValidator(ctx)->addError(this->typeName->toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_965(), ctx), this, ctx);
		}
				else 
		{
			__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(clazz, ctx)), AlinousType);
			this->analysedType->setDimension(this->dimension, ctx);
		}
		break ;
	}
	if(this->initExp != nullptr)
	{
		this->initExp->analyse(context, false, ctx);
	}
	return true;
}
AlinousName* TypedVariableDeclare::getTypeName(ThreadContext* ctx) throw() 
{
	return typeName;
}
AlinousName* TypedVariableDeclare::getName(ThreadContext* ctx) throw() 
{
	return name;
}
TypedVariableDeclare::VariableType TypedVariableDeclare::getTypeEnum(ThreadContext* ctx) throw() 
{
	return typeEnum;
}
IExpression* TypedVariableDeclare::getInitExp(ThreadContext* ctx) throw() 
{
	return initExp;
}
void TypedVariableDeclare::setInitExp(IExpression* initExp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->initExp), initExp, IExpression);
}
AlinousType* TypedVariableDeclare::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
int TypedVariableDeclare::getDimension(ThreadContext* ctx) throw() 
{
	return dimension;
}
void TypedVariableDeclare::setDimension(int dimension, ThreadContext* ctx) throw() 
{
	this->dimension = dimension;
}
}}}

