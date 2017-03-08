#include "include/global.h"


#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
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
#include "alinous.runtime.dom.typed/TypedVariableDomFactory.h"

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
 TypedVariableDomFactory::TypedVariableDomFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void TypedVariableDomFactory::__construct_impl(ThreadContext* ctx) throw() 
{
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
void TypedVariableDomFactory::__cleanUp(ThreadContext* ctx){
}
}}}}

