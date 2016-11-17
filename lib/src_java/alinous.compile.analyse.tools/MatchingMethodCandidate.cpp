#include "includes.h"


namespace alinous {namespace compile {namespace analyse {namespace tools {





bool MatchingMethodCandidate::__init_done = __init_static_variables();
bool MatchingMethodCandidate::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MatchingMethodCandidate", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MatchingMethodCandidate::MatchingMethodCandidate(ClassMethodFunction* method, int score, ThreadContext* ctx) throw()  : IObject(ctx), method(nullptr), score(0), sameScores(GCUtils<ArrayList<ClassMethodFunction> >::ins(this, (new(ctx) ArrayList<ClassMethodFunction>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->method), method, ClassMethodFunction);
	this->score = score;
}
void MatchingMethodCandidate::__construct_impl(ClassMethodFunction* method, int score, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->method), method, ClassMethodFunction);
	this->score = score;
}
 MatchingMethodCandidate::~MatchingMethodCandidate() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MatchingMethodCandidate::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MatchingMethodCandidate", L"~MatchingMethodCandidate");
	__e_obj1.add(this->method, this);
	method = nullptr;
	__e_obj1.add(this->sameScores, this);
	sameScores = nullptr;
	if(!prepare){
		return;
	}
}
ClassMethodFunction* MatchingMethodCandidate::getMethod(ThreadContext* ctx) throw() 
{
	return method;
}
void MatchingMethodCandidate::setMethod(ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->method), method, ClassMethodFunction);
}
int MatchingMethodCandidate::getScore(ThreadContext* ctx) throw() 
{
	return score;
}
void MatchingMethodCandidate::setScore(int score, ThreadContext* ctx) throw() 
{
	this->score = score;
}
ArrayList<ClassMethodFunction>* MatchingMethodCandidate::getSameScores(ThreadContext* ctx) throw() 
{
	return sameScores;
}
void MatchingMethodCandidate::addSameScore(ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	this->sameScores->add(method, ctx);
}
bool MatchingMethodCandidate::isAmbitious(ThreadContext* ctx) throw() 
{
	return this->sameScores->size(ctx) > 0;
}
}}}}

