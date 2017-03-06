#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
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
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"

namespace alinous {namespace compile {namespace declare {





bool AlinousName::__init_done = __init_static_variables();
bool AlinousName::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousName", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousName::AlinousName(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), segments(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AlinousName::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousName::~AlinousName() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousName::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousName", L"~AlinousName");
	__e_obj1.add(this->segments, this);
	segments = nullptr;
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
DomVariableDescriptor* AlinousName::toDomVariableDescriptor(ThreadContext* ctx) throw() 
{
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	ArrayList<String>* segments = this->segments;
	int maxLoop = segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* nm = segments->get(i, ctx);
		IDomSegment* seg = (new(ctx) DomNameSegment(nm, ctx));
		desc->addSegment(seg, ctx);
	}
	return desc;
}
String* AlinousName::getClassName(ThreadContext* ctx) throw() 
{
	int last = this->segments->size(ctx) - 1;
	return this->segments->get(last, ctx);
}
String* AlinousName::getPackageName(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int last = this->segments->size(ctx) - 1;
	for(int i = 0; i != last; ++i)
	{
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_950(), ctx);
		}
		buff->append(this->segments->get(i, ctx), ctx);
	}
	return buff->toString(ctx);
}
bool AlinousName::isVoid(ThreadContext* ctx) throw() 
{
	if(this->segments->size(ctx) != 1)
	{
		return false;
	}
	String* typeStr = toString(ctx);
	return typeStr->equals(ConstStr::getCNST_STR_956(), ctx);
}
bool AlinousName::isPrimitive(ThreadContext* ctx) throw() 
{
	if(this->segments->size(ctx) != 1)
	{
		return false;
	}
	String* typeStr = toString(ctx);
	return typeStr->equals(ConstStr::getCNST_STR_957(), ctx) || typeStr->equals(ConstStr::getCNST_STR_958(), ctx) || typeStr->equals(ConstStr::getCNST_STR_959(), ctx) || typeStr->equals(ConstStr::getCNST_STR_960(), ctx) || typeStr->equals(ConstStr::getCNST_STR_961(), ctx) || typeStr->equals(ConstStr::getCNST_STR_962(), ctx) || typeStr->equals(ConstStr::getCNST_STR_963(), ctx) || typeStr->equals(ConstStr::getCNST_STR_964(), ctx);
}
bool AlinousName::isPrimitiveArray(ThreadContext* ctx) throw() 
{
	if(this->segments->size(ctx) != 1)
	{
		return false;
	}
	String* typeStr = toString(ctx);
	return typeStr->equals(ConstStr::getCNST_STR_957(), ctx) || typeStr->equals(ConstStr::getCNST_STR_958(), ctx) || typeStr->equals(ConstStr::getCNST_STR_959(), ctx) || typeStr->equals(ConstStr::getCNST_STR_960(), ctx) || typeStr->equals(ConstStr::getCNST_STR_961(), ctx) || typeStr->equals(ConstStr::getCNST_STR_962(), ctx) || typeStr->equals(ConstStr::getCNST_STR_963(), ctx) || typeStr->equals(ConstStr::getCNST_STR_964(), ctx);
}
bool AlinousName::isStandardType(ThreadContext* ctx) throw() 
{
	if(this->segments->size(ctx) != 1)
	{
		return false;
	}
	String* typeStr = toString(ctx);
	return typeStr->equals(ConstStr::getCNST_STR_965(), ctx) || typeStr->equals(ConstStr::getCNST_STR_966(), ctx) || typeStr->equals(ConstStr::getCNST_STR_967(), ctx) || typeStr->equals(ConstStr::getCNST_STR_968(), ctx);
}
bool AlinousName::isStandardTypeArray(ThreadContext* ctx) throw() 
{
	if(this->segments->size(ctx) != 1)
	{
		return false;
	}
	String* typeStr = toString(ctx);
	return typeStr->equals(ConstStr::getCNST_STR_965(), ctx) || typeStr->equals(ConstStr::getCNST_STR_966(), ctx) || typeStr->equals(ConstStr::getCNST_STR_967(), ctx) || typeStr->equals(ConstStr::getCNST_STR_968(), ctx);
}
AlinousType* AlinousName::toAlinousType(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	AlinousType* alType = nullptr;
	if(isVoid(ctx))
	{
		alType = (new(ctx) AlinousType(AlinousType::NULL_TYPE, AlinousType::TYPE_VOID, ctx));
	}
		else 
	{
		if(isPrimitive(ctx) || isPrimitiveArray(ctx))
		{
			String* typeStr = toString(ctx);
			if(typeStr->equals(ConstStr::getCNST_STR_957(), ctx))
			{
				alType = (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
			}
						else 
			{
				if(typeStr->equals(ConstStr::getCNST_STR_958(), ctx))
				{
					alType = (new(ctx) AlinousType(AlinousType::BYTE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
				}
								else 
				{
					if(typeStr->equals(ConstStr::getCNST_STR_959(), ctx))
					{
						alType = (new(ctx) AlinousType(AlinousType::SHORT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
					}
										else 
					{
						if(typeStr->equals(ConstStr::getCNST_STR_960(), ctx))
						{
							alType = (new(ctx) AlinousType(AlinousType::CHAR_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
						}
												else 
						{
							if(typeStr->equals(ConstStr::getCNST_STR_961(), ctx))
							{
								alType = (new(ctx) AlinousType(AlinousType::INT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
							}
														else 
							{
								if(typeStr->equals(ConstStr::getCNST_STR_962(), ctx))
								{
									alType = (new(ctx) AlinousType(AlinousType::LONG_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
								}
																else 
								{
									if(typeStr->equals(ConstStr::getCNST_STR_963(), ctx))
									{
										alType = (new(ctx) AlinousType(AlinousType::DOUBLE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
									}
																		else 
									{
										if(typeStr->equals(ConstStr::getCNST_STR_964(), ctx))
										{
											alType = (new(ctx) AlinousType(AlinousType::FLOAT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
										}
									}
								}
							}
						}
					}
				}
			}
		}
				else 
		{
			if(isStandardType(ctx) || isStandardTypeArray(ctx))
			{
				String* typeStr = toString(ctx);
				if(typeStr->equals(ConstStr::getCNST_STR_965(), ctx))
				{
					alType = (new(ctx) AlinousType(AlinousType::STRING_TYPE, AlinousType::TYPE_STANDARD_OBJ, ctx));
				}
								else 
				{
					if(typeStr->equals(ConstStr::getCNST_STR_966(), ctx))
					{
						alType = (new(ctx) AlinousType(AlinousType::TIME, AlinousType::TYPE_STANDARD_OBJ, ctx));
					}
										else 
					{
						if(typeStr->equals(ConstStr::getCNST_STR_967(), ctx))
						{
							alType = (new(ctx) AlinousType(AlinousType::TIMESTAMP, AlinousType::TYPE_STANDARD_OBJ, ctx));
						}
												else 
						{
							if(typeStr->equals(ConstStr::getCNST_STR_968(), ctx))
							{
								alType = (new(ctx) AlinousType(AlinousType::BIGDECIMAL, AlinousType::TYPE_STANDARD_OBJ, ctx));
							}
						}
					}
				}
			}
						else 
			{
				AlinousClass* clazz = context->findClassDeclare(this, ctx);
				if(clazz == nullptr)
				{
					context->addError(toString(ctx)->clone(ctx)->append(ConstStr::getCNST_STR_969(), ctx), this, ctx);
				}
								else 
				{
					alType = (new(ctx) AlinousType(clazz, ctx));
				}
			}
		}
	}
	return alType;
}
void AlinousName::addSegment(String* str, ThreadContext* ctx) throw() 
{
	this->segments->add(str, ctx);
}
ArrayList<String>* AlinousName::getSegments(ThreadContext* ctx) throw() 
{
	return segments;
}
bool AlinousName::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<AlinousName*>(obj) != 0)))
	{
		return false;
	}
	AlinousName* other = dynamic_cast<AlinousName*>(obj);
	return this->toString(ctx)->equals(other->toString(ctx), ctx);
}
bool AlinousName::equals(String* obj, ThreadContext* ctx) throw() 
{
	return this->toString(ctx)->equals(obj, ctx);
}
String* AlinousName::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = this->segments->size(ctx);
	buff->append(segments->get(0, ctx), ctx);
	for(int i = 1; i != maxLoop; ++i)
	{
		buff->append(ConstStr::getCNST_STR_950(), ctx)->append(segments->get(i, ctx), ctx);
	}
	return buff->toString(ctx);
}
bool AlinousName::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool AlinousName::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
int AlinousName::getLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getLine(ctx);
}
int AlinousName::getStartPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getStartPosition(ctx);
}
int AlinousName::getEndLine(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndLine(ctx);
}
int AlinousName::getEndPosition(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getEndPosition(ctx);
}
AbstractSrcElement* AlinousName::getParent(ThreadContext* ctx) throw() 
{
	return IAlinousElement::getParent(ctx);
}
void AlinousName::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IAlinousElement::setParent(parent, ctx);
}
void AlinousName::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = buff->getString(ctx);
		this->segments->add(s, ctx);
	}
}
void AlinousName::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__AlinousName, ctx);
	int maxLoop = this->segments->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* s = this->segments->get(i, ctx);
		buff->putString(s, ctx);
	}
}
int AlinousName::fileSize(ThreadContext* ctx) throw() 
{
	int total = 4;
	int maxLoop = this->segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* str = this->segments->get(i, ctx);
		total += str->length(ctx) * 2 + 4;
	}
	return total;
}
void AlinousName::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	int maxLoop = this->segments->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* str = this->segments->get(i, ctx);
		builder->putString(str, ctx);
	}
}
AlinousName* AlinousName::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	AlinousName* name = (new(ctx) AlinousName(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* str = fetcher->fetchString(ctx);
		name->segments->add(str, ctx);
	}
	return name;
}
void AlinousName::__cleanUp(ThreadContext* ctx){
}
}}}

