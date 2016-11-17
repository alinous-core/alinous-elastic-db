#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {



constexpr EnumBase __AbstractXHtmlElement__ElementType::__DEFAULT_NULL;
constexpr EnumBase __AbstractXHtmlElement__ElementType::HtmlDocType;
constexpr EnumBase __AbstractXHtmlElement__ElementType::XmlHeader;
constexpr EnumBase __AbstractXHtmlElement__ElementType::BodyText;
constexpr EnumBase __AbstractXHtmlElement__ElementType::Attribute;
constexpr EnumBase __AbstractXHtmlElement__ElementType::Comment;
constexpr EnumBase __AbstractXHtmlElement__ElementType::DqString;
constexpr EnumBase __AbstractXHtmlElement__ElementType::SqString;
constexpr EnumBase __AbstractXHtmlElement__ElementType::Tag;


bool AbstractXHtmlElement::__init_done = __init_static_variables();
bool AbstractXHtmlElement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractXHtmlElement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractXHtmlElement::~AbstractXHtmlElement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractXHtmlElement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractXHtmlElement", L"~AbstractXHtmlElement");
	__e_obj1.add(this->parts, this);
	parts = nullptr;
	if(!prepare){
		return;
	}
}
void AbstractXHtmlElement::position(Token* start, Token* end, ThreadContext* ctx) throw() 
{
	this->line = start->beginLine;
	this->startPosition = start->beginColumn;
	this->endLine = end->endLine;
	this->_endPosition = end->endColumn;
}
void AbstractXHtmlElement::position(AbstractXHtmlElement* start, AbstractXHtmlElement* end, ThreadContext* ctx) throw() 
{
	this->line = start->getLine(ctx);
	this->startPosition = start->getStartPosition(ctx);
	this->endLine = end->getEndLine(ctx);
	this->_endPosition = end->get_endPosition(ctx);
}
void AbstractXHtmlElement::position(AbstractXHtmlElement* start, Token* end, ThreadContext* ctx) throw() 
{
	this->line = start->getLine(ctx);
	this->startPosition = start->getStartPosition(ctx);
	this->endLine = end->endLine;
	this->_endPosition = end->endColumn;
}
void AbstractXHtmlElement::position(Token* start, AbstractXHtmlElement* end, ThreadContext* ctx) throw() 
{
	this->line = start->beginLine;
	this->startPosition = start->beginColumn;
	this->endLine = end->getEndLine(ctx);
	this->_endPosition = end->get_endPosition(ctx);
}
int AbstractXHtmlElement::getLine(ThreadContext* ctx) throw() 
{
	return line;
}
void AbstractXHtmlElement::setLine(int line, ThreadContext* ctx) throw() 
{
	this->line = line;
}
int AbstractXHtmlElement::getStartPosition(ThreadContext* ctx) throw() 
{
	return startPosition;
}
void AbstractXHtmlElement::setStartPosition(int startPosition, ThreadContext* ctx) throw() 
{
	this->startPosition = startPosition;
}
int AbstractXHtmlElement::getEndLine(ThreadContext* ctx) throw() 
{
	return endLine;
}
void AbstractXHtmlElement::setEndLine(int endLine, ThreadContext* ctx) throw() 
{
	this->endLine = endLine;
}
int AbstractXHtmlElement::get_endPosition(ThreadContext* ctx) throw() 
{
	return _endPosition;
}
void AbstractXHtmlElement::set_endPosition(int _endPosition, ThreadContext* ctx) throw() 
{
	this->_endPosition = _endPosition;
}
}}}

