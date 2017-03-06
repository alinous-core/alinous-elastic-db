#include "include/global.h"


#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/NodeIterator.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree.scan/MaxNodeIterator.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree.scan/LeafContainerIterator.h"

namespace alinous {namespace btree {namespace scan {





bool NodeIterator::__init_done = __init_static_variables();
bool NodeIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeIterator::NodeIterator(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx) : IObject(ctx), AbstractNodeIterator(loader, filePointer, ctx), node(nullptr), length(0), current(0)
{
	__GC_MV(this, &(this->node), static_cast<BTreeNode*>(loader->loadBTreeNode(filePointer, ctx)), BTreeNode);
	this->node->loadChildren(ctx);
	if(endStart)
	{
		current = this->node->getNodeUsed(ctx) - 1;
	}
		else 
	{
		current = 0;
	}
	this->length = this->node->getNodeUsed(ctx);
}
void NodeIterator::__construct_impl(BTreeNodeLoader* loader, long long filePointer, bool endStart, ThreadContext* ctx)
{
	__GC_MV(this, &(this->node), static_cast<BTreeNode*>(loader->loadBTreeNode(filePointer, ctx)), BTreeNode);
	this->node->loadChildren(ctx);
	if(endStart)
	{
		current = this->node->getNodeUsed(ctx) - 1;
	}
		else 
	{
		current = 0;
	}
	this->length = this->node->getNodeUsed(ctx);
}
 NodeIterator::~NodeIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeIterator", L"~NodeIterator");
	__e_obj1.add(this->node, this);
	node = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeIterator::__releaseRegerences(true, ctx);
}
void NodeIterator::gotoNode(IBTreeKey* key, ThreadContext* ctx)
{
	this->current = this->node->getNodeAtInsertPositionNumber(key, ctx);
}
void NodeIterator::incCurrent(ThreadContext* ctx) throw() 
{
	this->current ++ ;
}
bool NodeIterator::hasNext(ThreadContext* ctx) throw() 
{
	return this->current >= 0 && length != current;
}
IBTreeNode* NodeIterator::next(ThreadContext* ctx)
{
	this->node->loadChildren(ctx);
	return this->node->get(this->current++, ctx)->getNode(ctx);
}
bool NodeIterator::isLeafContainer(ThreadContext* ctx) throw() 
{
	return false;
}
void NodeIterator::dispose(ThreadContext* ctx)
{
	this->node->endUse(ctx);
}
int NodeIterator::getType(ThreadContext* ctx) throw() 
{
	return INodeIterator::IT_MAX_NODE;
}
void NodeIterator::__cleanUp(ThreadContext* ctx){
}
}}}

