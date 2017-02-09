#include "includes.h"


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
		buff->append(ConstStr::getCNST_STR_1657(), ctx);
	}
}
int AbstractMemoryNode::ValueCompare::operator() (IBTreeNode* _this, IBTreeNode* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

