#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"

namespace alinous {namespace compile {namespace expression {





constexpr const int IDomSegment::TYPE_NORMAL;
constexpr const int IDomSegment::TYPE_INDEX;
bool IDomSegment::__init_done = __init_static_variables();
bool IDomSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDomSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDomSegment::IDomSegment(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx)
{
}
void IDomSegment::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IDomSegment::~IDomSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDomSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
IDomSegment* IDomSegment::fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int type = fetcher->fetchInt(ctx);
	IDomSegment* seg = nullptr;
	switch(type) {
	case TYPE_NORMAL:
		seg = (new(ctx) DomNameSegment(ctx));
		break ;
	case TYPE_INDEX:
		seg = (new(ctx) DomIndexSegment(ctx));
		break ;
	default:
		return nullptr;
		break;
	}
	seg->fromFileEntry(fetcher, ctx);
	return seg;
}
void IDomSegment::__cleanUp(ThreadContext* ctx){
}
}}}

