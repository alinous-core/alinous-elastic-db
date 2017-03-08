#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"

namespace alinous {namespace compile {namespace analyse {





bool DomVariableDeclareSource::__init_done = __init_static_variables();
bool DomVariableDeclareSource::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariableDeclareSource", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariableDeclareSource::DomVariableDeclareSource(String* domPath, IExpression* exp, ThreadContext* ctx) throw()  : IObject(ctx), domPath(nullptr), exp(nullptr)
{
	__GC_MV(this, &(this->domPath), domPath, String);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
void DomVariableDeclareSource::__construct_impl(String* domPath, IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domPath), domPath, String);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
 DomVariableDeclareSource::~DomVariableDeclareSource() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariableDeclareSource::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomVariableDeclareSource", L"~DomVariableDeclareSource");
	__e_obj1.add(this->domPath, this);
	domPath = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
}
String* DomVariableDeclareSource::getDomPath(ThreadContext* ctx) throw() 
{
	return domPath;
}
void DomVariableDeclareSource::setDomPath(String* domPath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domPath), domPath, String);
}
IExpression* DomVariableDeclareSource::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void DomVariableDeclareSource::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
void DomVariableDeclareSource::__cleanUp(ThreadContext* ctx){
}
}}}

