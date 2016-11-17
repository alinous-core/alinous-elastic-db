#ifndef JAVA_LANG_DOUBLE_H_
#define JAVA_LANG_DOUBLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Double;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace com {namespace google {namespace re2j {
class PatternSyntaxException;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class Number;}}

namespace java {namespace lang {
template <typename  T> class Comparable;}}

namespace java {namespace harmoney {
class FloatingPointParser;}}

namespace java {namespace harmoney {
class NumberConverter;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace lang {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::harmoney::FloatingPointParser;
using ::java::harmoney::NumberConverter;
using ::java::nio::ByteBuffer;
using ::com::google::re2j::PatternSyntaxException;



class Double final : public Number, public Comparable<Double> {
public:
	Double(const Double& base) = default;
public:
	Double(double value, ThreadContext* ctx) throw() ;
	void __construct_impl(double value, ThreadContext* ctx) throw() ;
	Double(String* string, ThreadContext* ctx);
	void __construct_impl(String* string, ThreadContext* ctx);
	virtual ~Double() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	double value;
public:
	constexpr static const double MAX_VALUE{1.79769313486231570e+308};
	constexpr static const double MIN_VALUE{5e-324};
	static double NaN;
	static double POSITIVE_INFINITY;
	static double NEGATIVE_INFINITY;
	constexpr static const int SIZE{64};
private:
	static long long DOUBLE_EXPONENT_MASK;
	static long long DOUBLE_MANTISSA_MASK;
	static long long DOUBLE_NAN_BITS;
public:
	int compareTo(Double* object, ThreadContext* ctx) throw() ;
	char byteValue(ThreadContext* ctx) throw()  final;
	double doubleValue(ThreadContext* ctx) throw()  final;
	bool equals(IObject* object, ThreadContext* ctx) throw() ;
	float floatValue(ThreadContext* ctx) throw()  final;
	int hashCode(ThreadContext* ctx) throw() ;
	int intValue(ThreadContext* ctx) throw()  final;
	bool isInfinite(ThreadContext* ctx) throw() ;
	bool isNaN(ThreadContext* ctx) throw() ;
	long long longValue(ThreadContext* ctx) throw()  final;
	short shortValue(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static long long doubleToLongBits(double value, ThreadContext* ctx) throw() ;
	static long long doubleToRawLongBits(double value, ThreadContext* ctx) throw() ;
	static bool isInfinite(double d, ThreadContext* ctx) throw() ;
	static bool isNaN(double d, ThreadContext* ctx) throw() ;
	static double longBitsToDouble(long long bits, ThreadContext* ctx) throw() ;
	static double parseDouble(String* string, ThreadContext* ctx);
	static String* toString(double d, ThreadContext* ctx) throw() ;
	static Double* valueOf(String* string, ThreadContext* ctx);
	static int compare(double double1, double double2, ThreadContext* ctx) throw() ;
	static Double* valueOf(double d, ThreadContext* ctx) throw() ;
	static String* toHexString(double d, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (Double* _this, Double* object, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_LANG_DOUBLE_H_ */
