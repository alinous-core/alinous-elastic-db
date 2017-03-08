#include "include/global.h"


#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"

namespace alinous {namespace btree {namespace scan {





bool AbstractNodeIterator::__init_done = __init_static_variables();
bool AbstractNodeIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractNodeIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractNodeIterator::AbstractNodeIterator(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw()  : IObject(ctx), INodeIterator(ctx), loader(nullptr), filePointer(0)
{
	this->filePointer = filePointer;
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
}
void AbstractNodeIterator::__construct_impl(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw() 
{
	this->filePointer = filePointer;
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
}
 AbstractNodeIterator::~AbstractNodeIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractNodeIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractNodeIterator", L"~AbstractNodeIterator");
	__e_obj1.add(this->loader, this);
	loader = nullptr;
	if(!prepare){
		return;
	}
}
void AbstractNodeIterator::__cleanUp(ThreadContext* ctx){
}
}}}

