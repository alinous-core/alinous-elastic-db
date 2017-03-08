#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.analyse.tools/FunctionCallCollector.h"

namespace alinous {namespace compile {namespace analyse {namespace tools {





bool FunctionCallCollector::__init_done = __init_static_variables();
bool FunctionCallCollector::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionCallCollector", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionCallCollector::FunctionCallCollector(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElementVisitor(ctx), list(GCUtils<ArrayList<FunctionCallExpression> >::ins(this, (new(ctx) ArrayList<FunctionCallExpression>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void FunctionCallCollector::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FunctionCallCollector::~FunctionCallCollector() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionCallCollector::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionCallCollector", L"~FunctionCallCollector");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
bool FunctionCallCollector::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<FunctionCallExpression*>(element) != 0))
	{
		this->list->add(static_cast<FunctionCallExpression*>(element), ctx);
	}
	return true;
}
ArrayList<FunctionCallExpression>* FunctionCallCollector::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void FunctionCallCollector::__cleanUp(ThreadContext* ctx){
}
}}}}

