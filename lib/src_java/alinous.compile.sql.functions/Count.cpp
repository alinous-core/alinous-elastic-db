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
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.sql.functions/ISQLFunctionBody.h"
#include "alinous.compile.sql.functions/Count.h"
#include "alinous.compile.sql.functions/Coalesce.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.sql.functions/ToNumber.h"

namespace alinous {namespace compile {namespace sql {namespace functions {





bool Count::__init_done = __init_static_variables();
bool Count::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Count", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Count::Count(ThreadContext* ctx) throw()  : IObject(ctx), ISQLFunctionBody(ctx)
{
}
void Count::__construct_impl(ThreadContext* ctx) throw() 
{
}
 Count::~Count() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Count::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* Count::getName(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1083();
}
VariantValue* Count::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, FunctionArguments* args, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void Count::__cleanUp(ThreadContext* ctx){
}
}}}}

