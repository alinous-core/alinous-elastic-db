#ifndef JAVA_LANG_INTEGER_H_
#define JAVA_LANG_INTEGER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Integer;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace java {namespace lang {
class Number;}}

namespace java {namespace lang {
template <typename  T> class Comparable;}}

namespace java {namespace nio {
class CharBuffer;}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace lang {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::nio::CharBuffer;



class Integer final : public Number, public Comparable<Integer> {
public:
	Integer(const Integer& base) = default;
public:
	Integer(int value, ThreadContext* ctx) throw() ;
	void __construct_impl(int value, ThreadContext* ctx) throw() ;
	Integer(String* string, ThreadContext* ctx);
	void __construct_impl(String* string, ThreadContext* ctx);
	virtual ~Integer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int value;
public:
	constexpr static const int MAX_VALUE{((int)0x7FFFFFFF)};
	constexpr static const int MIN_VALUE{((int)0x80000000)};
	constexpr static const int SIZE{32};
private:
	static const StaticArrayObjectPrimitive<int> __decimalScale;
	static IArrayObjectPrimitive<int>* decimalScale;
public:
	char byteValue(ThreadContext* ctx) throw()  final;
	int compareTo(Integer* object, ThreadContext* ctx) throw() ;
	double doubleValue(ThreadContext* ctx) throw()  final;
	bool equals(IObject* o, ThreadContext* ctx) throw() ;
	float floatValue(ThreadContext* ctx) throw()  final;
	int hashCode(ThreadContext* ctx) throw() ;
	int intValue(ThreadContext* ctx) throw()  final;
	long long longValue(ThreadContext* ctx) throw()  final;
	short shortValue(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static Integer* decode(String* string, ThreadContext* ctx);
	static Integer* getInteger(String* string, ThreadContext* ctx) throw() ;
	static Integer* getInteger(String* string, int defaultValue, ThreadContext* ctx) throw() ;
	static Integer* getInteger(String* string, Integer* defaultValue, ThreadContext* ctx) throw() ;
	static int parseInt(String* string, ThreadContext* ctx);
	static int parseInt(String* string, int radix, ThreadContext* ctx);
	static String* toBinaryString(int i, ThreadContext* ctx) throw() ;
	static String* toHexString(int i, ThreadContext* ctx) throw() ;
	static String* toOctalString(int i, ThreadContext* ctx) throw() ;
	static String* toString(int value, ThreadContext* ctx) throw() ;
	static String* toString(int i, int radix, ThreadContext* ctx) throw() ;
	static Integer* valueOf(String* string, ThreadContext* ctx);
	static Integer* valueOf(String* string, int radix, ThreadContext* ctx);
	static int highestOneBit(int i, ThreadContext* ctx) throw() ;
	static int lowestOneBit(int i, ThreadContext* ctx) throw() ;
	static int numberOfLeadingZeros(int i, ThreadContext* ctx) throw() ;
	static int numberOfTrailingZeros(int i, ThreadContext* ctx) throw() ;
	static int bitCount(int i, ThreadContext* ctx) throw() ;
	static int rotateLeft(int i, int distance, ThreadContext* ctx) throw() ;
	static int rotateRight(int i, int distance, ThreadContext* ctx) throw() ;
	static int reverseBytes(int i, ThreadContext* ctx) throw() ;
	static int reverse(int i, ThreadContext* ctx) throw() ;
	static int signum(int i, ThreadContext* ctx) throw() ;
	static Integer* valueOf(int i, ThreadContext* ctx) throw() ;
private:
	static int parse(String* string, int offset, int radix, bool negative, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (Integer* _this, Integer* object, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_LANG_INTEGER_H_ */
