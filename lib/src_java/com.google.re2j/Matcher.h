#ifndef COM_GOOGLE_RE2J_MATCHER_H_
#define COM_GOOGLE_RE2J_MATCHER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace com {namespace google {namespace re2j {
class Pattern;}}}

namespace java {namespace lang {
class NullPointerException;}}

namespace com {namespace google {namespace re2j {
class RE2;}}}

namespace java {namespace lang {
class CharSequence;}}

namespace com {namespace google {namespace re2j {
class Matcher;}}}

namespace java {namespace lang {
class IllegalStateException;}}

namespace java {namespace lang {
class StringBuffer;}}

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



class Matcher final : public virtual IObject {
public:
	Matcher(const Matcher& base) = default;
public:
	Matcher(Pattern* pattern, ThreadContext* ctx) throw() ;
	void __construct_impl(Pattern* pattern, ThreadContext* ctx) throw() ;
	Matcher(Pattern* pattern, CharSequence* input, ThreadContext* ctx) throw() ;
	void __construct_impl(Pattern* pattern, CharSequence* input, ThreadContext* ctx) throw() ;
	virtual ~Matcher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Pattern* _pattern;
	IArrayObjectPrimitive<int>* groups;
	int _groupCount;
	CharSequence* inputSequence;
	int _inputLength;
	int appendPos;
	bool hasMatch;
	bool hasGroups;
	int anchorFlag;
public:
	Pattern* pattern(ThreadContext* ctx) throw() ;
	Matcher* reset(ThreadContext* ctx) throw() ;
	Matcher* reset(CharSequence* input, ThreadContext* ctx) throw() ;
	int start(ThreadContext* ctx) throw() ;
	int end(ThreadContext* ctx) throw() ;
	int start(int group, ThreadContext* ctx) throw() ;
	int end(int group, ThreadContext* ctx) throw() ;
	String* group(ThreadContext* ctx) throw() ;
	String* group(int group, ThreadContext* ctx) throw() ;
	int groupCount(ThreadContext* ctx) throw() ;
	bool matches(ThreadContext* ctx) throw() ;
	bool lookingAt(ThreadContext* ctx) throw() ;
	bool find(ThreadContext* ctx) throw() ;
	bool find(int start, ThreadContext* ctx) throw() ;
	Matcher* appendReplacement(StringBuffer* sb, String* replacement, ThreadContext* ctx) throw() ;
	StringBuffer* appendTail(StringBuffer* sb, ThreadContext* ctx) throw() ;
	String* replaceAll(String* replacement, ThreadContext* ctx) throw() ;
	String* replaceFirst(String* replacement, ThreadContext* ctx) throw() ;
	String* substring(int start, int end, ThreadContext* ctx) throw() ;
	int inputLength(ThreadContext* ctx) throw() ;
private:
	void loadGroup(int group, ThreadContext* ctx) throw() ;
	bool genMatch(int startByte, int anchor, ThreadContext* ctx) throw() ;
	String* replace(String* replacement, bool all, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_MATCHER_H_ */
