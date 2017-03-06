#ifndef JAVA_UTIL_DATE_H_
#define JAVA_UTIL_DATE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
class GregorianCalendar;}}

namespace java {namespace util {
class Date;}}

namespace java {namespace util {
class Calendar;}}

namespace java {namespace util {
class TimeZone;}}

namespace java {namespace lang {
class StringBuilder;}}

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



class Date final : public virtual IObject {
public:
	Date(const Date& base) = default;
public:
	Date(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	Date(int year, int month, int day, ThreadContext* ctx) throw() ;
	void __construct_impl(int year, int month, int day, ThreadContext* ctx) throw() ;
	Date(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() ;
	void __construct_impl(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() ;
	Date(long long milliseconds, ThreadContext* ctx) throw() ;
	void __construct_impl(long long milliseconds, ThreadContext* ctx) throw() ;
	virtual ~Date() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long milliseconds;
private:
	static IArrayObject<String>* dayOfWeekNames;
	static IArrayObject<String>* monthNames;
public:
	bool after(Date* date, ThreadContext* ctx) throw() ;
	bool before(Date* date, ThreadContext* ctx) throw() ;
	IObject* clone(ThreadContext* ctx) throw() ;
	int compareTo(Date* date, ThreadContext* ctx) throw() ;
	bool equals(IObject* object, ThreadContext* ctx) throw() ;
	int hashCode(ThreadContext* ctx) throw() ;
	void setTime(long long milliseconds, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	int getYear(ThreadContext* ctx) throw() ;
	int getDate(ThreadContext* ctx) throw() ;
	int getDay(ThreadContext* ctx) throw() ;
	int getHours(ThreadContext* ctx) throw() ;
	int getMinutes(ThreadContext* ctx) throw() ;
	int getMonth(ThreadContext* ctx) throw() ;
	int getSeconds(ThreadContext* ctx) throw() ;
	long long getTime(ThreadContext* ctx) throw() ;
private:
	String* toTwoDigits(int digit, ThreadContext* ctx) throw() ;
public:
	static int zone(String* text, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (Date* _this, Date* date, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_UTIL_DATE_H_ */
