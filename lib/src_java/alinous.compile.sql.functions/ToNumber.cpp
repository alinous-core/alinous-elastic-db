#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/ToNumber.h"

namespace alinous {namespace compile {namespace sql {namespace functions {





bool ToNumber::__init_done = __init_static_variables();
bool ToNumber::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ToNumber", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ToNumber::ToNumber(ThreadContext* ctx) throw()  : IObject(ctx), ISQLFunctionBody(ctx)
{
}
void ToNumber::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ToNumber::~ToNumber() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ToNumber::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* ToNumber::getName(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1148();
}
VariantValue* ToNumber::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, FunctionArguments* args, bool debug, ThreadContext* ctx)
{
	ArrayList<IExpression>* arglist = args->arguments;
	int maxLoop = arglist->size(ctx);
	if(maxLoop < 1)
	{
		throw (new(ctx) AlinousException(ctx));
	}
	IExpression* exp = arglist->get(0, ctx);
	VariantValue* value = nullptr;
	if(!exp->isSQLExp(ctx))
	{
		value = static_cast<VariantValue*>(exp->resolveExpression(machine, debug, ctx));
	}
		else 
	{
		ISQLExpression* sqlExp = static_cast<ISQLExpression*>(exp);
		value = sqlExp->resolveSQLExpression(record, machine, debug, ctx);
	}
	return (new(ctx) VariantValue(value->getInt(ctx), ctx));
}
void ToNumber::__cleanUp(ThreadContext* ctx){
}
}}}}

