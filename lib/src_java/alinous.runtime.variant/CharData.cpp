#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* CharData::TAG_NAME = ConstStr::getCNST_STR_1214();
bool CharData::__init_done = __init_static_variables();
bool CharData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharData::CharData(wchar_t data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
	this->data = data;
}
void CharData::__construct_impl(wchar_t data, ThreadContext* ctx) throw() 
{
	this->data = data;
}
 CharData::~CharData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CharData", L"~CharData");
	if(!prepare){
		return;
	}
}
void CharData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Character::toString(this->data, ctx), node, ctx));
	node->addAttribute(attr, ctx);
}
int CharData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_CHAR;
}
String* CharData::getString(ThreadContext* ctx) throw() 
{
	return Character::toString(this->data, ctx);
}
long long CharData::getLong(ThreadContext* ctx) throw() 
{
	return this->data;
}
int CharData::getInt(ThreadContext* ctx) throw() 
{
	return this->data;
}
short CharData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data);
}
wchar_t CharData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data);
}
char CharData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data);
}
float CharData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data;
}
double CharData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data;
}
bool CharData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data > (wchar_t)0;
}
BigDecimal* CharData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data, ctx));
}
TimeOnlyTimestamp* CharData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(this->data, ctx));
}
Timestamp* CharData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(this->data, ctx));
}
int CharData::bufferSize(ThreadContext* ctx) throw() 
{
	return 2;
}
void CharData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putChar(this->data, ctx);
}
bool CharData::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
int CharData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data - variant->getChar(ctx);
}
void CharData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->data = buff->getChar(ctx);
}
void CharData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(IVariantData::TYPE_CHAR, ctx);
	buff->putChar(this->data, ctx);
}
CharData* CharData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(TAG_NAME, ctx))
	{
		return nullptr;
	}
	IVariableValue* attr = node->getAttributeValue(IVariantData::ATTR_VALUE, ctx);
	if(attr == nullptr)
	{
		return nullptr;
	}
	CharData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			int val = Integer::parseInt(str, ctx);
			data = (new(ctx) CharData(((wchar_t)val), ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int CharData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

