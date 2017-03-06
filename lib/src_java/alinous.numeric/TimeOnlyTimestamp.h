#ifndef ALINOUS_NUMERIC_TIMEONLYTIMESTAMP_H_
#define ALINOUS_NUMERIC_TIMEONLYTIMESTAMP_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
class GregorianCalendar;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace alinous {namespace numeric {
class InternalDate;}}

namespace java {namespace util {
class Calendar;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace numeric {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Calendar;
using ::java::util::GregorianCalendar;



class TimeOnlyTimestamp final : public InternalDate {
public:
	TimeOnlyTimestamp(const TimeOnlyTimestamp& base) = default;
public:
	TimeOnlyTimestamp(int theHour, int theMinute, int theSecond, ThreadContext* ctx) throw() ;
	void __construct_impl(int theHour, int theMinute, int theSecond, ThreadContext* ctx) throw() ;
	TimeOnlyTimestamp(long long theTime, ThreadContext* ctx) throw() ;
	void __construct_impl(long long theTime, ThreadContext* ctx) throw() ;
	virtual ~TimeOnlyTimestamp() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	static String* PADDING;
public:
	int getDate(ThreadContext* ctx) throw()  final;
	int getDay(ThreadContext* ctx) throw()  final;
	int getMonth(ThreadContext* ctx) throw()  final;
	int getYear(ThreadContext* ctx) throw()  final;
	void setTime(long long time, ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw()  final;
private:
	void format(int date, int digits, StringBuilder* sb, ThreadContext* ctx) throw() ;
public:
	static TimeOnlyTimestamp* valueOf(String* timeString, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_NUMERIC_TIMEONLYTIMESTAMP_H_ */
