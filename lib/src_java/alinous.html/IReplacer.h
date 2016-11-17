#ifndef ALINOUS_HTML_IREPLACER_H_
#define ALINOUS_HTML_IREPLACER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

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



class IReplacer : public virtual IObject {
public:
	IReplacer(const IReplacer& base) = default;
public:
	IReplacer(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IReplacer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void addBodyString(String* str, ThreadContext* ctx) throw()  = 0;
	virtual void startTag(String* tag, bool endTag, ThreadContext* ctx) throw()  = 0;
	virtual void endTag(bool singleEnd, ThreadContext* ctx) throw()  = 0;
	virtual void attributeName(String* name, ThreadContext* ctx) throw()  = 0;
	virtual void attributeValue(String* name, ThreadContext* ctx) throw()  = 0;
	virtual void parseEnd(ThreadContext* ctx) throw()  = 0;
	virtual void startComment(ThreadContext* ctx) throw()  = 0;
	virtual void endComment(ThreadContext* ctx) throw()  = 0;
	virtual void addComment(String* comment, ThreadContext* ctx) throw()  = 0;
	virtual DomNode* getCurrentTag(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_IREPLACER_H_ */
