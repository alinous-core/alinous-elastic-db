#include "includes.h"


namespace alinous {namespace compile {namespace declare {namespace function {



constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::__DEFAULT_NULL;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::DOM_VARIABLE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::DOM_ARRAY_VARIABLE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::BOOL_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::BYTE_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::SHORT_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::CHAR_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::INT_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::LONG_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::FLOAT_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::DOUBLE_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::STRING_TYPE;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::TIMESTAMP;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::TIME;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::BIGDECIMAL;
constexpr EnumBase __FunctionArgumentDefine__FunctionArgumentType::OBJECT_TYPE;


bool FunctionArgumentDefine::__init_done = __init_static_variables();
bool FunctionArgumentDefine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionArgumentDefine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionArgumentDefine::~FunctionArgumentDefine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionArgumentDefine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionArgumentDefine", L"~FunctionArgumentDefine");
	__e_obj1.add(this->type, this);
	type = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->domDescriptor, this);
	domDescriptor = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
bool FunctionArgumentDefine::sameMethodSig(FunctionArgumentDefine* other, ThreadContext* ctx) throw() 
{
	if(this->domDescriptor != nullptr && other->domDescriptor != nullptr)
	{
		return true;
	}
	if(this->type != nullptr && other->type != nullptr)
	{
		return this->type->equals(other, ctx);
	}
	return false;
}
void FunctionArgumentDefine::putArgument(ScriptMachine* machine, MainStackFrame* frame, IAlinousVariable* variable, bool debug, ThreadContext* ctx)
{
	FunctionArgumentDefine::FunctionArgumentType variableType = getVariableType(ctx);
	switch(variableType) {
	case FunctionArgumentDefine::FunctionArgumentType::DOM_VARIABLE:
		frame->putVariable(machine, this->domDescriptor, variable->toDomVariable(ctx), debug, ctx);
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::DOM_ARRAY_VARIABLE:
		if(variable->getVariableClass(ctx) != IAlinousVariable::CLASS_DOM || (static_cast<IDomVariable*>(variable))->getDomType(ctx) != IDomVariable::TYPE_ARRAY)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_969(), ctx));
		}
		frame->putVariable(machine, this->domDescriptor, static_cast<IDomVariable*>(variable), debug, ctx);
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BOOL_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toBoolVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BYTE_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toByteVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::SHORT_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toShortVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::CHAR_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toCharVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::INT_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toIntVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::LONG_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toLongVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::FLOAT_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toFloatVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::DOUBLE_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toDoubleVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::STRING_TYPE:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toStringVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::TIMESTAMP:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toTimestampVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::TIME:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toTimeVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::BIGDECIMAL:
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), variable->toBigDecimalVariable(ctx), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break ;
	case FunctionArgumentDefine::FunctionArgumentType::OBJECT_TYPE:
	default:
		if(!((dynamic_cast<IAlinousClassVariable*>(variable) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		{
			try
			{
				frame->putTypedVariable(this->name->toString(ctx), static_cast<ITypedVariable*>(variable), ctx);
			}
			catch(AlinousException* e)
			{
				e->setSrcElement(this, ctx);
			}
		}
		break;
	}
}
FunctionArgumentDefine::FunctionArgumentType FunctionArgumentDefine::getVariableType(ThreadContext* ctx) throw() 
{
	if(this->domDescriptor != nullptr)
	{
		if(this->domDescriptor->getPrefix(ctx)->equals(ConstStr::getCNST_STR_971(), ctx))
		{
			return FunctionArgumentType::DOM_VARIABLE;
		}
				else 
		{
			return FunctionArgumentType::DOM_ARRAY_VARIABLE;
		}
	}
	String* strName = this->type->toString(ctx);
	if(strName->equals(ConstStr::getCNST_STR_953(), ctx))
	{
		return FunctionArgumentType::BOOL_TYPE;
	}
		else 
	{
		if(strName->equals(ConstStr::getCNST_STR_957(), ctx))
		{
			return FunctionArgumentType::INT_TYPE;
		}
				else 
		{
			if(strName->equals(ConstStr::getCNST_STR_961(), ctx))
			{
				return FunctionArgumentType::STRING_TYPE;
			}
						else 
			{
				if(strName->equals(ConstStr::getCNST_STR_961(), ctx))
				{
					return FunctionArgumentType::STRING_TYPE;
				}
								else 
				{
					if(strName->equals(ConstStr::getCNST_STR_954(), ctx))
					{
						return FunctionArgumentType::BYTE_TYPE;
					}
										else 
					{
						if(strName->equals(ConstStr::getCNST_STR_955(), ctx))
						{
							return FunctionArgumentType::SHORT_TYPE;
						}
												else 
						{
							if(strName->equals(ConstStr::getCNST_STR_956(), ctx))
							{
								return FunctionArgumentType::CHAR_TYPE;
							}
														else 
							{
								if(strName->equals(ConstStr::getCNST_STR_958(), ctx))
								{
									return FunctionArgumentType::LONG_TYPE;
								}
																else 
								{
									if(strName->equals(ConstStr::getCNST_STR_960(), ctx))
									{
										return FunctionArgumentType::FLOAT_TYPE;
									}
																		else 
									{
										if(strName->equals(ConstStr::getCNST_STR_959(), ctx))
										{
											return FunctionArgumentType::DOUBLE_TYPE;
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
	return FunctionArgumentType::OBJECT_TYPE;
}
bool FunctionArgumentDefine::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->domDescriptor != nullptr && !this->domDescriptor->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->type != nullptr && !this->type->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool FunctionArgumentDefine::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	VariableDeclareHolder* mainFrame = context->getCurrentStack(ctx);
	SubVariableDeclareHolder* subFrame = mainFrame->getCurrentSubStack(ctx);
	subFrame->addFunctionArgumentDefine(this, ctx);
	if(this->type == nullptr)
	{
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(ctx)), AlinousType);
	}
		else 
	{
		__GC_MV(this, &(this->analysedType), this->type->toAlinousType(context, ctx), AlinousType);
	}
	return true;
}
String* FunctionArgumentDefine::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->type != nullptr)
	{
		buff->append(this->type->toString(ctx), ctx);
	}
		else 
	{
		buff->append(this->domDescriptor->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
AlinousName* FunctionArgumentDefine::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void FunctionArgumentDefine::setType(AlinousName* type, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->type), type, AlinousName);
}
AlinousName* FunctionArgumentDefine::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void FunctionArgumentDefine::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
DomVariableDescriptor* FunctionArgumentDefine::getDomDescriptor(ThreadContext* ctx) throw() 
{
	return domDescriptor;
}
void FunctionArgumentDefine::setDomDescriptor(DomVariableDescriptor* domDescriptor, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domDescriptor), domDescriptor, DomVariableDescriptor);
}
AlinousType* FunctionArgumentDefine::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
int FunctionArgumentDefine::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int FunctionArgumentDefine::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int FunctionArgumentDefine::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int FunctionArgumentDefine::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* FunctionArgumentDefine::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void FunctionArgumentDefine::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
}}}}

