#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {namespace module {





bool DynamicTag::__init_done = __init_static_variables();
bool DynamicTag::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DynamicTag", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DynamicTag::DynamicTag(XMLTagBase* tagbase, ThreadContext* ctx) : IObject(ctx), AbstractSerializedHtmlPart(ctx), nameParts(nullptr), attrstack(GCUtils<Stack<AbstractSerializedHtmlPart> >::ins(this, (new(ctx) Stack<AbstractSerializedHtmlPart>(ctx)), ctx, __FILEW__, __LINE__, L"")), innerStack(GCUtils<Stack<AbstractSerializedHtmlPart> >::ins(this, (new(ctx) Stack<AbstractSerializedHtmlPart>(ctx)), ctx, __FILEW__, __LINE__, L"")), dynValue(nullptr), alnsIf(nullptr), alnsInner(nullptr), alnsTagId(nullptr), alnsTarget(nullptr), alnsIterate(nullptr), alnsVariable(nullptr), alnsIgnoreself(nullptr), alnsMsgTarget(nullptr), alnsForm(nullptr), alnsValidate(nullptr), alnsValidateif(nullptr), alnsRegExp(nullptr), alnsParam(nullptr), alnsType(nullptr)
{
	this->type = AbstractSerializedHtmlPart::TYPE_DYNAMIC_TAG;
	GCUtils<ArrayList<IHtmlStringPart> >::mv(this, &(this->nameParts), tagbase->parts, ctx);
	SerializeContext* context = (new(ctx) SerializeContext(ctx));
	ArrayList<XHtmlAttribute>* attributes = tagbase->attributes;
	int maxLoop = attributes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		XHtmlAttribute* attr = attributes->get(i, ctx);
		if(attr->isAlinousAttr)
		{
			setAlinoutAttributes(attr, ctx);
		}
				else 
		{
			attr->serialize(context, ctx);
		}
	}
	GCUtils<Stack<AbstractSerializedHtmlPart> >::mv(this, &(this->attrstack), context->stack, ctx);
	context = (new(ctx) SerializeContext(ctx));
	ArrayList<AbstractXHtmlElement>* innerElements = tagbase->innerElements;
	maxLoop = innerElements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* elm = innerElements->get(i, ctx);
		elm->serialize(context, ctx);
	}
	GCUtils<Stack<AbstractSerializedHtmlPart> >::mv(this, &(this->innerStack), context->stack, ctx);
}
void DynamicTag::__construct_impl(XMLTagBase* tagbase, ThreadContext* ctx)
{
	this->type = AbstractSerializedHtmlPart::TYPE_DYNAMIC_TAG;
	GCUtils<ArrayList<IHtmlStringPart> >::mv(this, &(this->nameParts), tagbase->parts, ctx);
	SerializeContext* context = (new(ctx) SerializeContext(ctx));
	ArrayList<XHtmlAttribute>* attributes = tagbase->attributes;
	int maxLoop = attributes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		XHtmlAttribute* attr = attributes->get(i, ctx);
		if(attr->isAlinousAttr)
		{
			setAlinoutAttributes(attr, ctx);
		}
				else 
		{
			attr->serialize(context, ctx);
		}
	}
	GCUtils<Stack<AbstractSerializedHtmlPart> >::mv(this, &(this->attrstack), context->stack, ctx);
	context = (new(ctx) SerializeContext(ctx));
	ArrayList<AbstractXHtmlElement>* innerElements = tagbase->innerElements;
	maxLoop = innerElements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* elm = innerElements->get(i, ctx);
		elm->serialize(context, ctx);
	}
	GCUtils<Stack<AbstractSerializedHtmlPart> >::mv(this, &(this->innerStack), context->stack, ctx);
}
 DynamicTag::~DynamicTag() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DynamicTag::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DynamicTag", L"~DynamicTag");
	__e_obj1.add(this->nameParts, this);
	nameParts = nullptr;
	__e_obj1.add(this->attrstack, this);
	attrstack = nullptr;
	__e_obj1.add(this->innerStack, this);
	innerStack = nullptr;
	__e_obj1.add(this->dynValue, this);
	dynValue = nullptr;
	__e_obj1.add(this->alnsIf, this);
	alnsIf = nullptr;
	__e_obj1.add(this->alnsInner, this);
	alnsInner = nullptr;
	__e_obj1.add(this->alnsTagId, this);
	alnsTagId = nullptr;
	__e_obj1.add(this->alnsTarget, this);
	alnsTarget = nullptr;
	__e_obj1.add(this->alnsIterate, this);
	alnsIterate = nullptr;
	__e_obj1.add(this->alnsVariable, this);
	alnsVariable = nullptr;
	__e_obj1.add(this->alnsIgnoreself, this);
	alnsIgnoreself = nullptr;
	__e_obj1.add(this->alnsMsgTarget, this);
	alnsMsgTarget = nullptr;
	__e_obj1.add(this->alnsForm, this);
	alnsForm = nullptr;
	__e_obj1.add(this->alnsValidate, this);
	alnsValidate = nullptr;
	__e_obj1.add(this->alnsValidateif, this);
	alnsValidateif = nullptr;
	__e_obj1.add(this->alnsRegExp, this);
	alnsRegExp = nullptr;
	__e_obj1.add(this->alnsParam, this);
	alnsParam = nullptr;
	__e_obj1.add(this->alnsType, this);
	alnsType = nullptr;
	if(!prepare){
		return;
	}
	AbstractSerializedHtmlPart::__releaseRegerences(true, ctx);
}
void DynamicTag::validate(ThreadContext* ctx) throw() 
{
	if(this->alnsIf != nullptr)
	{
	}
	if(this->alnsInner != nullptr || this->alnsTagId != nullptr)
	{
	}
	if(this->alnsTarget != nullptr)
	{
	}
	if(this->alnsIterate != nullptr || this->alnsVariable != nullptr || this->alnsIgnoreself != nullptr)
	{
	}
	if(this->alnsValidate != nullptr || this->alnsMsgTarget != nullptr || this->alnsForm != nullptr || this->alnsValidateif != nullptr || this->alnsValidateif != nullptr || this->alnsRegExp != nullptr || this->alnsParam != nullptr)
	{
	}
	if(this->alnsType != nullptr)
	{
	}
}
void DynamicTag::prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	Stack<AbstractSerializedHtmlPart>* attrstack = this->attrstack;
	int maxLoop = attrstack->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractSerializedHtmlPart* part = attrstack->get(i, ctx);
		part->prepare(context, ctx);
	}
	maxLoop = innerStack->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractSerializedHtmlPart* part = innerStack->get(i, ctx);
		part->prepare(context, ctx);
	}
	if(this->dynValue != nullptr)
	{
		this->dynValue->prepare(context, ctx);
	}
}
void DynamicTag::execute(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx)
{
	if(this->alnsIf != nullptr)
	{
		IAlinousVariable* ifResult = this->dynValue->execute(machine, debug, ctx);
		if(ifResult == nullptr || !ifResult->isTrue(ctx))
		{
			return;
		}
	}
	writeTag(machine, writer, debug, ctx);
	writeInnerElements(machine, writer, debug, ctx);
	writeEndTag(machine, writer, debug, ctx);
}
String* DynamicTag::toString(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1835();
}
void DynamicTag::setAlinoutAttributes(XHtmlAttribute* attr, ThreadContext* ctx)
{
	String* attrName = attr->getName(ctx);
	if(attrName->equals(AlinousAttrs::ALINOUS_IF, ctx))
	{
		__GC_MV(this, &(this->alnsIf), attr, XHtmlAttribute);
		AbstractXHtmlAttributeValue* dynAttrBase = this->alnsIf->getValue(ctx);
		if(dynAttrBase != nullptr)
		{
			__GC_MV(this, &(this->dynValue), (new(ctx) DynamicExecutableAttributeValue(dynAttrBase->getValue(ctx), ctx)), DynamicExecutableAttributeValue);
		}
	}
		else 
	{
		if(attrName->equals(AlinousAttrs::ALINOUS_INNER, ctx))
		{
			__GC_MV(this, &(this->alnsInner), attr, XHtmlAttribute);
		}
				else 
		{
			if(attrName->equals(AlinousAttrs::ALINOUS_TAGID, ctx))
			{
				__GC_MV(this, &(this->alnsTagId), attr, XHtmlAttribute);
			}
						else 
			{
				if(attrName->equals(AlinousAttrs::ALINOUS_TARGET, ctx))
				{
					__GC_MV(this, &(this->alnsTarget), attr, XHtmlAttribute);
				}
								else 
				{
					if(attrName->equals(AlinousAttrs::ALINOUS_ITERATE, ctx))
					{
						__GC_MV(this, &(this->alnsIterate), attr, XHtmlAttribute);
					}
										else 
					{
						if(attrName->equals(AlinousAttrs::ALINOUS_VARIABLE, ctx))
						{
							__GC_MV(this, &(this->alnsVariable), attr, XHtmlAttribute);
						}
												else 
						{
							if(attrName->equals(AlinousAttrs::ALINOUS_MSG, ctx) || attr->equals(AlinousAttrs::ALINOUS_MSG_TARGET, ctx))
							{
								__GC_MV(this, &(this->alnsMsgTarget), attr, XHtmlAttribute);
							}
														else 
							{
								if(attrName->equals(AlinousAttrs::ALINOUS_FORM, ctx))
								{
									__GC_MV(this, &(this->alnsForm), attr, XHtmlAttribute);
								}
																else 
								{
									if(attrName->equals(AlinousAttrs::ALINOUS_VALIDATE_IF, ctx))
									{
										__GC_MV(this, &(this->alnsValidateif), attr, XHtmlAttribute);
									}
																		else 
									{
										if(attrName->equals(AlinousAttrs::ALINOUS_REGEX, ctx))
										{
											__GC_MV(this, &(this->alnsRegExp), attr, XHtmlAttribute);
										}
																				else 
										{
											if(attrName->equals(AlinousAttrs::ALINOUS_PARAM, ctx))
											{
												__GC_MV(this, &(this->alnsParam), attr, XHtmlAttribute);
											}
																						else 
											{
												if(attrName->equals(AlinousAttrs::ALINOUS_TYPE, ctx))
												{
													__GC_MV(this, &(this->alnsType), attr, XHtmlAttribute);
												}
																								else 
												{
													if(attrName->equals(AlinousAttrs::ALINOUS_IGNORE_SELF_ITERATE, ctx))
													{
														__GC_MV(this, &(this->alnsIgnoreself), attr, XHtmlAttribute);
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
}
void DynamicTag::writeInnerElements(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx)
{
	Stack<AbstractSerializedHtmlPart>* innerStack = this->innerStack;
	int maxLoop = innerStack->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractSerializedHtmlPart* part = innerStack->get(i, ctx);
		part->execute(machine, writer, debug, ctx);
	}
}
void DynamicTag::writeTag(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* ignoreResult = nullptr;
	if(this->alnsIgnoreself != nullptr)
	{
		ignoreResult = this->dynValue->execute(machine, debug, ctx);
		if(!ignoreResult->isTrue(ctx))
		{
			return;
		}
	}
	writer->write(ConstStr::getCNST_STR_1010(), ctx);
	writeName(machine, writer, debug, ctx);
	if(this->innerStack->isEmpty(ctx))
	{
		writer->write(ConstStr::getCNST_STR_1834(), ctx);
	}
		else 
	{
		writer->write(ConstStr::getCNST_STR_82(), ctx);
	}
}
void DynamicTag::writeEndTag(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* ignoreResult = nullptr;
	if(this->alnsIgnoreself != nullptr)
	{
		ignoreResult = this->dynValue->execute(machine, debug, ctx);
		if(!ignoreResult->isTrue(ctx))
		{
			return;
		}
	}
	if(!this->innerStack->isEmpty(ctx))
	{
		writer->write(ConstStr::getCNST_STR_1770(), ctx);
		writeName(machine, writer, debug, ctx);
		writer->write(ConstStr::getCNST_STR_82(), ctx);
	}
}
void DynamicTag::writeName(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->nameParts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IHtmlStringPart* part = this->nameParts->get(i, ctx);
		writer->write(part->execute(machine, debug, ctx), ctx);
	}
}
}}}}

