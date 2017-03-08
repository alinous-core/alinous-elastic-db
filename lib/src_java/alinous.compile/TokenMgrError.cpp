#include "include/global.h"


#include "alinous.compile/TokenMgrError.h"

namespace alinous {namespace compile {





constexpr const long long TokenMgrError::serialVersionUID;
constexpr const int TokenMgrError::LEXICAL_ERROR;
constexpr const int TokenMgrError::STATIC_LEXER_ERROR;
constexpr const int TokenMgrError::INVALID_LEXICAL_STATE;
constexpr const int TokenMgrError::LOOP_DETECTED;
bool TokenMgrError::__init_done = __init_static_variables();
bool TokenMgrError::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TokenMgrError", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TokenMgrError::TokenMgrError(ThreadContext* ctx) throw()  : IObject(ctx), Error(ctx), errorCode(0)
{
}
void TokenMgrError::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TokenMgrError::TokenMgrError(String* message, int reason, ThreadContext* ctx) throw()  : IObject(ctx), Error(message, ctx), errorCode(0)
{
	errorCode = reason;
}
void TokenMgrError::__construct_impl(String* message, int reason, ThreadContext* ctx) throw() 
{
	errorCode = reason;
}
 TokenMgrError::TokenMgrError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw()  : IObject(ctx), Error(ctx), errorCode(0)
{
	__construct_impl(LexicalError(EOFSeen, lexState, errorLine, errorColumn, errorAfter, curChar, ctx), reason, ctx);
}
void TokenMgrError::__construct_impl(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw() 
{
	__construct_impl(LexicalError(EOFSeen, lexState, errorLine, errorColumn, errorAfter, curChar, ctx), reason, ctx);
}
 TokenMgrError::~TokenMgrError() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TokenMgrError::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TokenMgrError", L"~TokenMgrError");
	if(!prepare){
		return;
	}
	Error::__releaseRegerences(true, ctx);
}
String* TokenMgrError::getMessage(ThreadContext* ctx) throw() 
{
	return Error::getMessage(ctx);
}
String* TokenMgrError::addEscapes(String* str, ThreadContext* ctx) throw() 
{
	StringBuffer* retval = (new(ctx) StringBuffer(ctx));
	wchar_t ch = 0;
	for(int i = 0; i < str->length(ctx); i ++ )
	{
		switch(str->charAt(i, ctx)) {
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
			retval->append(ConstStr::getCNST_STR_1311(), ctx);
			continue;
		case L'\\':
			retval->append(ConstStr::getCNST_STR_124(), ctx);
			continue;
		default:
			ch = str->charAt(i, ctx);
			if((ch) < (wchar_t)0x20 || ch > (wchar_t)0x7e)
			{
				String* s = ConstStr::getCNST_STR_384()->clone(ctx)->append(Integer::toString((int)ch, 16, ctx), ctx);
				retval->append(ConstStr::getCNST_STR_1312()->clone(ctx)->append(s->substring(s->length(ctx) - 4, s->length(ctx), ctx), ctx), ctx);
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
String* TokenMgrError::LexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, ThreadContext* ctx) throw() 
{
	return (ConstStr::getCNST_STR_1313()->clone(ctx)->append(errorLine, ctx)->append(ConstStr::getCNST_STR_1314(), ctx)->append(errorColumn, ctx)->append(ConstStr::getCNST_STR_1315(), ctx)->append((EOFSeen ? ConstStr::getCNST_STR_1316() : (ConstStr::getCNST_STR_1317()->clone(ctx)->append(addEscapes(String::valueOf(curChar, ctx), ctx), ctx)->append(ConstStr::getCNST_STR_1317(), ctx))->clone(ctx)->append(ConstStr::getCNST_STR_887(), ctx)->append(((int)curChar), ctx)->append(ConstStr::getCNST_STR_1318(), ctx)), ctx)->append(ConstStr::getCNST_STR_1319(), ctx)->append(addEscapes(errorAfter, ctx), ctx)->append(ConstStr::getCNST_STR_1317(), ctx));
}
void TokenMgrError::__cleanUp(ThreadContext* ctx){
}
}}

