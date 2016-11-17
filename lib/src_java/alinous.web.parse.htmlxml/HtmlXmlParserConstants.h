#ifndef ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSERCONSTANTS_H_
#define ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSERCONSTANTS_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace parse {namespace htmlxml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class HtmlXmlParserConstants : public virtual IObject {
public:
	HtmlXmlParserConstants(const HtmlXmlParserConstants& base) = default;
public:
	HtmlXmlParserConstants(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~HtmlXmlParserConstants() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const long long EOF{0};
	constexpr static const long long br{1};
	constexpr static const long long img{2};
	constexpr static const long long link{3};
	constexpr static const long long meta{4};
	constexpr static const long long col{5};
	constexpr static const long long param{6};
	constexpr static const long long base{7};
	constexpr static const long long area{8};
	constexpr static const long long hr{9};
	constexpr static const long long input{10};
	constexpr static const long long GT{11};
	constexpr static const long long LT{12};
	constexpr static const long long LT_SLASH{13};
	constexpr static const long long GT_SLASH{14};
	constexpr static const long long EQUALS{15};
	constexpr static const long long CDATA_START{16};
	constexpr static const long long CDATA_END{17};
	constexpr static const long long XML_HEADER_START{18};
	constexpr static const long long XML_HEADER_END{19};
	constexpr static const long long DOCTYPE{20};
	constexpr static const long long COM_START{21};
	constexpr static const long long COMMENT{22};
	constexpr static const long long WHITE_SPACE{24};
	constexpr static const long long STRING_LITERAL{25};
	constexpr static const long long SQ_STRING_LITERAL{26};
	constexpr static const long long IDENTIFIER_BASE{27};
	constexpr static const long long IDENTIFIER{28};
	constexpr static const long long HTML_BODY_STRING{29};
	constexpr static const long long DEFAULT{0};
	constexpr static const long long COMM{1};
	static const StaticArrayObject<UnicodeStringWrapper> __tokenImage;
	static IArrayObject<String>* tokenImage;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSERCONSTANTS_H_ */
