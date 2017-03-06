#ifndef JAVA_UTIL_ARRAYS_H_
#define JAVA_UTIL_ARRAYS_H_
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



class Arrays final : public virtual IObject {
public:
	Arrays(const Arrays& base) = default;
public:
	Arrays(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Arrays() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool equals(IArrayObjectPrimitive<char>* array1, IArrayObjectPrimitive<char>* array2, ThreadContext* ctx) throw() ;
	static bool equals(IArrayObjectPrimitive<short>* array1, IArrayObjectPrimitive<short>* array2, ThreadContext* ctx) throw() ;
	static bool equals(IArrayObjectPrimitive<wchar_t>* array1, IArrayObjectPrimitive<wchar_t>* array2, ThreadContext* ctx) throw() ;
	static bool equals(IArrayObjectPrimitive<int>* array1, IArrayObjectPrimitive<int>* array2, ThreadContext* ctx) throw() ;
	static bool equals(IArrayObjectPrimitive<long long>* array1, IArrayObjectPrimitive<long long>* array2, ThreadContext* ctx) throw() ;
	static bool equals(IArrayObjectPrimitive<double>* array1, IArrayObjectPrimitive<double>* array2, ThreadContext* ctx) throw() ;
	static bool equals(IArrayObjectPrimitive<bool>* array1, IArrayObjectPrimitive<bool>* array2, ThreadContext* ctx) throw() ;
	static bool equals(IArrayObjectPrimitive<float>* array1, IArrayObjectPrimitive<float>* array2, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<int>* groupBounds, int i, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<char>* array, char value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<char>* array, int start, int end, char value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<short>* array, short value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<short>* array, int start, int end, short value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<wchar_t>* array, wchar_t value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<wchar_t>* array, int start, int end, wchar_t value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<int>* array, int start, int end, int value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<long long>* array, long long value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<long long>* array, int start, int end, long long value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<float>* array, float value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<float>* array, int start, int end, float value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<double>* array, double value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<double>* array, int start, int end, double value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<bool>* array, bool value, ThreadContext* ctx) throw() ;
	static void fill(IArrayObjectPrimitive<bool>* array, int start, int end, bool value, ThreadContext* ctx) throw() ;
	static int binarySearch(IArrayObjectPrimitive<wchar_t>* array, wchar_t value, ThreadContext* ctx) throw() ;
	static int binarySearch(IArrayObjectPrimitive<int>* array, int value, ThreadContext* ctx) throw() ;
	static int binarySearch(IArrayObjectPrimitive<long long>* array, long long value, ThreadContext* ctx) throw() ;
	static int binarySearch(IArrayObjectPrimitive<short>* array, short value, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of JAVA_UTIL_ARRAYS_H_ */
