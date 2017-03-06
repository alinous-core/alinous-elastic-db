#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html.xpath/StringValue.h"
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





bool DomTokenizer::__init_done = __init_static_variables();
bool DomTokenizer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomTokenizer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomTokenizer::DomTokenizer(String* html, ThreadContext* ctx) throw()  : IObject(ctx), html(nullptr), pos(0), stopChars(__GC_INS(this, ((IArrayObjectPrimitive<wchar_t>*)new(ctx) ArrayObjectPrimitive<wchar_t>({L'<', L'>', L'=', L'"', L'/', L'\'', L'\t', L'\n', L' ', L'\\'}, ctx)), IArrayObjectPrimitive<wchar_t>)), reservedToken(nullptr), lookAheadList(GCUtils<LinkedList<String> >::ins(this, (new(ctx) LinkedList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->html), html, String);
}
void DomTokenizer::__construct_impl(String* html, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->html), html, String);
}
 DomTokenizer::~DomTokenizer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomTokenizer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomTokenizer", L"~DomTokenizer");
	__e_obj1.add(this->html, this);
	html = nullptr;
	__e_obj1.add(this->stopChars, this);
	stopChars = nullptr;
	__e_obj1.add(this->reservedToken, this);
	reservedToken = nullptr;
	__e_obj1.add(this->lookAheadList, this);
	lookAheadList = nullptr;
	if(!prepare){
		return;
	}
}
String* DomTokenizer::lookAhead(ThreadContext* ctx) throw() 
{
	if(!this->lookAheadList->isEmpty(ctx))
	{
		String* token = this->lookAheadList->get(0, ctx);
		return token;
	}
	String* token = doGetToken(ctx);
	this->lookAheadList->add(token, ctx);
	return token;
}
String* DomTokenizer::getToken(ThreadContext* ctx) throw() 
{
	if(!this->lookAheadList->isEmpty(ctx))
	{
		String* token = this->lookAheadList->get(0, ctx);
		this->lookAheadList->removeFirst(ctx);
		return token;
	}
	return doGetToken(ctx);
}
String* DomTokenizer::lookAhead(int ahead, ThreadContext* ctx) throw() 
{
	int storedCurrent = this->pos;
	String* storedReservedToken = this->reservedToken;
	String* token = nullptr;
	for(int i = 0; i < ahead; i ++ )
	{
		if(isEof(ctx))
		{
			this->pos = storedCurrent;
			__GC_MV(this, &(this->reservedToken), storedReservedToken, String);
			return nullptr;
		}
		token = getToken(ctx);
	}
	__GC_MV(this, &(this->reservedToken), storedReservedToken, String);
	this->pos = storedCurrent;
	return token;
}
String* DomTokenizer::doGetToken(ThreadContext* ctx) throw() 
{
	if(this->reservedToken != nullptr)
	{
		String* lastToken = this->reservedToken;
		__GC_MV(this, &(this->reservedToken), nullptr, String);
		return lastToken;
	}
	StringBuffer* token = (new(ctx) StringBuffer(ctx));
	while(true)
	{
		if(isEof(ctx))
		{
			return token->toString(ctx);
		}
		wchar_t ch = getChar(ctx);
		if(isStopchar(ch, ctx))
		{
			if(token->length(ctx) == 0)
			{
				return (new(ctx) String(((IArrayObjectPrimitive<wchar_t>*)new(ctx) ArrayObjectPrimitive<wchar_t>({ch}, ctx)), ctx));
			}
			__GC_MV(this, &(this->reservedToken), (new(ctx) String(((IArrayObjectPrimitive<wchar_t>*)new(ctx) ArrayObjectPrimitive<wchar_t>({ch}, ctx)), ctx)), String);
			break ;
		}
		token->append(ch, ctx);
	}
	return token->toString(ctx);
}
bool DomTokenizer::isEof(ThreadContext* ctx) throw() 
{
	if(reservedToken != nullptr)
	{
		return false;
	}
	return pos == html->length(ctx);
}
bool DomTokenizer::isStopchar(wchar_t ch, ThreadContext* ctx) throw() 
{
	for(int i = 0; i < stopChars->length; i ++ )
	{
		if(ch == stopChars->get(i))
		{
			return true;
		}
	}
	return false;
}
wchar_t DomTokenizer::getChar(ThreadContext* ctx) throw() 
{
	wchar_t ch = this->html->charAt(this->pos++, ctx);
	return ch;
}
void DomTokenizer::__cleanUp(ThreadContext* ctx){
}
}}

