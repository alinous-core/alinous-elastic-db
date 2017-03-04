#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/TimeZone.h"
#include "java.util/SimpleTimeZone.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Date.h"
#include "java.util/BitSet.h"
#include "java.util/TimeZones.h"
#include "java.util/Random.h"
#include "java.util/Arrays.h"

namespace java {namespace util {





constexpr const int Calendar::JANUARY;
constexpr const int Calendar::FEBRUARY;
constexpr const int Calendar::MARCH;
constexpr const int Calendar::APRIL;
constexpr const int Calendar::MAY;
constexpr const int Calendar::JUNE;
constexpr const int Calendar::JULY;
constexpr const int Calendar::AUGUST;
constexpr const int Calendar::SEPTEMBER;
constexpr const int Calendar::OCTOBER;
constexpr const int Calendar::NOVEMBER;
constexpr const int Calendar::DECEMBER;
constexpr const int Calendar::UNDECIMBER;
constexpr const int Calendar::SUNDAY;
constexpr const int Calendar::MONDAY;
constexpr const int Calendar::TUESDAY;
constexpr const int Calendar::WEDNESDAY;
constexpr const int Calendar::THURSDAY;
constexpr const int Calendar::FRIDAY;
constexpr const int Calendar::SATURDAY;
constexpr const int Calendar::ERA;
constexpr const int Calendar::YEAR;
constexpr const int Calendar::MONTH;
constexpr const int Calendar::WEEK_OF_YEAR;
constexpr const int Calendar::WEEK_OF_MONTH;
constexpr const int Calendar::DATE;
constexpr const int Calendar::DAY_OF_MONTH;
constexpr const int Calendar::DAY_OF_YEAR;
constexpr const int Calendar::DAY_OF_WEEK;
constexpr const int Calendar::DAY_OF_WEEK_IN_MONTH;
constexpr const int Calendar::AM_PM;
constexpr const int Calendar::HOUR;
constexpr const int Calendar::HOUR_OF_DAY;
constexpr const int Calendar::MINUTE;
constexpr const int Calendar::SECOND;
constexpr const int Calendar::MILLISECOND;
constexpr const int Calendar::ZONE_OFFSET;
constexpr const int Calendar::DST_OFFSET;
constexpr const int Calendar::FIELD_COUNT;
constexpr const int Calendar::AM;
constexpr const int Calendar::PM;
IArrayObject<String>* Calendar::fieldNames = nullptr;
bool Calendar::__init_done = __init_static_variables();
bool Calendar::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Calendar", L"__init_static_variables");
		__GC_MV(nullptr, &(fieldNames), (new ArrayObject<String>({ConstStr::getCNST_STR_531(), ConstStr::getCNST_STR_532(), ConstStr::getCNST_STR_533(), ConstStr::getCNST_STR_534(), ConstStr::getCNST_STR_535(), ConstStr::getCNST_STR_536(), ConstStr::getCNST_STR_537(), ConstStr::getCNST_STR_538(), ConstStr::getCNST_STR_539(), ConstStr::getCNST_STR_540(), ConstStr::getCNST_STR_541(), ConstStr::getCNST_STR_542(), ConstStr::getCNST_STR_543(), ConstStr::getCNST_STR_544(), ConstStr::getCNST_STR_545(), ConstStr::getCNST_STR_546(), ConstStr::getCNST_STR_547()}, ctx)), IArrayObject<String>);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Calendar::Calendar(ThreadContext* ctx) throw()  : IObject(ctx), _isSet(nullptr), areFieldsSet(0), fields(nullptr), isTimeSet(0), time(0), lastTimeFieldSet(0), lastDateFieldSet(0), zone(nullptr), lenient(0), firstDayOfWeek(0), minimalDaysInFirstWeek(0)
{
	__construct_impl(TimeZone::getDefault(ctx), Locale::getDefault(ctx), ctx);
}
void Calendar::__construct_impl(ThreadContext* ctx) throw() 
{
	__construct_impl(TimeZone::getDefault(ctx), Locale::getDefault(ctx), ctx);
}
 Calendar::Calendar(TimeZone* timezone, ThreadContext* ctx) throw()  : IObject(ctx), _isSet(nullptr), areFieldsSet(0), fields(nullptr), isTimeSet(0), time(0), lastTimeFieldSet(0), lastDateFieldSet(0), zone(nullptr), lenient(0), firstDayOfWeek(0), minimalDaysInFirstWeek(0)
{
	__GC_MV(this, &(fields), ArrayAllocatorPrimitive<int>::allocatep(ctx, FIELD_COUNT), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(_isSet), ArrayAllocatorPrimitive<bool>::allocatep(ctx, FIELD_COUNT), IArrayObjectPrimitive<bool>);
	areFieldsSet = isTimeSet = false;
	setLenient(true, ctx);
	setTimeZone(timezone, ctx);
}
void Calendar::__construct_impl(TimeZone* timezone, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(fields), ArrayAllocatorPrimitive<int>::allocatep(ctx, FIELD_COUNT), IArrayObjectPrimitive<int>);
	__GC_MV(this, &(_isSet), ArrayAllocatorPrimitive<bool>::allocatep(ctx, FIELD_COUNT), IArrayObjectPrimitive<bool>);
	areFieldsSet = isTimeSet = false;
	setLenient(true, ctx);
	setTimeZone(timezone, ctx);
}
 Calendar::Calendar(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw()  : IObject(ctx), _isSet(nullptr), areFieldsSet(0), fields(nullptr), isTimeSet(0), time(0), lastTimeFieldSet(0), lastDateFieldSet(0), zone(nullptr), lenient(0), firstDayOfWeek(0), minimalDaysInFirstWeek(0)
{
	__construct_impl(timezone, ctx);
	setFirstDayOfWeek(firstDays(locale->getLanguage(ctx), locale->getCountry(ctx), ctx), ctx);
	setMinimalDaysInFirstWeek(minumalDays(locale->getLanguage(ctx), locale->getCountry(ctx), ctx), ctx);
}
void Calendar::__construct_impl(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() 
{
	__construct_impl(timezone, ctx);
	setFirstDayOfWeek(firstDays(locale->getLanguage(ctx), locale->getCountry(ctx), ctx), ctx);
	setMinimalDaysInFirstWeek(minumalDays(locale->getLanguage(ctx), locale->getCountry(ctx), ctx), ctx);
}
 Calendar::~Calendar() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Calendar::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Calendar", L"~Calendar");
	__e_obj1.add(this->_isSet, this);
	_isSet = nullptr;
	__e_obj1.add(this->fields, this);
	fields = nullptr;
	__e_obj1.add(this->zone, this);
	zone = nullptr;
	if(!prepare){
		return;
	}
}
bool Calendar::after(IObject* calendar, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<Calendar*>(calendar) != 0)))
	{
		return false;
	}
	return getTimeInMillis(ctx) > (dynamic_cast<Calendar*>(calendar))->getTimeInMillis(ctx);
}
bool Calendar::before(IObject* calendar, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<Calendar*>(calendar) != 0)))
	{
		return false;
	}
	return getTimeInMillis(ctx) < (dynamic_cast<Calendar*>(calendar))->getTimeInMillis(ctx);
}
void Calendar::clear(ThreadContext* ctx) throw() 
{
	for(int i = 0; i < FIELD_COUNT; i ++ )
	{
		fields->set(0,i, ctx);
		_isSet->set(false,i, ctx);
	}
	areFieldsSet = isTimeSet = false;
}
void Calendar::clear(int field, ThreadContext* ctx) throw() 
{
	fields->set(0,field, ctx);
	_isSet->set(false,field, ctx);
	areFieldsSet = isTimeSet = false;
}
bool Calendar::equals(IObject* object, ThreadContext* ctx) throw() 
{
	if(this == object)
	{
		return true;
	}
	if(!((dynamic_cast<Calendar*>(object) != 0)))
	{
		return false;
	}
	Calendar* cal = dynamic_cast<Calendar*>(object);
	return getTimeInMillis(ctx) == cal->getTimeInMillis(ctx) && isLenient(ctx) == cal->isLenient(ctx) && getFirstDayOfWeek(ctx) == cal->getFirstDayOfWeek(ctx) && getMinimalDaysInFirstWeek(ctx) == cal->getMinimalDaysInFirstWeek(ctx) && getTimeZone(ctx)->equals(cal->getTimeZone(ctx), ctx);
}
int Calendar::get(int field, ThreadContext* ctx) throw() 
{
	complete(ctx);
	return fields->get(field);
}
int Calendar::getActualMaximum(int field, ThreadContext* ctx) throw() 
{
	int value = 0;int next = 0;
	next = getLeastMaximum(field, ctx);
	if(getMaximum(field, ctx) == (next))
	{
		return next;
	}
	complete(ctx);
	long long orgTime = time;
	set(field, next, ctx);
	do
	{
		value = next;
		roll(field, true, ctx);
		next = get(field, ctx);
	}
	while(next > value);
	time = orgTime;
	areFieldsSet = false;
	return value;
}
int Calendar::getActualMinimum(int field, ThreadContext* ctx) throw() 
{
	int value = 0;int next = 0;
	next = getGreatestMinimum(field, ctx);
	if(getMinimum(field, ctx) == (next))
	{
		return next;
	}
	complete(ctx);
	long long orgTime = time;
	set(field, next, ctx);
	do
	{
		value = next;
		roll(field, false, ctx);
		next = get(field, ctx);
	}
	while(next < value);
	time = orgTime;
	areFieldsSet = false;
	return value;
}
int Calendar::getFirstDayOfWeek(ThreadContext* ctx) throw() 
{
	return firstDayOfWeek;
}
int Calendar::getMinimalDaysInFirstWeek(ThreadContext* ctx) throw() 
{
	return minimalDaysInFirstWeek;
}
java::util::Date* Calendar::getTime(ThreadContext* ctx) throw() 
{
	return (new(ctx) java::util::Date(getTimeInMillis(ctx), ctx));
}
long long Calendar::getTimeInMillis(ThreadContext* ctx) throw() 
{
	if(!isTimeSet)
	{
		computeTime(ctx);
		isTimeSet = true;
	}
	return time;
}
TimeZone* Calendar::getTimeZone(ThreadContext* ctx) throw() 
{
	return zone;
}
int Calendar::hashCode(ThreadContext* ctx) throw() 
{
	return (isLenient(ctx) ? 1237 : 1231) + getFirstDayOfWeek(ctx) + getMinimalDaysInFirstWeek(ctx) + getTimeZone(ctx)->hashCode(ctx);
}
bool Calendar::isLenient(ThreadContext* ctx) throw() 
{
	return lenient;
}
bool Calendar::isSet(int field, ThreadContext* ctx) throw() 
{
	return _isSet->get(field);
}
void Calendar::roll(int field, int value, ThreadContext* ctx) throw() 
{
	bool increment = value >= 0;
	int count = increment ? value : -value;
	for(int i = 0; i < count; i ++ )
	{
		roll(field, increment, ctx);
	}
}
void Calendar::set(int field, int value, ThreadContext* ctx) throw() 
{
	fields->set(value,field, ctx);
	_isSet->set(true,field, ctx);
	areFieldsSet = isTimeSet = false;
	if(field > MONTH && field < AM_PM)
	{
		lastDateFieldSet = field;
	}
	if(field == HOUR || field == HOUR_OF_DAY)
	{
		lastTimeFieldSet = field;
	}
	if(field == AM_PM)
	{
		lastTimeFieldSet = HOUR;
	}
}
void Calendar::set(int year, int month, int day, ThreadContext* ctx) throw() 
{
	set(YEAR, year, ctx);
	set(MONTH, month, ctx);
	set(DATE, day, ctx);
}
void Calendar::set(int year, int month, int day, int hourOfDay, int minute, ThreadContext* ctx) throw() 
{
	set(year, month, day, ctx);
	set(HOUR_OF_DAY, hourOfDay, ctx);
	set(MINUTE, minute, ctx);
}
void Calendar::set(int year, int month, int day, int hourOfDay, int minute, int second, ThreadContext* ctx) throw() 
{
	set(year, month, day, hourOfDay, minute, ctx);
	set(SECOND, second, ctx);
}
void Calendar::setFirstDayOfWeek(int value, ThreadContext* ctx) throw() 
{
	firstDayOfWeek = value;
}
void Calendar::setLenient(bool value, ThreadContext* ctx) throw() 
{
	lenient = value;
}
void Calendar::setMinimalDaysInFirstWeek(int value, ThreadContext* ctx) throw() 
{
	minimalDaysInFirstWeek = value;
}
void Calendar::setTime(java::util::Date* date, ThreadContext* ctx) throw() 
{
	setTimeInMillis(date->getTime(ctx), ctx);
}
void Calendar::setTimeInMillis(long long milliseconds, ThreadContext* ctx) throw() 
{
	if(!isTimeSet || !areFieldsSet || time != milliseconds)
	{
		time = milliseconds;
		isTimeSet = true;
		areFieldsSet = false;
		complete(ctx);
	}
}
void Calendar::setTimeZone(TimeZone* timezone, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(zone), timezone, TimeZone);
	areFieldsSet = false;
}
String* Calendar::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* result = (new(ctx) StringBuilder(ConstStr::getCNST_STR_524()->clone(ctx)->append((isTimeSet ? String::valueOf(time, ctx) : ConstStr::getCNST_STR_525()), ctx)->append(ConstStr::getCNST_STR_526(), ctx)->append(areFieldsSet, ctx)->append(ConstStr::getCNST_STR_527(), ctx)->append(lenient, ctx)->append(ConstStr::getCNST_STR_528(), ctx)->append(zone->toString(ctx), ctx)->append(ConstStr::getCNST_STR_529(), ctx)->append(firstDayOfWeek, ctx)->append(ConstStr::getCNST_STR_530(), ctx)->append(minimalDaysInFirstWeek, ctx), ctx));
	for(int i = 0; i < FIELD_COUNT; i ++ )
	{
		result->append(L',', ctx);
		result->append(fieldNames->get(i), ctx);
		result->append(L'=', ctx);
		if(_isSet->get(i))
		{
			result->append(fields->get(i), ctx);
		}
				else 
		{
			result->append(L'?', ctx);
		}
	}
	result->append(L']', ctx);
	return result->toString(ctx);
}
int Calendar::compareTo(Calendar* anotherCalendar, ThreadContext* ctx) throw() 
{
	if(nullptr == anotherCalendar)
	{
		throw (new(ctx) NullPointerException(ctx));
	}
	long long timeInMillis = getTimeInMillis(ctx);
	long long anotherTimeInMillis = anotherCalendar->getTimeInMillis(ctx);
	if(timeInMillis > anotherTimeInMillis)
	{
		return 1;
	}
	if(timeInMillis == anotherTimeInMillis)
	{
		return 0;
	}
	return -1;
}
void Calendar::complete(ThreadContext* ctx) throw() 
{
	if(!isTimeSet)
	{
		computeTime(ctx);
		isTimeSet = true;
	}
	if(!areFieldsSet)
	{
		computeFields(ctx);
		areFieldsSet = true;
	}
}
int Calendar::internalGet(int field, ThreadContext* ctx) throw() 
{
	return fields->get(field);
}
int Calendar::firstDays(String* langage, String* country, ThreadContext* ctx) throw() 
{
	if(langage->equals(ConstStr::getCNST_STR_385(), ctx) && country->equals(ConstStr::getCNST_STR_386(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_388(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_389(), ctx) && country->equals(ConstStr::getCNST_STR_390(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_391(), ctx) && country->equals(ConstStr::getCNST_STR_392(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_393(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_395(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_396(), ctx) && country->equals(ConstStr::getCNST_STR_397(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_398(), ctx) && country->equals(ConstStr::getCNST_STR_399(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_400(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_401(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_403(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_404(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_391(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_406(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_407(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_408(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_409(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_411(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_412(), ctx) && country->equals(ConstStr::getCNST_STR_413(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_412(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_414(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_415(), ctx) && country->equals(ConstStr::getCNST_STR_416(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_398(), ctx) && country->equals(ConstStr::getCNST_STR_417(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_418(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_420(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_421(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_418(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_423(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_424(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_425(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_426(), ctx) && country->equals(ConstStr::getCNST_STR_427(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_428(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_429(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_430(), ctx) && country->equals(ConstStr::getCNST_STR_431(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_432(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_426(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_433(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_434(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_435(), ctx) && country->equals(ConstStr::getCNST_STR_436(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_437(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_438(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_439(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_389(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_433(), ctx) && country->equals(ConstStr::getCNST_STR_440(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_441(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_442(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_385(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_443(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_444(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_414(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_445(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_446(), ctx) && country->equals(ConstStr::getCNST_STR_447(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_448(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_449(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_450(), ctx) && country->equals(ConstStr::getCNST_STR_451(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_399(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_452(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_453(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_454(), ctx) && country->equals(ConstStr::getCNST_STR_455(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_456(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_454(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_407(), ctx) && country->equals(ConstStr::getCNST_STR_457(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_458(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_459(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_460(), ctx) && country->equals(ConstStr::getCNST_STR_452(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_423(), ctx) && country->equals(ConstStr::getCNST_STR_461(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_462(), ctx) && country->equals(ConstStr::getCNST_STR_463(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_464(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_465(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_393(), ctx) && country->equals(ConstStr::getCNST_STR_466(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_467(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_468(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_396(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_462(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_469(), ctx) && country->equals(ConstStr::getCNST_STR_470(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_471(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_472(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_473(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_453(), ctx) && country->equals(ConstStr::getCNST_STR_474(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_428(), ctx) && country->equals(ConstStr::getCNST_STR_475(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_476(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_477(), ctx) && country->equals(ConstStr::getCNST_STR_478(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_479(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_480(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_446(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_481(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_482(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_476(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_483(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_484(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_450(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_485(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_486(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_398(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_487(), ctx) && country->equals(ConstStr::getCNST_STR_488(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_489(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_490(), ctx) && country->equals(ConstStr::getCNST_STR_491(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_445(), ctx) && country->equals(ConstStr::getCNST_STR_492(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_396(), ctx) && country->equals(ConstStr::getCNST_STR_493(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_433(), ctx) && country->equals(ConstStr::getCNST_STR_440(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_479(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_397(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_485(), ctx) && country->equals(ConstStr::getCNST_STR_395(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_494(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_495(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_415(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_448(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_439(), ctx) && country->equals(ConstStr::getCNST_STR_496(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_480(), ctx) && country->equals(ConstStr::getCNST_STR_497(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_490(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_397(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_481(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_498(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_499(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_471(), ctx) && country->equals(ConstStr::getCNST_STR_500(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_501(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_502(), ctx) && country->equals(ConstStr::getCNST_STR_503(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_504(), ctx) && country->equals(ConstStr::getCNST_STR_505(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_502(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_506(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_500(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_488(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_507(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_508(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_460(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_435(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_430(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_495(), ctx) && country->equals(ConstStr::getCNST_STR_509(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_439(), ctx) && country->equals(ConstStr::getCNST_STR_510(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_425(), ctx) && country->equals(ConstStr::getCNST_STR_511(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_434(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_484(), ctx) && country->equals(ConstStr::getCNST_STR_512(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_513(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_514(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_480(), ctx) && country->equals(ConstStr::getCNST_STR_497(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_515(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_456(), ctx) && country->equals(ConstStr::getCNST_STR_516(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_477(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_517(), ctx))
	{
		return 7;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_518(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_423(), ctx) && country->equals(ConstStr::getCNST_STR_461(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_504(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_519(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_520(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_489(), ctx) && country->equals(ConstStr::getCNST_STR_521(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_490(), ctx) && country->equals(ConstStr::getCNST_STR_522(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_469(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 2;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_523(), ctx))
	{
		return 2;
	}
	return 1;
}
int Calendar::minumalDays(String* langage, String* country, ThreadContext* ctx) throw() 
{
	if(langage->equals(ConstStr::getCNST_STR_385(), ctx) && country->equals(ConstStr::getCNST_STR_386(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_388(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_389(), ctx) && country->equals(ConstStr::getCNST_STR_390(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_391(), ctx) && country->equals(ConstStr::getCNST_STR_392(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_393(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_395(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_396(), ctx) && country->equals(ConstStr::getCNST_STR_397(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_398(), ctx) && country->equals(ConstStr::getCNST_STR_399(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_400(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_401(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_403(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_404(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_391(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_406(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_407(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_408(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_409(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_411(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_412(), ctx) && country->equals(ConstStr::getCNST_STR_413(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_412(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_414(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_415(), ctx) && country->equals(ConstStr::getCNST_STR_416(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_398(), ctx) && country->equals(ConstStr::getCNST_STR_417(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_418(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_420(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_421(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_418(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_423(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_424(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_425(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_426(), ctx) && country->equals(ConstStr::getCNST_STR_427(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_428(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_429(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_430(), ctx) && country->equals(ConstStr::getCNST_STR_431(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_432(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_426(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_433(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_434(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_435(), ctx) && country->equals(ConstStr::getCNST_STR_436(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_437(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_438(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_439(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_389(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_433(), ctx) && country->equals(ConstStr::getCNST_STR_440(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_441(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_442(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_385(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_443(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_444(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_414(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_445(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_446(), ctx) && country->equals(ConstStr::getCNST_STR_447(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_448(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_449(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_450(), ctx) && country->equals(ConstStr::getCNST_STR_451(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_399(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_452(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_453(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_454(), ctx) && country->equals(ConstStr::getCNST_STR_455(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_456(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_454(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_407(), ctx) && country->equals(ConstStr::getCNST_STR_457(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_458(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_459(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_460(), ctx) && country->equals(ConstStr::getCNST_STR_452(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_423(), ctx) && country->equals(ConstStr::getCNST_STR_461(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_462(), ctx) && country->equals(ConstStr::getCNST_STR_463(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_464(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_465(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_393(), ctx) && country->equals(ConstStr::getCNST_STR_466(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_467(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_468(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_396(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_462(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_469(), ctx) && country->equals(ConstStr::getCNST_STR_470(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_471(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_472(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_473(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_453(), ctx) && country->equals(ConstStr::getCNST_STR_474(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_428(), ctx) && country->equals(ConstStr::getCNST_STR_475(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_476(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_477(), ctx) && country->equals(ConstStr::getCNST_STR_478(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_479(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_480(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_446(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_481(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_482(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_476(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_483(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_484(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_450(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_485(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_486(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_398(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_487(), ctx) && country->equals(ConstStr::getCNST_STR_488(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_489(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_490(), ctx) && country->equals(ConstStr::getCNST_STR_491(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_445(), ctx) && country->equals(ConstStr::getCNST_STR_492(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_396(), ctx) && country->equals(ConstStr::getCNST_STR_493(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_433(), ctx) && country->equals(ConstStr::getCNST_STR_440(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_479(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_397(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_485(), ctx) && country->equals(ConstStr::getCNST_STR_395(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_494(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_495(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_415(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_448(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_439(), ctx) && country->equals(ConstStr::getCNST_STR_496(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_480(), ctx) && country->equals(ConstStr::getCNST_STR_497(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_490(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_397(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_419(), ctx) && country->equals(ConstStr::getCNST_STR_481(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_498(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_499(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_471(), ctx) && country->equals(ConstStr::getCNST_STR_500(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_501(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_502(), ctx) && country->equals(ConstStr::getCNST_STR_503(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_504(), ctx) && country->equals(ConstStr::getCNST_STR_505(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_502(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_506(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_500(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_488(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_507(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_508(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_460(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_435(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_430(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_495(), ctx) && country->equals(ConstStr::getCNST_STR_509(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_439(), ctx) && country->equals(ConstStr::getCNST_STR_510(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_425(), ctx) && country->equals(ConstStr::getCNST_STR_511(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_410(), ctx) && country->equals(ConstStr::getCNST_STR_434(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_484(), ctx) && country->equals(ConstStr::getCNST_STR_512(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_513(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_514(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_480(), ctx) && country->equals(ConstStr::getCNST_STR_497(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_515(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_456(), ctx) && country->equals(ConstStr::getCNST_STR_516(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_477(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_387(), ctx) && country->equals(ConstStr::getCNST_STR_517(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_405(), ctx) && country->equals(ConstStr::getCNST_STR_518(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_423(), ctx) && country->equals(ConstStr::getCNST_STR_461(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_504(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_402(), ctx) && country->equals(ConstStr::getCNST_STR_519(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_394(), ctx) && country->equals(ConstStr::getCNST_STR_520(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_489(), ctx) && country->equals(ConstStr::getCNST_STR_521(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_490(), ctx) && country->equals(ConstStr::getCNST_STR_522(), ctx))
	{
		return 1;
	}
	if(langage->equals(ConstStr::getCNST_STR_469(), ctx) && country->equals(ConstStr::getCNST_STR_4(), ctx))
	{
		return 4;
	}
	if(langage->equals(ConstStr::getCNST_STR_422(), ctx) && country->equals(ConstStr::getCNST_STR_523(), ctx))
	{
		return 4;
	}
	return 1;
}
IArrayObject<Locale>* Calendar::getAvailableLocales(ThreadContext* ctx) throw() 
{
	return Locale::getAvailableLocales(ctx);
}
Calendar* Calendar::getInstance(ThreadContext* ctx) throw() 
{
	return static_cast<Calendar*>((new(ctx) GregorianCalendar(ctx)));
}
Calendar* Calendar::getInstance(Locale* locale, ThreadContext* ctx) throw() 
{
	return static_cast<Calendar*>((new(ctx) GregorianCalendar(locale, ctx)));
}
Calendar* Calendar::getInstance(TimeZone* timezone, ThreadContext* ctx) throw() 
{
	return static_cast<Calendar*>((new(ctx) GregorianCalendar(timezone, ctx)));
}
Calendar* Calendar::getInstance(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() 
{
	return static_cast<Calendar*>((new(ctx) GregorianCalendar(timezone, locale, ctx)));
}
int Calendar::ValueCompare::operator() (Calendar* _this, Calendar* anotherCalendar, ThreadContext* ctx) const throw()
{
	return _this->compareTo(anotherCalendar, ctx);
}
}}

