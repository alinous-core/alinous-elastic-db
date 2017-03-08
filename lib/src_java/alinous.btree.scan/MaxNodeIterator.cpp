#include "include/global.h"


#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/MaxNodeIterator.h"

namespace alinous {namespace btree {namespace scan {





bool MaxNodeIterator::__init_done = __init_static_variables();
bool MaxNodeIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MaxNodeIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MaxNodeIterator::MaxNodeIterator(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx) : IObject(ctx), AbstractNodeIterator(loader, filePointer, ctx), node(nullptr), length(0), current(0)
{
	__GC_MV(this, &(this->node), static_cast<BTreeMaxNode*>(loader->loadBTreeNode(filePointer, ctx)), BTreeMaxNode);
	this->node->loadChildren(ctx);
	this->length = this->node->getNodeUsed(ctx);
	if(endStart)
	{
		current = this->length;
	}
		else 
	{
		current = 0;
	}
	this->length = this->node->getNodeUsed(ctx);
}
void MaxNodeIterator::__construct_impl(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx)
{
	__GC_MV(this, &(this->node), static_cast<BTreeMaxNode*>(loader->loadBTreeNode(filePointer, ctx)), BTreeMaxNode);
	this->node->loadChildren(ctx);
	this->length = this->node->getNodeUsed(ctx);
	if(endStart)
	{
		current = this->length;
	}
		else 
	{
		current = 0;
	}
	this->length = this->node->getNodeUsed(ctx);
}
 MaxNodeIterator::~MaxNodeIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MaxNodeIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MaxNodeIterator", L"~MaxNodeIterator");
	__e_obj1.add(this->node, this);
	node = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeIterator::__releaseRegerences(true, ctx);
}
void MaxNodeIterator::gotoNode(IBTreeKey* key, ThreadContext* ctx)
{
	int pos = this->node->getNodeAtInsertPositionNumber(key, ctx);
	this->current = pos;
}
void MaxNodeIterator::incCurrent(ThreadContext* ctx) throw() 
{
	this->current ++ ;
}
bool MaxNodeIterator::hasNext(ThreadContext* ctx) throw() 
{
	return this->current >= 0 && this->current <= this->length;
}
IBTreeNode* MaxNodeIterator::next(ThreadContext* ctx) throw() 
{
	IBTreeNode* node = this->length == this->current ? this->node->getMax(ctx)->getNode(ctx) : this->node->get(this->current, ctx)->getNode(ctx);
	this->current ++ ;
	return node;
}
bool MaxNodeIterator::isLeafContainer(ThreadContext* ctx) throw() 
{
	return false;
}
void MaxNodeIterator::dispose(ThreadContext* ctx)
{
	this->node->endUse(ctx);
}
int MaxNodeIterator::getType(ThreadContext* ctx) throw() 
{
	return INodeIterator::IT_NODE;
}
void MaxNodeIterator::__cleanUp(ThreadContext* ctx){
}
}}}

