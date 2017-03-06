#ifndef ALINOUS_HTML_DOMDOCUMENT_H_
#define ALINOUS_HTML_DOMDOCUMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {
class IDomObject;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Iterator;



class DomDocument final : public DomNode {
public:
	DomDocument(const DomDocument& base) = default;
public:
	DomDocument(String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ThreadContext* ctx) throw() ;
	virtual ~DomDocument() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* getPathString(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw()  final;
	int getType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_HTML_DOMDOCUMENT_H_ */
