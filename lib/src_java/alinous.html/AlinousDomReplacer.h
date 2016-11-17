#ifndef ALINOUS_HTML_ALINOUSDOMREPLACER_H_
#define ALINOUS_HTML_ALINOUSDOMREPLACER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomText;}}

namespace alinous {namespace html {
class DomComment;}}

namespace alinous {namespace html {
class DocType;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace html {
class AlinousDomEventHandler;}}

namespace alinous {namespace html {
class IReplacer;}}

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



class AlinousDomReplacer final : public IReplacer, public virtual IObject {
public:
	AlinousDomReplacer(const AlinousDomReplacer& base) = default;
public:
	AlinousDomReplacer(ThreadContext* ctx) throw()  : IObject(ctx), IReplacer(ctx), currentAttribute(nullptr), currentTag(nullptr), processingTagIsEnd(0), eventHandler(__GC_INS(this, (new(ctx) AlinousDomEventHandler(ctx)), AlinousDomEventHandler))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousDomReplacer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Attribute* currentAttribute;
	DomNode* currentTag;
	bool processingTagIsEnd;
	AlinousDomEventHandler* eventHandler;
public:
	DomDocument* getDocument(ThreadContext* ctx) throw() ;
	void addBodyString(String* str, ThreadContext* ctx) throw()  final;
	void startComment(ThreadContext* ctx) throw()  final;
	void endComment(ThreadContext* ctx) throw()  final;
	void addComment(String* comment, ThreadContext* ctx) throw()  final;
	void startTag(String* tag, bool endTag, ThreadContext* ctx) throw()  final;
	void endTag(bool singleEnd, ThreadContext* ctx) throw()  final;
	void attributeName(String* name, ThreadContext* ctx) throw()  final;
	void attributeValue(String* value, ThreadContext* ctx) throw()  final;
	void parseEnd(ThreadContext* ctx) throw()  final;
	DomNode* getCurrentTag(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_ALINOUSDOMREPLACER_H_ */
