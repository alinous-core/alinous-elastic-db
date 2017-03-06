#include "include/global.h"


#include "alinous.web.htmlxml/XmlHeaderTagObject.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.parse.htmlxml/Token.h"
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/AbstractXHtmlAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/XHtmlComment.h"
#include "alinous.web.htmlxml/HtmlDocType.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml/AlinousAttrs.h"
#include "alinous.web.htmlxml.module/DynamicExecutableAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlDqString.h"
#include "alinous.web.htmlxml/XHtmlSQString.h"
#include "alinous.web.htmlxml/BodyText.h"

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
 AbstractXHtmlElement::AbstractXHtmlElement(ThreadContext* ctx) throw()  : IObject(ctx), parts(nullptr), isDynamic(false), line(0), startPosition(0), endLine(0), _endPosition(0)
{
}
void AbstractXHtmlElement::__construct_impl(ThreadContext* ctx) throw() 
{
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
void AbstractXHtmlElement::__cleanUp(ThreadContext* ctx){
}
}}}

