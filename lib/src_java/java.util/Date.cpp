#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/TimeZone.h"
#include "java.util/SimpleTimeZone.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZones.h"
#include "java.sql/Date.h"
#include "java.util/BitSet.h"
#include "java.util/Random.h"
#include "java.util/Arrays.h"

namespace java {namespace util {





IArrayObject<String>* Date::dayOfWeekNames = nullptr;
IArrayObject<String>* Date::monthNames = nullptr;
bool Date::__init_done = __init_static_variables();
bool Date::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Date", L"__init_static_variables");
		__GC_MV(nullptr, &(dayOfWeekNames), (new ArrayObject<String>({ConstStr::getCNST_STR_28(), ConstStr::getCNST_STR_29(), ConstStr::getCNST_STR_30(), ConstStr::getCNST_STR_31(), ConstStr::getCNST_STR_32(), ConstStr::getCNST_STR_33(), ConstStr::getCNST_STR_34()}, ctx)), IArrayObject<String>);
		__GC_MV(nullptr, &(monthNames), (new ArrayObject<String>({ConstStr::getCNST_STR_35(), ConstStr::getCNST_STR_36(), ConstStr::getCNST_STR_37(), ConstStr::getCNST_STR_38(), ConstStr::getCNST_STR_39(), ConstStr::getCNST_STR_40(), ConstStr::getCNST_STR_41(), ConstStr::getCNST_STR_42(), ConstStr::getCNST_STR_43(), ConstStr::getCNST_STR_44(), ConstStr::getCNST_STR_45(), ConstStr::getCNST_STR_46()}, ctx)), IArrayObject<String>);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Date::Date(ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	__construct_impl(System::currentTimeMillis(ctx), ctx);
}
void Date::__construct_impl(ThreadContext* ctx) throw() 
{
	__construct_impl(System::currentTimeMillis(ctx), ctx);
}
 Date::Date(int year, int month, int day, ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	GregorianCalendar* cal = (new(ctx) GregorianCalendar(false, ctx));
	cal->set(1900 + year, month, day, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
void Date::__construct_impl(int year, int month, int day, ThreadContext* ctx) throw() 
{
	GregorianCalendar* cal = (new(ctx) GregorianCalendar(false, ctx));
	cal->set(1900 + year, month, day, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
 Date::Date(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	GregorianCalendar* cal = (new(ctx) GregorianCalendar(false, ctx));
	cal->set(1900 + year, month, day, hour, minute, second, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
void Date::__construct_impl(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() 
{
	GregorianCalendar* cal = (new(ctx) GregorianCalendar(false, ctx));
	cal->set(1900 + year, month, day, hour, minute, second, ctx);
	milliseconds = cal->getTimeInMillis(ctx);
}
 Date::Date(long long milliseconds, ThreadContext* ctx) throw()  : IObject(ctx), milliseconds(0)
{
	this->milliseconds = milliseconds;
}
void Date::__construct_impl(long long milliseconds, ThreadContext* ctx) throw() 
{
	this->milliseconds = milliseconds;
}
 Date::~Date() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Date::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Date", L"~Date");
	if(!prepare){
		return;
	}
}
bool Date::after(Date* date, ThreadContext* ctx) throw() 
{
	return milliseconds > date->milliseconds;
}
bool Date::before(Date* date, ThreadContext* ctx) throw() 
{
	return milliseconds < date->milliseconds;
}
IObject* Date::clone(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx));
}
int Date::compareTo(Date* date, ThreadContext* ctx) throw() 
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
bool Date::equals(IObject* object, ThreadContext* ctx) throw() 
{
	return (object == this) || (((dynamic_cast<Date*>(object) != 0)) && (milliseconds == (dynamic_cast<Date*>(object))->milliseconds));
}
int Date::hashCode(ThreadContext* ctx) throw() 
{
	return ((int)(((unsigned long long)milliseconds)>> 32)) ^ ((int)milliseconds);
}
void Date::setTime(long long milliseconds, ThreadContext* ctx) throw() 
{
	this->milliseconds = milliseconds;
}
String* Date::toString(ThreadContext* ctx) throw() 
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
int Date::getYear(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::YEAR, ctx) - 1900;
}
int Date::getDate(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::DATE, ctx);
}
int Date::getDay(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::DAY_OF_WEEK, ctx) - 1;
}
int Date::getHours(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::HOUR_OF_DAY, ctx);
}
int Date::getMinutes(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::MINUTE, ctx);
}
int Date::getMonth(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::MONTH, ctx);
}
int Date::getSeconds(ThreadContext* ctx) throw() 
{
	return (new(ctx) GregorianCalendar(milliseconds, ctx))->get(Calendar::SECOND, ctx);
}
long long Date::getTime(ThreadContext* ctx) throw() 
{
	return milliseconds;
}
String* Date::toTwoDigits(int digit, ThreadContext* ctx) throw() 
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
int Date::zone(String* text, ThreadContext* ctx) throw() 
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
void Date::__cleanUp(ThreadContext* ctx){
	GCUtils<IArrayObject<String>>::dec(nullptr, Date::dayOfWeekNames, ctx, __FILEW__, __LINE__, L"IArrayObject<String>");
	GCUtils<IArrayObject<String>>::dec(nullptr, Date::monthNames, ctx, __FILEW__, __LINE__, L"IArrayObject<String>");
}
int Date::ValueCompare::operator() (Date* _this, Date* date, ThreadContext* ctx) const throw()
{
	return _this->compareTo(date, ctx);
}
}}

