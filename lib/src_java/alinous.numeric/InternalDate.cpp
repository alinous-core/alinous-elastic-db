#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.util/Random.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigInteger.h"
#include "alinous.numeric/BitLevel.h"
#include "alinous.numeric/Multiplication.h"
#include "alinous.numeric/Conversion.h"
#include "alinous.numeric/RoundingMode.h"
#include "alinous.numeric/Logical.h"
#include "alinous.numeric/MathContext.h"
#include "alinous.numeric/Division.h"
#include "alinous.lock/LockObject.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.numeric/Elementary.h"
#include "alinous.numeric/Primality.h"

namespace alinous {namespace numeric {





IArrayObject<String>* InternalDate::dayOfWeekNames = nullptr;
IArrayObject<String>* InternalDate::monthNames = nullptr;
bool InternalDate::__init_done = __init_static_variables();
bool InternalDate::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InternalDate", L"__init_static_variables");
		__GC_MV(nullptr, &(dayOfWeekNames), (new ArrayObject<String>({ConstStr::getCNST_STR_28(), ConstStr::getCNST_STR_29(), ConstStr::getCNST_STR_30(), ConstStr::getCNST_STR_31(), ConstStr::getCNST_STR_32(), ConstStr::getCNST_STR_33(), ConstStr::getCNST_STR_34()}, ctx)), IArrayObject<String>);
		__GC_MV(nullptr, &(monthNames), (new ArrayObject<String>({ConstStr::getCNST_STR_35(), ConstStr::getCNST_STR_36(), ConstStr::getCNST_STR_37(), ConstStr::getCNST_STR_38(), ConstStr::getCNST_STR_39(), ConstStr::getCNST_STR_40(), ConstStr::getCNST_STR_41(), ConstStr::getCNST_STR_42(), ConstStr::getCNST_STR_43(), ConstStr::getCNST_STR_44(), ConstStr::getCNST_STR_45(), ConstStr::getCNST_STR_46()}, ctx)), IArrayObject<String>);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InternalDate::InternalDate(ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	__construct_impl(System::currentTimeMillis(ctx), ctx);
}
void InternalDate::__construct_impl(ThreadContext* ctx) throw() 
{
	__construct_impl(System::currentTimeMillis(ctx), ctx);
}
 InternalDate::InternalDate(int year, int month, int day, ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	Calendar* cal = Calendar::getInstance(ctx);
	cal->set(1900 + year, month, day, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
void InternalDate::__construct_impl(int year, int month, int day, ThreadContext* ctx) throw() 
{
	Calendar* cal = Calendar::getInstance(ctx);
	cal->set(1900 + year, month, day, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
 InternalDate::InternalDate(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	Calendar* cal = Calendar::getInstance(ctx);
	cal->set(1900 + year, month, day, hour, minute, second, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
void InternalDate::__construct_impl(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() 
{
	Calendar* cal = Calendar::getInstance(ctx);
	cal->set(1900 + year, month, day, hour, minute, second, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
 InternalDate::InternalDate(long long milliseconds, ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	this->milliseconds = milliseconds;
}
void InternalDate::__construct_impl(long long milliseconds, ThreadContext* ctx) throw() 
{
	this->milliseconds = milliseconds;
}
 InternalDate::~InternalDate() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InternalDate::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InternalDate", L"~InternalDate");
	if(!prepare){
		return;
	}
}
bool InternalDate::after(InternalDate* date, ThreadContext* ctx) throw() 
{
	return milliseconds > date->milliseconds;
}
bool InternalDate::before(InternalDate* date, ThreadContext* ctx) throw() 
{
	return milliseconds < date->milliseconds;
}
IObject* InternalDate::clone(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx));
}
int InternalDate::compareTo(InternalDate* date, ThreadContext* ctx) throw() 
{
	if(milliseconds < date->milliseconds)
	{
		return -1;
	}
	if(milliseconds == date->milliseconds)
	{
		return 0;
	}
	return 1;
}
bool InternalDate::equals(IObject* object, ThreadContext* ctx) throw() 
{
	return (object == this) || (((dynamic_cast<Date*>(object) != 0)) && (milliseconds == (dynamic_cast<Date*>(object))->getTime(ctx)));
}
int InternalDate::hashCode(ThreadContext* ctx) throw() 
{
	return ((int)(((unsigned long long)milliseconds)>> 32)) ^ ((int)milliseconds);
}
void InternalDate::setTime(long long milliseconds, ThreadContext* ctx) throw() 
{
	this->milliseconds = milliseconds;
}
String* InternalDate::toString(ThreadContext* ctx) throw() 
{
	Calendar* cal = (new(ctx) GregorianCalendar(milliseconds, ctx));
	TimeZone* zone = cal->getTimeZone(ctx);
	String* zoneName = zone->getDisplayName(zone->inDaylightTime(this, ctx), TimeZone::SHORT, Locale::getDefault(ctx), ctx);
	StringBuilder* sb = (new(ctx) StringBuilder(34, ctx));
	sb->append(dayOfWeekNames->get(cal->get(Calendar::DAY_OF_WEEK, ctx) - 1), ctx);
	sb->append(L' ', ctx);
	sb->append(monthNames->get(cal->get(Calendar::MONTH, ctx)), ctx);
	sb->append(L' ', ctx);
	sb->append(toTwoDigits(cal->get(Calendar::DAY_OF_MONTH, ctx), ctx), ctx);
	sb->append(L' ', ctx);
	sb->append(toTwoDigits(cal->get(Calendar::HOUR_OF_DAY, ctx), ctx), ctx);
	sb->append(L':', ctx);
	sb->append(toTwoDigits(cal->get(Calendar::MINUTE, ctx), ctx), ctx);
	sb->append(L':', ctx);
	sb->append(toTwoDigits(cal->get(Calendar::SECOND, ctx), ctx), ctx);
	sb->append(L' ', ctx);
	sb->append(zoneName, ctx);
	sb->append(L' ', ctx);
	sb->append(cal->get(Calendar::YEAR, ctx), ctx);
	return sb->toString(ctx);
}
int InternalDate::getYear(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::YEAR, ctx) - 1900;
}
int InternalDate::getDate(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::DATE, ctx);
}
int InternalDate::getDay(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::DAY_OF_WEEK, ctx) - 1;
}
int InternalDate::getHours(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::HOUR_OF_DAY, ctx);
}
int InternalDate::getMinutes(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::MINUTE, ctx);
}
int InternalDate::getMonth(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::MONTH, ctx);
}
int InternalDate::getSeconds(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::SECOND, ctx);
}
long long InternalDate::getTime(ThreadContext* ctx) throw() 
{
	return milliseconds;
}
String* InternalDate::toTwoDigits(int digit, ThreadContext* ctx) throw() 
{
	if(digit >= 10)
	{
		return ConstStr::getCNST_STR_4()->clone(ctx)->append(digit, ctx);
	}
		else 
	{
		return ConstStr::getCNST_STR_9()->clone(ctx)->append(digit, ctx);
	}
}
int InternalDate::zone(String* text, ThreadContext* ctx) throw() 
{
	if(text->equals(ConstStr::getCNST_STR_20(), ctx))
	{
		return -5;
	}
	if(text->equals(ConstStr::getCNST_STR_21(), ctx))
	{
		return -4;
	}
	if(text->equals(ConstStr::getCNST_STR_22(), ctx))
	{
		return -6;
	}
	if(text->equals(ConstStr::getCNST_STR_23(), ctx))
	{
		return -5;
	}
	if(text->equals(ConstStr::getCNST_STR_24(), ctx))
	{
		return -7;
	}
	if(text->equals(ConstStr::getCNST_STR_25(), ctx))
	{
		return -6;
	}
	if(text->equals(ConstStr::getCNST_STR_26(), ctx))
	{
		return -8;
	}
	if(text->equals(ConstStr::getCNST_STR_27(), ctx))
	{
		return -7;
	}
	return 0;
}
void InternalDate::__cleanUp(ThreadContext* ctx){
	GCUtils<IArrayObject<String>>::dec(nullptr, InternalDate::dayOfWeekNames, ctx, __FILEW__, __LINE__, L"IArrayObject<String>");
	GCUtils<IArrayObject<String>>::dec(nullptr, InternalDate::monthNames, ctx, __FILEW__, __LINE__, L"IArrayObject<String>");
}
int InternalDate::ValueCompare::operator() (InternalDate* _this, InternalDate* date, ThreadContext* ctx) const throw()
{
	return _this->compareTo(date, ctx);
}
}}

