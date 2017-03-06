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
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btreememory.scan/MemoryLeafContainerIterator.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/AbstractMemoryBTreeLeafContainer.h"
#include "alinous.btreememory/MBTreeLeafContainer.h"
#include "alinous.btreememory/MBTreeMaxLeafContainer.h"
#include "alinous.btreememory/AbstractMemoryBTreeNode.h"
#include "alinous.btreememory/MBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btreememory/MBTreeLeafNode.h"
#include "alinous.btreememory/MBTreeMaxNode.h"
#include "alinous.btreememory/MemoryBTreeMachine.h"
#include "alinous.btreememory/BTreeOnMemory.h"

namespace alinous {namespace btreememory {





bool AbstractMemoryNode::__init_done = __init_static_variables();
bool AbstractMemoryNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractMemoryNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractMemoryNode::AbstractMemoryNode(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeNode(ctx)
{
}
void AbstractMemoryNode::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractMemoryNode::~AbstractMemoryNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractMemoryNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
long long AbstractMemoryNode::getFilePointer(ThreadContext* ctx) throw() 
{
	return -1;
}
int AbstractMemoryNode::nodeSize(ThreadContext* ctx)
{
	return -1;
}
void AbstractMemoryNode::use(ThreadContext* ctx)
{
}
void AbstractMemoryNode::endUse(ThreadContext* ctx)
{
}
FileStorageEntry* AbstractMemoryNode::toFileStorageEntry(FileStorageEntryBuilder* buffBuilder, FileStorageEntry* buffEntry, ThreadContext* ctx)
{
	return nullptr;
}
void AbstractMemoryNode::setFilePointer(long long position, ThreadContext* ctx) throw() 
{
}
bool AbstractMemoryNode::isDeletable(ThreadContext* ctx) throw() 
{
	return true;
}
void AbstractMemoryNode::incCount(ThreadContext* ctx) throw() 
{
}
int AbstractMemoryNode::getUseGCRefCount(ThreadContext* ctx) throw() 
{
	return -1;
}
long long AbstractMemoryNode::getHashKey(ThreadContext* ctx) throw() 
{
	return IObject::hashCode(ctx);
}
int AbstractMemoryNode::compareTo(IBTreeNode* another, ThreadContext* ctx) throw() 
{
	if(this->getKey(ctx) == nullptr || another->getKey(ctx) == nullptr)
	{
		if(this->getKey(ctx) == nullptr && another->getKey(ctx) == nullptr)
		{
			return 0;
		}
				else 
		{
			if(this->getKey(ctx) != nullptr && another->getKey(ctx) == nullptr)
			{
				return 1;
			}
						else 
			{
				if(this->getKey(ctx) == nullptr && another->getKey(ctx) != nullptr)
				{
					return -1;
				}
			}
		}
	}
	return this->getKey(ctx)->compareTo(another->getKey(ctx), ctx);
}
void AbstractMemoryNode::printTab(StringBuffer* buff, int level, ThreadContext* ctx) throw() 
{
	for(int i = 0; i != level; ++i)
	{
		buff->append(ConstStr::getCNST_STR_1662(), ctx);
	}
}
void AbstractMemoryNode::__cleanUp(ThreadContext* ctx){
}
int AbstractMemoryNode::ValueCompare::operator() (IBTreeNode* _this, IBTreeNode* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

