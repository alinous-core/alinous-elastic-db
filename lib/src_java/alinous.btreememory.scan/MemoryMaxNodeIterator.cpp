#include "includes.h"


namespace alinous {namespace btreememory {namespace scan {





bool MemoryMaxNodeIterator::__init_done = __init_static_variables();
bool MemoryMaxNodeIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MemoryMaxNodeIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MemoryMaxNodeIterator::MemoryMaxNodeIterator(bool endStart, MBTreeMaxNode* node, ThreadContext* ctx) throw()  : IObject(ctx), INodeIterator(ctx), current(0), length(0), node(nullptr)
{
	__GC_MV(this, &(this->node), node, MBTreeMaxNode);
	this->length = node->getNodeUsed(ctx);
	current = endStart ? this->length : 0;
	this->length = this->node->getNodeUsed(ctx);
}
void MemoryMaxNodeIterator::__construct_impl(bool endStart, MBTreeMaxNode* node, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->node), node, MBTreeMaxNode);
	this->length = node->getNodeUsed(ctx);
	current = endStart ? this->length : 0;
	this->length = this->node->getNodeUsed(ctx);
}
 MemoryMaxNodeIterator::~MemoryMaxNodeIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MemoryMaxNodeIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MemoryMaxNodeIterator", L"~MemoryMaxNodeIterator");
	__e_obj1.add(this->node, this);
	node = nullptr;
	if(!prepare){
		return;
	}
}
void MemoryMaxNodeIterator::gotoNode(IBTreeKey* key, ThreadContext* ctx)
{
	int pos = this->node->getNodeAtInsertPositionNumber(key, ctx);
	this->current = pos;
}
void MemoryMaxNodeIterator::incCurrent(ThreadContext* ctx) throw() 
{
	this->current ++ ;
}
bool MemoryMaxNodeIterator::hasNext(ThreadContext* ctx) throw() 
{
	return this->current >= 0 && this->current <= this->length;
}
IBTreeNode* MemoryMaxNodeIterator::next(ThreadContext* ctx) throw() 
{
	IBTreeNode* node = this->length == this->current ? this->node->getMax(ctx) : this->node->get(this->current, ctx);
	this->current ++ ;
	return node;
}
bool MemoryMaxNodeIterator::isLeafContainer(ThreadContext* ctx) throw() 
{
	return false;
}
void MemoryMaxNodeIterator::dispose(ThreadContext* ctx)
{
}
int MemoryMaxNodeIterator::getType(ThreadContext* ctx) throw() 
{
	return INodeIterator::IT_NODE;
}
}}}

