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





bool DomText::__init_done = __init_static_variables();
bool DomText::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomText", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomText::~DomText() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomText::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomText", L"~DomText");
	__e_obj1.add(this->text, this);
	text = nullptr;
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	if(!prepare){
		return;
	}
}
DomNode* DomText::getParent(ThreadContext* ctx) throw() 
{
	return parent;
}
void DomText::setParent(DomNode* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, DomNode);
}
String* DomText::getText(ThreadContext* ctx) throw() 
{
	return text;
}
void DomText::setText(String* text, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->text), text, String);
}
String* DomText::toString(ThreadContext* ctx) throw() 
{
	return text;
}
IDomObject* DomText::getNextSibilingElement(ThreadContext* ctx) throw() 
{
	if(this->parent == nullptr)
	{
		return nullptr;
	}
	int index = this->parent->children->indexOf(this, ctx);
	if(index >= (this->parent->children->size(ctx) - 1))
	{
		return this->parent->getNextSibilingElement(ctx);
	}
	index ++ ;
	return this->parent->children->get(index, ctx);
}
IDomObject* DomText::getNextElement(ThreadContext* ctx) throw() 
{
	return getNextSibilingElement(ctx);
}
int DomText::getType(ThreadContext* ctx) throw() 
{
	return IDomObject::TYPE_DOM_TEXT;
}
}}

