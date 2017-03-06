#ifndef JAVA_UTIL_TIMEZONE_H_
#define JAVA_UTIL_TIMEZONE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
class TimeZones;}}

namespace java {namespace util {
class TimeZone;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace util {
class SimpleTimeZone;}}

namespace java {namespace util {
class Locale;}}

namespace java {namespace util {
class Date;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace numeric {
class InternalDate;}}

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
using ::alinous::numeric::InternalDate;



class TimeZone : public virtual IObject {
public:
	TimeZone(const TimeZone& base) = default;
public:
	TimeZone(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TimeZone() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* ID;
public:
	constexpr static const int SHORT{0};
	constexpr static const int LONG{1};
	static TimeZone* GMT;
private:
	static HashMap<String,TimeZone>* AvailableZones;
	static TimeZone* Default;
public:
	void includeDummy(TimeZones* arg0, ThreadContext* ctx) throw() ;
	virtual IObject* clone(ThreadContext* ctx) throw() ;
	String* getDisplayName(ThreadContext* ctx) throw() ;
	String* getDisplayName(Locale* locale, ThreadContext* ctx) throw() ;
	String* getDisplayName(bool daylightTime, int style, ThreadContext* ctx) throw() ;
	String* getDisplayName(bool daylightTime, int style, Locale* locale, ThreadContext* ctx) throw() ;
	String* getID(ThreadContext* ctx) throw() ;
	virtual int getDSTSavings(ThreadContext* ctx) throw() ;
	virtual int getOffset(long long time, ThreadContext* ctx) throw() ;
	virtual int getOffset(int era, int year, int month, int day, int dayOfWeek, int time, ThreadContext* ctx) throw()  = 0;
	virtual int getRawOffset(ThreadContext* ctx) throw()  = 0;
	virtual bool hasSameRules(TimeZone* zone, ThreadContext* ctx) throw() ;
	virtual bool inDaylightTime(Date* time, ThreadContext* ctx) throw()  = 0;
	virtual bool inDaylightTime(InternalDate* time, ThreadContext* ctx) throw()  = 0;
	void setID(String* name, ThreadContext* ctx) throw() ;
	virtual void setRawOffset(int offset, ThreadContext* ctx) throw()  = 0;
	virtual bool useDaylightTime(ThreadContext* ctx) throw()  = 0;
public:
	static IArrayObject<String>* getAvailableIDs(ThreadContext* ctx) throw() ;
	static IArrayObject<String>* getAvailableIDs(int offset, ThreadContext* ctx) throw() ;
	static TimeZone* getDefault(ThreadContext* ctx) throw() ;
	static TimeZone* getTimeZone(String* name, ThreadContext* ctx) throw() ;
	static void setDefault(TimeZone* timezone, ThreadContext* ctx) throw() ;
private:
	static void initializeAvailable(ThreadContext* ctx) throw() ;
	static String* formatTimeZoneName(String* name, int offset, ThreadContext* ctx) throw() ;
	static int parseNumber(String* string, int offset, IArrayObjectPrimitive<int>* position, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_UTIL_TIMEZONE_H_ */
