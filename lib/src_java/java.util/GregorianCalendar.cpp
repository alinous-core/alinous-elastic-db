#include "include/global.h"


#include "java.util/Date.h"
#include "java.util/TimeZones.h"
#include "java.util/Locale.h"
#include "java.util/TimeZone.h"
#include "java.util/Calendar.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/SimpleTimeZone.h"
#include "java.util/GregorianCalendar.h"
#include "java.sql/Date.h"

namespace java {namespace util {





constexpr const int GregorianCalendar::BC;
constexpr const int GregorianCalendar::AD;
constexpr const long long GregorianCalendar::defaultGregorianCutover;
const StaticArrayObjectPrimitive<char> GregorianCalendar::__DaysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
IArrayObjectPrimitive<char>* GregorianCalendar::DaysInMonth = (IArrayObjectPrimitive<char>*)const_cast<StaticArrayObjectPrimitive<char>*>(&__DaysInMonth);
const StaticArrayObjectPrimitive<int> GregorianCalendar::__DaysInYear = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
IArrayObjectPrimitive<int>* GregorianCalendar::DaysInYear = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__DaysInYear);
const StaticArrayObjectPrimitive<int> GregorianCalendar::__maximums = {1, 292278994, 11, 53, 6, 31, 366, 7, 6, 1, 11, 23, 59, 59, 999, 14 * 3600 * 1000, 7200000};
IArrayObjectPrimitive<int>* GregorianCalendar::maximums = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__maximums);
const StaticArrayObjectPrimitive<int> GregorianCalendar::__minimums = {0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, -13 * 3600 * 1000, 0};
IArrayObjectPrimitive<int>* GregorianCalendar::minimums = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__minimums);
const StaticArrayObjectPrimitive<int> GregorianCalendar::__leastMaximums = {1, 292269054, 11, 50, 3, 28, 355, 7, 3, 1, 11, 23, 59, 59, 999, 50400000, 1200000};
IArrayObjectPrimitive<int>* GregorianCalendar::leastMaximums = (IArrayObjectPrimitive<int>*)const_cast<StaticArrayObjectPrimitive<int>*>(&__leastMaximums);
bool GregorianCalendar::__init_done = __init_static_variables();
bool GregorianCalendar::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GregorianCalendar", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GregorianCalendar::GregorianCalendar(ThreadContext* ctx) throw()  : IObject(ctx), Calendar(ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	__construct_impl(TimeZone::getDefault(ctx), Locale::getDefault(ctx), ctx);
}
void GregorianCalendar::__construct_impl(ThreadContext* ctx) throw() 
{
	__construct_impl(TimeZone::getDefault(ctx), Locale::getDefault(ctx), ctx);
}
 GregorianCalendar::GregorianCalendar(int year, int month, int day, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(TimeZone::getDefault(ctx), Locale::getDefault(ctx), ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	set(year, month, day, ctx);
}
void GregorianCalendar::__construct_impl(int year, int month, int day, ThreadContext* ctx) throw() 
{
	set(year, month, day, ctx);
}
 GregorianCalendar::GregorianCalendar(int year, int month, int day, int hour, int minute, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(TimeZone::getDefault(ctx), Locale::getDefault(ctx), ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	set(year, month, day, hour, minute, ctx);
}
void GregorianCalendar::__construct_impl(int year, int month, int day, int hour, int minute, ThreadContext* ctx) throw() 
{
	set(year, month, day, hour, minute, ctx);
}
 GregorianCalendar::GregorianCalendar(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(TimeZone::getDefault(ctx), Locale::getDefault(ctx), ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	set(year, month, day, hour, minute, second, ctx);
}
void GregorianCalendar::__construct_impl(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() 
{
	set(year, month, day, hour, minute, second, ctx);
}
 GregorianCalendar::GregorianCalendar(long long milliseconds, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	__construct_impl(false, ctx);
	setTimeInMillis(milliseconds, ctx);
}
void GregorianCalendar::__construct_impl(long long milliseconds, ThreadContext* ctx) throw() 
{
	__construct_impl(false, ctx);
	setTimeInMillis(milliseconds, ctx);
}
 GregorianCalendar::GregorianCalendar(Locale* locale, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	__construct_impl(TimeZone::getDefault(ctx), locale, ctx);
}
void GregorianCalendar::__construct_impl(Locale* locale, ThreadContext* ctx) throw() 
{
	__construct_impl(TimeZone::getDefault(ctx), locale, ctx);
}
 GregorianCalendar::GregorianCalendar(TimeZone* timezone, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	__construct_impl(timezone, Locale::getDefault(ctx), ctx);
}
void GregorianCalendar::__construct_impl(TimeZone* timezone, ThreadContext* ctx) throw() 
{
	__construct_impl(timezone, Locale::getDefault(ctx), ctx);
}
 GregorianCalendar::GregorianCalendar(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(timezone, locale, ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	setTimeInMillis(System::currentTimeMillis(ctx), ctx);
}
void GregorianCalendar::__construct_impl(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() 
{
	setTimeInMillis(System::currentTimeMillis(ctx), ctx);
}
 GregorianCalendar::GregorianCalendar(bool ignored, ThreadContext* ctx) throw()  : IObject(ctx), Calendar(TimeZone::getDefault(ctx), ctx), gregorianCutover(defaultGregorianCutover), changeYear(1582), julianSkew(((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100)), isCached(0), cachedFields(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, ctx)), IArrayObjectPrimitive<int>)), nextMidnightMillis(0L), lastMidnightMillis(0L), currentYearSkew(10), lastYearSkew(0)
{
	setFirstDayOfWeek(SUNDAY, ctx);
	setMinimalDaysInFirstWeek(1, ctx);
}
void GregorianCalendar::__construct_impl(bool ignored, ThreadContext* ctx) throw() 
{
	setFirstDayOfWeek(SUNDAY, ctx);
	setMinimalDaysInFirstWeek(1, ctx);
}
 GregorianCalendar::~GregorianCalendar() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GregorianCalendar::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"GregorianCalendar", L"~GregorianCalendar");
	__e_obj1.add(this->cachedFields, this);
	cachedFields = nullptr;
	if(!prepare){
		return;
	}
	Calendar::__releaseRegerences(true, ctx);
}
void GregorianCalendar::add(int field, int value, ThreadContext* ctx) throw() 
{
	if(value == 0)
	{
		return;
	}
	if(field < 0 || field >= ZONE_OFFSET)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	isCached = false;
	if(field == ERA)
	{
		complete(ctx);
		if(fields->get(ERA) == AD)
		{
			if(value >= 0)
			{
				return;
			}
			set(ERA, BC, ctx);
		}
				else 
		{
			if(value <= 0)
			{
				return;
			}
			set(ERA, AD, ctx);
		}
		complete(ctx);
		return;
	}
	if(field == YEAR || field == MONTH)
	{
		complete(ctx);
		if(field == MONTH)
		{
			int month = fields->get(MONTH) + value;
			if(month < 0)
			{
				value = (month - 11) / 12;
				month = 12 + (month % 12);
			}
						else 
			{
				value = month / 12;
			}
			set(MONTH, month % 12, ctx);
		}
		set(YEAR, fields->get(YEAR) + value, ctx);
		int days = daysInMonth(isLeapYear(fields->get(YEAR), ctx), fields->get(MONTH), ctx);
		if(fields->get(DATE) > days)
		{
			set(DATE, days, ctx);
		}
		complete(ctx);
		return;
	}
	long long multiplier = 0;
	getTimeInMillis(ctx);
	switch(field) {
	case MILLISECOND:
		time += value;
		break ;
	case SECOND:
		time += value * 1000L;
		break ;
	case MINUTE:
		time += value * 60000L;
		break ;
	case HOUR:
	case HOUR_OF_DAY:
		time += value * 3600000L;
		break ;
	case AM_PM:
		multiplier = 43200000L;
		break ;
	case DATE:
	case DAY_OF_YEAR:
	case DAY_OF_WEEK:
		multiplier = 86400000L;
		break ;
	case WEEK_OF_YEAR:
	case WEEK_OF_MONTH:
	case DAY_OF_WEEK_IN_MONTH:
		multiplier = 604800000L;
		break ;
	}
	if(multiplier > (long long)0)
	{
		int zoneOffset = getTimeZone(ctx)->getRawOffset(ctx);
		int offset = getOffset(time + zoneOffset, ctx);
		time += value * multiplier;
		int newOffset = getOffset(time + zoneOffset, ctx);
		if(newOffset != offset)
		{
			time += offset - newOffset;
		}
	}
	areFieldsSet = false;
	complete(ctx);
}
IObject* GregorianCalendar::clone(ThreadContext* ctx) throw() 
{
	GregorianCalendar* thisClone = (new(ctx) GregorianCalendar(getTimeInMillis(ctx), ctx));
	__GC_MV(thisClone, &(thisClone->cachedFields), cachedFields->clone(ctx), IArrayObjectPrimitive<int>);
	__GC_MV(thisClone, &(thisClone->fields), fields->clone(ctx), IArrayObjectPrimitive<int>);
	__GC_MV(thisClone, &(thisClone->_isSet), _isSet->clone(ctx), IArrayObjectPrimitive<bool>);
	__GC_MV(thisClone, &(thisClone->zone), dynamic_cast<TimeZone*>(zone->clone(ctx)), TimeZone);
	return thisClone;
}
bool GregorianCalendar::equals(IObject* object, ThreadContext* ctx) throw() 
{
	return Calendar::equals(object, ctx) && gregorianCutover == (dynamic_cast<GregorianCalendar*>(object))->gregorianCutover;
}
int GregorianCalendar::getActualMaximum(int field, ThreadContext* ctx) throw() 
{
	int value = 0;
	value = maximums->get(field);
	if((value) == leastMaximums->get(field))
	{
		return value;
	}
	switch(field) {
	case WEEK_OF_YEAR:
	case WEEK_OF_MONTH:
		isCached = false;
		break ;
	}
	complete(ctx);
	long long orgTime = time;
	int result = 0;
	switch(field) {
	case WEEK_OF_YEAR:
		set(DATE, 31, ctx);
		set(MONTH, DECEMBER, ctx);
		result = get(WEEK_OF_YEAR, ctx);
		if(result == 1)
		{
			set(DATE, 31 - 7, ctx);
			result = get(WEEK_OF_YEAR, ctx);
		}
		areFieldsSet = false;
		break ;
	case WEEK_OF_MONTH:
		set(DATE, daysInMonth(ctx), ctx);
		result = get(WEEK_OF_MONTH, ctx);
		areFieldsSet = false;
		break ;
	case DATE:
		return daysInMonth(ctx);
	case DAY_OF_YEAR:
		return daysInYear(fields->get(YEAR), ctx);
	case DAY_OF_WEEK_IN_MONTH:
		result = get(DAY_OF_WEEK_IN_MONTH, ctx) + ((daysInMonth(ctx) - get(DATE, ctx)) / 7);
		break ;
	case YEAR:
		{
		GregorianCalendar* cloneedObj = dynamic_cast<GregorianCalendar*>(clone(ctx));
		if(get(ERA, ctx) == AD)
		{
			cloneedObj->setTimeInMillis(Long::MAX_VALUE, ctx);
		}
				else 
		{
			cloneedObj->setTimeInMillis(Long::MIN_VALUE, ctx);
		}
		result = cloneedObj->get(YEAR, ctx);
		cloneedObj->set(YEAR, get(YEAR, ctx), ctx);
		if(cloneedObj->before(this, ctx))
		{
			result -- ;
		}
		break ;
		}
	case DST_OFFSET:
		result = getMaximum(DST_OFFSET, ctx);
		break ;
	}
	time = orgTime;
	return result;
}
int GregorianCalendar::getActualMinimum(int field, ThreadContext* ctx) throw() 
{
	return getMinimum(field, ctx);
}
int GregorianCalendar::getGreatestMinimum(int field, ThreadContext* ctx) throw() 
{
	return minimums->get(field);
}
Date* GregorianCalendar::getGregorianChange(ThreadContext* ctx) throw() 
{
	return (new(ctx) Date(gregorianCutover, ctx));
}
int GregorianCalendar::getLeastMaximum(int field, ThreadContext* ctx) throw() 
{
	if(gregorianCutover != defaultGregorianCutover && field == WEEK_OF_YEAR)
	{
		long long currentTimeInMillis = time;
		setTimeInMillis(gregorianCutover, ctx);
		int actual = getActualMaximum(field, ctx);
		setTimeInMillis(currentTimeInMillis, ctx);
		return actual;
	}
	return leastMaximums->get(field);
}
int GregorianCalendar::getMaximum(int field, ThreadContext* ctx) throw() 
{
	return maximums->get(field);
}
int GregorianCalendar::getMinimum(int field, ThreadContext* ctx) throw() 
{
	return minimums->get(field);
}
int GregorianCalendar::hashCode(ThreadContext* ctx) throw() 
{
	return Calendar::hashCode(ctx) + (((int)(((unsigned long long)gregorianCutover)>> 32)) ^ ((int)gregorianCutover));
}
bool GregorianCalendar::isLeapYear(int year, ThreadContext* ctx) throw() 
{
	if(year > changeYear)
	{
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}
	return year % 4 == 0;
}
void GregorianCalendar::roll(int field, int value, ThreadContext* ctx) throw() 
{
	if(value == 0)
	{
		return;
	}
	if(field < 0 || field >= ZONE_OFFSET)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	isCached = false;
	complete(ctx);
	int days = 0;int day = 0;int mod = 0;int maxWeeks = 0;int newWeek = 0;
	int max = -1;
	switch(field) {
	case YEAR:
		max = maximums->get(field);
		break ;
	case WEEK_OF_YEAR:
		days = daysInYear(fields->get(YEAR), ctx);
		day = DAY_OF_YEAR;
		mod = mod7((long long)fields->get(DAY_OF_WEEK) - fields->get(day) - (getFirstDayOfWeek(ctx) - 1), ctx);
		maxWeeks = (days - 1 + mod) / 7 + 1;
		newWeek = _mod(fields->get(field) - 1 + value, maxWeeks, ctx) + 1;
		if(newWeek == maxWeeks)
		{
			int addDays = (newWeek - fields->get(field)) * 7;
			if(fields->get(day) > addDays && fields->get(day) + addDays > days)
			{
				set(field, 1, ctx);
			}
						else 
			{
				set(field, newWeek - 1, ctx);
			}
		}
				else 
		{
			if(newWeek == 1)
			{
				int week = (fields->get(day) - ((fields->get(day) - 1) / 7 * 7) - 1 + mod) / 7 + 1;
				if(week > 1)
				{
					set(field, 1, ctx);
				}
								else 
				{
					set(field, newWeek, ctx);
				}
			}
						else 
			{
				set(field, newWeek, ctx);
			}
		}
		break ;
	case WEEK_OF_MONTH:
		days = daysInMonth(ctx);
		day = DATE;
		mod = mod7((long long)fields->get(DAY_OF_WEEK) - fields->get(day) - (getFirstDayOfWeek(ctx) - 1), ctx);
		maxWeeks = (days - 1 + mod) / 7 + 1;
		newWeek = _mod(fields->get(field) - 1 + value, maxWeeks, ctx) + 1;
		if(newWeek == maxWeeks)
		{
			if(fields->get(day) + (newWeek - fields->get(field)) * 7 > days)
			{
				set(day, days, ctx);
			}
						else 
			{
				set(field, newWeek, ctx);
			}
		}
				else 
		{
			if(newWeek == 1)
			{
				int week = (fields->get(day) - ((fields->get(day) - 1) / 7 * 7) - 1 + mod) / 7 + 1;
				if(week > 1)
				{
					set(day, 1, ctx);
				}
								else 
				{
					set(field, newWeek, ctx);
				}
			}
						else 
			{
				set(field, newWeek, ctx);
			}
		}
		break ;
	case DATE:
		max = daysInMonth(ctx);
		break ;
	case DAY_OF_YEAR:
		max = daysInYear(fields->get(YEAR), ctx);
		break ;
	case DAY_OF_WEEK:
		max = maximums->get(field);
		lastDateFieldSet = WEEK_OF_MONTH;
		break ;
	case DAY_OF_WEEK_IN_MONTH:
		max = (fields->get(DATE) + ((daysInMonth(ctx) - fields->get(DATE)) / 7 * 7) - 1) / 7 + 1;
		break ;
	case ERA:
	case MONTH:
	case AM_PM:
	case HOUR:
	case HOUR_OF_DAY:
	case MINUTE:
	case SECOND:
	case MILLISECOND:
		set(field, _mod(fields->get(field) + value, maximums->get(field) + 1, ctx), ctx);
		if(field == MONTH && fields->get(DATE) > daysInMonth(ctx))
		{
			set(DATE, daysInMonth(ctx), ctx);
		}
				else 
		{
			if(field == AM_PM)
			{
				lastTimeFieldSet = HOUR;
			}
		}
		break ;
	}
	if(max != -1)
	{
		set(field, _mod(fields->get(field) - 1 + value, max, ctx) + 1, ctx);
	}
	complete(ctx);
}
void GregorianCalendar::roll(int field, bool increment, ThreadContext* ctx) throw() 
{
	roll(field, increment ? 1 : -1, ctx);
}
void GregorianCalendar::setGregorianChange(Date* date, ThreadContext* ctx) throw() 
{
	gregorianCutover = date->getTime(ctx);
	GregorianCalendar* cal = (new(ctx) GregorianCalendar(TimeZone::GMT, ctx));
	cal->setTime(date, ctx);
	changeYear = cal->get(YEAR, ctx);
	if(cal->get(ERA, ctx) == BC)
	{
		changeYear = 1 - changeYear;
	}
	julianSkew = ((changeYear - 2000) / 400) + julianError(ctx) - ((changeYear - 2000) / 100);
	isCached = false;
	int dayOfYear = cal->get(DAY_OF_YEAR, ctx);
	if(dayOfYear < julianSkew)
	{
		currentYearSkew = dayOfYear - 1;
		lastYearSkew = julianSkew - dayOfYear + 1;
	}
		else 
	{
		lastYearSkew = 0;
		currentYearSkew = julianSkew;
	}
	isCached = false;
}
void GregorianCalendar::setFirstDayOfWeek(int value, ThreadContext* ctx) throw() 
{
	Calendar::setFirstDayOfWeek(value, ctx);
	isCached = false;
}
void GregorianCalendar::setMinimalDaysInFirstWeek(int value, ThreadContext* ctx) throw() 
{
	Calendar::setMinimalDaysInFirstWeek(value, ctx);
	isCached = false;
}
void GregorianCalendar::computeFields(ThreadContext* ctx) throw() 
{
	int zoneOffset = getTimeZone(ctx)->getRawOffset(ctx);
	if(!_isSet->get(ZONE_OFFSET))
	{
		fields->set(zoneOffset,ZONE_OFFSET, ctx);
	}
	int millis = ((int)(time % 86400000));
	int savedMillis = millis;
	int dstOffset = fields->get(DST_OFFSET);
	int offset = zoneOffset + dstOffset;
	long long newTime = time + offset;
	if(time > (long long)0L && newTime < (long long)0L && offset > 0)
	{
		newTime = 0x7fffffffffffffffL;
	}
		else 
	{
		if(time < (long long)0L && newTime > (long long)0L && offset < 0)
		{
			newTime = 0x8000000000000000L;
		}
	}
	if(isCached)
	{
		if(millis < 0)
		{
			millis += 86400000;
		}
		millis += zoneOffset;
		millis += dstOffset;
		if(millis < 0)
		{
			millis += 86400000;
		}
				else 
		{
			if(millis >= 86400000)
			{
				millis -= 86400000;
			}
		}
		fields->set((millis % 1000),MILLISECOND, ctx);
		millis /= 1000;
		fields->set((millis % 60),SECOND, ctx);
		millis /= 60;
		fields->set((millis % 60),MINUTE, ctx);
		millis /= 60;
		fields->set((millis % 24),HOUR_OF_DAY, ctx);
		millis /= 24;
		fields->set(fields->get(HOUR_OF_DAY) > 11 ? 1 : 0,AM_PM, ctx);
		fields->set(fields->get(HOUR_OF_DAY) % 12,HOUR, ctx);
		long long newTimeAdjusted = newTime;
		if(getTimeZone(ctx)->useDaylightTime(ctx))
		{
			int dstSavings = (static_cast<SimpleTimeZone*>(getTimeZone(ctx)))->getDSTSavings(ctx);
			newTimeAdjusted += (dstOffset == 0) ? dstSavings : -dstSavings;
		}
		if(newTime > (long long)0L && newTimeAdjusted < (long long)0L && dstOffset == 0)
		{
			newTimeAdjusted = 0x7fffffffffffffffL;
		}
				else 
		{
			if(newTime < (long long)0L && newTimeAdjusted > (long long)0L && dstOffset != 0)
			{
				newTimeAdjusted = 0x8000000000000000L;
			}
		}
		cachedFieldsCheckAndGet(time, newTime, newTimeAdjusted, savedMillis, zoneOffset, ctx);
	}
		else 
	{
		fullFieldsCalc(time, savedMillis, zoneOffset, ctx);
	}
	for(int i = 0; i < FIELD_COUNT; i ++ )
	{
		_isSet->set(true,i, ctx);
	}
	if(!isCached && newTime != (long long)0x7fffffffffffffffL && newTime != (long long)0x8000000000000000L && (!getTimeZone(ctx)->useDaylightTime(ctx) || (dynamic_cast<SimpleTimeZone*>(getTimeZone(ctx)) != 0)))
	{
		int cacheMillis = 0;
		cachedFields->set(fields->get(YEAR),0, ctx);
		cachedFields->set(fields->get(MONTH),1, ctx);
		cachedFields->set(fields->get(DATE),2, ctx);
		cachedFields->set(fields->get(DAY_OF_WEEK),3, ctx);
		cachedFields->set(zoneOffset,4, ctx);
		cachedFields->set(fields->get(ERA),5, ctx);
		cachedFields->set(fields->get(WEEK_OF_YEAR),6, ctx);
		cachedFields->set(fields->get(WEEK_OF_MONTH),7, ctx);
		cachedFields->set(fields->get(DAY_OF_YEAR),8, ctx);
		cachedFields->set(fields->get(DAY_OF_WEEK_IN_MONTH),9, ctx);
		cacheMillis += (23 - fields->get(HOUR_OF_DAY)) * 60 * 60 * 1000;
		cacheMillis += (59 - fields->get(MINUTE)) * 60 * 1000;
		cacheMillis += (59 - fields->get(SECOND)) * 1000;
		nextMidnightMillis = newTime + cacheMillis;
		cacheMillis = fields->get(HOUR_OF_DAY) * 60 * 60 * 1000;
		cacheMillis += fields->get(MINUTE) * 60 * 1000;
		cacheMillis += fields->get(SECOND) * 1000;
		lastMidnightMillis = newTime - cacheMillis;
		isCached = true;
	}
}
void GregorianCalendar::computeTime(ThreadContext* ctx) throw() 
{
	if(!isLenient(ctx))
	{
		if(_isSet->get(HOUR_OF_DAY))
		{
			if(fields->get(HOUR_OF_DAY) < 0 || fields->get(HOUR_OF_DAY) > 23)
			{
				throw (new(ctx) IllegalArgumentException(ctx));
			}
		}
				else 
		{
			if(_isSet->get(HOUR) && (fields->get(HOUR) < 0 || fields->get(HOUR) > 11))
			{
				throw (new(ctx) IllegalArgumentException(ctx));
			}
		}
		if(_isSet->get(MINUTE) && (fields->get(MINUTE) < 0 || fields->get(MINUTE) > 59))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(SECOND) && (fields->get(SECOND) < 0 || fields->get(SECOND) > 59))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(MILLISECOND) && (fields->get(MILLISECOND) < 0 || fields->get(MILLISECOND) > 999))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(WEEK_OF_YEAR) && (fields->get(WEEK_OF_YEAR) < 1 || fields->get(WEEK_OF_YEAR) > 53))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(DAY_OF_WEEK) && (fields->get(DAY_OF_WEEK) < 1 || fields->get(DAY_OF_WEEK) > 7))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(DAY_OF_WEEK_IN_MONTH) && (fields->get(DAY_OF_WEEK_IN_MONTH) < 1 || fields->get(DAY_OF_WEEK_IN_MONTH) > 6))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(WEEK_OF_MONTH) && (fields->get(WEEK_OF_MONTH) < 1 || fields->get(WEEK_OF_MONTH) > 6))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(AM_PM) && fields->get(AM_PM) != AM && fields->get(AM_PM) != PM)
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(HOUR) && (fields->get(HOUR) < 0 || fields->get(HOUR) > 11))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(_isSet->get(YEAR))
		{
			if(_isSet->get(ERA) && fields->get(ERA) == BC && (fields->get(YEAR) < 1 || fields->get(YEAR) > 292269054))
			{
				throw (new(ctx) IllegalArgumentException(ctx));
			}
						else 
			{
				if(fields->get(YEAR) < 1 || fields->get(YEAR) > 292278994)
				{
					throw (new(ctx) IllegalArgumentException(ctx));
				}
			}
		}
		if(_isSet->get(MONTH) && (fields->get(MONTH) < 0 || fields->get(MONTH) > 11))
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
	}
	long long timeVal = 0;
	long long hour = 0;
	if(_isSet->get(HOUR_OF_DAY) && lastTimeFieldSet != HOUR)
	{
		hour = fields->get(HOUR_OF_DAY);
	}
		else 
	{
		if(_isSet->get(HOUR))
		{
			hour = (fields->get(AM_PM) * 12) + fields->get(HOUR);
		}
	}
	timeVal = hour * 3600000;
	if(_isSet->get(MINUTE))
	{
		timeVal += (((long long)fields->get(MINUTE))) * 60000;
	}
	if(_isSet->get(SECOND))
	{
		timeVal += (((long long)fields->get(SECOND))) * 1000;
	}
	if(_isSet->get(MILLISECOND))
	{
		timeVal += fields->get(MILLISECOND);
	}
	long long days = 0;
	int year = _isSet->get(YEAR) ? fields->get(YEAR) : 1970;
	if(_isSet->get(ERA))
	{
		if(fields->get(ERA) != BC && fields->get(ERA) != AD)
		{
			throw (new(ctx) IllegalArgumentException(ctx));
		}
		if(fields->get(ERA) == BC)
		{
			year = 1 - year;
		}
	}
	bool weekMonthSet = _isSet->get(WEEK_OF_MONTH) || _isSet->get(DAY_OF_WEEK_IN_MONTH);
	bool useMonth = (_isSet->get(DATE) || _isSet->get(MONTH) || weekMonthSet) && lastDateFieldSet != DAY_OF_YEAR;
	if(useMonth && (lastDateFieldSet == DAY_OF_WEEK || lastDateFieldSet == WEEK_OF_YEAR))
	{
		if(_isSet->get(WEEK_OF_YEAR) && _isSet->get(DAY_OF_WEEK))
		{
			useMonth = lastDateFieldSet != WEEK_OF_YEAR && weekMonthSet && _isSet->get(DAY_OF_WEEK);
		}
				else 
		{
			if(_isSet->get(DAY_OF_YEAR))
			{
				useMonth = _isSet->get(DATE) && _isSet->get(MONTH);
			}
		}
	}
	if(useMonth)
	{
		int month = fields->get(MONTH);
		year += month / 12;
		month %= 12;
		if(month < 0)
		{
			year -- ;
			month += 12;
		}
		bool leapYear = isLeapYear(year, ctx);
		days = daysFromBaseYear(year, ctx) + daysInYear(leapYear, month, ctx);
		bool useDate = _isSet->get(DATE);
		if(useDate && (lastDateFieldSet == DAY_OF_WEEK || lastDateFieldSet == WEEK_OF_MONTH || lastDateFieldSet == DAY_OF_WEEK_IN_MONTH))
		{
			useDate = !(_isSet->get(DAY_OF_WEEK) && weekMonthSet);
		}
		if(useDate)
		{
			if(!isLenient(ctx) && (fields->get(DATE) < 1 || fields->get(DATE) > daysInMonth(leapYear, month, ctx)))
			{
				throw (new(ctx) IllegalArgumentException(ctx));
			}
			days += fields->get(DATE) - 1;
		}
				else 
		{
			int dayOfWeek = 0;
			if(_isSet->get(DAY_OF_WEEK))
			{
				dayOfWeek = fields->get(DAY_OF_WEEK) - 1;
			}
						else 
			{
				dayOfWeek = getFirstDayOfWeek(ctx) - 1;
			}
			if(_isSet->get(WEEK_OF_MONTH) && lastDateFieldSet != DAY_OF_WEEK_IN_MONTH)
			{
				int skew = mod7(days - 3 - (getFirstDayOfWeek(ctx) - 1), ctx);
				days += (fields->get(WEEK_OF_MONTH) - 1) * 7 + mod7((long long)skew + dayOfWeek - (days - 3), ctx) - skew;
			}
						else 
			{
				if(_isSet->get(DAY_OF_WEEK_IN_MONTH))
				{
					if(fields->get(DAY_OF_WEEK_IN_MONTH) >= 0)
					{
						days += mod7((long long)dayOfWeek - (days - 3), ctx) + (fields->get(DAY_OF_WEEK_IN_MONTH) - 1) * 7;
					}
										else 
					{
						days += daysInMonth(leapYear, month, ctx) + mod7((long long)dayOfWeek - (days + daysInMonth(leapYear, month, ctx) - 3), ctx) + fields->get(DAY_OF_WEEK_IN_MONTH) * 7;
					}
				}
								else 
				{
					if(_isSet->get(DAY_OF_WEEK))
					{
						int skew = mod7(days - 3 - (getFirstDayOfWeek(ctx) - 1), ctx);
						days += mod7((long long)mod7((long long)skew + dayOfWeek - (days - 3), ctx) - skew, ctx);
					}
				}
			}
		}
	}
		else 
	{
		bool useWeekYear = _isSet->get(WEEK_OF_YEAR) && lastDateFieldSet != DAY_OF_YEAR;
		if(useWeekYear && _isSet->get(DAY_OF_YEAR))
		{
			useWeekYear = _isSet->get(DAY_OF_WEEK);
		}
		days = daysFromBaseYear(year, ctx);
		if(useWeekYear)
		{
			int dayOfWeek = 0;
			if(_isSet->get(DAY_OF_WEEK))
			{
				dayOfWeek = fields->get(DAY_OF_WEEK) - 1;
			}
						else 
			{
				dayOfWeek = getFirstDayOfWeek(ctx) - 1;
			}
			int skew = mod7(days - 3 - (getFirstDayOfWeek(ctx) - 1), ctx);
			days += (fields->get(WEEK_OF_YEAR) - 1) * 7 + mod7((long long)skew + dayOfWeek - (days - 3), ctx) - skew;
			if(7 - skew < getMinimalDaysInFirstWeek(ctx))
			{
				days += 7;
			}
		}
				else 
		{
			if(_isSet->get(DAY_OF_YEAR))
			{
				if(!isLenient(ctx) && (fields->get(DAY_OF_YEAR) < 1 || fields->get(DAY_OF_YEAR) > (365 + (isLeapYear(year, ctx) ? 1 : 0))))
				{
					throw (new(ctx) IllegalArgumentException(ctx));
				}
				days += fields->get(DAY_OF_YEAR) - 1;
			}
						else 
			{
				if(_isSet->get(DAY_OF_WEEK))
				{
					days += mod7((long long)fields->get(DAY_OF_WEEK) - 1 - (days - 3), ctx);
				}
			}
		}
	}
	lastDateFieldSet = 0;
	timeVal += days * 86400000;
	if(year == changeYear && timeVal >= gregorianCutover + julianError(ctx) * 86400000L)
	{
		timeVal -= julianError(ctx) * 86400000L;
	}
	long long timeValWithoutDST = timeVal - getOffset(timeVal, ctx) + getTimeZone(ctx)->getRawOffset(ctx);
	timeVal -= getOffset(timeValWithoutDST, ctx);
	this->time = timeVal;
	if(timeValWithoutDST != timeVal)
	{
		computeFields(ctx);
		areFieldsSet = true;
	}
}
int GregorianCalendar::getOffset(long long localTime, ThreadContext* ctx) throw() 
{
	TimeZone* timeZone = getTimeZone(ctx);
	if(!timeZone->useDaylightTime(ctx))
	{
		return timeZone->getRawOffset(ctx);
	}
	long long dayCount = localTime / 86400000;
	int millis = ((int)(localTime % 86400000));
	if(millis < 0)
	{
		millis += 86400000;
		dayCount -- ;
	}
	int year = 1970;
	long long days = dayCount;
	if(localTime < gregorianCutover)
	{
		days -= julianSkew;
	}
	int approxYears = 0;
	approxYears = ((int)(days / 365));
	while((approxYears) != 0)
	{
		year = year + approxYears;
		days = dayCount - daysFromBaseYear(year, ctx);
	}
	if(days < (long long)0)
	{
		year = year - 1;
		days = days + 365 + (isLeapYear(year, ctx) ? 1 : 0);
		if(year == changeYear && localTime < gregorianCutover)
		{
			days -= julianError(ctx);
		}
	}
	if(year <= 0)
	{
		return timeZone->getRawOffset(ctx);
	}
	int dayOfYear = ((int)days) + 1;
	int month = dayOfYear / 32;
	bool leapYear = isLeapYear(year, ctx);
	int date = dayOfYear - daysInYear(leapYear, month, ctx);
	if(date > daysInMonth(leapYear, month, ctx))
	{
		date -= daysInMonth(leapYear, month, ctx);
		month ++ ;
	}
	int dayOfWeek = mod7(dayCount - 3, ctx) + 1;
	int offset = timeZone->getOffset(AD, year, month, date, dayOfWeek, millis, ctx);
	return offset;
}
void GregorianCalendar::fullFieldsCalc(long long timeVal, int millis, int zoneOffset, ThreadContext* ctx) throw() 
{
	long long days = timeVal / 86400000;
	if(millis < 0)
	{
		millis += 86400000;
		days -- ;
	}
	millis += zoneOffset;
	while(millis < 0)
	{
		millis += 86400000;
		days -- ;
	}
	while(millis >= 86400000)
	{
		millis -= 86400000;
		days ++ ;
	}
	int dayOfYear = computeYearAndDay(days, timeVal + zoneOffset, ctx);
	fields->set(dayOfYear,DAY_OF_YEAR, ctx);
	if(fields->get(YEAR) == changeYear && gregorianCutover <= timeVal + zoneOffset)
	{
		dayOfYear += currentYearSkew;
	}
	int month = dayOfYear / 32;
	bool leapYear = isLeapYear(fields->get(YEAR), ctx);
	int date = dayOfYear - daysInYear(leapYear, month, ctx);
	if(date > daysInMonth(leapYear, month, ctx))
	{
		date -= daysInMonth(leapYear, month, ctx);
		month ++ ;
	}
	fields->set(mod7(days - 3, ctx) + 1,DAY_OF_WEEK, ctx);
	int dstOffset = fields->get(YEAR) <= 0 ? 0 : getTimeZone(ctx)->getOffset(AD, fields->get(YEAR), month, date, fields->get(DAY_OF_WEEK), millis, ctx);
	if(fields->get(YEAR) > 0)
	{
		dstOffset -= zoneOffset;
	}
	fields->set(dstOffset,DST_OFFSET, ctx);
	if(dstOffset != 0)
	{
		long long oldDays = days;
		millis += dstOffset;
		if(millis < 0)
		{
			millis += 86400000;
			days -- ;
		}
				else 
		{
			if(millis >= 86400000)
			{
				millis -= 86400000;
				days ++ ;
			}
		}
		if(oldDays != days)
		{
			dayOfYear = computeYearAndDay(days, timeVal - zoneOffset + dstOffset, ctx);
			fields->set(dayOfYear,DAY_OF_YEAR, ctx);
			if(fields->get(YEAR) == changeYear && gregorianCutover <= timeVal - zoneOffset + dstOffset)
			{
				dayOfYear += currentYearSkew;
			}
			month = dayOfYear / 32;
			leapYear = isLeapYear(fields->get(YEAR), ctx);
			date = dayOfYear - daysInYear(leapYear, month, ctx);
			if(date > daysInMonth(leapYear, month, ctx))
			{
				date -= daysInMonth(leapYear, month, ctx);
				month ++ ;
			}
			fields->set(mod7(days - 3, ctx) + 1,DAY_OF_WEEK, ctx);
		}
	}
	fields->set((millis % 1000),MILLISECOND, ctx);
	millis /= 1000;
	fields->set((millis % 60),SECOND, ctx);
	millis /= 60;
	fields->set((millis % 60),MINUTE, ctx);
	millis /= 60;
	fields->set((millis % 24),HOUR_OF_DAY, ctx);
	fields->set(fields->get(HOUR_OF_DAY) > 11 ? 1 : 0,AM_PM, ctx);
	fields->set(fields->get(HOUR_OF_DAY) % 12,HOUR, ctx);
	if(fields->get(YEAR) <= 0)
	{
		fields->set(BC,ERA, ctx);
		fields->set(-fields->get(YEAR) + 1,YEAR, ctx);
	}
		else 
	{
		fields->set(AD,ERA, ctx);
	}
	fields->set(month,MONTH, ctx);
	fields->set(date,DATE, ctx);
	fields->set((date - 1) / 7 + 1,DAY_OF_WEEK_IN_MONTH, ctx);
	fields->set((date - 1 + mod7(days - date - 2 - (getFirstDayOfWeek(ctx) - 1), ctx)) / 7 + 1,WEEK_OF_MONTH, ctx);
	int daysFromStart = mod7(days - 3 - (fields->get(DAY_OF_YEAR) - 1) - (getFirstDayOfWeek(ctx) - 1), ctx);
	int week = (fields->get(DAY_OF_YEAR) - 1 + daysFromStart) / 7 + (7 - daysFromStart >= getMinimalDaysInFirstWeek(ctx) ? 1 : 0);
	if(week == 0)
	{
		fields->set(7 - mod7((long long)daysFromStart - (isLeapYear(fields->get(YEAR) - 1, ctx) ? 2 : 1), ctx) >= getMinimalDaysInFirstWeek(ctx) ? 53 : 52,WEEK_OF_YEAR, ctx);
	}
		else 
	{
		if(fields->get(DAY_OF_YEAR) >= (leapYear ? 367 : 366) - mod7((long long)daysFromStart + (leapYear ? 2 : 1), ctx))
		{
			fields->set(7 - mod7((long long)daysFromStart + (leapYear ? 2 : 1), ctx) >= getMinimalDaysInFirstWeek(ctx) ? 1 : week,WEEK_OF_YEAR, ctx);
		}
				else 
		{
			fields->set(week,WEEK_OF_YEAR, ctx);
		}
	}
}
void GregorianCalendar::cachedFieldsCheckAndGet(long long timeVal, long long newTimeMillis, long long newTimeMillisAdjusted, int millis, int zoneOffset, ThreadContext* ctx) throw() 
{
	int dstOffset = fields->get(DST_OFFSET);
	if(!isCached || newTimeMillis >= nextMidnightMillis || newTimeMillis <= lastMidnightMillis || cachedFields->get(4) != zoneOffset || (dstOffset == 0 && (newTimeMillisAdjusted >= nextMidnightMillis)) || (dstOffset != 0 && (newTimeMillisAdjusted <= lastMidnightMillis)))
	{
		fullFieldsCalc(timeVal, millis, zoneOffset, ctx);
		isCached = false;
	}
		else 
	{
		fields->set(cachedFields->get(0),YEAR, ctx);
		fields->set(cachedFields->get(1),MONTH, ctx);
		fields->set(cachedFields->get(2),DATE, ctx);
		fields->set(cachedFields->get(3),DAY_OF_WEEK, ctx);
		fields->set(cachedFields->get(5),ERA, ctx);
		fields->set(cachedFields->get(6),WEEK_OF_YEAR, ctx);
		fields->set(cachedFields->get(7),WEEK_OF_MONTH, ctx);
		fields->set(cachedFields->get(8),DAY_OF_YEAR, ctx);
		fields->set(cachedFields->get(9),DAY_OF_WEEK_IN_MONTH, ctx);
	}
}
int GregorianCalendar::computeYearAndDay(long long dayCount, long long localTime, ThreadContext* ctx) throw() 
{
	int year = 1970;
	long long days = dayCount;
	if(localTime < gregorianCutover)
	{
		days -= julianSkew;
	}
	int approxYears = 0;
	approxYears = ((int)(days / 365));
	while((approxYears) != 0)
	{
		year = year + approxYears;
		days = dayCount - daysFromBaseYear(year, ctx);
	}
	if(days < (long long)0)
	{
		year = year - 1;
		days = days + daysInYear(year, ctx);
	}
	fields->set(year,YEAR, ctx);
	return ((int)days) + 1;
}
long long GregorianCalendar::daysFromBaseYear(int iyear, ThreadContext* ctx) throw() 
{
	long long year = iyear;
	if(year >= (long long)1970)
	{
		long long days = (year - 1970) * 365 + ((year - 1969) / 4);
		if(year > (long long)changeYear)
		{
			days -= ((year - 1901) / 100) - ((year - 1601) / 400);
		}
				else 
		{
			if(year == (long long)changeYear)
			{
				days += currentYearSkew;
			}
						else 
			{
				if(year == (long long)changeYear - 1)
				{
					days += lastYearSkew;
				}
								else 
				{
					days += julianSkew;
				}
			}
		}
		return days;
	}
		else 
	{
		if(year <= (long long)changeYear)
		{
			return (year - 1970) * 365 + ((year - 1972) / 4) + julianSkew;
		}
	}
	return (year - 1970) * 365 + ((year - 1972) / 4) - ((year - 2000) / 100) + ((year - 2000) / 400);
}
int GregorianCalendar::daysInMonth(ThreadContext* ctx) throw() 
{
	return daysInMonth(isLeapYear(fields->get(YEAR), ctx), fields->get(MONTH), ctx);
}
int GregorianCalendar::daysInMonth(bool leapYear, int month, ThreadContext* ctx) throw() 
{
	if(leapYear && month == FEBRUARY)
	{
		return DaysInMonth->get(month) + 1;
	}
	return DaysInMonth->get(month);
}
int GregorianCalendar::daysInYear(int year, ThreadContext* ctx) throw() 
{
	int daysInYear = isLeapYear(year, ctx) ? 366 : 365;
	if(year == changeYear)
	{
		daysInYear -= currentYearSkew;
	}
	if(year == changeYear - 1)
	{
		daysInYear -= lastYearSkew;
	}
	return daysInYear;
}
int GregorianCalendar::daysInYear(bool leapYear, int month, ThreadContext* ctx) throw() 
{
	if(leapYear && month > FEBRUARY)
	{
		return DaysInYear->get(month) + 1;
	}
	return DaysInYear->get(month);
}
int GregorianCalendar::julianError(ThreadContext* ctx) throw() 
{
	return changeYear / 100 - changeYear / 400 - 2;
}
int GregorianCalendar::_mod(int value, int mod, ThreadContext* ctx) throw() 
{
	int rem = value % mod;
	if(value < 0 && rem < 0)
	{
		return rem + mod;
	}
	return rem;
}
int GregorianCalendar::mod7(long long num1, ThreadContext* ctx) throw() 
{
	int rem = ((int)(num1 % 7));
	if(num1 < (long long)0 && rem < 0)
	{
		return rem + 7;
	}
	return rem;
}
void GregorianCalendar::include(SimpleTimeZone* arg0, ThreadContext* ctx) throw() 
{
}
void GregorianCalendar::__cleanUp(ThreadContext* ctx){
}
}}

