#ifndef JAVA_SQL_TIMESTAMP_H_
#define JAVA_SQL_TIMESTAMP_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace numeric {
class InternalDate;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace com {namespace google {namespace re2j {
class PatternSyntaxException;}}}

namespace java {namespace util {
class Calendar;}}

namespace com {namespace google {namespace re2j {
class Pattern;}}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace sql {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Calendar;
using ::com::google::re2j::Pattern;
using ::com::google::re2j::PatternSyntaxException;
using ::alinous::numeric::InternalDate;
using ::alinous::numeric::TimeOnlyTimestamp;



class Timestamp final : public InternalDate {
public:
	Timestamp(const Timestamp& base) = default;
public:
	Timestamp(long long theTime, ThreadContext* ctx) throw() ;
	void __construct_impl(long long theTime, ThreadContext* ctx) throw() ;
	virtual ~Timestamp() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int nanos;
private:
	static String* TIME_FORMAT_REGEX;
	static String* PADDING;
public:
	bool after(Timestamp* theTimestamp, ThreadContext* ctx) throw() ;
	bool before(Timestamp* theTimestamp, ThreadContext* ctx) throw() ;
	int compareTo(InternalDate* theObject, ThreadContext* ctx) throw()  final;
	int compareTo(Timestamp* theTimestamp, ThreadContext* ctx) throw() ;
	bool equals(IObject* theObject, ThreadContext* ctx) throw()  final;
	bool equals(Timestamp* theTimestamp, ThreadContext* ctx) throw() ;
	int getNanos(ThreadContext* ctx) throw() ;
	long long getTime(ThreadContext* ctx) throw()  final;
	void setNanos(int n, ThreadContext* ctx);
	void setTime(long long theTime, ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw()  final;
private:
	void setTimeImpl(long long theTime, ThreadContext* ctx) throw() ;
	void format(int date, int digits, StringBuilder* sb, ThreadContext* ctx) throw() ;
public:
	static Timestamp* valueOf(String* s, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (InternalDate* _this, InternalDate* theObject, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_SQL_TIMESTAMP_H_ */
