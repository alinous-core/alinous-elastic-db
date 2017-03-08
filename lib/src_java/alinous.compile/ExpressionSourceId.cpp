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
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"

namespace alinous {namespace compile {





bool ExpressionSourceId::__init_done = __init_static_variables();
bool ExpressionSourceId::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpressionSourceId", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpressionSourceId::ExpressionSourceId(String* id, IExpression* exp, AlinousType* alinousType, ThreadContext* ctx) throw()  : IObject(ctx), id(nullptr), exp(nullptr), type(nullptr)
{
	__GC_MV(this, &(this->id), id, String);
	__GC_MV(this, &(this->exp), exp, IExpression);
	__GC_MV(this, &(this->type), alinousType, AlinousType);
}
void ExpressionSourceId::__construct_impl(String* id, IExpression* exp, AlinousType* alinousType, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, String);
	__GC_MV(this, &(this->exp), exp, IExpression);
	__GC_MV(this, &(this->type), alinousType, AlinousType);
}
 ExpressionSourceId::~ExpressionSourceId() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpressionSourceId::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpressionSourceId", L"~ExpressionSourceId");
	__e_obj1.add(this->id, this);
	id = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->type, this);
	type = nullptr;
	if(!prepare){
		return;
	}
}
String* ExpressionSourceId::getId(ThreadContext* ctx) throw() 
{
	return id;
}
void ExpressionSourceId::setId(String* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, String);
}
String* ExpressionSourceId::toString(ThreadContext* ctx) throw() 
{
	return this->id;
}
IExpression* ExpressionSourceId::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
AlinousType* ExpressionSourceId::getType(ThreadContext* ctx) throw() 
{
	return type;
}
void ExpressionSourceId::__cleanUp(ThreadContext* ctx){
}
}}

