#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* StringData::TAG_NAME = ConstStr::getCNST_STR_1228();
bool StringData::__init_done = __init_static_variables();
bool StringData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringData::StringData(String* data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(nullptr)
{
	__GC_MV(this, &(this->data), data, String);
}
void StringData::__construct_impl(String* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->data), data, String);
}
 StringData::~StringData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringData", L"~StringData");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
}
void StringData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	if(data != nullptr)
	{
		Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, this->data, node, ctx));
		node->addAttribute(attr, ctx);
	}
}
int StringData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_STRING;
}
String* StringData::getString(ThreadContext* ctx) throw() 
{
	return this->data;
}
long long StringData::getLong(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return Long::parseLong(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return 0;
		}
	}
}
int StringData::getInt(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return Integer::parseInt(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return 0;
		}
	}
}
short StringData::getShort(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return Short::parseShort(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return 0;
		}
	}
}
wchar_t StringData::getChar(ThreadContext* ctx) throw() 
{
	return this->data->charAt(0, ctx);
}
char StringData::getByte(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return Byte::parseByte(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return 0;
		}
	}
}
float StringData::getFloat(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return Float::parseFloat(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return 0;
		}
	}
}
double StringData::getDouble(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return Double::parseDouble(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return 0;
		}
	}
}
bool StringData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data->equals(ConstStr::getCNST_STR_372(), ctx);
}
BigDecimal* StringData::getBigDecimal(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return (new(ctx) BigDecimal(this->data, ctx));
		}
		catch(Throwable* e)
		{
			return nullptr;
		}
	}
}
TimeOnlyTimestamp* StringData::getTime(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return TimeOnlyTimestamp::valueOf(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return nullptr;
		}
	}
}
Timestamp* StringData::getTimestamp(ThreadContext* ctx) throw() 
{
	{
		try
		{
			return Timestamp::valueOf(this->data, ctx);
		}
		catch(Throwable* e)
		{
			return nullptr;
		}
	}
}
int StringData::bufferSize(ThreadContext* ctx) throw() 
{
	return this->data->length(ctx) * 2 + 4;
}
void StringData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putString(this->data, ctx);
}
bool StringData::isNull(ThreadContext* ctx) throw() 
{
	return this->data == nullptr;
}
int StringData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data->compareTo(variant->getString(ctx), ctx);
}
void StringData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	char nullb = buff->getByte(ctx);
	if(nullb == (char)0)
	{
		__GC_MV(this, &(this->data), nullptr, String);
		return;
	}
	__GC_MV(this, &(this->data), buff->getString(ctx), String);
}
void StringData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(IVariantData::TYPE_STRING, ctx);
	if(isNull(ctx))
	{
		buff->putByte(((char)0), ctx);
		return;
	}
		else 
	{
		buff->putByte(((char)1), ctx);
	}
	buff->putString(this->data, ctx);
}
StringData* StringData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	return (new(ctx) StringData(attr->toString(ctx), ctx));
}
int StringData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

