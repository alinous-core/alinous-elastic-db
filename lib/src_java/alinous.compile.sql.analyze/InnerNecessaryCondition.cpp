#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/IndexConditionDetector.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool InnerNecessaryCondition::__init_done = __init_static_variables();
bool InnerNecessaryCondition::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InnerNecessaryCondition", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InnerNecessaryCondition::InnerNecessaryCondition(ISQLExpression* exp, ThreadContext* ctx) throw()  : IObject(ctx), exp(nullptr), strategy(nullptr)
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
void InnerNecessaryCondition::__construct_impl(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
 InnerNecessaryCondition::~InnerNecessaryCondition() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InnerNecessaryCondition::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InnerNecessaryCondition", L"~InnerNecessaryCondition");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->strategy, this);
	strategy = nullptr;
	if(!prepare){
		return;
	}
}
void InnerNecessaryCondition::analyze(ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx)
{
	__GC_MV(this, &(this->strategy), IndexConditionDetector::detect(this->exp, tableMetadata, debug, ctx), IndexScanStrategy);
}
ISQLExpression* InnerNecessaryCondition::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
IndexScanStrategy* InnerNecessaryCondition::getStrategy(ThreadContext* ctx) throw() 
{
	return strategy;
}
bool InnerNecessaryCondition::optimizeIndexStrategy(AlinousDatabase* database, ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw() 
{
	return this->strategy->calcBestIndexPlan(joinRequest, ctx);
}
void InnerNecessaryCondition::includes(IndexConditionDetector* arg0, ThreadContext* ctx) throw() 
{
}
void InnerNecessaryCondition::__cleanUp(ThreadContext* ctx){
}
}}}}

