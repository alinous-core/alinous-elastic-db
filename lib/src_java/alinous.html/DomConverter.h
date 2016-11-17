#ifndef ALINOUS_HTML_DOMCONVERTER_H_
#define ALINOUS_HTML_DOMCONVERTER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class IReplacer;}}

namespace alinous {namespace html {
class DomTokenizer;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;

class __DomConverter__Status : public EnumBase {
public:
	__DomConverter__Status() = default;
	constexpr __DomConverter__Status(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __DomConverter__Status(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  text{1};
	static constexpr EnumBase  text_dq{2};
	static constexpr EnumBase  text_sq{3};
	static constexpr EnumBase  intag{4};
	static constexpr EnumBase  intag_after_tag_name{5};
	static constexpr EnumBase  intag_after_attr_name{6};
	static constexpr EnumBase  intag_attr_value{7};
	static constexpr EnumBase  intag_attr_value_in{8};
	static constexpr EnumBase  incomment{9};
};


class DomConverter final : public virtual IObject {
public:
	class Status : public __DomConverter__Status {
	public:
		Status() = default;constexpr Status(const EnumBase& base) :  __DomConverter__Status(base) {};
	};
public:
	DomConverter(const DomConverter& base) = default;
public:
	DomConverter(String* html, IReplacer* replacer, ThreadContext* ctx) throw() ;
	void __construct_impl(String* html, IReplacer* replacer, ThreadContext* ctx) throw() ;
	virtual ~DomConverter() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DomTokenizer* tokenizer;
	DomConverter::Status currentStatus;
	String* currentQuote;
	bool tagSet;
	bool singleEnding;
	bool endingTag;
	bool escape;
	StringBuffer* buffer;
	IReplacer* replacer;
public:
	static String* GT;
	static String* LT;
	static String* QUOTE;
	static String* DOUBLE_QUOTE;
	static String* SRC;
	static String* EQUALS;
	static String* A;
	static String* IMG;
	static String* SPACE;
	static String* TAB;
	static String* NEW_LINE;
	static String* SLASH;
	static String* BACK_SLASH;
public:
	void parse(ThreadContext* ctx) throw() ;
	void handleIncomment(String* token, ThreadContext* ctx) throw() ;
	void handleAttrValueIn(String* token, ThreadContext* ctx) throw() ;
	void handleAttrValue(String* token, ThreadContext* ctx) throw() ;
	void handleAfterAttrName(String* token, ThreadContext* ctx) throw() ;
	void handleAfterTagName(String* token, ThreadContext* ctx) throw() ;
	void handleIntag(String* token, ThreadContext* ctx) throw() ;
	void handleText(String* token, ThreadContext* ctx) throw() ;
	void handleJavaScriptCode(String* token, ThreadContext* ctx) throw() ;
	void handleQuote(String* token, ThreadContext* ctx) throw() ;
	void handleDoubleQuote(String* token, ThreadContext* ctx) throw() ;
private:
	bool isJavaScript(ThreadContext* ctx) throw() ;
	void changeStatus(DomConverter::Status status, ThreadContext* ctx) throw() ;
	void changeStatus(DomConverter::Status status, bool clearBuffer, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<String>::dec(nullptr, DomConverter::GT, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::LT, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::QUOTE, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::DOUBLE_QUOTE, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::SRC, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::EQUALS, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::A, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::IMG, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::SPACE, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::TAB, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::NEW_LINE, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::SLASH, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, DomConverter::BACK_SLASH, ctx, __FILEW__, __LINE__, L"String");
	}
};

}}

#endif /* end of ALINOUS_HTML_DOMCONVERTER_H_ */
