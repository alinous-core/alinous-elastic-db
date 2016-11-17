#ifndef ALINOUS_HTML_DOMTOKENIZER_H_
#define ALINOUS_HTML_DOMTOKENIZER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class LinkedList;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::LinkedList;



class DomTokenizer final : public virtual IObject {
public:
	DomTokenizer(const DomTokenizer& base) = default;
public:
	DomTokenizer(String* html, ThreadContext* ctx) throw() ;
	void __construct_impl(String* html, ThreadContext* ctx) throw() ;
	virtual ~DomTokenizer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* html;
	int pos;
	IArrayObjectPrimitive<wchar_t>* stopChars;
	String* reservedToken;
	LinkedList<String>* lookAheadList;
public:
	String* lookAhead(ThreadContext* ctx) throw() ;
	String* getToken(ThreadContext* ctx) throw() ;
	String* lookAhead(int ahead, ThreadContext* ctx) throw() ;
private:
	String* doGetToken(ThreadContext* ctx) throw() ;
	bool isEof(ThreadContext* ctx) throw() ;
	bool isStopchar(wchar_t ch, ThreadContext* ctx) throw() ;
	wchar_t getChar(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_DOMTOKENIZER_H_ */
