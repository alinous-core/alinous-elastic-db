#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TableMetadataUnique::__init_done = __init_static_variables();
bool TableMetadataUnique::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableMetadataUnique", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableMetadataUnique::~TableMetadataUnique() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableMetadataUnique::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableMetadataUnique", L"~TableMetadataUnique");
	__e_obj1.add(this->uniqueColList, this);
	uniqueColList = nullptr;
	if(!prepare){
		return;
	}
}
ScanUnique* TableMetadataUnique::toScanUnique(String* tableFullName, ThreadContext* ctx) throw() 
{
	ScanUnique* unique = (new(ctx) ScanUnique(ctx));
	unique->setTableFullName(tableFullName, ctx);
	int maxLoop = uniqueColList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->uniqueColList->get(i, ctx);
		unique->addUnique(col, ctx);
	}
	return unique;
}
void TableMetadataUnique::addUnique(TableColumnMetadata* col, ThreadContext* ctx) throw() 
{
	this->uniqueColList->add(col, ctx);
}
ArrayList<TableColumnMetadata>* TableMetadataUnique::getUniqueColList(ThreadContext* ctx) throw() 
{
	return uniqueColList;
}
int TableMetadataUnique::fileSize(ThreadContext* ctx)
{
	int total = 4;
	int maxLoop = this->uniqueColList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->uniqueColList->get(i, ctx);
		total += col->fileSize(ctx);
	}
	return total;
}
void TableMetadataUnique::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	int maxLoop = this->uniqueColList->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->uniqueColList->get(i, ctx);
		col->toFileEntry(builder, ctx);
	}
}
void TableMetadataUnique::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::fromNetwork(buff, ctx);
		addUnique(col, ctx);
	}
}
void TableMetadataUnique::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = this->uniqueColList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->uniqueColList->get(i, ctx);
		col->writeData(buff, ctx);
	}
}
TableMetadataUnique* TableMetadataUnique::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	TableMetadataUnique* unique = (new(ctx) TableMetadataUnique(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::loadFromFetcher(fetcher, ctx);
		unique->addUnique(col, ctx);
	}
	return unique;
}
TableMetadataUnique* TableMetadataUnique::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TableMetadataUnique* unique = (new(ctx) TableMetadataUnique(ctx));
	unique->readData(buff, ctx);
	return unique;
}
}}}

