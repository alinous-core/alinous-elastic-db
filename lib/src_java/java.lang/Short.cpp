#include "include/global.h"


#include "java.lang/Boolean.h"
#include "java.lang/Comparable.h"
#include "java.lang/Number.h"
#include "java.lang/Double.h"
#include "java.lang/Integer.h"
#include "java.lang/Byte.h"
#include "java.lang/Long.h"
#include "java.lang/Float.h"
#include "java.lang/Short.h"
#include "java.lang/BinarySearch.h"

namespace java {namespace lang {





constexpr const short Short::MAX_VALUE;
constexpr const short Short::MIN_VALUE;
constexpr const int Short::SIZE;
bool Short::__init_done = __init_static_variables();
bool Short::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Short", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Short::Short(String* string, ThreadContext* ctx) : IObject(ctx), Number(ctx), Comparable<Short>(ctx), value(0)
{
	__construct_impl(parseShort(string, ctx), ctx);
}
void Short::__construct_impl(String* string, ThreadContext* ctx)
{
	__construct_impl(parseShort(string, ctx), ctx);
}
 Short::Short(short value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<Short>(ctx), value(0)
{
	this->value = value;
}
void Short::__construct_impl(short value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 Short::~Short() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Short::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Short", L"~Short");
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
char Short::byteValue(ThreadContext* ctx) throw() 
{
	return ((char)value);
}
int Short::compareTo(Short* object, ThreadContext* ctx) throw() 
{
	return value > object->value ? 1 : (value < object->value ? -1 : 0);
}
double Short::doubleValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool Short::equals(IObject* object, ThreadContext* ctx) throw() 
{
	return ((dynamic_cast<Short*>(object) != 0)) && (value == (dynamic_cast<Short*>(object))->value);
}
float Short::floatValue(ThreadContext* ctx) throw() 
{
	return value;
}
int Short::hashCode(ThreadContext* ctx) throw() 
{
	return value;
}
int Short::intValue(ThreadContext* ctx) throw() 
{
	return value;
}
long long Short::longValue(ThreadContext* ctx) throw() 
{
	return value;
}
short Short::shortValue(ThreadContext* ctx) throw() 
{
	return value;
}
String* Short::toString(ThreadContext* ctx) throw() 
{
	return Integer::toString((int)value, ctx);
}
Short* Short::decode(String* string, ThreadContext* ctx)
{
	int intValue = Integer::decode(string, ctx)->intValue(ctx);
	short result = ((short)intValue);
	if(result == (short)intValue)
	{
		return valueOf(result, ctx);
	}
	throw (new(ctx) NumberFormatException(ctx));
}
short Short::parseShort(String* string, ThreadContext* ctx)
{
	return parseShort(string, 10, ctx);
}
short Short::parseShort(String* string, int radix, ThreadContext* ctx)
{
	int intValue = Integer::parseInt(string, radix, ctx);
	short result = ((short)intValue);
	if(result == (short)intValue)
	{
		return result;
	}
	throw (new(ctx) NumberFormatException(ctx));
}
String* Short::toString(short value, ThreadContext* ctx) throw() 
{
	return Integer::toString((int)value, ctx);
}
Short* Short::valueOf(String* string, ThreadContext* ctx)
{
	return valueOf(parseShort(string, ctx), ctx);
}
Short* Short::valueOf(String* string, int radix, ThreadContext* ctx)
{
	return valueOf(parseShort(string, radix, ctx), ctx);
}
short Short::reverseBytes(short s, ThreadContext* ctx) throw() 
{
	int high = (s >> 8) & 0xFF;
	int low = (s & 0xFF) << 8;
	return ((short)(low | high));
}
Short* Short::valueOf(short s, ThreadContext* ctx) throw() 
{
	return (new(ctx) Short(s, ctx));
}
int Short::ValueCompare::operator() (Short* _this, Short* object, ThreadContext* ctx) const throw()
{
	return _this->compareTo(object, ctx);
}
}}

