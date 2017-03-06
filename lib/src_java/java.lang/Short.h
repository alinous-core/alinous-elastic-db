#ifndef JAVA_LANG_SHORT_H_
#define JAVA_LANG_SHORT_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Short;}}

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



class Short final : public Number, public Comparable<Short> {
public:
	Short(const Short& base) = default;
public:
	Short(String* string, ThreadContext* ctx);
	void __construct_impl(String* string, ThreadContext* ctx);
	Short(short value, ThreadContext* ctx) throw() ;
	void __construct_impl(short value, ThreadContext* ctx) throw() ;
	virtual ~Short() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	short value;
public:
	constexpr static const short MAX_VALUE{((short)0x7FFF)};
	constexpr static const short MIN_VALUE{((short)0x8000)};
	constexpr static const int SIZE{16};
public:
	char byteValue(ThreadContext* ctx) throw()  final;
	int compareTo(Short* object, ThreadContext* ctx) throw() ;
	double doubleValue(ThreadContext* ctx) throw()  final;
	bool equals(IObject* object, ThreadContext* ctx) throw() ;
	float floatValue(ThreadContext* ctx) throw()  final;
	int hashCode(ThreadContext* ctx) throw() ;
	int intValue(ThreadContext* ctx) throw()  final;
	long long longValue(ThreadContext* ctx) throw()  final;
	short shortValue(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static Short* decode(String* string, ThreadContext* ctx);
	static short parseShort(String* string, ThreadContext* ctx);
	static short parseShort(String* string, int radix, ThreadContext* ctx);
	static String* toString(short value, ThreadContext* ctx) throw() ;
	static Short* valueOf(String* string, ThreadContext* ctx);
	static Short* valueOf(String* string, int radix, ThreadContext* ctx);
	static short reverseBytes(short s, ThreadContext* ctx) throw() ;
	static Short* valueOf(short s, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (Short* _this, Short* object, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_LANG_SHORT_H_ */
