#include "includes.h"


namespace alinous {namespace html {



constexpr EnumBase __DomConverter__Status::__DEFAULT_NULL;
constexpr EnumBase __DomConverter__Status::text;
constexpr EnumBase __DomConverter__Status::text_dq;
constexpr EnumBase __DomConverter__Status::text_sq;
constexpr EnumBase __DomConverter__Status::intag;
constexpr EnumBase __DomConverter__Status::intag_after_tag_name;
constexpr EnumBase __DomConverter__Status::intag_after_attr_name;
constexpr EnumBase __DomConverter__Status::intag_attr_value;
constexpr EnumBase __DomConverter__Status::intag_attr_value_in;
constexpr EnumBase __DomConverter__Status::incomment;


String* DomConverter::GT = nullptr;
String* DomConverter::LT = nullptr;
String* DomConverter::QUOTE = nullptr;
String* DomConverter::DOUBLE_QUOTE = nullptr;
String* DomConverter::SRC = nullptr;
String* DomConverter::EQUALS = nullptr;
String* DomConverter::A = nullptr;
String* DomConverter::IMG = nullptr;
String* DomConverter::SPACE = nullptr;
String* DomConverter::TAB = nullptr;
String* DomConverter::NEW_LINE = nullptr;
String* DomConverter::SLASH = nullptr;
String* DomConverter::BACK_SLASH = nullptr;
bool DomConverter::__init_done = __init_static_variables();
bool DomConverter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomConverter", L"__init_static_variables");
		__GC_MV(nullptr, &(GT), ConstStr::getCNST_STR_82(), String);
		__GC_MV(nullptr, &(LT), ConstStr::getCNST_STR_1010(), String);
		__GC_MV(nullptr, &(QUOTE), ConstStr::getCNST_STR_1735(), String);
		__GC_MV(nullptr, &(DOUBLE_QUOTE), ConstStr::getCNST_STR_1302(), String);
		__GC_MV(nullptr, &(SRC), ConstStr::getCNST_STR_1736(), String);
		__GC_MV(nullptr, &(EQUALS), ConstStr::getCNST_STR_1073(), String);
		__GC_MV(nullptr, &(A), ConstStr::getCNST_STR_1737(), String);
		__GC_MV(nullptr, &(IMG), ConstStr::getCNST_STR_1738(), String);
		__GC_MV(nullptr, &(SPACE), ConstStr::getCNST_STR_380(), String);
		__GC_MV(nullptr, &(TAB), ConstStr::getCNST_STR_380(), String);
		__GC_MV(nullptr, &(NEW_LINE), ConstStr::getCNST_STR_1206(), String);
		__GC_MV(nullptr, &(SLASH), ConstStr::getCNST_STR_1007(), String);
		__GC_MV(nullptr, &(BACK_SLASH), ConstStr::getCNST_STR_1739(), String);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomConverter::DomConverter(String* html, IReplacer* replacer, ThreadContext* ctx) throw()  : IObject(ctx), tokenizer(nullptr), currentQuote(nullptr), tagSet(0), singleEnding(0), endingTag(0), escape(0), buffer(__GC_INS(this, (new(ctx) StringBuffer(ctx)), StringBuffer)), replacer(nullptr)
{
	__GC_MV(this, &(this->tokenizer), (new(ctx) DomTokenizer(html, ctx)), DomTokenizer);
	__GC_MV(this, &(this->replacer), replacer, IReplacer);
	this->tagSet = false;
	this->singleEnding = false;
	this->endingTag = false;
	this->escape = false;
}
void DomConverter::__construct_impl(String* html, IReplacer* replacer, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tokenizer), (new(ctx) DomTokenizer(html, ctx)), DomTokenizer);
	__GC_MV(this, &(this->replacer), replacer, IReplacer);
	this->tagSet = false;
	this->singleEnding = false;
	this->endingTag = false;
	this->escape = false;
}
 DomConverter::~DomConverter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomConverter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomConverter", L"~DomConverter");
	__e_obj1.add(this->tokenizer, this);
	tokenizer = nullptr;
	__e_obj1.add(this->currentQuote, this);
	currentQuote = nullptr;
	__e_obj1.add(this->buffer, this);
	buffer = nullptr;
	__e_obj1.add(this->replacer, this);
	replacer = nullptr;
	if(!prepare){
		return;
	}
}
void DomConverter::parse(ThreadContext* ctx) throw() 
{
	changeStatus(Status::text, ctx);
	String* token = this->tokenizer->getToken(ctx);
	do
	{
		switch(this->currentStatus) {
		case DomConverter::Status::intag:
			handleIntag(token, ctx);
			break ;
		case DomConverter::Status::intag_after_tag_name:
			handleAfterTagName(token, ctx);
			break ;
		case DomConverter::Status::intag_after_attr_name:
			handleAfterAttrName(token, ctx);
			break ;
		case DomConverter::Status::intag_attr_value:
			handleAttrValue(token, ctx);
			break ;
		case DomConverter::Status::intag_attr_value_in:
			handleAttrValueIn(token, ctx);
			break ;
		case DomConverter::Status::text_dq:
			handleDoubleQuote(token, ctx);
			break ;
		case DomConverter::Status::text_sq:
			handleQuote(token, ctx);
			break ;
		case DomConverter::Status::incomment:
			handleIncomment(token, ctx);
			break ;
		default:
			handleText(token, ctx);
			break;
		}
		token = this->tokenizer->getToken(ctx);
	}
	while(!token->equals(ConstStr::getCNST_STR_4(), ctx));
	this->replacer->addBodyString(this->buffer->toString(ctx), ctx);
	this->replacer->parseEnd(ctx);
}
void DomConverter::handleIncomment(String* token, ThreadContext* ctx) throw() 
{
	if(token->endsWith(ConstStr::getCNST_STR_1732(), ctx))
	{
		String* next = this->tokenizer->lookAhead(ctx);
		if(next->equals(ConstStr::getCNST_STR_82(), ctx))
		{
			this->replacer->endComment(ctx);
			changeStatus(Status::text, ctx);
			this->tokenizer->getToken(ctx);
			return;
		}
				else 
		{
			this->replacer->addComment(token, ctx);
			this->replacer->addComment(next, ctx);
			return;
		}
	}
	this->replacer->addComment(token, ctx);
}
void DomConverter::handleAttrValueIn(String* token, ThreadContext* ctx) throw() 
{
	if(this->escape)
	{
		this->buffer->append(token, ctx);
		this->escape = false;
		return;
	}
	if(token->equals(DomConverter::BACK_SLASH, ctx))
	{
		this->escape = true;
		this->buffer->append(token, ctx);
		return;
	}
	if(token->equals(this->currentQuote, ctx))
	{
		this->replacer->attributeValue(this->buffer->toString(ctx), ctx);
		changeStatus(Status::intag, ctx);
		return;
	}
	this->buffer->append(token, ctx);
}
void DomConverter::handleAttrValue(String* token, ThreadContext* ctx) throw() 
{
	if(token->equals(DomConverter::LT, ctx) || token->equals(DomConverter::SPACE, ctx) || token->equals(DomConverter::TAB, ctx) || token->equals(DomConverter::NEW_LINE, ctx))
	{
		return;
	}
	if(token->equals(DomConverter::DOUBLE_QUOTE, ctx) || token->equals(DomConverter::QUOTE, ctx))
	{
		__GC_MV(this, &(this->currentQuote), token, String);
		changeStatus(Status::intag_attr_value_in, ctx);
		return;
	}
	changeStatus(Status::intag, ctx);
}
void DomConverter::handleAfterAttrName(String* token, ThreadContext* ctx) throw() 
{
	if(token->equals(DomConverter::LT, ctx) || token->equals(DomConverter::SPACE, ctx) || token->equals(DomConverter::TAB, ctx) || token->equals(DomConverter::NEW_LINE, ctx))
	{
		return;
	}
	if(token->equals(DomConverter::EQUALS, ctx))
	{
		this->replacer->attributeName(this->buffer->toString(ctx), ctx);
		changeStatus(Status::intag_attr_value, ctx);
		return;
	}
	if(token->equals(DomConverter::QUOTE, ctx) || token->equals(DomConverter::DOUBLE_QUOTE, ctx))
	{
		if(this->buffer->length(ctx) > 0)
		{
			this->replacer->attributeName(this->buffer->toString(ctx), ctx);
			this->replacer->attributeValue(nullptr, ctx);
			this->buffer->setLength(0, ctx);
		}
		__GC_MV(this, &(this->currentQuote), token, String);
		changeStatus(Status::intag_attr_value_in, ctx);
		return;
	}
	if(token->equals(DomConverter::GT, ctx))
	{
		changeStatus(Status::text, ctx);
		return;
	}
	this->buffer->append(token, ctx);
}
void DomConverter::handleAfterTagName(String* token, ThreadContext* ctx) throw() 
{
	if(token->equals(DomConverter::LT, ctx) || token->equals(DomConverter::SPACE, ctx) || token->equals(DomConverter::TAB, ctx) || token->equals(DomConverter::NEW_LINE, ctx))
	{
		return;
	}
	if(token->equals(DomConverter::QUOTE, ctx) || token->equals(DomConverter::DOUBLE_QUOTE, ctx))
	{
		__GC_MV(this, &(this->currentQuote), token, String);
		changeStatus(Status::intag_attr_value, ctx);
		return;
	}
	if(token->equals(DomConverter::GT, ctx))
	{
		this->replacer->attributeName(this->buffer->toString(ctx), ctx);
		this->replacer->endTag(false, ctx);
		this->tagSet = false;
		changeStatus(Status::text, ctx);
		return;
	}
	if(token->equals(DomConverter::SLASH, ctx))
	{
		if(this->buffer->length(ctx) > 0)
		{
			this->replacer->attributeName(this->buffer->toString(ctx), ctx);
		}
		this->singleEnding = true;
		changeStatus(Status::intag, ctx);
		return;
	}
		else 
	{
		if(token->equals(DomConverter::EQUALS, ctx))
		{
			this->replacer->attributeName(this->buffer->toString(ctx), ctx);
			changeStatus(Status::intag_attr_value, ctx);
			return;
		}
	}
	if(this->buffer->length(ctx) > 0)
	{
		this->replacer->attributeName(this->buffer->toString(ctx), ctx);
		changeStatus(Status::intag_after_attr_name, ctx);
		this->buffer->append(token, ctx);
		return;
	}
	this->buffer->append(token, ctx);
}
void DomConverter::handleIntag(String* token, ThreadContext* ctx) throw() 
{
	if(token->equals(DomConverter::LT, ctx) || token->equals(DomConverter::SPACE, ctx) || token->equals(DomConverter::TAB, ctx) || token->equals(DomConverter::NEW_LINE, ctx))
	{
		return;
	}
	if(!this->tagSet)
	{
		if(token->equals(DomConverter::SLASH, ctx))
		{
			this->endingTag = true;
			return;
		}
		if(token->startsWith(ConstStr::getCNST_STR_1733(), ctx))
		{
			changeStatus(Status::incomment, ctx);
			this->replacer->startComment(ctx);
			return;
		}
		this->tagSet = true;
		this->replacer->startTag(token, this->endingTag, ctx);
		this->endingTag = false;
		return;
	}
	if(token->equals(DomConverter::QUOTE, ctx) || token->equals(DomConverter::DOUBLE_QUOTE, ctx))
	{
		__GC_MV(this, &(this->currentQuote), token, String);
		changeStatus(Status::intag_attr_value_in, ctx);
		return;
	}
	if(token->equals(DomConverter::SLASH, ctx))
	{
		this->singleEnding = true;
		return;
	}
	if(token->equals(DomConverter::GT, ctx))
	{
		this->replacer->endTag(this->singleEnding, ctx);
		changeStatus(Status::text, ctx);
		__GC_MV(this, &(this->currentQuote), nullptr, String);
		this->tagSet = false;
		this->singleEnding = false;
		return;
	}
	changeStatus(Status::intag_after_tag_name, ctx);
	this->buffer->append(token, ctx);
}
void DomConverter::handleText(String* token, ThreadContext* ctx) throw() 
{
	if(isJavaScript(ctx))
	{
		handleJavaScriptCode(token, ctx);
		return;
	}
	if(token->equals(DomConverter::LT, ctx))
	{
		this->replacer->addBodyString(this->buffer->toString(ctx), ctx);
		changeStatus(Status::intag, ctx);
		this->tagSet = false;
		return;
	}
	this->buffer->append(token, ctx);
}
void DomConverter::handleJavaScriptCode(String* token, ThreadContext* ctx) throw() 
{
	if(token->equals(DomConverter::QUOTE, ctx))
	{
		changeStatus(Status::text_sq, false, ctx);
		this->buffer->append(token, ctx);
		return;
	}
		else 
	{
		if(token->equals(DomConverter::DOUBLE_QUOTE, ctx))
		{
			changeStatus(Status::text_dq, false, ctx);
			this->buffer->append(token, ctx);
			return;
		}
	}
	if(token->equals(DomConverter::LT, ctx))
	{
		int ahead = 1;
		String* tagEnds = this->tokenizer->lookAhead(ahead, ctx);
		while(token->equals(DomConverter::SPACE, ctx) || token->equals(DomConverter::TAB, ctx) || token->equals(DomConverter::NEW_LINE, ctx))
		{
			ahead ++ ;
			tagEnds = this->tokenizer->lookAhead(ahead, ctx);
		}
		ahead ++ ;
		String* tagName = this->tokenizer->lookAhead(ahead, ctx);
		while(token->equals(DomConverter::SPACE, ctx) || token->equals(DomConverter::TAB, ctx) || token->equals(DomConverter::NEW_LINE, ctx))
		{
			ahead ++ ;
			tagName = this->tokenizer->lookAhead(ahead, ctx);
		}
		if(tagEnds->equals(ConstStr::getCNST_STR_1007(), ctx) && tagName->toLowerCase(ctx)->equals(ConstStr::getCNST_STR_1734(), ctx))
		{
			this->replacer->addBodyString(this->buffer->toString(ctx), ctx);
			changeStatus(Status::intag, ctx);
			this->tagSet = false;
			return;
		}
	}
	this->buffer->append(token, ctx);
}
void DomConverter::handleQuote(String* token, ThreadContext* ctx) throw() 
{
	if(token->equals(DomConverter::QUOTE, ctx))
	{
		changeStatus(Status::text, false, ctx);
		this->buffer->append(token, ctx);
		return;
	}
	this->buffer->append(token, ctx);
}
void DomConverter::handleDoubleQuote(String* token, ThreadContext* ctx) throw() 
{
	if(token->equals(DomConverter::DOUBLE_QUOTE, ctx))
	{
		changeStatus(Status::text, false, ctx);
		this->buffer->append(token, ctx);
		return;
	}
	this->buffer->append(token, ctx);
}
bool DomConverter::isJavaScript(ThreadContext* ctx) throw() 
{
	if(this->replacer->getCurrentTag(ctx) == nullptr)
	{
		return false;
	}
	if(this->replacer->getCurrentTag(ctx)->getName(ctx)->toLowerCase(ctx)->equals(ConstStr::getCNST_STR_1734(), ctx))
	{
		return true;
	}
	return false;
}
void DomConverter::changeStatus(DomConverter::Status status, ThreadContext* ctx) throw() 
{
	changeStatus(status, true, ctx);
}
void DomConverter::changeStatus(DomConverter::Status status, bool clearBuffer, ThreadContext* ctx) throw() 
{
	this->currentStatus = status;
	if(clearBuffer)
	{
		this->buffer->setLength(0, ctx);
	}
}
}}

