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





bool DomComment::__init_done = __init_static_variables();
bool DomComment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomComment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomComment::DomComment(ThreadContext* ctx) throw()  : IObject(ctx), DomNode(ConstStr::getCNST_STR_1780(), ctx), buff(__GC_INS(this, (new(ctx) StringBuffer(ctx)), StringBuffer))
{
	this->buff->append(ConstStr::getCNST_STR_1781(), ctx);
}
void DomComment::__construct_impl(ThreadContext* ctx) throw() 
{
	this->buff->append(ConstStr::getCNST_STR_1781(), ctx);
}
 DomComment::~DomComment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomComment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomComment", L"~DomComment");
	__e_obj1.add(this->buff, this);
	buff = nullptr;
	if(!prepare){
		return;
	}
	DomNode::__releaseRegerences(true, ctx);
}
void DomComment::addComment(String* token, ThreadContext* ctx) throw() 
{
	buff->append(token, ctx);
}
String* DomComment::toString(ThreadContext* ctx) throw() 
{
	this->buff->append(ConstStr::getCNST_STR_1782(), ctx);
	return this->buff->toString(ctx);
}
int DomComment::getType(ThreadContext* ctx) throw() 
{
	return IDomObject::TYPE_DOM_COMMENT;
}
}}

