#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"

namespace alinous {namespace db {namespace table {





bool TablePartitionRangeCollection::__init_done = __init_static_variables();
bool TablePartitionRangeCollection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TablePartitionRangeCollection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TablePartitionRangeCollection::TablePartitionRangeCollection(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), ranges(GCUtils<ArrayList<TablePartitionRange> >::ins(this, (new(ctx) ArrayList<TablePartitionRange>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TablePartitionRangeCollection::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TablePartitionRangeCollection::~TablePartitionRangeCollection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TablePartitionRangeCollection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TablePartitionRangeCollection", L"~TablePartitionRangeCollection");
	__e_obj1.add(this->ranges, this);
	ranges = nullptr;
	if(!prepare){
		return;
	}
}
void TablePartitionRangeCollection::addRange(TablePartitionRange* value, ThreadContext* ctx) throw() 
{
	this->ranges->add(value, ctx);
}
ArrayList<TablePartitionRange>* TablePartitionRangeCollection::getRanges(ThreadContext* ctx) throw() 
{
	return ranges;
}
int TablePartitionRangeCollection::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->ranges->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionRange* range = this->ranges->get(i, ctx);
		total += range->fileSize(ctx);
	}
	return total;
}
void TablePartitionRangeCollection::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	int maxLoop = this->ranges->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionRange* range = this->ranges->get(i, ctx);
		range->toFileEntry(builder, ctx);
	}
}
void TablePartitionRangeCollection::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionRange* range = TablePartitionRange::fromNetwork(buff, ctx);
		this->ranges->add(range, ctx);
	}
}
void TablePartitionRangeCollection::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->ranges->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionRange* range = this->ranges->get(i, ctx);
		range->writeData(buff, ctx);
	}
}
TablePartitionRangeCollection* TablePartitionRangeCollection::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	TablePartitionRangeCollection* collection = (new(ctx) TablePartitionRangeCollection(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TablePartitionRange* range = TablePartitionRange::loadFromFetcher(fetcher, ctx);
		collection->ranges->add(range, ctx);
	}
	return collection;
}
TablePartitionRangeCollection* TablePartitionRangeCollection::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TablePartitionRangeCollection* collection = (new(ctx) TablePartitionRangeCollection(ctx));
	collection->readData(buff, ctx);
	return collection;
}
void TablePartitionRangeCollection::__cleanUp(ThreadContext* ctx){
}
}}}

