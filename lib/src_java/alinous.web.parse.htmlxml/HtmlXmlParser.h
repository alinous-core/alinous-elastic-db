#ifndef ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSER_H_
#define ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSER_H_
namespace alinous {namespace web {namespace htmlxml {
class HtmlTopObject;}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace alinous {namespace web {namespace htmlxml {
class HtmlDocType;}}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class ParseException;}}}}

namespace java {namespace lang {
class Error;}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class Token;}}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlDqString;}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlAttribute;}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlComment;}}}

namespace alinous {namespace web {namespace htmlxml {
class XMLTagBase;}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlAttributeValue;}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlSQString;}}}

namespace alinous {namespace web {namespace htmlxml {
class BodyText;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class JavaCharStream;}}}}

namespace java {namespace lang {
class RuntimeException;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class HtmlXmlParserTokenManager;}}}}

namespace java {namespace io {
class Reader;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class HtmlXmlParserConstants;}}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::AbstractXHtmlAttributeValue;
using ::alinous::web::htmlxml::AbstractXHtmlElement;
using ::alinous::web::htmlxml::BodyText;
using ::alinous::web::htmlxml::HtmlDocType;
using ::alinous::web::htmlxml::HtmlTopObject;
using ::alinous::web::htmlxml::XHtmlAttribute;
using ::alinous::web::htmlxml::XHtmlComment;
using ::alinous::web::htmlxml::XHtmlDqString;
using ::alinous::web::htmlxml::XHtmlSQString;
using ::alinous::web::htmlxml::XMLTagBase;



class HtmlXmlParser final : public HtmlXmlParserConstants, public virtual IObject {
public:
	class LookaheadSuccess;
	class JJCalls;
	HtmlXmlParser(const HtmlXmlParser& base) = default;
public:
	HtmlXmlParser(java::io::InputStream* stream, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* stream, ThreadContext* ctx);
	HtmlXmlParser(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	HtmlXmlParser(java::io::Reader* stream, ThreadContext* ctx);
	void __construct_impl(java::io::Reader* stream, ThreadContext* ctx);
	HtmlXmlParser(HtmlXmlParserTokenManager* tm, ThreadContext* ctx);
	void __construct_impl(HtmlXmlParserTokenManager* tm, ThreadContext* ctx);
	virtual ~HtmlXmlParser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	HtmlXmlParserTokenManager* token_source;
	Token* token;
	Token* jj_nt;
	JavaCharStream* jj_input_stream;
private:
	long long jj_ntk;
	Token* jj_scanpos; Token* jj_lastpos;
	long long jj_la;
	long long jj_gen;
	IArrayObjectPrimitive<long long>* jj_la1;
	IArrayObject<JJCalls>* jj_2_rtns;
	bool jj_rescan;
	long long jj_gc;
	HtmlXmlParser::LookaheadSuccess* jj_ls;
	java::util::List<IArrayObjectPrimitive<long long>>* jj_expentries;
	IArrayObjectPrimitive<long long>* jj_expentry;
	long long jj_kind;
	IArrayObjectPrimitive<long long>* jj_lasttokens;
	long long jj_endpos;
private:
	static IArrayObjectPrimitive<long long>* jj_la1_0;
public:
	HtmlTopObject* parse(ThreadContext* ctx);
	HtmlDocType* docType(ThreadContext* ctx);
	XHtmlComment* comment(ThreadContext* ctx);
	XMLTagBase* tagObject(ThreadContext* ctx);
	XMLTagBase* normalTagObject(ThreadContext* ctx);
	void singleTagObjectLookAhead(ThreadContext* ctx);
	XMLTagBase* singleTagObject(ThreadContext* ctx);
	XMLTagBase* htmlSingleTagObject(ThreadContext* ctx);
	XHtmlAttribute* attribute(ThreadContext* ctx);
	void skipWhiteSpace(ThreadContext* ctx);
	void skipWhiteSpace2(ThreadContext* ctx);
	BodyText* bodyText(ThreadContext* ctx);
	void ReInit(java::io::InputStream* stream, ThreadContext* ctx);
	void ReInit(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	void ReInit(java::io::Reader* stream, ThreadContext* ctx);
	void ReInit(HtmlXmlParserTokenManager* tm, ThreadContext* ctx);
	Token* getNextToken(ThreadContext* ctx);
	Token* getToken(long long index, ThreadContext* ctx);
	ParseException* generateParseException(ThreadContext* ctx);
	void enable_tracing(ThreadContext* ctx);
	void disable_tracing(ThreadContext* ctx);
private:
	bool jj_2_1(long long xla, ThreadContext* ctx);
	bool jj_2_2(long long xla, ThreadContext* ctx);
	bool jj_2_3(long long xla, ThreadContext* ctx);
	bool jj_2_4(long long xla, ThreadContext* ctx);
	bool jj_2_5(long long xla, ThreadContext* ctx);
	bool jj_2_6(long long xla, ThreadContext* ctx);
	bool jj_3R_18(ThreadContext* ctx);
	bool jj_3R_15(ThreadContext* ctx);
	bool jj_3R_14(ThreadContext* ctx);
	bool jj_3_5(ThreadContext* ctx);
	bool jj_3_2(ThreadContext* ctx);
	bool jj_3R_17(ThreadContext* ctx);
	bool jj_3_3(ThreadContext* ctx);
	bool jj_3_4(ThreadContext* ctx);
	bool jj_3R_13(ThreadContext* ctx);
	bool jj_3R_12(ThreadContext* ctx);
	bool jj_3R_11(ThreadContext* ctx);
	bool jj_3R_16(ThreadContext* ctx);
	bool jj_3_1(ThreadContext* ctx);
	bool jj_3_6(ThreadContext* ctx);
	Token* jj_consume_token(long long kind, ThreadContext* ctx);
	bool jj_scan_token(long long kind, ThreadContext* ctx);
	long long jj_ntk_f(ThreadContext* ctx);
	void jj_add_error_token(long long kind, long long pos, ThreadContext* ctx);
	void jj_rescan_token(ThreadContext* ctx);
	void jj_save(long long index, long long xla, ThreadContext* ctx);
private:
	static void jj_la1_init_0(ThreadContext* ctx);
public:



	class LookaheadSuccess final : public java::lang::Error {
	public:
		LookaheadSuccess(const LookaheadSuccess& base) = default;
	public:
		LookaheadSuccess(ThreadContext* ctx) throw()  : IObject(ctx), java::lang::Error(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~LookaheadSuccess() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class JJCalls final : public virtual IObject {
	public:
		JJCalls(const JJCalls& base) = default;
	public:
		JJCalls(ThreadContext* ctx) throw()  : IObject(ctx), gen(0), first(nullptr), arg(0), next(nullptr)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~JJCalls() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		long long gen;
		Token* first;
		long long arg;
		HtmlXmlParser::JJCalls* next;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, HtmlXmlParser::jj_la1_0, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
	}
};

}}}}

#endif /* end of ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSER_H_ */
