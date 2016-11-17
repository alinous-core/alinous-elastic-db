#ifndef ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSER_H_
#define ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class Xpath;}}}

namespace alinous {namespace html {namespace xpath {
class XpathContext;}}}

namespace java {namespace lang {
class Error;}}

namespace alinous {namespace html {namespace xpath {
class XpathFilter;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathContextLocation;}}}

namespace alinous {namespace parser {namespace xpath {
class ParseException;}}}

namespace alinous {namespace html {namespace xpath {
class XpathContextLocationCtrl;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathBooleanCondition;}}}

namespace alinous {namespace html {namespace xpath {
class XpathOrStatement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathAndStatement;}}}

namespace alinous {namespace parser {namespace xpath {
class Token;}}}

namespace alinous {namespace html {namespace xpath {
class XpathNotStatement;}}}

namespace alinous {namespace html {namespace xpath {
class Xpath2Compare;}}}

namespace alinous {namespace html {namespace xpath {
class XpathFunction;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathFunctionArgument;}}}

namespace alinous {namespace html {namespace xpath {
class XpathReference;}}}

namespace alinous {namespace html {namespace xpath {
class XpathNumber;}}}

namespace alinous {namespace html {namespace xpath {
class XpathString;}}}

namespace alinous {namespace html {namespace xpath {
class AttributeIdentifier;}}}

