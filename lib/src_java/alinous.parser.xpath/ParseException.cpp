#include "includes.h"


namespace alinous {namespace parser {namespace xpath {





constexpr const long long ParseException::serialVersionUID;
bool ParseException::__init_done = __init_static_variables();
bool ParseException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ParseException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ParseException::ParseException(Token* currentTokenVal, IArrayObject<IArrayObjectPrimitive<long long>>* expectedTokenSequencesVal, IArrayObject<String>* tokenImageVal, ThreadContext* ctx) throw()  : IObject(ctx), Exception(initialise(currentTokenVal, expectedTokenSequencesVal, tokenImageVal, ctx), ctx), currentToken(nullptr), expectedTokenSequences(nullptr), tokenImage(nullptr), eol(__GC_INS(this, System::getProperty(ConstStr::getCNST_STR_1213(), ConstStr::getCNST_STR_1152(), ctx), String))
{
	__GC_MV(this, &(currentToken), currentTokenVal, Token);
	GCUtils<IArrayObject<IArrayObjectPrimitive<long long>> >::mv(this, &(expectedTokenSequences), expectedTokenSequencesVal, ctx);
	__GC_MV(this, &(tokenImage), tokenImageVal, IArrayObject<String>);
}
void ParseException::__construct_impl(Token* currentTokenVal, IArrayObject<IArrayObjectPrimitive<long long>>* expectedTokenSequencesVal, IArrayObject<String>* tokenImageVal, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(currentToken), currentTokenVal, Token);
	GCUtils<IArrayObject<IArrayObjectPrimitive<long long>> >::mv(this, &(expectedTokenSequences), expectedTokenSequencesVal, ctx);
	__GC_MV(this, &(tokenImage), tokenImageVal, IArrayObject<String>);
}
 ParseException::ParseException(ThreadContext* ctx) throw()  : IObject(ctx), Exception(ctx), currentToken(nullptr), expectedTokenSequences(nullptr), tokenImage(nullptr), eol(__GC_INS(this, System::getProperty(ConstStr::getCNST_STR_1213(), ConstStr::getCNST_STR_1152(), ctx), String))
{
}
void ParseException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ParseException::ParseException(String* message, ThreadContext* ctx) throw()  : IObject(ctx), Exception(message, ctx), currentToken(nullptr), expectedTokenSequences(nullptr), tokenImage(nullptr), eol(__GC_INS(this, System::getProperty(ConstStr::getCNST_STR_1213(), ConstStr::getCNST_STR_1152(), ctx), String))
{
}
void ParseException::__construct_impl(String* message, ThreadContext* ctx) throw() 
{
}
 ParseException::~ParseException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ParseException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ParseException", L"~ParseException");
	__e_obj1.add(this->currentToken, this);
	currentToken = nullptr;
	__e_obj1.add(this->expectedTokenSequences, this);
	expectedTokenSequences = nullptr;
	__e_obj1.add(this->tokenImage, this);
	tokenImage = nullptr;
	__e_obj1.add(this->eol, this);
	eol = nullptr;
	if(!prepare){
		return;
	}
	Exception::__releaseRegerences(true, ctx);
}
String* ParseException::add_escapes(String* str, ThreadContext* ctx) throw() 
{
	StringBuffer* retval = (new(ctx) StringBuffer(ctx));
	wchar_t ch = 0;
	for(long long i = 0; i < (long long)str->length(ctx); i ++ )
	{
		switch(str->charAt((int)i, ctx)) {
		case 0:
			continue;
		case L'\b':
			retval->append(ConstStr::getCNST_STR_86(), ctx);
			continue;
		case L'\t':
			retval->append(ConstStr::getCNST_STR_125(), ctx);
			continue;
		case L'\n':
			retval->append(ConstStr::getCNST_STR_126(), ctx);
			continue;
		case L'\f':
			retval->append(ConstStr::getCNST_STR_128(), ctx);
			continue;
		case L'\r':
			retval->append(ConstStr::getCNST_STR_127(), ctx);
			continue;
		case L'\"':
			retval->append(ConstStr::getCNST_STR_123(), ctx);
			continue;
		case L'\'':
			retval->append(ConstStr::getCNST_STR_1202(), ctx);
			continue;
		case L'\\':
			retval->append(ConstStr::getCNST_STR_124(), ctx);
			continue;
		default:
			ch = str->charAt((int)i, ctx);
			if((ch) < (wchar_t)0x20 || ch > (wchar_t)0x7e)
			{
				String* s = ConstStr::getCNST_STR_384()->clone(ctx)->append(Integer::toString((int)ch, 16, ctx), ctx);
				retval->append(ConstStr::getCNST_STR_1203()->clone(ctx)->append(s->substring(s->length(ctx) - 4, s->length(ctx), ctx), ctx), ctx);
			}
						else 
			{
				retval->append(ch, ctx);
			}
			continue;
			break;
		}
	}
	return retval->toString(ctx);
}
String* ParseException::initialise(Token* currentToken, IArrayObject<IArrayObjectPrimitive<long long>>* expectedTokenSequences, IArrayObject<String>* tokenImage, ThreadContext* ctx) throw() 
{
	String* eol = System::getProperty(ConstStr::getCNST_STR_1213(), ConstStr::getCNST_STR_1152(), ctx);
	StringBuffer* expected = (new(ctx) StringBuffer(ctx));
	long long maxSize = 0;
	for(long long i = 0; i < (long long)expectedTokenSequences->length; i ++ )
	{
		if(maxSize < (long long)expectedTokenSequences->get(i)->length)
		{
			maxSize = expectedTokenSequences->get(i)->length;
		}
		for(long long j = 0; j < (long long)expectedTokenSequences->get(i)->length; j ++ )
		{
			expected->append(tokenImage->get(expectedTokenSequences->get(i)->get(j)), ctx)->append(L' ', ctx);
		}
		if(expectedTokenSequences->get(i)->get(expectedTokenSequences->get(i)->length - 1) != (long long)0)
		{
			expected->append(ConstStr::getCNST_STR_1214(), ctx);
		}
		expected->append(eol, ctx)->append(ConstStr::getCNST_STR_1215(), ctx);
	}
	String* retval = ConstStr::getCNST_STR_1216();
	Token* tok = currentToken->next;
	for(long long i = 0; i < maxSize; i ++ )
	{
		if(i != (long long)0)
		{
			retval->append(ConstStr::getCNST_STR_380(), ctx);
		}
		if(tok->kind == 0)
		{
			retval->append(tokenImage->get(0), ctx);
			break ;
		}
		retval->append(ConstStr::getCNST_STR_380()->clone(ctx)->append(tokenImage->get(tok->kind), ctx), ctx);
		retval->append(ConstStr::getCNST_STR_1217(), ctx);
		retval->append(add_escapes(tok->image, ctx), ctx);
		retval->append(ConstStr::getCNST_STR_1217(), ctx);
		tok = tok->next;
	}
	retval->append(ConstStr::getCNST_STR_1218()->clone(ctx)->append(currentToken->next->beginLine, ctx)->append(ConstStr::getCNST_STR_1205(), ctx)->append(currentToken->next->beginColumn, ctx), ctx);
	retval->append(ConstStr::getCNST_STR_947()->clone(ctx)->append(eol, ctx), ctx);
	if(expectedTokenSequences->length == 1)
	{
		retval->append(ConstStr::getCNST_STR_1219()->clone(ctx)->append(eol, ctx)->append(ConstStr::getCNST_STR_1215(), ctx), ctx);
	}
		else 
	{
		retval->append(ConstStr::getCNST_STR_1220()->clone(ctx)->append(eol, ctx)->append(ConstStr::getCNST_STR_1215(), ctx), ctx);
	}
	retval->append(expected->toString(ctx), ctx);
	return retval;
}
}}}

