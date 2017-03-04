#ifndef JAVA_UTIL_CALENDAR_H_
#define JAVA_UTIL_CALENDAR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
class TimeZone;}}

namespace java {namespace util {
class Locale;}}

namespace java {namespace util {
class Calendar;}}

namespace java {namespace util {
class GregorianCalendar;}}

namespace java {namespace util {
class Date;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class NullPointerException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace util {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class Calendar : public virtual IObject {
public:
	Calendar(const Calendar& base) = default;
public:
	Calendar(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	Calendar(TimeZone* timezone, ThreadContext* ctx) throw() ;
	void __construct_impl(TimeZone* timezone, ThreadContext* ctx) throw() ;
	Calendar(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() ;
	void __construct_impl(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() ;
	virtual ~Calendar() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IArrayObjectPrimitive<bool>* _isSet;
	bool areFieldsSet;
	IArrayObjectPrimitive<int>* fields;
	bool isTimeSet;
	long long time;
	int lastTimeFieldSet;
	int lastDateFieldSet;
	TimeZone* zone;
private:
	bool lenient;
	int firstDayOfWeek;
	int minimalDaysInFirstWeek;
public:
	constexpr static const int JANUARY{0};
	constexpr static const int FEBRUARY{1};
	constexpr static const int MARCH{2};
	constexpr static const int APRIL{3};
	constexpr static const int MAY{4};
	constexpr static const int JUNE{5};
	constexpr static const int JULY{6};
	constexpr static const int AUGUST{7};
	constexpr static const int SEPTEMBER{8};
	constexpr static const int OCTOBER{9};
	constexpr static const int NOVEMBER{10};
	constexpr static const int DECEMBER{11};
	constexpr static const int UNDECIMBER{12};
	constexpr static const int SUNDAY{1};
	constexpr static const int MONDAY{2};
	constexpr static const int TUESDAY{3};
	constexpr static const int WEDNESDAY{4};
	constexpr static const int THURSDAY{5};
	constexpr static const int FRIDAY{6};
	constexpr static const int SATURDAY{7};
	constexpr static const int ERA{0};
	constexpr static const int YEAR{1};
	constexpr static const int MONTH{2};
	constexpr static const int WEEK_OF_YEAR{3};
	constexpr static const int WEEK_OF_MONTH{4};
	constexpr static const int DATE{5};
	constexpr static const int DAY_OF_MONTH{5};
	constexpr static const int DAY_OF_YEAR{6};
	constexpr static const int DAY_OF_WEEK{7};
	constexpr static const int DAY_OF_WEEK_IN_MONTH{8};
	constexpr static const int AM_PM{9};
	constexpr static const int HOUR{10};
	constexpr static const int HOUR_OF_DAY{11};
	constexpr static const int MINUTE{12};
	constexpr static const int SECOND{13};
	constexpr static const int MILLISECOND{14};
	constexpr static const int ZONE_OFFSET{15};
	constexpr static const int DST_OFFSET{16};
	constexpr static const int FIELD_COUNT{17};
	constexpr static const int AM{0};
	constexpr static const int PM{1};
private:
	static IArrayObject<String>* fieldNames;
public:
	virtual void add(int field, int value, ThreadContext* ctx) throw()  = 0;
	bool after(IObject* calendar, ThreadContext* ctx) throw() ;
	bool before(IObject* calendar, ThreadContext* ctx) throw() ;
	void clear(ThreadContext* ctx) throw() ;
	void clear(int field, ThreadContext* ctx) throw() ;
	virtual bool equals(IObject* object, ThreadContext* ctx) throw() ;
	int get(int field, ThreadContext* ctx) throw() ;
	virtual int getActualMaximum(int field, ThreadContext* ctx) throw() ;
	virtual int getActualMinimum(int field, ThreadContext* ctx) throw() ;
	int getFirstDayOfWeek(ThreadContext* ctx) throw() ;
	virtual int getGreatestMinimum(int field, ThreadContext* ctx) throw()  = 0;
	virtual int getLeastMaximum(int field, ThreadContext* ctx) throw()  = 0;
	virtual int getMaximum(int field, ThreadContext* ctx) throw()  = 0;
	int getMinimalDaysInFirstWeek(ThreadContext* ctx) throw() ;
	virtual int getMinimum(int field, ThreadContext* ctx) throw()  = 0;
	java::util::Date* getTime(ThreadContext* ctx) throw() ;
	long long getTimeInMillis(ThreadContext* ctx) throw() ;
	TimeZone* getTimeZone(ThreadContext* ctx) throw() ;
	virtual int hashCode(ThreadContext* ctx) throw() ;
	bool isLenient(ThreadContext* ctx) throw() ;
	bool isSet(int field, ThreadContext* ctx) throw() ;
	virtual void roll(int field, int value, ThreadContext* ctx) throw() ;
	virtual void roll(int field, bool increment, ThreadContext* ctx) throw()  = 0;
	void set(int field, int value, ThreadContext* ctx) throw() ;
	void set(int year, int month, int day, ThreadContext* ctx) throw() ;
	void set(int year, int month, int day, int hourOfDay, int minute, ThreadContext* ctx) throw() ;
	void set(int year, int month, int day, int hourOfDay, int minute, int second, ThreadContext* ctx) throw() ;
	virtual void setFirstDayOfWeek(int value, ThreadContext* ctx) throw() ;
	void setLenient(bool value, ThreadContext* ctx) throw() ;
	virtual void setMinimalDaysInFirstWeek(int value, ThreadContext* ctx) throw() ;
	void setTime(java::util::Date* date, ThreadContext* ctx) throw() ;
	void setTimeInMillis(long long milliseconds, ThreadContext* ctx) throw() ;
	void setTimeZone(TimeZone* timezone, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	int compareTo(Calendar* anotherCalendar, ThreadContext* ctx) throw() ;
	void complete(ThreadContext* ctx) throw() ;
	virtual void computeFields(ThreadContext* ctx) throw()  = 0;
	virtual void computeTime(ThreadContext* ctx) throw()  = 0;
	int internalGet(int field, ThreadContext* ctx) throw() ;
private:
	int firstDays(String* langage, String* country, ThreadContext* ctx) throw() ;
	int minumalDays(String* langage, String* country, ThreadContext* ctx) throw() ;
public:
	static IArrayObject<Locale>* getAvailableLocales(ThreadContext* ctx) throw() ;
	static Calendar* getInstance(ThreadContext* ctx) throw() ;
	static Calendar* getInstance(Locale* locale, ThreadContext* ctx) throw() ;
	static Calendar* getInstance(TimeZone* timezone, ThreadContext* ctx) throw() ;
	static Calendar* getInstance(TimeZone* timezone, Locale* locale, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<IArrayObject<String>>::dec(nullptr, Calendar::fieldNames, ctx, __FILEW__, __LINE__, L"IArrayObject<String>");
	}
	class ValueCompare {
	public:
		int operator() (Calendar* _this, Calendar* anotherCalendar, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_UTIL_CALENDAR_H_ */
