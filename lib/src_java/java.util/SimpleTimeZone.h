#ifndef JAVA_UTIL_SIMPLETIMEZONE_H_
#define JAVA_UTIL_SIMPLETIMEZONE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace util {
class SimpleTimeZone;}}

namespace java {namespace util {
class GregorianCalendar;}}

namespace java {namespace util {
class TimeZone;}}

namespace java {namespace util {
class Date;}}

namespace alinous {namespace numeric {
class InternalDate;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace util {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::numeric::InternalDate;



class SimpleTimeZone final : public TimeZone {
public:
	SimpleTimeZone(const SimpleTimeZone& base) = default;
public:
	SimpleTimeZone(int offset, String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(int offset, String* name, ThreadContext* ctx) throw() ;
	SimpleTimeZone(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, ThreadContext* ctx) throw() ;
	void __construct_impl(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, ThreadContext* ctx) throw() ;
	SimpleTimeZone(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, int daylightSavings, ThreadContext* ctx) throw() ;
	void __construct_impl(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int endMonth, int endDay, int endDayOfWeek, int endTime, int daylightSavings, ThreadContext* ctx) throw() ;
	SimpleTimeZone(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int startTimeMode, int endMonth, int endDay, int endDayOfWeek, int endTime, int endTimeMode, int daylightSavings, ThreadContext* ctx) throw() ;
	void __construct_impl(int offset, String* name, int startMonth, int startDay, int startDayOfWeek, int startTime, int startTimeMode, int endMonth, int endDay, int endDayOfWeek, int endTime, int endTimeMode, int daylightSavings, ThreadContext* ctx) throw() ;
	virtual ~SimpleTimeZone() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int rawOffset;
	int startYear; int startMonth; int startDay; int startDayOfWeek; int startTime;
	int endMonth; int endDay; int endDayOfWeek; int endTime;
	int startMode; int endMode;
	bool useDaylight;
	GregorianCalendar* daylightSavings;
	int dstSavings;
public:
	constexpr static const int UTC_TIME{2};
	constexpr static const int STANDARD_TIME{1};
	constexpr static const int WALL_TIME{0};
private:
	constexpr static const int DOM_MODE{1};
	constexpr static const int DOW_IN_MONTH_MODE{2};
	constexpr static const int DOW_GE_DOM_MODE{3};
	constexpr static const int DOW_LE_DOM_MODE{4};
public:
	IObject* clone(ThreadContext* ctx) throw()  final;
	bool equals(IObject* object, ThreadContext* ctx) throw() ;
	int getDSTSavings(ThreadContext* ctx) throw()  final;
	int getOffset(int era, int year, int month, int day, int dayOfWeek, int time, ThreadContext* ctx) throw()  final;
	int getOffset(long long time, ThreadContext* ctx) throw()  final;
	int getRawOffset(ThreadContext* ctx) throw()  final;
	int hashCode(ThreadContext* ctx) throw() ;
	bool hasSameRules(TimeZone* zone, ThreadContext* ctx) throw()  final;
	bool inDaylightTime(Date* time, ThreadContext* ctx) throw()  final;
	bool inDaylightTime(InternalDate* time, ThreadContext* ctx) throw()  final;
	void setDSTSavings(int milliseconds, ThreadContext* ctx) throw() ;
	void setEndRule(int month, int dayOfMonth, int time, ThreadContext* ctx) throw() ;
	void setEndRule(int month, int day, int dayOfWeek, int time, ThreadContext* ctx) throw() ;
	void setEndRule(int month, int day, int dayOfWeek, int time, bool after, ThreadContext* ctx) throw() ;
	void setRawOffset(int offset, ThreadContext* ctx) throw()  final;
	void setStartRule(int month, int dayOfMonth, int time, ThreadContext* ctx) throw() ;
	void setStartRule(int month, int day, int dayOfWeek, int time, ThreadContext* ctx) throw() ;
	void setStartRule(int month, int day, int dayOfWeek, int time, bool after, ThreadContext* ctx) throw() ;
	void setStartYear(int year, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	bool useDaylightTime(ThreadContext* ctx) throw()  final;
private:
	bool isLeapYear(int year, ThreadContext* ctx) throw() ;
	void checkRange(int month, int dayOfWeek, int time, ThreadContext* ctx) throw() ;
	void checkDay(int month, int day, ThreadContext* ctx) throw() ;
	void setEndMode(ThreadContext* ctx) throw() ;
	void setStartMode(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_UTIL_SIMPLETIMEZONE_H_ */
