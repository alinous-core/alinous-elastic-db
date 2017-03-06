#ifndef COM_GOOGLE_RE2J_UTILS_H_
#define COM_GOOGLE_RE2J_UTILS_H_
namespace java {namespace lang {
class StringBuilder;}}

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



class Utils final : public virtual IObject {
public:
	Utils(const Utils& base) = default;
public:
	Utils(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Utils() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static const StaticArrayObjectPrimitive<int> __EMPTY_INTS;
	static IArrayObjectPrimitive<int>* EMPTY_INTS;
	constexpr static const int EMPTY_BEGIN_LINE{0x01};
	constexpr static const int EMPTY_END_LINE{0x02};
	constexpr static const int EMPTY_BEGIN_TEXT{0x04};
	constexpr static const int EMPTY_END_TEXT{0x08};
	constexpr static const int EMPTY_WORD_BOUNDARY{0x10};
	constexpr static const int EMPTY_NO_WORD_BOUNDARY{0x20};
	constexpr static const int EMPTY_ALL{-1};
private:
	static String* METACHARACTERS;
public:
	static bool isalnum(int c, ThreadContext* ctx) throw() ;
	static int unhex(int c, ThreadContext* ctx) throw() ;
	static void escapeRune(StringBuilder* out, int rune, ThreadContext* ctx) throw() ;
	static IArrayObjectPrimitive<int>* stringToRunes(String* str, ThreadContext* ctx) throw() ;
	static String* runeToString(int r, ThreadContext* ctx) throw() ;
	static IArrayObjectPrimitive<int>* subarray(IArrayObjectPrimitive<int>* array, int start, int end, ThreadContext* ctx) throw() ;
	static IArrayObjectPrimitive<char>* subarray(IArrayObjectPrimitive<char>* array, int start, int end, ThreadContext* ctx) throw() ;
	static int indexOf(IArrayObjectPrimitive<char>* source, IArrayObjectPrimitive<char>* target, int fromIndex, ThreadContext* ctx) throw() ;
	static bool isWordRune(int r, ThreadContext* ctx) throw() ;
	static int emptyOpContext(int r1, int r2, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of COM_GOOGLE_RE2J_UTILS_H_ */
