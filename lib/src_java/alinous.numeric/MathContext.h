#ifndef ALINOUS_NUMERIC_MATHCONTEXT_H_
#define ALINOUS_NUMERIC_MATHCONTEXT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class RoundingMode;}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace alinous {namespace numeric {
class MathContext;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace numeric {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class MathContext final : public virtual IObject {
public:
	MathContext(const MathContext& base) = default;
public:
	MathContext(int precision, ThreadContext* ctx) throw() ;
	void __construct_impl(int precision, ThreadContext* ctx) throw() ;
	MathContext(int precision, int roundingMode, ThreadContext* ctx) throw() ;
	void __construct_impl(int precision, int roundingMode, ThreadContext* ctx) throw() ;
	MathContext(int precision, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	void __construct_impl(int precision, RoundingMode* roundingMode, ThreadContext* ctx) throw() ;
	MathContext(String* val, ThreadContext* ctx) throw() ;
	void __construct_impl(String* val, ThreadContext* ctx) throw() ;
	virtual ~MathContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int precision;
	RoundingMode* roundingMode;
public:
	static MathContext* DECIMAL128;
	static MathContext* DECIMAL32;
	static MathContext* DECIMAL64;
	static MathContext* UNLIMITED;
private:
	static const StaticArrayObjectPrimitive<wchar_t> __chPrecision;
	static IArrayObjectPrimitive<wchar_t>* chPrecision;
	static const StaticArrayObjectPrimitive<wchar_t> __chRoundingMode;
	static IArrayObjectPrimitive<wchar_t>* chRoundingMode;
public:
	int getPrecision(ThreadContext* ctx) throw() ;
	RoundingMode* getRoundingMode(ThreadContext* ctx) throw() ;
	bool equals(IObject* x, ThreadContext* ctx) throw() ;
	int hashCode(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<MathContext>::dec(nullptr, MathContext::DECIMAL128, ctx, __FILEW__, __LINE__, L"MathContext");
		GCUtils<MathContext>::dec(nullptr, MathContext::DECIMAL32, ctx, __FILEW__, __LINE__, L"MathContext");
		GCUtils<MathContext>::dec(nullptr, MathContext::DECIMAL64, ctx, __FILEW__, __LINE__, L"MathContext");
		GCUtils<MathContext>::dec(nullptr, MathContext::UNLIMITED, ctx, __FILEW__, __LINE__, L"MathContext");
	}
};

}}

#endif /* end of ALINOUS_NUMERIC_MATHCONTEXT_H_ */
