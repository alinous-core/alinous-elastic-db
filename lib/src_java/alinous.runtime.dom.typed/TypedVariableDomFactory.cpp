#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





bool TypedVariableDomFactory::__init_done = __init_static_variables();
bool TypedVariableDomFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TypedVariableDomFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TypedVariableDomFactory::~TypedVariableDomFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TypedVariableDomFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
AbstractTypedVariable* TypedVariableDomFactory::importFromDomNode(DomNode* node, ThreadContext* ctx) throw() 
{
	String* name = node->getName(ctx);
	if(name->equals(BoolVariable::VAL_TYPE, ctx))
	{
		return BoolVariable::fromDebugXml(node, ctx);
	}
		else 
	{
		if(name->equals(ByteVariable::VAL_TYPE, ctx))
		{
			return ByteVariable::fromDebugXml(node, ctx);
		}
				else 
		{
			if(name->equals(ShortVariable::VAL_TYPE, ctx))
			{
				return ShortVariable::fromDebugXml(node, ctx);
			}
						else 
			{
				if(name->equals(CharVariable::VAL_TYPE, ctx))
				{
					return CharVariable::fromDebugXml(node, ctx);
				}
								else 
				{
					if(name->equals(IntegerVariable::VAL_TYPE, ctx))
					{
						return IntegerVariable::fromDebugXml(node, ctx);
					}
										else 
					{
						if(name->equals(LongVariable::VAL_TYPE, ctx))
						{
							return LongVariable::fromDebugXml(node, ctx);
						}
												else 
						{
							if(name->equals(StringVariable::VAL_TYPE, ctx))
							{
								return StringVariable::fromDebugXml(node, ctx);
							}
														else 
							{
								if(name->equals(TimeVariable::VAL_TYPE, ctx))
								{
									return TimeVariable::fromDebugXml(node, ctx);
								}
																else 
								{
									if(name->equals(TimestampVariable::VAL_TYPE, ctx))
									{
										return TimestampVariable::fromDebugXml(node, ctx);
									}
																		else 
									{
										if(name->equals(BigDecimalVariable::VAL_TYPE, ctx))
										{
											return BigDecimalVariable::fromDebugXml(node, ctx);
										}
																				else 
										{
											if(name->equals(FloatVariable::VAL_TYPE, ctx))
											{
												return FloatVariable::fromDebugXml(node, ctx);
											}
																						else 
											{
												if(name->equals(DoubleVariable::VAL_TYPE, ctx))
												{
													return DoubleVariable::fromDebugXml(node, ctx);
												}
																								else 
												{
													if(name->equals(TypedVariableArray::VAL_TYPE, ctx))
													{
														return TypedVariableArray::fromDebugXml(node, ctx);
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
	return nullptr;
}
}}}}

