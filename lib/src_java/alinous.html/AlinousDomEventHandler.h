#ifndef ALINOUS_HTML_ALINOUSDOMEVENTHANDLER_H_
#define ALINOUS_HTML_ALINOUSDOMEVENTHANDLER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomComment;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {
class DomText;}}

namespace java {namespace util {
template <typename  T> class Stack;}}

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
using ::java::util::Stack;



class AlinousDomEventHandler final : public virtual IObject {
public:
	AlinousDomEventHandler(const AlinousDomEventHandler& base) = default;
public:
	AlinousDomEventHandler(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AlinousDomEventHandler() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DomNode* topObject;
	Stack<DomNode>* tagStack;
public:
	void reportCommentStarts(DomComment* comment, ThreadContext* ctx) throw() ;
	DomNode* reportTagAppears(DomNode* tag, bool singleEnds, ThreadContext* ctx) throw() ;
	DomNode* reportTagClosed(String* tagName, ThreadContext* ctx) throw() ;
	void parseEnd(ThreadContext* ctx) throw() ;
	void reportBodyString(DomText* bodyString, ThreadContext* ctx) throw() ;
	DomNode* getTopObject(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_ALINOUSDOMEVENTHANDLER_H_ */
