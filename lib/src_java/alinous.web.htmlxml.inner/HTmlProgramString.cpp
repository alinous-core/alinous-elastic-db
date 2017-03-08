#include "include/global.h"


#include "java.io/StringReader.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/ParseException.h"
#include "alinous.compile/AlinousPlusParserConstants.h"
#include "alinous.compile/AlinousPlusParser.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.htmlxml.inner/HTmlProgramString.h"

namespace alinous {namespace web {namespace htmlxml {namespace inner {





bool HTmlProgramString::__init_done = __init_static_variables();
bool HTmlProgramString::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HTmlProgramString", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HTmlProgramString::HTmlProgramString(String* prog, ThreadContext* ctx) : IObject(ctx), IHtmlStringPart(ctx), exp(nullptr), prog(nullptr)
{
	this->isDynamic = true;
	__GC_MV(this, &(this->prog), prog, String);
	StringReader* reader = (new(ctx) StringReader(prog, ctx));
	AlinousPlusParser* parser = (new(ctx) AlinousPlusParser(reader, ctx));
	{
		try
		{
			__GC_MV(this, &(this->exp), parser->conditionalExpression(ctx), IExpression);
		}
		catch(ParseException* e)
		{
			throw (new(ctx) AlinousException(e, ctx));
		}
	}
}
void HTmlProgramString::__construct_impl(String* prog, ThreadContext* ctx)
{
	this->isDynamic = true;
	__GC_MV(this, &(this->prog), prog, String);
	StringReader* reader = (new(ctx) StringReader(prog, ctx));
	AlinousPlusParser* parser = (new(ctx) AlinousPlusParser(reader, ctx));
	{
		try
		{
			__GC_MV(this, &(this->exp), parser->conditionalExpression(ctx), IExpression);
		}
		catch(ParseException* e)
		{
			throw (new(ctx) AlinousException(e, ctx));
		}
	}
}
 HTmlProgramString::~HTmlProgramString() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HTmlProgramString::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HTmlProgramString", L"~HTmlProgramString");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->prog, this);
	prog = nullptr;
	if(!prepare){
		return;
	}
	IHtmlStringPart::__releaseRegerences(true, ctx);
}
String* HTmlProgramString::toString(ThreadContext* ctx) throw() 
{
	return this->prog;
}
String* HTmlProgramString::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->exp->resolveExpression(machine, debug, ctx);
	return val->getStringValue(ctx);
}
void HTmlProgramString::__cleanUp(ThreadContext* ctx){
}
}}}}

