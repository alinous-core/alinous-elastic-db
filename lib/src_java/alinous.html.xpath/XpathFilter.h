#ifndef ALINOUS_HTML_XPATH_XPATHFILTER_H_
#define ALINOUS_HTML_XPATH_XPATHFILTER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IXpathBooleanCondition;}}}

namespace alinous {namespace html {namespace xpath {
class Xpath2Compare;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathNumber;}}}

namespace alinous {namespace html {namespace xpath {
class XpathFunction;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace java {namespace lang {
class StringBuffer;}}

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

class __XpathFilter__FilterType : public EnumBase {
public:
	__XpathFilter__FilterType() = default;
	constexpr __XpathFilter__FilterType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __XpathFilter__FilterType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  logical{1};
	static constexpr EnumBase  index_number{2};
};


class XpathFilter final : public IXpathElement, public virtual IObject {
public:
	class FilterType : public __XpathFilter__FilterType {
	public:
		FilterType() = default;constexpr FilterType(const EnumBase& base) :  __XpathFilter__FilterType(base) {};
	};
public:
	XpathFilter(const XpathFilter& base) = default;
public:
	XpathFilter(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), condition(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~XpathFilter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IXpathBooleanCondition* condition;
public:
	IXpathBooleanCondition* getCondition(ThreadContext* ctx) throw() ;
	void setCondition(IXpathBooleanCondition* condition, ThreadContext* ctx) throw() ;
	bool isIndex(ThreadContext* ctx) throw() ;
	IXpathStatement* getIndexStatement(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHFILTER_H_ */
