#include "includes.h"


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
}}}}

