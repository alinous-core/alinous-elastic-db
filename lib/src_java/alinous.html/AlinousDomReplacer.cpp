#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/IReplacer.h"
#include "alinous.html/DomTokenizer.h"
#include "alinous.html/DomConverter.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html/DocType.h"
#include "alinous.html/DomComment.h"
#include "alinous.html/DomText.h"
#include "alinous.html/AlinousDomEventHandler.h"
#include "alinous.html/AlinousDomReplacer.h"
#include "alinous.html/Test.h"

namespace alinous {namespace html {





bool AlinousDomReplacer::__init_done = __init_static_variables();
bool AlinousDomReplacer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDomReplacer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDomReplacer::AlinousDomReplacer(ThreadContext* ctx) throw()  : IObject(ctx), IReplacer(ctx), currentAttribute(nullptr), currentTag(nullptr), processingTagIsEnd(0), eventHandler(__GC_INS(this, (new(ctx) AlinousDomEventHandler(ctx)), AlinousDomEventHandler))
{
}
void AlinousDomReplacer::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousDomReplacer::~AlinousDomReplacer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDomReplacer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDomReplacer", L"~AlinousDomReplacer");
	__e_obj1.add(this->currentAttribute, this);
	currentAttribute = nullptr;
	__e_obj1.add(this->currentTag, this);
	currentTag = nullptr;
	__e_obj1.add(this->eventHandler, this);
	eventHandler = nullptr;
	if(!prepare){
		return;
	}
}
DomDocument* AlinousDomReplacer::getDocument(ThreadContext* ctx) throw() 
{
	return static_cast<DomDocument*>(this->eventHandler->getTopObject(ctx));
}
void AlinousDomReplacer::addBodyString(String* str, ThreadContext* ctx) throw() 
{
	DomText* text = (new(ctx) DomText(ctx));
	text->setText(str, ctx);
	this->eventHandler->reportBodyString(text, ctx);
}
void AlinousDomReplacer::startComment(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->currentTag), (new(ctx) DomComment(ctx)), DomNode);
	this->eventHandler->reportCommentStarts(static_cast<DomComment*>(this->currentTag), ctx);
}
void AlinousDomReplacer::endComment(ThreadContext* ctx) throw() 
{
}
void AlinousDomReplacer::addComment(String* comment, ThreadContext* ctx) throw() 
{
	(static_cast<DomComment*>(this->currentTag))->addComment(comment, ctx);
}
void AlinousDomReplacer::startTag(String* tag, bool endTag, ThreadContext* ctx) throw() 
{
	if(endTag)
	{
		__GC_MV(this, &(this->currentTag), eventHandler->reportTagClosed(tag, ctx), DomNode);
		__GC_MV(this, &(this->currentAttribute), nullptr, Attribute);
		this->processingTagIsEnd = true;
		return;
	}
	if(tag->equals(ConstStr::getCNST_STR_1799(), ctx))
	{
		__GC_MV(this, &(this->currentTag), (new(ctx) DocType(tag, ctx)), DomNode);
		this->processingTagIsEnd = false;
		return;
	}
	__GC_MV(this, &(this->currentTag), (new(ctx) DomNode(tag, ctx)), DomNode);
	this->processingTagIsEnd = false;
}
void AlinousDomReplacer::endTag(bool singleEnd, ThreadContext* ctx) throw() 
{
	if(!this->processingTagIsEnd)
	{
		__GC_MV(this, &(this->currentTag), eventHandler->reportTagAppears(this->currentTag, singleEnd, ctx), DomNode);
	}
}
void AlinousDomReplacer::attributeName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->currentAttribute), (new(ctx) Attribute(ctx)), Attribute);
	this->currentAttribute->setName(name, ctx);
	this->currentTag->addAttribute(this->currentAttribute, ctx);
}
void AlinousDomReplacer::attributeValue(String* value, ThreadContext* ctx) throw() 
{
	if(this->currentAttribute == nullptr)
	{
		__GC_MV(this, &(this->currentAttribute), (new(ctx) Attribute(ctx)), Attribute);
		this->currentTag->addAttribute(this->currentAttribute, ctx);
	}
	this->currentAttribute->setValue(value, ctx);
	__GC_MV(this, &(this->currentAttribute), nullptr, Attribute);
}
void AlinousDomReplacer::parseEnd(ThreadContext* ctx) throw() 
{
	this->eventHandler->parseEnd(ctx);
}
DomNode* AlinousDomReplacer::getCurrentTag(ThreadContext* ctx) throw() 
{
	return currentTag;
}
void AlinousDomReplacer::__cleanUp(ThreadContext* ctx){
}
}}

