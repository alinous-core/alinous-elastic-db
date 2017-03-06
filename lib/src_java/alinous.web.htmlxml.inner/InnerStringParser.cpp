#include "include/global.h"


#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.htmlxml.inner/StaticHtmlString.h"
#include "alinous.web.htmlxml.inner/HTmlProgramString.h"
#include "alinous.web.htmlxml.inner/InnerStringParser.h"

namespace alinous {namespace web {namespace htmlxml {namespace inner {



constexpr EnumBase __InnerStringParser__Status::__DEFAULT_NULL;
constexpr EnumBase __InnerStringParser__Status::BODY;
constexpr EnumBase __InnerStringParser__Status::ESCAPED;
constexpr EnumBase __InnerStringParser__Status::PROG;


bool InnerStringParser::__init_done = __init_static_variables();
bool InnerStringParser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InnerStringParser", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InnerStringParser::InnerStringParser(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void InnerStringParser::__construct_impl(ThreadContext* ctx) throw() 
{
}
 InnerStringParser::~InnerStringParser() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InnerStringParser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
ArrayList<IHtmlStringPart>* InnerStringParser::parse(String* str, ThreadContext* ctx)
{
	int index = 0;
	InnerStringParser::Status stat = Status::BODY;
	ArrayList<IHtmlStringPart>* result = (new(ctx) ArrayList<IHtmlStringPart>(ctx));
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int length = str->length(ctx);
	for(int i = 0; i != length; ++i)
	{
		wchar_t ch = str->charAt(index++, ctx);
		switch(stat) {
		case InnerStringParser::Status::BODY:
			{
				stat = handleBody(ch, buff, result, ctx);
				break ;
			}
		case InnerStringParser::Status::ESCAPED:
			{
				buff->append(ch, ctx);
				stat = Status::BODY;
				break ;
			}
		case InnerStringParser::Status::PROG:
			{
				stat = handleProg(ch, buff, result, ctx);
				break ;
			}
		default:
			break ;
		}
	}
	if(buff->length(ctx) > 0)
	{
		StaticHtmlString* remain = (new(ctx) StaticHtmlString(buff->toString(ctx), ctx));
		result->add(remain, ctx);
	}
	return result;
}
InnerStringParser::Status InnerStringParser::handleProg(wchar_t ch, StringBuffer* buff, ArrayList<IHtmlStringPart>* result, ThreadContext* ctx)
{
	if(ch == L'}')
	{
		if(buff->length(ctx) > 0)
		{
			HTmlProgramString* str = (new(ctx) HTmlProgramString(buff->toString(ctx), ctx));
			result->add(str, ctx);
			buff->setLength(0, ctx);
		}
		return Status::BODY;
	}
	buff->append(ch, ctx);
	return Status::PROG;
}
InnerStringParser::Status InnerStringParser::handleBody(wchar_t ch, StringBuffer* buff, ArrayList<IHtmlStringPart>* result, ThreadContext* ctx) throw() 
{
	if(ch == L'\\')
	{
		return Status::ESCAPED;
	}
		else 
	{
		if(ch == L'{')
		{
			if(buff->length(ctx) > 0)
			{
				StaticHtmlString* str = (new(ctx) StaticHtmlString(buff->toString(ctx), ctx));
				result->add(str, ctx);
				buff->setLength(0, ctx);
			}
			return Status::PROG;
		}
	}
	buff->append(ch, ctx);
	return Status::BODY;
}
void InnerStringParser::__cleanUp(ThreadContext* ctx){
}
}}}}

