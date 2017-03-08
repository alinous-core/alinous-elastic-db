#include "include/global.h"


#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool JoinStrategyPart::__init_done = __init_static_variables();
bool JoinStrategyPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinStrategyPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinStrategyPart::JoinStrategyPart(ThreadContext* ctx) throw()  : IObject(ctx), andexpressions(GCUtils<ArrayList<JoinMatchExpression> >::ins(this, (new(ctx) ArrayList<JoinMatchExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), bestExp(nullptr), indexStatus(-1)
{
}
void JoinStrategyPart::__construct_impl(ThreadContext* ctx) throw() 
{
}
 JoinStrategyPart::~JoinStrategyPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinStrategyPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinStrategyPart", L"~JoinStrategyPart");
	__e_obj1.add(this->andexpressions, this);
	andexpressions = nullptr;
	__e_obj1.add(this->bestExp, this);
	bestExp = nullptr;
	if(!prepare){
		return;
	}
}
void JoinStrategyPart::calcIindexStatus(ThreadContext* ctx) throw() 
{
	int maxLoop = this->andexpressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		JoinMatchExpression* match = this->andexpressions->get(i, ctx);
		int status = match->getIndexStatus(ctx);
		if(status > this->indexStatus)
		{
			this->indexStatus = status;
			__GC_MV(this, &(this->bestExp), match, JoinMatchExpression);
		}
	}
}
JoinMatchExpression* JoinStrategyPart::getBestExp(ThreadContext* ctx) throw() 
{
	return bestExp;
}
void JoinStrategyPart::addExpression(JoinMatchExpression* matchExp, ThreadContext* ctx) throw() 
{
	this->andexpressions->add(matchExp, ctx);
	return;
}
ArrayList<JoinMatchExpression>* JoinStrategyPart::getExpressions(ThreadContext* ctx) throw() 
{
	return andexpressions;
}
bool JoinStrategyPart::requireFullScan(ThreadContext* ctx) throw() 
{
	return this->andexpressions->isEmpty(ctx);
}
void JoinStrategyPart::__cleanUp(ThreadContext* ctx){
}
}}}}

