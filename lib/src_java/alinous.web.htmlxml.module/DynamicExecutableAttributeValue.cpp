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
#include "alinous.web.htmlxml.module/DynamicExecutableAttributeValue.h"

namespace alinous {namespace web {namespace htmlxml {namespace module {





bool DynamicExecutableAttributeValue::__init_done = __init_static_variables();
bool DynamicExecutableAttributeValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DynamicExecutableAttributeValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DynamicExecutableAttributeValue::DynamicExecutableAttributeValue(String* value, ThreadContext* ctx) : IObject(ctx), exp(nullptr)
{
	String* prog = value->trim(ctx);
	if(prog->startsWith(ConstStr::getCNST_STR_1878(), ctx) && prog->endsWith(ConstStr::getCNST_STR_1190(), ctx))
	{
		prog = prog->substring(1, prog->length(ctx) - 1, ctx);
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
}
void DynamicExecutableAttributeValue::__construct_impl(String* value, ThreadContext* ctx)
{
	String* prog = value->trim(ctx);
	if(prog->startsWith(ConstStr::getCNST_STR_1878(), ctx) && prog->endsWith(ConstStr::getCNST_STR_1190(), ctx))
	{
		prog = prog->substring(1, prog->length(ctx) - 1, ctx);
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
}
 DynamicExecutableAttributeValue::~DynamicExecutableAttributeValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DynamicExecutableAttributeValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DynamicExecutableAttributeValue", L"~DynamicExecutableAttributeValue");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
}
void DynamicExecutableAttributeValue::prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw() 
{
	if(this->exp == nullptr)
	{
		return;
	}
	this->exp->analyse(context, false, ctx);
}
IAlinousVariable* DynamicExecutableAttributeValue::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->exp->resolveExpression(machine, debug, ctx);
	return val;
}
void DynamicExecutableAttributeValue::__cleanUp(ThreadContext* ctx){
}
}}}}

