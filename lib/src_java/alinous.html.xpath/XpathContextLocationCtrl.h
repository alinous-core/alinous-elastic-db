#ifndef ALINOUS_HTML_XPATH_XPATHCONTEXTLOCATIONCTRL_H_
#define ALINOUS_HTML_XPATH_XPATHCONTEXTLOCATIONCTRL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;

class __XpathContextLocationCtrl__CtrlType : public EnumBase {
public:
	__XpathContextLocationCtrl__CtrlType() = default;
	constexpr __XpathContextLocationCtrl__CtrlType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __XpathContextLocationCtrl__CtrlType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  current{1};
	static constexpr EnumBase  parent{2};
	static constexpr EnumBase  children{3};
	static constexpr EnumBase  all{4};
};


class XpathContextLocationCtrl final : public virtual IObject {
public:
	class CtrlType : public __XpathContextLocationCtrl__CtrlType {
	public:
		CtrlType() = default;constexpr CtrlType(const EnumBase& base) :  __XpathContextLocationCtrl__CtrlType(base) {};
	};
public:
	XpathContextLocationCtrl(const XpathContextLocationCtrl& base) = default;
public:
	XpathContextLocationCtrl(XpathContextLocationCtrl::CtrlType type, ThreadContext* ctx) throw() ;
	void __construct_impl(XpathContextLocationCtrl::CtrlType type, ThreadContext* ctx) throw() ;
	virtual ~XpathContextLocationCtrl() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	XpathContextLocationCtrl::CtrlType type;
public:
	XpathContextLocationCtrl::CtrlType getType(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHCONTEXTLOCATIONCTRL_H_ */
