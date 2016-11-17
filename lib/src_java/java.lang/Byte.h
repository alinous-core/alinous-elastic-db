#ifndef JAVA_LANG_BYTE_H_
#define JAVA_LANG_BYTE_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Byte;}}

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



class Byte final : public Number, public Comparable<Byte> {
public:
	Byte(const Byte& base) = default;
public:
	Byte(char value, ThreadContext* ctx) throw() ;
	void __construct_impl(char value, ThreadContext* ctx) throw() ;
	Byte(String* string, ThreadContext* ctx);
	void __construct_impl(String* string, ThreadContext* ctx);
	virtual ~Byte() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	char value;
public:
	constexpr static const char MAX_VALUE{((char)0x7F)};
	constexpr static const char MIN_VALUE{((char)0x80)};
	constexpr static const int SIZE{8};
public:
	char byteValue(ThreadContext* ctx) throw()  final;
	int compareTo(Byte* object, ThreadContext* ctx) throw() ;
	double doubleValue(ThreadContext* ctx) throw()  final;
	bool equals(IObject* object, ThreadContext* ctx) throw() ;
	float floatValue(ThreadContext* ctx) throw()  final;
	int hashCode(ThreadContext* ctx) throw() ;
	int intValue(ThreadContext* ctx) throw()  final;
	long long longValue(ThreadContext* ctx) throw()  final;
	short shortValue(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static Byte* decode(String* string, ThreadContext* ctx);
	static char parseByte(String* string, ThreadContext* ctx);
	static char parseByte(String* string, int radix, ThreadContext* ctx);
	static String* toString(char value, ThreadContext* ctx) throw() ;
	static Byte* valueOf(String* string, ThreadContext* ctx);
	static Byte* valueOf(String* string, int radix, ThreadContext* ctx);
	static Byte* valueOf(char b, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (Byte* _this, Byte* object, ThreadContext* ctx) const throw();
	};
};

}}

#endif /* end of JAVA_LANG_BYTE_H_ */
