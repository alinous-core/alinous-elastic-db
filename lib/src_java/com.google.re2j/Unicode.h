#ifndef COM_GOOGLE_RE2J_UNICODE_H_
#define COM_GOOGLE_RE2J_UNICODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace com {namespace google {namespace re2j {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class Unicode final : public virtual IObject {
public:
	Unicode(const Unicode& base) = default;
public:
	Unicode(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Unicode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int MAX_RUNE{0x10FFFF};
	constexpr static const int MAX_ASCII{0x7f};
	constexpr static const int MAX_LATIN1{0xFF};
	constexpr static const int MIN_FOLD{0x0041};
	constexpr static const int MAX_FOLD{0x1044f};
private:
	constexpr static const int MAX_CASE{3};
	constexpr static const int REPLACEMENT_CHAR{0xFFFD};
public:
	static bool isUpper(int r, ThreadContext* ctx) throw() ;
	static bool isLower(int r, ThreadContext* ctx) throw() ;
	static bool isTitle(int r, ThreadContext* ctx) throw() ;
	static bool isPrint(int r, ThreadContext* ctx) throw() ;
	static int toUpper(int r, ThreadContext* ctx) throw() ;
	static int toLower(int r, ThreadContext* ctx) throw() ;
	static int simpleFold(int r, ThreadContext* ctx) throw() ;
private:
	static bool is32(IArrayObject<IArrayObjectPrimitive<int>>* ranges, int r, ThreadContext* ctx) throw() ;
	static bool is(IArrayObject<IArrayObjectPrimitive<int>>* ranges, int r, ThreadContext* ctx) throw() ;
	static int to(int kase, int r, IArrayObject<IArrayObjectPrimitive<int>>* caseRange, ThreadContext* ctx) throw() ;
	static int to(int kase, int r, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_UNICODE_H_ */
