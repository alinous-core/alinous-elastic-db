#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree.scan/INodeIterator.h"

namespace alinous {namespace btree {namespace scan {




constexpr const int INodeIterator::IT_LEAF_CONTAINER;
constexpr const int INodeIterator::IT_MAX_NODE;
constexpr const int INodeIterator::IT_NODE;
bool INodeIterator::__init_done = __init_static_variables();
bool INodeIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"INodeIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 INodeIterator::INodeIterator(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void INodeIterator::__construct_impl(ThreadContext* ctx) throw() 
{
}
 INodeIterator::~INodeIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void INodeIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void INodeIterator::__cleanUp(ThreadContext* ctx){
}
}}}

