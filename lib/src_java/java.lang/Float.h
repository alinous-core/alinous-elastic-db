#ifndef JAVA_LANG_FLOAT_H_
#define JAVA_LANG_FLOAT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Float;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace lang {
class NullPointerException;}}

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



class Float final : public Number, public Comparable<Float> {
public:
	Float(const Float& base) = default;
public:
	Float(float value, ThreadContext* ctx) throw() ;
	void __construct_impl(float value, ThreadContext* ctx) throw() ;
	Float(double value, ThreadContext* ctx) throw() ;
	void __construct_impl(double value, ThreadContext* ctx) throw() ;
	Float(String* string, ThreadContext* ctx);
	void __construct_impl(String* string, ThreadContext* ctx);
	virtual ~Float() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	float value;
public:
	constexpr static const float MAX_VALUE{3.40282346638528860e+38f};
	constexpr static const float MIN_VALUE{1.40129846432481707e-45f};
	static float NaN;
	static float POSITIVE_INFINITY;
	static float NEGATIVE_INFINITY;
	constexpr static const int SIZE{32};
	static int SINGLE_EXPONENT_MASK;
	static int SINGLE_MANTISSA_MASK;
	static int SINGLE_NAN_BITS;
public:
	int compareTo(Float* object, ThreadContext* ctx) throw() ;
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
	static int floatToIntBits(float value, ThreadContext* ctx) throw() ;
	static int floatToRawIntBits(float value, ThreadContext* ctx) throw() ;
	static float intBitsToFloat(int bits, ThreadContext* ctx) throw() ;
	static bool isInfinite(float f, ThreadContext* ctx) throw() ;
	static bool isNaN(float f, ThreadContext* ctx) throw() ;
	static float parseFloat(String* string, ThreadContext* ctx);
	static String* toString(float f, ThreadContext* ctx) throw() ;
	static Float* valueOf(String* string, ThreadContext* ctx);
	static int compare(float float1, float float2, ThreadContext* ctx) throw() ;
	static Float* valueOf(float f, ThreadContext* ctx) throw() ;
	static String* toHexString(float f, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (Float* _this, Float* object, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_LANG_FLOAT_H_ */
