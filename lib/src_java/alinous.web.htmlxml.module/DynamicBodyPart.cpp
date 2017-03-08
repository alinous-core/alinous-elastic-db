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
#include "alinous.web.htmlxml.module/AbstractSerializedHtmlPart.h"
#include "alinous.web.htmlxml.module/DynamicBodyPart.h"

namespace alinous {namespace web {namespace htmlxml {namespace module {





bool DynamicBodyPart::__init_done = __init_static_variables();
bool DynamicBodyPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DynamicBodyPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DynamicBodyPart::DynamicBodyPart(String* progCode, ThreadContext* ctx) : IObject(ctx), AbstractSerializedHtmlPart(ctx), exp(nullptr)
{
	this->type = AbstractSerializedHtmlPart::TYPE_DYNAMIC_BODY;
	StringReader* reader = (new(ctx) StringReader(progCode, ctx));
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
void DynamicBodyPart::__construct_impl(String* progCode, ThreadContext* ctx)
{
	this->type = AbstractSerializedHtmlPart::TYPE_DYNAMIC_BODY;
	StringReader* reader = (new(ctx) StringReader(progCode, ctx));
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
 DynamicBodyPart::~DynamicBodyPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DynamicBodyPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DynamicBodyPart", L"~DynamicBodyPart");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractSerializedHtmlPart::__releaseRegerences(true, ctx);
}
String* DynamicBodyPart::toString(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1840();
}
void DynamicBodyPart::prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	this->exp->analyse(context, false, ctx);
}
void DynamicBodyPart::execute(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->exp->resolveExpression(machine, debug, ctx);
	if(val == nullptr)
	{
		writer->write(ConstStr::getCNST_STR_369(), ctx);
		return;
	}
	writer->write(val->getStringValue(ctx), ctx);
}
void DynamicBodyPart::__cleanUp(ThreadContext* ctx){
}
}}}}

