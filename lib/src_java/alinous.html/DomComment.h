#ifndef ALINOUS_HTML_DOMCOMMENT_H_
#define ALINOUS_HTML_DOMCOMMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class DomComment final : public DomNode {
public:
	DomComment(const DomComment& base) = default;
public:
	DomComment(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DomComment() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	StringBuffer* buff;
public:
	void addComment(String* token, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw()  final;
	int getType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_HTML_DOMCOMMENT_H_ */
