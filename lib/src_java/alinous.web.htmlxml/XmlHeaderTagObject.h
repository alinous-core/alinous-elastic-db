#ifndef ALINOUS_WEB_HTMLXML_XMLHEADERTAGOBJECT_H_
#define ALINOUS_WEB_HTMLXML_XMLHEADERTAGOBJECT_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class XmlHeaderTagObject final : public virtual IObject {
public:
	XmlHeaderTagObject(const XmlHeaderTagObject& base) = default;
public:
	XmlHeaderTagObject(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~XmlHeaderTagObject() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_XMLHEADERTAGOBJECT_H_ */
