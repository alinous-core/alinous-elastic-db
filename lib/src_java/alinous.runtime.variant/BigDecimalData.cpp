#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* BigDecimalData::TAG_NAME = ConstStr::getCNST_STR_1241();
bool BigDecimalData::__init_done = __init_static_variables();
bool BigDecimalData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BigDecimalData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BigDecimalData::BigDecimalData(BigDecimal* data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(nullptr)
{
	__GC_MV(this, &(this->data), data, BigDecimal);
}
void BigDecimalData::__construct_impl(BigDecimal* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->data), data, BigDecimal);
}
 BigDecimalData::~BigDecimalData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BigDecimalData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BigDecimalData", L"~BigDecimalData");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
}
void BigDecimalData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	if(data != nullptr)
	{
		Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, this->data->toString(ctx), node, ctx));
		node->addAttribute(attr, ctx);
	}
}
int BigDecimalData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_BIG_DECIMAL;
}
String* BigDecimalData::getString(ThreadContext* ctx) throw() 
{
	return this->data->toString(ctx);
}
long long BigDecimalData::getLong(ThreadContext* ctx) throw() 
{
	return this->data->longValue(ctx);
}
int BigDecimalData::getInt(ThreadContext* ctx) throw() 
{
	return ((int)this->data->intValue(ctx));
}
short BigDecimalData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data->longValue(ctx));
}
wchar_t BigDecimalData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data->longValue(ctx));
}
char BigDecimalData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data->longValue(ctx));
}
float BigDecimalData::getFloat(ThreadContext* ctx) throw() 
{
	return ((float)this->data->longValue(ctx));
}
double BigDecimalData::getDouble(ThreadContext* ctx) throw() 
{
	return ((double)this->data->longValue(ctx));
}
bool BigDecimalData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data->longValue(ctx) > (long long)0;
}
BigDecimal* BigDecimalData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return this->data;
}
TimeOnlyTimestamp* BigDecimalData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(this->data->longValue(ctx), ctx));
}
Timestamp* BigDecimalData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(this->data->longValue(ctx), ctx));
}
int BigDecimalData::bufferSize(ThreadContext* ctx) throw() 
{
	return 8;
}
void BigDecimalData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putLong(this->data->longValue(ctx), ctx);
}
bool BigDecimalData::isNull(ThreadContext* ctx) throw() 
{
	return this->data == nullptr;
}
int BigDecimalData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data->compareTo(variant->getBigDecimal(ctx), ctx);
}
void BigDecimalData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	char nullb = buff->getByte(ctx);
	if(nullb == (char)0)
	{
		__GC_MV(this, &(this->data), nullptr, BigDecimal);
		return;
	}
	String* value = buff->getString(ctx);
	__GC_MV(this, &(this->data), (new(ctx) BigDecimal(value, ctx)), BigDecimal);
}
void BigDecimalData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(IVariantData::TYPE_BIG_DECIMAL, ctx);
	if(isNull(ctx))
	{
		buff->putByte(((char)0), ctx);
		return;
	}
		else 
	{
		buff->putByte(((char)1), ctx);
	}
	String* val = this->data->toPlainString(ctx);
	buff->putString(val, ctx);
}
BigDecimalData* BigDecimalData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	BigDecimalData* data = nullptr;
	{
		try
		{
			data = (new(ctx) BigDecimalData((new(ctx) BigDecimal(attr->toString(ctx), ctx)), ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int BigDecimalData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

