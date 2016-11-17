#ifndef JAVA_UTIL_TIMEZONES_H_
#define JAVA_UTIL_TIMEZONES_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace util {
class TimeZone;}}

namespace java {namespace util {
class SimpleTimeZone;}}

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



class TimeZones final : public virtual IObject {
public:
	TimeZones(const TimeZones& base) = default;
public:
	TimeZones(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TimeZones() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const int HALF_HOUR{1800000};
	constexpr static const int ONE_HOUR{HALF_HOUR * 2};
public:
	static IArrayObject<TimeZone>* getTimeZones(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of JAVA_UTIL_TIMEZONES_H_ */
