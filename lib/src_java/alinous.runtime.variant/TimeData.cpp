#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* TimeData::TAG_NAME = ConstStr::getCNST_STR_1214();
bool TimeData::__init_done = __init_static_variables();
bool TimeData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimeData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimeData::TimeData(TimeOnlyTimestamp* data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(nullptr)
{
	__GC_MV(this, &(this->data), data, TimeOnlyTimestamp);
}
void TimeData::__construct_impl(TimeOnlyTimestamp* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->data), data, TimeOnlyTimestamp);
}
 TimeData::~TimeData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimeData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimeData", L"~TimeData");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
}
void TimeData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	if(data != nullptr)
	{
		Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Long::toString(this->data->getTime(ctx), ctx), node, ctx));
		node->addAttribute(attr, ctx);
	}
}
int TimeData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_TIME;
}
String* TimeData::getString(ThreadContext* ctx) throw() 
{
	return this->data->toString(ctx);
}
long long TimeData::getLong(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx);
}
int TimeData::getInt(ThreadContext* ctx) throw() 
{
	return ((int)this->data->getTime(ctx));
}
short TimeData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data->getTime(ctx));
}
wchar_t TimeData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data->getTime(ctx));
}
char TimeData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data->getTime(ctx));
}
float TimeData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx);
}
double TimeData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx);
}
bool TimeData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data->getTime(ctx) > (long long)0;
}
BigDecimal* TimeData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data->getTime(ctx), ctx));
}
TimeOnlyTimestamp* TimeData::getTime(ThreadContext* ctx) throw() 
{
	return this->data;
}
Timestamp* TimeData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(this->data->getTime(ctx), ctx));
}
int TimeData::bufferSize(ThreadContext* ctx) throw() 
{
	return 8;
}
void TimeData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putLong(this->data->getTime(ctx), ctx);
}
bool TimeData::isNull(ThreadContext* ctx) throw() 
{
	return this->data == nullptr;
}
int TimeData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data->compareTo(variant->getTime(ctx), ctx);
}
void TimeData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	char nullb = buff->getByte(ctx);
	if(nullb == (char)0)
	{
		__GC_MV(this, &(this->data), nullptr, TimeOnlyTimestamp);
		return;
	}
	long long value = buff->getLong(ctx);
	__GC_MV(this, &(this->data), (new(ctx) TimeOnlyTimestamp(value, ctx)), TimeOnlyTimestamp);
}
void TimeData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(IVariantData::TYPE_TIME, ctx);
	if(isNull(ctx))
	{
		buff->putByte(((char)0), ctx);
		return;
	}
		else 
	{
		buff->putByte(((char)1), ctx);
	}
	long long val = this->data->getTime(ctx);
	buff->putLong(val, ctx);
}
TimeData* TimeData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	TimeData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			long long theTime = Long::parseLong(str, ctx);
			data = (new(ctx) TimeData((new(ctx) TimeOnlyTimestamp(theTime, ctx)), ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int TimeData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

