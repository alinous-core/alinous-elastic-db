#ifndef ALINOUS_HTML_XPATH_ATTRIBUTEIDENTIFIER_H_
#define ALINOUS_HTML_XPATH_ATTRIBUTEIDENTIFIER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class XpathIdentifier;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class AttributeIdentifier final : public XpathIdentifier {
public:
	AttributeIdentifier(const AttributeIdentifier& base) = default;
public:
	AttributeIdentifier(String* id, ThreadContext* ctx) throw() ;
	void __construct_impl(String* id, ThreadContext* ctx) throw() ;
	virtual ~AttributeIdentifier() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* toString(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_ATTRIBUTEIDENTIFIER_H_ */
