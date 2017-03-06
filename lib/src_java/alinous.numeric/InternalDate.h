#ifndef ALINOUS_NUMERIC_INTERNALDATE_H_
#define ALINOUS_NUMERIC_INTERNALDATE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
class Calendar;}}

namespace alinous {namespace numeric {
class InternalDate;}}

namespace java {namespace util {
class GregorianCalendar;}}

namespace java {namespace util {
class Date;}}

namespace java {namespace util {
class TimeZone;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace util {
class Locale;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace numeric {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Calendar;
using ::java::util::Date;
using ::java::util::GregorianCalendar;
using ::java::util::Locale;
using ::java::util::TimeZone;



class InternalDate : public virtual IObject {
public:
	InternalDate(const InternalDate& base) = default;
public:
	InternalDate(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	InternalDate(int year, int month, int day, ThreadContext* ctx) throw() ;
	void __construct_impl(int year, int month, int day, ThreadContext* ctx) throw() ;
	InternalDate(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() ;
	void __construct_impl(int year, int month, int day, int hour, int minute, int second, ThreadContext* ctx) throw() ;
	InternalDate(long long milliseconds, ThreadContext* ctx) throw() ;
	void __construct_impl(long long milliseconds, ThreadContext* ctx) throw() ;
	virtual ~InternalDate() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	long long milliseconds;
private:
	static IArrayObject<String>* dayOfWeekNames;
	static IArrayObject<String>* monthNames;
public:
	bool after(InternalDate* date, ThreadContext* ctx) throw() ;
	bool before(InternalDate* date, ThreadContext* ctx) throw() ;
	IObject* clone(ThreadContext* ctx) throw() ;
	virtual int compareTo(InternalDate* date, ThreadContext* ctx) throw() ;
	virtual bool equals(IObject* object, ThreadContext* ctx) throw() ;
	int hashCode(ThreadContext* ctx) throw() ;
	virtual void setTime(long long milliseconds, ThreadContext* ctx) throw() ;
	virtual String* toString(ThreadContext* ctx) throw() ;
	virtual int getYear(ThreadContext* ctx) throw() ;
	virtual int getDate(ThreadContext* ctx) throw() ;
	virtual int getDay(ThreadContext* ctx) throw() ;
	int getHours(ThreadContext* ctx) throw() ;
	int getMinutes(ThreadContext* ctx) throw() ;
	virtual int getMonth(ThreadContext* ctx) throw() ;
	int getSeconds(ThreadContext* ctx) throw() ;
	virtual long long getTime(ThreadContext* ctx) throw() ;
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
		int operator() (InternalDate* _this, InternalDate* date, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of ALINOUS_NUMERIC_INTERNALDATE_H_ */
