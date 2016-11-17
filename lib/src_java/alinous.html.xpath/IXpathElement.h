#ifndef ALINOUS_HTML_XPATH_IXPATHELEMENT_H_
#define ALINOUS_HTML_XPATH_IXPATHELEMENT_H_
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

class __IXpathElement__ScanPolicy : public EnumBase {
public:
	__IXpathElement__ScanPolicy() = default;
	constexpr __IXpathElement__ScanPolicy(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __IXpathElement__ScanPolicy(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  scan_all_inherited_children{1};
	static constexpr EnumBase  scan_children{2};
	static constexpr EnumBase  scan_this_only{3};
};
class __IXpathElement__ScanTarget : public EnumBase {
public:
	__IXpathElement__ScanTarget() = default;
	constexpr __IXpathElement__ScanTarget(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __IXpathElement__ScanTarget(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  node{1};
	static constexpr EnumBase  attribute{2};
	static constexpr EnumBase  value{3};
};


class IXpathElement : public virtual IObject {
public:
	class ScanPolicy : public __IXpathElement__ScanPolicy {
	public:
		ScanPolicy() = default;constexpr ScanPolicy(const EnumBase& base) :  __IXpathElement__ScanPolicy(base) {};
	};
public:
	class ScanTarget : public __IXpathElement__ScanTarget {
	public:
		ScanTarget() = default;constexpr ScanTarget(const EnumBase& base) :  __IXpathElement__ScanTarget(base) {};
	};
public:
	IXpathElement(const IXpathElement& base) = default;
public:
	IXpathElement(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IXpathElement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_IXPATHELEMENT_H_ */
