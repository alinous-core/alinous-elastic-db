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
#include "java.sql/Date.h"

namespace alinous {namespace numeric {





String* TimeOnlyTimestamp::PADDING = ConstStr::getCNST_STR_7();
bool TimeOnlyTimestamp::__init_done = __init_static_variables();
bool TimeOnlyTimestamp::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimeOnlyTimestamp", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimeOnlyTimestamp::TimeOnlyTimestamp(int theHour, int theMinute, int theSecond, ThreadContext* ctx) throw()  : IObject(ctx), InternalDate(70, 0, 1, theHour, theMinute, theSecond, ctx)
{
}
void TimeOnlyTimestamp::__construct_impl(int theHour, int theMinute, int theSecond, ThreadContext* ctx) throw() 
{
}
 TimeOnlyTimestamp::TimeOnlyTimestamp(long long theTime, ThreadContext* ctx) throw()  : IObject(ctx), InternalDate(ctx)
{
	GregorianCalendar* cal = (new(ctx) GregorianCalendar(theTime, ctx));
	cal->set(Calendar::YEAR, 1970, ctx);
	cal->set(Calendar::MONTH, 0, ctx);
	cal->set(Calendar::DATE, 1, ctx);
	this->milliseconds = cal->getTimeInMillis(ctx);
}
void TimeOnlyTimestamp::__construct_impl(long long theTime, ThreadContext* ctx) throw() 
{
	GregorianCalendar* cal = (new(ctx) GregorianCalendar(theTime, ctx));
	cal->set(Calendar::YEAR, 1970, ctx);
	cal->set(Calendar::MONTH, 0, ctx);
	cal->set(Calendar::DATE, 1, ctx);
	this->milliseconds = cal->getTimeInMillis(ctx);
}
 TimeOnlyTimestamp::~TimeOnlyTimestamp() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimeOnlyTimestamp::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	InternalDate::__releaseRegerences(true, ctx);
}
int TimeOnlyTimestamp::getDate(ThreadContext* ctx) throw() 
{
	throw (new(ctx) IllegalArgumentException(ctx));
}
int TimeOnlyTimestamp::getDay(ThreadContext* ctx) throw() 
{
	throw (new(ctx) IllegalArgumentException(ctx));
}
int TimeOnlyTimestamp::getMonth(ThreadContext* ctx) throw() 
{
	throw (new(ctx) IllegalArgumentException(ctx));
}
int TimeOnlyTimestamp::getYear(ThreadContext* ctx) throw() 
{
	throw (new(ctx) IllegalArgumentException(ctx));
}
void TimeOnlyTimestamp::setTime(long long time, ThreadContext* ctx) throw() 
{
	InternalDate::setTime(time, ctx);
}
String* TimeOnlyTimestamp::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* sb = (new(ctx) StringBuilder(8, ctx));
	format(getHours(ctx), 2, sb, ctx);
	sb->append(L':', ctx);
	format(getMinutes(ctx), 2, sb, ctx);
	sb->append(L':', ctx);
	format(getSeconds(ctx), 2, sb, ctx);
	return sb->toString(ctx);
}
void TimeOnlyTimestamp::format(int date, int digits, StringBuilder* sb, ThreadContext* ctx) throw() 
{
	String* str = String::valueOf(date, ctx);
	if(digits - str->length(ctx) > 0)
	{
		sb->append(PADDING->substring(0, digits - str->length(ctx), ctx), ctx);
	}
	sb->append(str, ctx);
}
TimeOnlyTimestamp* TimeOnlyTimestamp::valueOf(String* timeString, ThreadContext* ctx) throw() 
{
	if(timeString == nullptr)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	int firstIndex = timeString->indexOf((int)L':', ctx);
	int secondIndex = timeString->indexOf((int)L':', firstIndex + 1, ctx);
	if(secondIndex == -1 || firstIndex == 0 || secondIndex + 1 == timeString->length(ctx))
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	int hour = Integer::parseInt(timeString->substring(0, firstIndex, ctx), ctx);
	int minute = Integer::parseInt(timeString->substring(firstIndex + 1, secondIndex, ctx), ctx);
	int second = Integer::parseInt(timeString->substring(secondIndex + 1, timeString->length(ctx), ctx), ctx);
	return (new(ctx) TimeOnlyTimestamp(hour, minute, second, ctx));
}
}}

