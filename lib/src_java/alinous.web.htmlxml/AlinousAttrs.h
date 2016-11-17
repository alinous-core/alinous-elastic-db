#ifndef ALINOUS_WEB_HTMLXML_ALINOUSATTRS_H_
#define ALINOUS_WEB_HTMLXML_ALINOUSATTRS_H_
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



class AlinousAttrs final : public virtual IObject {
public:
	AlinousAttrs(const AlinousAttrs& base) = default;
public:
	AlinousAttrs(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousAttrs() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* ALINOUS_IF;
	static String* ALINOUS_INNER;
	static String* ALINOUS_TAGID;
	static String* ALINOUS_TARGET;
	static String* ALINOUS_ITERATE;
	static String* ALINOUS_VARIABLE;
	static String* ALINOUS_MSG;
	static String* ALINOUS_MSG_TARGET;
	static String* ALINOUS_FORM;
	static String* ALINOUS_BACK;
	static String* ALINOUS_VALIDATE_TYPE;
	static String* ALINOUS_VALIDATE_IF;
	static String* ALINOUS_REGEX;
	static String* ALINOUS_PARAM;
	static String* ALINOUS_TYPE;
	static String* ALINOUS_NO_FORM_CACHE;
	static String* ALINOUS_IGNOREBLANK;
	static String* ALINOUS_IGNORE_SELF_ITERATE;
	static String* ALINOUS_EXTRACT;
	static String* ALINOUS_COMPONENT;
	static String* ALINOUS_COMPONENT_ID;
	static String* ALINOUS_COMPONENT_WIDTH;
	static String* ALINOUS_COMPONENT_EDIT;
	static String* ALINOUS_COMPONENT_VIEW;
	static String* ALINOUS_COMPONENT_VIEWTYPE;
	static String* ALINOUS_COMPONENT_ROOT;
	static String* VALUE_TRUE;
	static String* VALUE_FALSE;
	static String* VALUE_VIEWTYPE_FRAME;
	static String* VALUE_VIEWTYPE_INNER;
	static String* ALINOUS_ALINOUS_FORM;
public:
	static bool isAlinousAttr(String* attrStr, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_ALINOUSATTRS_H_ */
