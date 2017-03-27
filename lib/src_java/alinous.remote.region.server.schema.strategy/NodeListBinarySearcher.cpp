#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.remote.region.server.schema.strategy/RegionShardPartAccess.h"
#include "alinous.remote.region.server.schema.strategy/NodeListBinarySearcher.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool NodeListBinarySearcher::__init_done = __init_static_variables();
bool NodeListBinarySearcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeListBinarySearcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeListBinarySearcher::NodeListBinarySearcher(List<RegionShardPartAccess>* nodeList, ThreadContext* ctx) throw()  : IObject(ctx), nodeList(nullptr)
{
	GCUtils<List<RegionShardPartAccess> >::mv(this, &(this->nodeList), nodeList, ctx);
}
void NodeListBinarySearcher::__construct_impl(List<RegionShardPartAccess>* nodeList, ThreadContext* ctx) throw() 
{
	GCUtils<List<RegionShardPartAccess> >::mv(this, &(this->nodeList), nodeList, ctx);
}
 NodeListBinarySearcher::~NodeListBinarySearcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeListBinarySearcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeListBinarySearcher", L"~NodeListBinarySearcher");
	__e_obj1.add(this->nodeList, this);
	nodeList = nullptr;
	if(!prepare){
		return;
	}
}
RegionShardPartAccess* NodeListBinarySearcher::searchNode(IDatabaseRecord* record, ThreadContext* ctx)
{
	RegionShardPartAccess* access = binarySearch(nodeList, record, ctx);
	if(access == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3621(), ctx));
	}
	return access;
}
RegionShardPartAccess* NodeListBinarySearcher::binarySearch(List<RegionShardPartAccess>* nodeList, IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	if(this->nodeList->size(ctx) == 0)
	{
		return nullptr;
	}
	int begin = 0;
	int end = nodeList->size(ctx) - 1;
	int mid = (begin + end) / 2;
	while(begin <= end)
	{
		mid = (begin + end) / 2;
		TablePartitionRangeCollection* midValue = nodeList->get(mid, ctx)->getPartitionRange(ctx);
		int cmpResult = compareTo(midValue, record, ctx);
		if(cmpResult == 0)
		{
			return nodeList->get(mid, ctx);
		}
				else 
		{
			if(cmpResult < 0)
			{
				begin = mid + 1;
			}
						else 
			{
				end = mid - 1;
			}
		}
	}
	return nullptr;
}
int NodeListBinarySearcher::compareTo(TablePartitionRangeCollection* collectionValue, IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	return collectionValue->compareToRecord(record, ctx);
}
void NodeListBinarySearcher::__cleanUp(ThreadContext* ctx){
}
}}}}}}

