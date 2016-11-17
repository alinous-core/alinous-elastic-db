#ifndef JAVA_UTIL_GREGORIANCALENDAR_H_
#define JAVA_UTIL_GREGORIANCALENDAR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
class Locale;}}

namespace java {namespace util {
class TimeZone;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace util {
class GregorianCalendar;}}

namespace java {namespace util {
class SimpleTimeZone;}}

namespace java {namespace util {
class Date;}}

namespace java {namespace util {
class Calendar;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace util {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class GregorianCalendar final : public Calendar {
public:
	GregorianCalendar(const GregorianCalendar& base) = default;
public:
	GregorianCalendar(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	GregorianCalendar(int year, int month, int day, ThreadContext* ctx) throw() ;
	void __construct_impl(int year, int month, int day, ThreadContext* ctx) throw() ;
	GregorianCalendar(int year, int month, int day, int hour, int minute, ThreadContext* ctx) throw() ;
	void __construct_impl(int year, int month, int day, int hour, int minute, ThreadContext* ctx) throw() ;
	GregorianCalendar(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() ;
	void __construct_impl(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() ;
	GregorianCalendar(long long milliseconds, ThreadContext* ctx) throw() ;
	void __construct_impl(long long milliseconds, ThreadContext* ctx) throw() ;
	GregorianCalendar(Locale* locale, ThreadContext* ctx) throw() ;
	void __construct_impl(Locale* locale, ThreadContext* ctx) throw() ;
	GregorianCalendar(TimeZone* timezone, ThreadContext* ctx) throw() ;
	void __construct_impl(TimeZone* timezone, ThreadContext* ctx) throw() ;
	GregorianCalendar(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() ;
	void __construct_impl(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() ;
	GregorianCalendar(bool ignored, ThreadContext* ctx) throw() ;
	void __construct_impl(bool ignored, ThreadContext* ctx) throw() ;
	virtual ~GregorianCalendar() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long gregorianCutover;
	int changeYear;
	int julianSkew;
	bool isCached;
	IArrayObjectPrimitive<int>* cachedFields;
	long long nextMidnightMillis;
	long long lastMidnightMillis;
	int currentYearSkew;
	int lastYearSkew;
public:
	constexpr static const int BC{0};
	constexpr static const int AD{1};
	static const StaticArrayObjectPrimitive<char> __DaysInMonth;
	static IArrayObjectPrimitive<char>* DaysInMonth;
private:
	constexpr static const long long defaultGregorianCutover{-12219292800000l};
	static const StaticArrayObjectPrimitive<int> __DaysInYear;
	static IArrayObjectPrimitive<int>* DaysInYear;
	static const StaticArrayObjectPrimitive<int> __maximums;
	static IArrayObjectPrimitive<int>* maximums;
	static const StaticArrayObjectPrimitive<int> __minimums;
	static IArrayObjectPrimitive<int>* minimums;
	static const StaticArrayObjectPrimitive<int> __leastMaximums;
	static IArrayObjectPrimitive<int>* leastMaximums;
public:
	void add(int field, int value, ThreadContext* ctx) throw()  final;
	IObject* clone(ThreadContext* ctx) throw() ;
	bool equals(IObject* object, ThreadContext* ctx) throw()  final;
	int getActualMaximum(int field, ThreadContext* ctx) throw()  final;
	int getActualMinimum(int field, ThreadContext* ctx) throw()  final;
	int getGreatestMinimum(int field, ThreadContext* ctx) throw()  final;
	Date* getGregorianChange(ThreadContext* ctx) throw() ;
	int getLeastMaximum(int field, ThreadContext* ctx) throw()  final;
	int getMaximum(int field, ThreadContext* ctx) throw()  final;
	int getMinimum(int field, ThreadContext* ctx) throw()  final;
	int hashCode(ThreadContext* ctx) throw()  final;
	bool isLeapYear(int year, ThreadContext* ctx) throw() ;
	void roll(int field, int value, ThreadContext* ctx) throw()  final;
	void roll(int field, bool increment, ThreadContext* ctx) throw()  final;
	void setGregorianChange(Date* date, ThreadContext* ctx) throw() ;
	void setFirstDayOfWeek(int value, ThreadContext* ctx) throw()  final;
	void setMinimalDaysInFirstWeek(int value, ThreadContext* ctx) throw()  final;
	void computeFields(ThreadContext* ctx) throw()  final;
	void computeTime(ThreadContext* ctx) throw()  final;
	int getOffset(long long localTime, ThreadContext* ctx) throw() ;
private:
	void fullFieldsCalc(long long timeVal, int millis, int zoneOffset, ThreadContext* ctx) throw() ;
	void cachedFieldsCheckAndGet(long long timeVal, long long newTimeMillis, long long newTimeMillisAdjusted, int millis, int zoneOffset, ThreadContext* ctx) throw() ;
	int computeYearAndDay(long long dayCount, long long localTime, ThreadContext* ctx) throw() ;
	long long daysFromBaseYear(int iyear, ThreadContext* ctx) throw() ;
	int daysInMonth(ThreadContext* ctx) throw() ;
	int daysInMonth(bool leapYear, int month, ThreadContext* ctx) throw() ;
	int daysInYear(int year, ThreadContext* ctx) throw() ;
	int daysInYear(bool leapYear, int month, ThreadContext* ctx) throw() ;
	int julianError(ThreadContext* ctx) throw() ;
	int _mod(int value, int mod, ThreadContext* ctx) throw() ;
	int mod7(long long num1, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_UTIL_GREGORIANCALENDAR_H_ */
