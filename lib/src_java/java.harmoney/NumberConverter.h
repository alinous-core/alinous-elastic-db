#ifndef JAVA_HARMONEY_NUMBERCONVERTER_H_
#define JAVA_HARMONEY_NUMBERCONVERTER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace harmoney {
class NumberConverter;}}

namespace java {namespace lang {
class Double;}}

namespace java {namespace lang {
class Integer;}}

namespace java {namespace lang {
class Math;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace java {namespace harmoney {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class NumberConverter final : public virtual IObject {
public:
	NumberConverter(const NumberConverter& base) = default;
public:
	NumberConverter(ThreadContext* ctx) throw()  : IObject(ctx), setCount(0), getCount(0), uArray(__GC_INS(this, ((IArrayObjectPrimitive<int>*)new(ctx) ArrayObjectPrimitive<int>(ArrayAllocatorPrimitive<int>::allocatep(ctx, 64), ctx)), IArrayObjectPrimitive<int>)), firstK(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NumberConverter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int setCount;
	int getCount;
	IArrayObjectPrimitive<int>* uArray;
	int firstK;
private:
	static double invLogOfTenBaseTwo;
	static IArrayObjectPrimitive<long long>* TEN_TO_THE;
public:
	String* convertD(double inputNumber, ThreadContext* ctx) throw() ;
private:
	String* freeFormatExponential(ThreadContext* ctx) throw() ;
	String* freeFormat(ThreadContext* ctx) throw() ;
	void bigIntDigitGeneratorInstImpl(long long f, int e, bool isDenormalized, bool mantissaIsZero, int p, ThreadContext* ctx) throw() ;
	void longDigitGenerator(long long f, int e, bool isDenormalized, bool mantissaIsZero, int p, ThreadContext* ctx) throw() ;
public:
	static String* convert(double input, ThreadContext* ctx) throw() ;
private:
	static NumberConverter* getConverter(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, NumberConverter::TEN_TO_THE, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
	}
};

}}

#endif /* end of JAVA_HARMONEY_NUMBERCONVERTER_H_ */
