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





constexpr const char Byte::MAX_VALUE;
constexpr const char Byte::MIN_VALUE;
constexpr const int Byte::SIZE;
bool Byte::__init_done = __init_static_variables();
bool Byte::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Byte", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Byte::Byte(char value, ThreadContext* ctx) throw()  : IObject(ctx), Number(ctx), Comparable<Byte>(ctx), value(0)
{
	this->value = value;
}
void Byte::__construct_impl(char value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 Byte::Byte(String* string, ThreadContext* ctx) : IObject(ctx), Number(ctx), Comparable<Byte>(ctx), value(0)
{
	__construct_impl(parseByte(string, ctx), ctx);
}
void Byte::__construct_impl(String* string, ThreadContext* ctx)
{
	__construct_impl(parseByte(string, ctx), ctx);
}
 Byte::~Byte() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Byte::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Byte", L"~Byte");
	if(!prepare){
		return;
	}
	Number::__releaseRegerences(true, ctx);
}
char Byte::byteValue(ThreadContext* ctx) throw() 
{
	return value;
}
int Byte::compareTo(Byte* object, ThreadContext* ctx) throw() 
{
	return value > object->value ? 1 : (value < object->value ? -1 : 0);
}
double Byte::doubleValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool Byte::equals(IObject* object, ThreadContext* ctx) throw() 
{
	return (object == this) || (((dynamic_cast<Byte*>(object) != 0)) && (value == (dynamic_cast<Byte*>(object))->value));
}
float Byte::floatValue(ThreadContext* ctx) throw() 
{
	return value;
}
int Byte::hashCode(ThreadContext* ctx) throw() 
{
	return value;
}
int Byte::intValue(ThreadContext* ctx) throw() 
{
	return value;
}
long long Byte::longValue(ThreadContext* ctx) throw() 
{
	return value;
}
short Byte::shortValue(ThreadContext* ctx) throw() 
{
	return value;
}
String* Byte::toString(ThreadContext* ctx) throw() 
{
	return Integer::toString((int)value, ctx);
}
Byte* Byte::decode(String* string, ThreadContext* ctx)
{
	int intValue = Integer::decode(string, ctx)->intValue(ctx);
	char result = ((char)intValue);
	if(result == (char)intValue)
	{
		return valueOf(result, ctx);
	}
	throw (new(ctx) NumberFormatException(ctx));
}
char Byte::parseByte(String* string, ThreadContext* ctx)
{
	int intValue = Integer::parseInt(string, ctx);
	char result = ((char)intValue);
	if(result == (char)intValue)
	{
		return result;
	}
	throw (new(ctx) NumberFormatException(ctx));
}
char Byte::parseByte(String* string, int radix, ThreadContext* ctx)
{
	int intValue = Integer::parseInt(string, radix, ctx);
	char result = ((char)intValue);
	if(result == (char)intValue)
	{
		return result;
	}
	throw (new(ctx) NumberFormatException(ctx));
}
String* Byte::toString(char value, ThreadContext* ctx) throw() 
{
	return Integer::toString((int)value, ctx);
}
Byte* Byte::valueOf(String* string, ThreadContext* ctx)
{
	return valueOf(parseByte(string, ctx), ctx);
}
Byte* Byte::valueOf(String* string, int radix, ThreadContext* ctx)
{
	return valueOf(parseByte(string, radix, ctx), ctx);
}
Byte* Byte::valueOf(char b, ThreadContext* ctx) throw() 
{
	return (new(ctx) Byte(b, ctx));
}
int Byte::ValueCompare::operator() (Byte* _this, Byte* object, ThreadContext* ctx) const throw()
{
	return _this->compareTo(object, ctx);
}
}}

