#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* TimestampData::TAG_NAME = ConstStr::getCNST_STR_1176();
bool TimestampData::__init_done = __init_static_variables();
bool TimestampData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimestampData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimestampData::TimestampData(Timestamp* data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(nullptr)
{
	__GC_MV(this, &(this->data), data, Timestamp);
}
void TimestampData::__construct_impl(Timestamp* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->data), data, Timestamp);
}
 TimestampData::~TimestampData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimestampData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimestampData", L"~TimestampData");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
}
void TimestampData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	if(data != nullptr)
	{
		Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Long::toString(this->data->getTime(ctx), ctx), node, ctx));
		node->addAttribute(attr, ctx);
	}
}
int TimestampData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_TIMESTAMP;
}
String* TimestampData::getString(ThreadContext* ctx) throw() 
{
	return this->data->toString(ctx);
}
long long TimestampData::getLong(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx);
}
int TimestampData::getInt(ThreadContext* ctx) throw() 
{
	return ((int)this->data->getTime(ctx));
}
short TimestampData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data->getTime(ctx));
}
wchar_t TimestampData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data->getTime(ctx));
}
char TimestampData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data->getTime(ctx));
}
float TimestampData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx);
}
double TimestampData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx);
}
bool TimestampData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx) > (long long)0;
}
BigDecimal* TimestampData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data->getTime(ctx), ctx));
}
TimeOnlyTimestamp* TimestampData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(this->data->getTime(ctx), ctx));
}
Timestamp* TimestampData::getTimestamp(ThreadContext* ctx) throw() 
{
	return this->data;
}
int TimestampData::bufferSize(ThreadContext* ctx) throw() 
{
	return 8;
}
void TimestampData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putLong(this->data->getTime(ctx), ctx);
}
bool TimestampData::isNull(ThreadContext* ctx) throw() 
{
	return this->data == nullptr;
}
int TimestampData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data->compareTo(variant->getTimestamp(ctx), ctx);
}
TimestampData* TimestampData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	TimestampData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			long long theTime = Long::parseLong(str, ctx);
			data = (new(ctx) TimestampData((new(ctx) Timestamp(theTime, ctx)), ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int TimestampData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