namespace alinous {namespace html {namespace xpath {
class XpathIdentifier;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace parser {namespace xpath {
class JavaCharStream;}}}

namespace java {namespace lang {
class RuntimeException;}}

namespace java {namespace io {
class UnsupportedEncodingException;}}

namespace alinous {namespace parser {namespace xpath {
class AlinousXpathParserTokenManager;}}}

namespace java {namespace io {
class Reader;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace parser {namespace xpath {
class AlinousXpathParserConstants;}}}

namespace alinous {namespace html {namespace xpath {
class XPathParser;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace parser {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::xpath::AttributeIdentifier;
using ::alinous::html::xpath::IXpathBooleanCondition;
using ::alinous::html::xpath::IXpathElement;
using ::alinous::html::xpath::IXpathStatement;
using ::alinous::html::xpath::XPathParser;
using ::alinous::html::xpath::Xpath;
using ::alinous::html::xpath::Xpath2Compare;
using ::alinous::html::xpath::XpathAndStatement;
using ::alinous::html::xpath::XpathContext;
using ::alinous::html::xpath::XpathContextLocation;
using ::alinous::html::xpath::XpathContextLocationCtrl;
using ::alinous::html::xpath::XpathFilter;
using ::alinous::html::xpath::XpathFunction;
using ::alinous::html::xpath::XpathFunctionArgument;
using ::alinous::html::xpath::XpathIdentifier;
using ::alinous::html::xpath::XpathNotStatement;
using ::alinous::html::xpath::XpathNumber;
using ::alinous::html::xpath::XpathOrStatement;
using ::alinous::html::xpath::XpathReference;
using ::alinous::html::xpath::XpathString;



class AlinousXpathParser final : public AlinousXpathParserConstants, public virtual IObject {
public:
	class LookaheadSuccess;
	class JJCalls;
	AlinousXpathParser(const AlinousXpathParser& base) = default;
public:
	AlinousXpathParser(java::io::InputStream* stream, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* stream, ThreadContext* ctx);
	AlinousXpathParser(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	void __construct_impl(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	AlinousXpathParser(java::io::Reader* stream, ThreadContext* ctx);
	void __construct_impl(java::io::Reader* stream, ThreadContext* ctx);
	AlinousXpathParser(AlinousXpathParserTokenManager* tm, ThreadContext* ctx);
	void __construct_impl(AlinousXpathParserTokenManager* tm, ThreadContext* ctx);
	virtual ~AlinousXpathParser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AlinousXpathParserTokenManager* token_source;
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
	AlinousXpathParser::LookaheadSuccess* jj_ls;
	java::util::List<IArrayObjectPrimitive<long long>>* jj_expentries;
	IArrayObjectPrimitive<long long>* jj_expentry;
	long long jj_kind;
	IArrayObjectPrimitive<long long>* jj_lasttokens;
	long long jj_endpos;
private:
	static IArrayObjectPrimitive<long long>* jj_la1_0;
	static IArrayObjectPrimitive<long long>* jj_la1_1;
public:
	Xpath* xpath(ThreadContext* ctx);
	XpathContext* context(ThreadContext* ctx);
	XpathContextLocation* location(ThreadContext* ctx);
	IXpathStatement* filterindex(ThreadContext* ctx);
	XpathFilter* filter(ThreadContext* ctx);
	IXpathBooleanCondition* orStatement(ThreadContext* ctx);
	IXpathBooleanCondition* andStatement(ThreadContext* ctx);
	IXpathBooleanCondition* notStatement(ThreadContext* ctx);
	IXpathBooleanCondition* compareStatement(ThreadContext* ctx);
	IXpathStatement* param(ThreadContext* ctx);
	XpathFunction* xpathFunction(ThreadContext* ctx);
	XpathReference* xpathReference(ThreadContext* ctx);
	XpathNumber* xpathNumber(ThreadContext* ctx);
	XpathString* xpathString(ThreadContext* ctx);
	AttributeIdentifier* attributeIdentifier(ThreadContext* ctx);
	XpathIdentifier* identifier(ThreadContext* ctx);
	void ReInit(java::io::InputStream* stream, ThreadContext* ctx);
	void ReInit(java::io::InputStream* stream, String* encoding, ThreadContext* ctx);
	void ReInit(java::io::Reader* stream, ThreadContext* ctx);
	void ReInit(AlinousXpathParserTokenManager* tm, ThreadContext* ctx);
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
	bool jj_3R_32(ThreadContext* ctx);
	bool jj_3R_18(ThreadContext* ctx);
	bool jj_3R_21(ThreadContext* ctx);
	bool jj_3_1(ThreadContext* ctx);
	bool jj_3R_7(ThreadContext* ctx);
	bool jj_3R_10(ThreadContext* ctx);
	bool jj_3R_26(ThreadContext* ctx);
	bool jj_3R_31(ThreadContext* ctx);
	bool jj_3_3(ThreadContext* ctx);
	bool jj_3R_9(ThreadContext* ctx);
	bool jj_3R_8(ThreadContext* ctx);
	bool jj_3R_25(ThreadContext* ctx);
	bool jj_3R_19(ThreadContext* ctx);
	bool jj_3R_24(ThreadContext* ctx);
	bool jj_3R_17(ThreadContext* ctx);
	bool jj_3R_13(ThreadContext* ctx);
	bool jj_3_5(ThreadContext* ctx);
	bool jj_3R_29(ThreadContext* ctx);
	bool jj_3_4(ThreadContext* ctx);
	bool jj_3R_16(ThreadContext* ctx);
	bool jj_3R_30(ThreadContext* ctx);
	bool jj_3_2(ThreadContext* ctx);
	bool jj_3R_15(ThreadContext* ctx);
	bool jj_3R_23(ThreadContext* ctx);
	bool jj_3R_20(ThreadContext* ctx);
	bool jj_3R_6(ThreadContext* ctx);
	bool jj_3R_12(ThreadContext* ctx);
	bool jj_3R_27(ThreadContext* ctx);
	bool jj_3R_28(ThreadContext* ctx);
	bool jj_3R_14(ThreadContext* ctx);
	bool jj_3R_11(ThreadContext* ctx);
	bool jj_3R_22(ThreadContext* ctx);
	Token* jj_consume_token(long long kind, ThreadContext* ctx);
	bool jj_scan_token(long long kind, ThreadContext* ctx);
	long long jj_ntk_f(ThreadContext* ctx);
	void jj_add_error_token(long long kind, long long pos, ThreadContext* ctx);
	void jj_rescan_token(ThreadContext* ctx);
	void jj_save(long long index, long long xla, ThreadContext* ctx);
private:
	static void jj_la1_init_0(ThreadContext* ctx);
	static void jj_la1_init_1(ThreadContext* ctx);
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
		AlinousXpathParser::JJCalls* next;
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
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousXpathParser::jj_la1_0, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
		GCUtils<IArrayObjectPrimitive<long long>>::dec(nullptr, AlinousXpathParser::jj_la1_1, ctx, __FILEW__, __LINE__, L"IArrayObjectPrimitive<long long>");
	}
};

}}}

#endif /* end of ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSER_H_ */
