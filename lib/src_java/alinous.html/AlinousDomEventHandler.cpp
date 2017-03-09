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





bool AlinousDomEventHandler::__init_done = __init_static_variables();
bool AlinousDomEventHandler::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDomEventHandler", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDomEventHandler::AlinousDomEventHandler(ThreadContext* ctx) throw()  : IObject(ctx), topObject(nullptr), tagStack(GCUtils<Stack<DomNode> >::ins(this, (new(ctx) Stack<DomNode>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->topObject), (new(ctx) DomDocument(ConstStr::getCNST_STR_1791(), ctx)), DomNode);
	this->tagStack->push(this->topObject, ctx);
}
void AlinousDomEventHandler::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->topObject), (new(ctx) DomDocument(ConstStr::getCNST_STR_1791(), ctx)), DomNode);
	this->tagStack->push(this->topObject, ctx);
}
 AlinousDomEventHandler::~AlinousDomEventHandler() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDomEventHandler::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDomEventHandler", L"~AlinousDomEventHandler");
	__e_obj1.add(this->topObject, this);
	topObject = nullptr;
	__e_obj1.add(this->tagStack, this);
	tagStack = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousDomEventHandler::reportCommentStarts(DomComment* comment, ThreadContext* ctx) throw() 
{
	DomNode* current = this->tagStack->peek(ctx);
	current->addChild(comment, ctx);
}
DomNode* AlinousDomEventHandler::reportTagAppears(DomNode* tag, bool singleEnds, ThreadContext* ctx) throw() 
{
	tag->setSingleEnd(singleEnds, ctx);
	DomNode* current = this->tagStack->peek(ctx);
	current->addChild(tag, ctx);
	if(tag->getName(ctx)->startsWith(ConstStr::getCNST_STR_525(), ctx))
	{
		singleEnds = true;
		tag->setSingleEnd(true, ctx);
		tag->setXmlHeader(true, ctx);
	}
	if(singleEnds)
	{
		return current;
	}
	this->tagStack->push(tag, ctx);
	return tag;
}
DomNode* AlinousDomEventHandler::reportTagClosed(String* tagName, ThreadContext* ctx) throw() 
{
	DomNode* top = this->tagStack->pop(ctx);
	while(top != this->topObject)
	{
		if(top->getName(ctx)->toLowerCase(ctx)->equals(tagName->toLowerCase(ctx), ctx))
		{
			break ;
		}
				else 
		{
			top->handleUnclosed(ctx);
		}
		top = this->tagStack->pop(ctx);
	}
	if(this->tagStack->isEmpty(ctx))
	{
		this->tagStack->push(this->topObject, ctx);
	}
	return this->tagStack->peek(ctx);
}
void AlinousDomEventHandler::parseEnd(ThreadContext* ctx) throw() 
{
	DomNode* top = this->tagStack->pop(ctx);
	while(top != this->topObject)
	{
		top->handleUnclosed(ctx);
		top = this->tagStack->pop(ctx);
	}
}
void AlinousDomEventHandler::reportBodyString(DomText* bodyString, ThreadContext* ctx) throw() 
{
	this->tagStack->peek(ctx)->addChild(bodyString, ctx);
}
DomNode* AlinousDomEventHandler::getTopObject(ThreadContext* ctx) throw() 
{
	return topObject;
}
void AlinousDomEventHandler::__cleanUp(ThreadContext* ctx){
}
}}

