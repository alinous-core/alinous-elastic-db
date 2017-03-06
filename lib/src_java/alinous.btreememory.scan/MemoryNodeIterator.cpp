#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btreememory.scan/MemoryNodeIterator.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/AbstractMemoryBTreeNode.h"
#include "alinous.btreememory/MBTreeNode.h"
#include "alinous.btreememory/MBTreeMaxNode.h"
#include "alinous.btreememory.scan/MemoryMaxNodeIterator.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.btreememory.scan/MemoryBTreeScanner.h"
#include "alinous.btreememory/AbstractMemoryBTreeLeafContainer.h"
#include "alinous.btreememory.scan/MemoryLeafContainerIterator.h"

namespace alinous {namespace btreememory {namespace scan {





bool MemoryNodeIterator::__init_done = __init_static_variables();
bool MemoryNodeIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MemoryNodeIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MemoryNodeIterator::MemoryNodeIterator(bool endStart, MBTreeNode* node, ThreadContext* ctx) throw()  : IObject(ctx), INodeIterator(ctx), current(0), length(0), node(nullptr)
{
	__GC_MV(this, &(this->node), node, MBTreeNode);
	this->current = endStart ? this->node->getNodeUsed(ctx) - 1 : 0;
	this->length = this->node->getNodeUsed(ctx);
}
void MemoryNodeIterator::__construct_impl(bool endStart, MBTreeNode* node, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->node), node, MBTreeNode);
	this->current = endStart ? this->node->getNodeUsed(ctx) - 1 : 0;
	this->length = this->node->getNodeUsed(ctx);
}
 MemoryNodeIterator::~MemoryNodeIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MemoryNodeIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MemoryNodeIterator", L"~MemoryNodeIterator");
	__e_obj1.add(this->node, this);
	node = nullptr;
	if(!prepare){
		return;
	}
}
void MemoryNodeIterator::gotoNode(IBTreeKey* key, ThreadContext* ctx)
{
	this->current = this->node->getNodeAtInsertPositionNumber(key, ctx);
}
void MemoryNodeIterator::incCurrent(ThreadContext* ctx) throw() 
{
	this->current ++ ;
}
bool MemoryNodeIterator::hasNext(ThreadContext* ctx) throw() 
{
	return this->current >= 0 && length != current;
}
IBTreeNode* MemoryNodeIterator::next(ThreadContext* ctx) throw() 
{
	return this->node->get(this->current++, ctx);
}
bool MemoryNodeIterator::isLeafContainer(ThreadContext* ctx) throw() 
{
	return false;
}
void MemoryNodeIterator::dispose(ThreadContext* ctx)
{
}
int MemoryNodeIterator::getType(ThreadContext* ctx) throw() 
{
	return INodeIterator::IT_MAX_NODE;
}
void MemoryNodeIterator::__cleanUp(ThreadContext* ctx){
}
}}}

