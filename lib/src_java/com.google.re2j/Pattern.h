#ifndef COM_GOOGLE_RE2J_PATTERN_H_
#define COM_GOOGLE_RE2J_PATTERN_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class RE2;}}}

namespace java {namespace lang {
class NullPointerException;}}

namespace com {namespace google {namespace re2j {
class Pattern;}}}

namespace java {namespace lang {
class IllegalArgumentException;}}

namespace java {namespace lang {
class CharSequence;}}

namespace com {namespace google {namespace re2j {
class Matcher;}}}

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



class Pattern final : public virtual IObject {
public:
	Pattern(const Pattern& base) = default;
public:
	Pattern(String* pattern, int flags, RE2* re2, ThreadContext* ctx) throw() ;
	void __construct_impl(String* pattern, int flags, RE2* re2, ThreadContext* ctx) throw() ;
	virtual ~Pattern() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* _pattern;
	int _flags;
	RE2* _re2;
public:
	constexpr static const int CASE_INSENSITIVE{1};
	constexpr static const int DOTALL{2};
	constexpr static const int MULTILINE{4};
	constexpr static const int DISABLE_UNICODE_GROUPS{8};
public:
	void reset(ThreadContext* ctx) throw() ;
	int flags(ThreadContext* ctx) throw() ;
	String* pattern(ThreadContext* ctx) throw() ;
	RE2* re2(ThreadContext* ctx) throw() ;
	bool matches(String* input, ThreadContext* ctx) throw() ;
	Matcher* matcher(CharSequence* input, ThreadContext* ctx) throw() ;
	IArrayObject<String>* split(String* input, ThreadContext* ctx) throw() ;
	IArrayObject<String>* split(String* input, int limit, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	int groupCount(ThreadContext* ctx) throw() ;
	IObject* readReplace(ThreadContext* ctx);
private:
	IArrayObject<String>* split(Matcher* m, int limit, ThreadContext* ctx) throw() ;
public:
	static Pattern* compile(String* regex, ThreadContext* ctx);
	static Pattern* compile(String* regex, int flags, ThreadContext* ctx);
	static bool matches(String* regex, CharSequence* input, ThreadContext* ctx);
	static String* quote(String* s, ThreadContext* ctx) throw() ;
private:
	static Pattern* compile(String* flregex, String* regex, int flags, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_PATTERN_H_ */
