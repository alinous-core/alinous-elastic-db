#ifndef JAVA_LANG_LONG_H_
#define JAVA_LANG_LONG_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Long;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace java {namespace lang {
class Number;}}

namespace java {namespace lang {
template <typename  T> class Comparable;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace lang {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class Long final : public Number, public Comparable<Long> {
public:
	Long(const Long& base) = default;
public:
	Long(long long value, ThreadContext* ctx) throw() ;
	void __construct_impl(long long value, ThreadContext* ctx) throw() ;
	Long(String* string, ThreadContext* ctx);
	void __construct_impl(String* string, ThreadContext* ctx);
	virtual ~Long() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long value;
public:
	constexpr static const long long MAX_VALUE{((long long)0x7FFFFFFFFFFFFFFFL)};
	constexpr static const long long MIN_VALUE{((long long)0x8000000000000000L)};
	constexpr static const int SIZE{64};
public:
	char byteValue(ThreadContext* ctx) throw()  final;
	int compareTo(Long* object, ThreadContext* ctx) throw() ;
	double doubleValue(ThreadContext* ctx) throw()  final;
	bool equals(IObject* o, ThreadContext* ctx) throw() ;
	float floatValue(ThreadContext* ctx) throw()  final;
	int hashCode(ThreadContext* ctx) throw() ;
	int intValue(ThreadContext* ctx) throw()  final;
	long long longValue(ThreadContext* ctx) throw()  final;
	short shortValue(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static Long* decode(String* string, ThreadContext* ctx);
	static Long* getLong(String* string, ThreadContext* ctx) throw() ;
	static Long* getLong(String* string, long long defaultValue, ThreadContext* ctx) throw() ;
	static Long* getLong(String* string, Long* defaultValue, ThreadContext* ctx) throw() ;
	static long long parseLong(String* string, ThreadContext* ctx);
	static long long parseLong(String* string, int radix, ThreadContext* ctx);
	static String* toBinaryString(long long l, ThreadContext* ctx) throw() ;
	static String* toHexString(long long l, ThreadContext* ctx) throw() ;
	static String* toOctalString(long long l, ThreadContext* ctx) throw() ;
	static String* toString(long long l, ThreadContext* ctx) throw() ;
	static String* toString(long long l, int radix, ThreadContext* ctx) throw() ;
	static Long* valueOf(String* string, ThreadContext* ctx);
	static Long* valueOf(String* string, int radix, ThreadContext* ctx);
	static long long highestOneBit(long long lng, ThreadContext* ctx) throw() ;
	static long long lowestOneBit(long long lng, ThreadContext* ctx) throw() ;
	static int numberOfLeadingZeros(long long lng, ThreadContext* ctx) throw() ;
	static int numberOfTrailingZeros(long long lng, ThreadContext* ctx) throw() ;
	static int bitCount(long long lng, ThreadContext* ctx) throw() ;
	static long long rotateLeft(long long lng, int distance, ThreadContext* ctx) throw() ;
	static long long rotateRight(long long lng, int distance, ThreadContext* ctx) throw() ;
	static long long reverseBytes(long long lng, ThreadContext* ctx) throw() ;
	static long long reverse(long long lng, ThreadContext* ctx) throw() ;
	static int signum(long long lng, ThreadContext* ctx) throw() ;
	static Long* valueOf(long long lng, ThreadContext* ctx) throw() ;
private:
	static long long parse(String* string, int offset, int radix, bool negative, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (Long* _this, Long* object, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_LANG_LONG_H_ */
