#ifndef ALINOUS_WEB_HTMLXML_INNER_INNERSTRINGPARSER_H_
#define ALINOUS_WEB_HTMLXML_INNER_INNERSTRINGPARSER_H_
namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class StaticHtmlString;}}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class HTmlProgramString;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {namespace inner {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::system::AlinousException;

class __InnerStringParser__Status : public EnumBase {
public:
	__InnerStringParser__Status() = default;
	constexpr __InnerStringParser__Status(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __InnerStringParser__Status(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  BODY{1};
	static constexpr EnumBase  ESCAPED{2};
	static constexpr EnumBase  PROG{3};
};


class InnerStringParser final : public virtual IObject {
public:
	class Status : public __InnerStringParser__Status {
	public:
		Status() = default;constexpr Status(const EnumBase& base) :  __InnerStringParser__Status(base) {};
	};
public:
	InnerStringParser(const InnerStringParser& base) = default;
public:
	InnerStringParser(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~InnerStringParser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static ArrayList<IHtmlStringPart>* parse(String* str, ThreadContext* ctx);
private:
	static InnerStringParser::Status handleProg(wchar_t ch, StringBuffer* buff, ArrayList<IHtmlStringPart>* result, ThreadContext* ctx);
	static InnerStringParser::Status handleBody(wchar_t ch, StringBuffer* buff, ArrayList<IHtmlStringPart>* result, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_INNER_INNERSTRINGPARSER_H_ */
