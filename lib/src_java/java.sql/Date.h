#ifndef JAVA_SQL_DATE_H_
#define JAVA_SQL_DATE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace sql {
class Date;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace alinous {namespace numeric {
class InternalDate;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace sql {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::numeric::InternalDate;



class Date final : public InternalDate {
public:
	Date(const Date& base) = default;
public:
	Date(int theYear, int theMonth, int theDay, ThreadContext* ctx) throw() ;
	void __construct_impl(int theYear, int theMonth, int theDay, ThreadContext* ctx) throw() ;
	Date(long long theDate, ThreadContext* ctx) throw() ;
	void __construct_impl(long long theDate, ThreadContext* ctx) throw() ;
	virtual ~Date() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	static String* PADDING;
public:
	void setTime(long long theTime, ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw()  final;
private:
	void format(int date, int digits, StringBuilder* sb, ThreadContext* ctx) throw() ;
public:
	static Date* valueOf(String* dateString, ThreadContext* ctx) throw() ;
private:
	static long long normalizeTime(long long theTime, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_SQL_DATE_H_ */
