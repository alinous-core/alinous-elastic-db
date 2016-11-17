#include "includes.h"


namespace java {namespace util {





constexpr const int SimpleTimeZone::DOM_MODE;
constexpr const int SimpleTimeZone::DOW_IN_MONTH_MODE;
constexpr const int SimpleTimeZone::DOW_GE_DOM_MODE;
constexpr const int SimpleTimeZone::DOW_LE_DOM_MODE;
constexpr const int SimpleTimeZone::UTC_TIME;
constexpr const int SimpleTimeZone::STANDARD_TIME;
constexpr const int SimpleTimeZone::WALL_TIME;
bool SimpleTimeZone::__init_done = __init_static_variables();
bool SimpleTimeZone::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SimpleTimeZone", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SimpleTimeZone::SimpleTimeZone(int offset, String* name, ThreadContext* ctx) throw()  : IObject(ctx), TimeZone(ctx), rawOffset(0), startYear(0), startMonth(0), startDay(0), startDayOfWeek(0), startTime(0), endMonth(0), endDay(0), endDayOfWeek(0), endTime(0), startMode(0), endMode(0), useDaylight(0), daylightSavings(nullptr), dstSavings(3600000)
{
	setID(name, ctx);
	rawOffset = offset;
	useDaylight = false;
}
void SimpleTimeZone::__construct_impl(int offset, String* name, ThreadContext* ctx) throw() 
{
	setID(name, ctx);
	rawOffset = offset;
	useDaylight = false;
}
 SimpleTimeZone::SimpleTimeZone(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, ThreadContext* ctx) throw()  : IObject(ctx), TimeZone(ctx), rawOffset(0), startYear(0), startMonth(0), startDay(0), startDayOfWeek(0), startTime(0), endMonth(0), endDay(0), endDayOfWeek(0), endTime(0), startMode(0), endMode(0), useDaylight(0), daylightSavings(nullptr), dstSavings(3600000)
{
	__construct_impl(offset, name, startMonth, startDay, startDayOfWeek, startTime, endMonth, endDay, endDayOfWeek, endTime, 3600000, ctx);
}
void SimpleTimeZone::__construct_impl(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, ThreadContext* ctx) throw() 
{
	__construct_impl(offset, name, startMonth, startDay, startDayOfWeek, startTime, endMonth, endDay, endDayOfWeek, endTime, 3600000, ctx);
}
 SimpleTimeZone::SimpleTimeZone(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, int daylightSavings, ThreadContext* ctx) throw()  : IObject(ctx), TimeZone(ctx), rawOffset(0), startYear(0), startMonth(0), startDay(0), startDayOfWeek(0), startTime(0), endMonth(0), endDay(0), endDayOfWeek(0), endTime(0), startMode(0), endMode(0), useDaylight(0), daylightSavings(nullptr), dstSavings(3600000)
{
	setID(name, ctx);
	rawOffset = offset;
	if(daylightSavings <= 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	dstSavings = daylightSavings;
	setStartRule(startMonth, startDay, startDayOfWeek, startTime, ctx);
	setEndRule(endMonth, endDay, endDayOfWeek, endTime, ctx);
	useDaylight = false;
}
void SimpleTimeZone::__construct_impl(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, int daylightSavings, ThreadContext* ctx) throw() 
{
	setID(name, ctx);
	rawOffset = offset;
	if(daylightSavings <= 0)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	dstSavings = daylightSavings;
	setStartRule(startMonth, startDay, startDayOfWeek, startTime, ctx);
	setEndRule(endMonth, endDay, endDayOfWeek, endTime, ctx);
	useDaylight = false;
}
 SimpleTimeZone::SimpleTimeZone(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int startTimeMode, int endMonth, int endDay, int endDayOfWeek, int endTime, int endTimeMode, int daylightSavings, ThreadContext* ctx) throw()  : IObject(ctx), TimeZone(ctx), rawOffset(0), startYear(0), startMonth(0), startDay(0), startDayOfWeek(0), startTime(0), endMonth(0), endDay(0), endDayOfWeek(0), endTime(0), startMode(0), endMode(0), useDaylight(0), daylightSavings(nullptr), dstSavings(3600000)
{
	__construct_impl(offset, name, startMonth, startDay, startDayOfWeek, startTime, endMonth, endDay, endDayOfWeek, endTime, daylightSavings, ctx);
	startMode = startTimeMode;
	endMode = endTimeMode;
}
void SimpleTimeZone::__construct_impl(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int startTimeMode, int endMonth, int endDay, int endDayOfWeek, int endTime, int endTimeMode, int daylightSavings, ThreadContext* ctx) throw() 
{
	__construct_impl(offset, name, startMonth, startDay, startDayOfWeek, startTime, endMonth, endDay, endDayOfWeek, endTime, daylightSavings, ctx);
	startMode = startTimeMode;
	endMode = endTimeMode;
}
 SimpleTimeZone::~SimpleTimeZone() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SimpleTimeZone::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SimpleTimeZone", L"~SimpleTimeZone");
	__e_obj1.add(this->daylightSavings, this);
	daylightSavings = nullptr;
	if(!prepare){
		return;
	}
	TimeZone::__releaseRegerences(true, ctx);
}
IObject* SimpleTimeZone::clone(ThreadContext* ctx) throw() 
{
	SimpleTimeZone* zone = dynamic_cast<SimpleTimeZone*>(TimeZone::clone(ctx));
	if(daylightSavings != nullptr)
	{
		__GC_MV(zone, &(zone->daylightSavings), dynamic_cast<GregorianCalendar*>(daylightSavings->clone(ctx)), GregorianCalendar);
	}
	return zone;
}
bool SimpleTimeZone::equals(IObject* object, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<SimpleTimeZone*>(object) != 0)))
	{
		return false;
	}
	SimpleTimeZone* tz = dynamic_cast<SimpleTimeZone*>(object);
	return getID(ctx)->equals(tz->getID(ctx), ctx) && rawOffset == tz->rawOffset && useDaylight == tz->useDaylight && (!useDaylight || (startYear == tz->startYear && startMonth == tz->startMonth && startDay == tz->startDay && startMode == tz->startMode && startDayOfWeek == tz->startDayOfWeek && startTime == tz->startTime && endMonth == tz->endMonth && endDay == tz->endDay && endDayOfWeek == tz->endDayOfWeek && endTime == tz->endTime && endMode == tz->endMode && dstSavings == tz->dstSavings));
}
int SimpleTimeZone::getDSTSavings(ThreadContext* ctx) throw() 
{
	if(!useDaylight)
	{
		return 0;
	}
	return dstSavings;
}
int SimpleTimeZone::getOffset(int era, int year, int month, int day, int dayOfWeek, int time, ThreadContext* ctx) throw() 
{
	if(era != GregorianCalendar::BC && era != GregorianCalendar::AD)
	{
		throw (new(ctx) IllegalArgumentException(ConstStr::getCNST_STR_4(), ctx));
	}
	checkRange(month, dayOfWeek, time, ctx);
	if(month != Calendar::FEBRUARY || day != 29 || !isLeapYear(year, ctx))
	{
		checkDay(month, day, ctx);
	}
	return this->rawOffset;
}
int SimpleTimeZone::getOffset(long long time, ThreadContext* ctx) throw() 
{
	return this->rawOffset;
}
int SimpleTimeZone::getRawOffset(ThreadContext* ctx) throw() 
{
	return rawOffset;
}
int SimpleTimeZone::hashCode(ThreadContext* ctx) throw() 
{
	int hashCode = getID(ctx)->hashCode(ctx) + rawOffset;
	if(useDaylight)
	{
		hashCode += startYear + startMonth + startDay + startDayOfWeek + startTime + startMode + endMonth + endDay + endDayOfWeek + endTime + endMode + dstSavings;
	}
	return hashCode;
}
bool SimpleTimeZone::hasSameRules(TimeZone* zone, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<SimpleTimeZone*>(zone) != 0)))
	{
		return false;
	}
	SimpleTimeZone* tz = static_cast<SimpleTimeZone*>(zone);
	if(useDaylight != tz->useDaylight)
	{
		return false;
	}
	if(!useDaylight)
	{
		return rawOffset == tz->rawOffset;
	}
	return rawOffset == tz->rawOffset && dstSavings == tz->dstSavings && startYear == tz->startYear && startMonth == tz->startMonth && startDay == tz->startDay && startMode == tz->startMode && startDayOfWeek == tz->startDayOfWeek && startTime == tz->startTime && endMonth == tz->endMonth && endDay == tz->endDay && endDayOfWeek == tz->endDayOfWeek && endTime == tz->endTime && endMode == tz->endMode;
}
bool SimpleTimeZone::inDaylightTime(Date* time, ThreadContext* ctx) throw() 
{
	return this->useDaylight;
}
bool SimpleTimeZone::inDaylightTime(InternalDate* time, ThreadContext* ctx) throw() 
{
	return this->useDaylight;
}
void SimpleTimeZone::setDSTSavings(int milliseconds, ThreadContext* ctx) throw() 
{
	if(milliseconds > 0)
	{
		dstSavings = milliseconds;
	}
		else 
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
}
void SimpleTimeZone::setEndRule(int month, int dayOfMonth, int time, ThreadContext* ctx) throw() 
{
	endMonth = month;
	endDay = dayOfMonth;
	endDayOfWeek = 0;
	endTime = time;
	setEndMode(ctx);
}
void SimpleTimeZone::setEndRule(int month, int day, int dayOfWeek, int time, ThreadContext* ctx) throw() 
{
	endMonth = month;
	endDay = day;
	endDayOfWeek = dayOfWeek;
	endTime = time;
	setEndMode(ctx);
}
void SimpleTimeZone::setEndRule(int month, int day, int dayOfWeek, int time, bool after, ThreadContext* ctx) throw() 
{
	endMonth = month;
	endDay = after ? day : -day;
	endDayOfWeek = -dayOfWeek;
	endTime = time;
	setEndMode(ctx);
}
void SimpleTimeZone::setRawOffset(int offset, ThreadContext* ctx) throw() 
{
	rawOffset = offset;
}
void SimpleTimeZone::setStartRule(int month, int dayOfMonth, int time, ThreadContext* ctx) throw() 
{
	startMonth = month;
	startDay = dayOfMonth;
	startDayOfWeek = 0;
	startTime = time;
	setStartMode(ctx);
}
void SimpleTimeZone::setStartRule(int month, int day, int dayOfWeek, int time, ThreadContext* ctx) throw() 
{
	startMonth = month;
	startDay = day;
	startDayOfWeek = dayOfWeek;
	startTime = time;
	setStartMode(ctx);
}
void SimpleTimeZone::setStartRule(int month, int day, int dayOfWeek, int time, bool after, ThreadContext* ctx) throw() 
{
	startMonth = month;
	startDay = after ? day : -day;
	startDayOfWeek = -dayOfWeek;
	startTime = time;
	setStartMode(ctx);
}
void SimpleTimeZone::setStartYear(int year, ThreadContext* ctx) throw() 
{
	startYear = year;
	useDaylight = true;
}
String* SimpleTimeZone::toString(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_548()->clone(ctx)->append(ConstStr::getCNST_STR_549(), ctx)->append(getID(ctx), ctx)->append(ConstStr::getCNST_STR_550(), ctx)->append(rawOffset, ctx)->append(ConstStr::getCNST_STR_551(), ctx)->append(dstSavings, ctx)->append(ConstStr::getCNST_STR_552(), ctx)->append(useDaylight, ctx)->append(ConstStr::getCNST_STR_553(), ctx)->append(startYear, ctx)->append(ConstStr::getCNST_STR_554(), ctx)->append(startMode, ctx)->append(ConstStr::getCNST_STR_555(), ctx)->append(startMonth, ctx)->append(ConstStr::getCNST_STR_556(), ctx)->append(startDay, ctx)->append(ConstStr::getCNST_STR_557(), ctx)->append((useDaylight && (startMode != DOM_MODE) ? startDayOfWeek + 1 : 0), ctx)->append(ConstStr::getCNST_STR_558(), ctx)->append(startTime, ctx)->append(ConstStr::getCNST_STR_559(), ctx)->append(endMode, ctx)->append(ConstStr::getCNST_STR_560(), ctx)->append(endMonth, ctx)->append(ConstStr::getCNST_STR_561(), ctx)->append(endDay, ctx)->append(ConstStr::getCNST_STR_562(), ctx)->append((useDaylight && (endMode != DOM_MODE) ? endDayOfWeek + 1 : 0), ctx)->append(ConstStr::getCNST_STR_563(), ctx)->append(endTime, ctx)->append(ConstStr::getCNST_STR_564(), ctx);
}
bool SimpleTimeZone::useDaylightTime(ThreadContext* ctx) throw() 
{
	return useDaylight;
}
bool SimpleTimeZone::isLeapYear(int year, ThreadContext* ctx) throw() 
{
	if(year > 1582)
	{
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}
	return year % 4 == 0;
}
void SimpleTimeZone::checkRange(int month, int dayOfWeek, int time, ThreadContext* ctx) throw() 
{
	if(month < Calendar::JANUARY || month > Calendar::DECEMBER)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	if(dayOfWeek < Calendar::SUNDAY || dayOfWeek > Calendar::SATURDAY)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
	if(time < 0 || time >= 24 * 3600000)
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
}
void SimpleTimeZone::checkDay(int month, int day, ThreadContext* ctx) throw() 
{
	if(day <= 0 || day > (int)GregorianCalendar::DaysInMonth->get(month))
	{
		throw (new(ctx) IllegalArgumentException(ctx));
	}
}
void SimpleTimeZone::setEndMode(ThreadContext* ctx) throw() 
{
	if(endDayOfWeek == 0)
	{
		endMode = DOM_MODE;
	}
		else 
	{
		if(endDayOfWeek < 0)
		{
			endDayOfWeek = -endDayOfWeek;
			if(endDay < 0)
			{
				endDay = -endDay;
				endMode = DOW_LE_DOM_MODE;
			}
						else 
			{
				endMode = DOW_GE_DOM_MODE;
			}
		}
				else 
		{
			endMode = DOW_IN_MONTH_MODE;
		}
	}
	useDaylight = startDay != 0 && endDay != 0;
	if(endDay != 0)
	{
		checkRange(endMonth, endMode == DOM_MODE ? 1 : endDayOfWeek, endTime, ctx);
		if(endMode != DOW_IN_MONTH_MODE)
		{
			checkDay(endMonth, endDay, ctx);
		}
				else 
		{
			if(endDay < -5 || endDay > 5)
			{
				throw (new(ctx) IllegalArgumentException(ctx));
			}
		}
	}
	if(endMode != DOM_MODE)
	{
		endDayOfWeek -- ;
	}
}
void SimpleTimeZone::setStartMode(ThreadContext* ctx) throw() 
{
	if(startDayOfWeek == 0)
	{
		startMode = DOM_MODE;
	}
		else 
	{
		if(startDayOfWeek < 0)
		{
			startDayOfWeek = -startDayOfWeek;
			if(startDay < 0)
			{
				startDay = -startDay;
				startMode = DOW_LE_DOM_MODE;
			}
						else 
			{
				startMode = DOW_GE_DOM_MODE;
			}
		}
				else 
		{
			startMode = DOW_IN_MONTH_MODE;
		}
	}
	useDaylight = startDay != 0 && endDay != 0;
	if(startDay != 0)
	{
		checkRange(startMonth, startMode == DOM_MODE ? 1 : startDayOfWeek, startTime, ctx);
		if(startMode != DOW_IN_MONTH_MODE)
		{
			checkDay(startMonth, startDay, ctx);
		}
				else 
		{
			if(startDay < -5 || startDay > 5)
			{
				throw (new(ctx) IllegalArgumentException(ctx));
			}
		}
	}
	if(startMode != DOM_MODE)
	{
		startDayOfWeek -- ;
	}
}
}}

