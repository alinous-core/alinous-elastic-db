#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/Attribute.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/StringData.h"
#include "alinous.runtime.variant/LongData.h"
#include "alinous.runtime.variant/IntData.h"
#include "alinous.runtime.variant/ShortData.h"
#include "alinous.runtime.variant/ByteData.h"
#include "alinous.runtime.variant/FloatData.h"
#include "alinous.runtime.variant/DoubleData.h"
#include "alinous.runtime.variant/BigDecimalData.h"
#include "alinous.runtime.variant/TimeData.h"
#include "alinous.runtime.variant/TimestampData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.variant/CharData.h"
#include "alinous.runtime.variant/VariantDataFactory.h"

namespace alinous {namespace runtime {namespace variant {





String* FloatData::TAG_NAME = ConstStr::getCNST_STR_1223();
bool FloatData::__init_done = __init_static_variables();
bool FloatData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FloatData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FloatData::FloatData(float data, ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
	this->data = data;
}
void FloatData::__construct_impl(float data, ThreadContext* ctx) throw() 
{
	this->data = data;
}
 FloatData::FloatData(ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(0)
{
}
void FloatData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FloatData::~FloatData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FloatData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FloatData", L"~FloatData");
	if(!prepare){
		return;
	}
}
void FloatData::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_NAME, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(IVariantData::ATTR_VALUE, Float::toString(this->data, ctx), node, ctx));
	node->addAttribute(attr, ctx);
}
int FloatData::getType(ThreadContext* ctx) throw() 
{
	return IVariantData::TYPE_FLOAT;
}
String* FloatData::getString(ThreadContext* ctx) throw() 
{
	return Float::toString(this->data, ctx);
}
long long FloatData::getLong(ThreadContext* ctx) throw() 
{
	return ((long long)this->data);
}
int FloatData::getInt(ThreadContext* ctx) throw() 
{
	return ((int)this->data);
}
short FloatData::getShort(ThreadContext* ctx) throw() 
{
	return ((short)this->data);
}
wchar_t FloatData::getChar(ThreadContext* ctx) throw() 
{
	return ((wchar_t)this->data);
}
char FloatData::getByte(ThreadContext* ctx) throw() 
{
	return ((char)this->data);
}
float FloatData::getFloat(ThreadContext* ctx) throw() 
{
	return this->data;
}
double FloatData::getDouble(ThreadContext* ctx) throw() 
{
	return this->data;
}
bool FloatData::getBoolean(ThreadContext* ctx) throw() 
{
	return this->data > (float)0;
}
BigDecimal* FloatData::getBigDecimal(ThreadContext* ctx) throw() 
{
	return (new(ctx) BigDecimal(this->data, ctx));
}
TimeOnlyTimestamp* FloatData::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) TimeOnlyTimestamp(((long long)this->data), ctx));
}
Timestamp* FloatData::getTimestamp(ThreadContext* ctx) throw() 
{
	return (new(ctx) Timestamp(((long long)this->data), ctx));
}
int FloatData::bufferSize(ThreadContext* ctx) throw() 
{
	return 4;
}
void FloatData::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putFloat(this->data, ctx);
}
bool FloatData::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
int FloatData::compareTo(VariantValue* variant, ThreadContext* ctx) throw() 
{
	float sub = this->data - variant->getFloat(ctx);
	return sub >= (float)0 ? ((int)sub) : -1;
}
void FloatData::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->data = buff->getFloat(ctx);
}
void FloatData::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(IVariantData::TYPE_FLOAT, ctx);
	buff->putFloat(this->data, ctx);
}
FloatData* FloatData::importFromXml(DomNode* node, ThreadContext* ctx) throw() 
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
	FloatData* data = nullptr;
	{
		try
		{
			String* str = attr->toString(ctx);
			float val = Float::parseFloat(str, ctx);
			data = (new(ctx) FloatData(val, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return data;
}
void FloatData::__cleanUp(ThreadContext* ctx){
}
int FloatData::ValueCompare::operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variant, ctx);
}
}}}

