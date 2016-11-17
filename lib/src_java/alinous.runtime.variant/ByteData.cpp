#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* ByteData::TAG_NAME = ConstStr::getCNST_STR_1158();
bool ByteData::__init_done = __init_static_variables();
bool ByteData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ByteData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ByteData::ByteData(char data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
	this->data = data;
}
void ByteData::__construct_impl(char data, ThreadContext* ctx) throw() 
{
	this->data = data;
}
 ByteData::~ByteData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ByteData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ByteData", L"~ByteData");
	if(!prepare){
		return;
	}
}
void ByteData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Byte::toString(this->data, ctx), node, ctx));
	node->addAttribute(attr, ctx);
}
int ByteData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_BYTE;
}
String* ByteData::getString(ThreadContext* ctx) throw() 
{
	return Byte::toString(this->data, ctx);
}
long long ByteData::getLong(ThreadContext* ctx) throw() 
{
	return this->data;
}
int ByteData::getInt(ThreadContext* ctx) throw() 
{
	return this->data;
}
short ByteData::getShort(ThreadContext* ctx) throw() 
{
	return this->data;
}
wchar_t ByteData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data);
}
char ByteData::getByte(ThreadContext* ctx) throw() 
{
	return this->data;
}
float ByteData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data;
}
double ByteData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data;
}
bool ByteData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data > (char)0;
}
BigDecimal* ByteData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data, ctx));
}
TimeOnlyTimestamp* ByteData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(this->data, ctx));
}
Timestamp* ByteData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(this->data, ctx));
}
int ByteData::bufferSize(ThreadContext* ctx) throw() 
{
	return 1;
}
void ByteData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putByte(this->data, ctx);
}
bool ByteData::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
int ByteData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data - variant->getByte(ctx);
}
ByteData* ByteData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	ByteData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			char val = Byte::parseByte(str, ctx);
			data = (new(ctx) ByteData(val, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int ByteData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

