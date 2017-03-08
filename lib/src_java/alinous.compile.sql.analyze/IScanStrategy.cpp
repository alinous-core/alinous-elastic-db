#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.compile.sql.analyze/IScanStrategy.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {




bool IScanStrategy::__init_done = __init_static_variables();
bool IScanStrategy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IScanStrategy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IScanStrategy::IScanStrategy(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IScanStrategy::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IScanStrategy::~IScanStrategy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IScanStrategy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IScanStrategy::__cleanUp(ThreadContext* ctx){
}
}}}}

