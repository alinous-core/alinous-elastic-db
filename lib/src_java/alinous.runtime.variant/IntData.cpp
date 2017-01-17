#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





String* IntData::TAG_NAME = ConstStr::getCNST_STR_1230();
bool IntData::__init_done = __init_static_variables();
bool IntData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IntData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IntData::IntData(int data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
	this->data = data;
}
void IntData::__construct_impl(int data, ThreadContext* ctx) throw() 
{
	this->data = data;
}
 IntData::~IntData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IntData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IntData", L"~IntData");
	if(!prepare){
		return;
	}
}
void IntData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Integer::toString(this->data, ctx), node, ctx));
	node->addAttribute(attr, ctx);
}
int IntData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_INT;
}
String* IntData::getString(ThreadContext* ctx) throw() 
{
	return Integer::toString(this->data, ctx);
}
long long IntData::getLong(ThreadContext* ctx) throw() 
{
	return this->data;
}
int IntData::getInt(ThreadContext* ctx) throw() 
{
	return this->data;
}
short IntData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data);
}
wchar_t IntData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data);
}
char IntData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data);
}
float IntData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data;
}
double IntData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data;
}
bool IntData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data > 0;
}
BigDecimal* IntData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data, ctx));
}
TimeOnlyTimestamp* IntData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(this->data, ctx));
}
Timestamp* IntData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(this->data, ctx));
}
int IntData::bufferSize(ThreadContext* ctx) throw() 
{
	return 4;
}
void IntData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(this->data, ctx);
}
bool IntData::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
int IntData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	return this->data - variant->getInt(ctx);
}
void IntData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->data = buff->getInt(ctx);
}
void IntData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(IVariantData::TYPE_INT, ctx);
	buff->putInt(this->data, ctx);
}
IntData* IntData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	IntData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			int val = Integer::parseInt(str, ctx);
			data = (new(ctx) IntData(val, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
int IntData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

