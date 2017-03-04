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





bool DocType::__init_done = __init_static_variables();
bool DocType::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DocType", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DocType::DocType(String* name, ThreadContext* ctx) throw()  : IObject(ctx), DomNode(name, ctx)
{
}
void DocType::__construct_impl(String* name, ThreadContext* ctx) throw() 
{
}
 DocType::~DocType() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DocType::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DomNode::__releaseRegerences(true, ctx);
}
String* DocType::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_1768(), ctx);
	Iterator<Attribute>* it = this->attributes->iterator(ctx);
	while(it->hasNext(ctx))
	{
		Attribute* attr = it->next(ctx);
		buff->append(ConstStr::getCNST_STR_380(), ctx);
		buff->append(attr->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_82(), ctx);
	return buff->toString(ctx);
}
int DocType::getType(ThreadContext* ctx) throw() 
{
	return IDomObject::TYPE_DOC_TYPE;
}
}}

