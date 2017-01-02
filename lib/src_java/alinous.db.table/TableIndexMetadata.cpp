#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TableIndexMetadata::__init_done = __init_static_variables();
bool TableIndexMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableIndexMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableIndexMetadata::TableIndexMetadata(String* name, ArrayList<String>* columns, ThreadContext* ctx) throw()  : IObject(ctx), name(nullptr), columns(nullptr), metadata(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->name), name, String);
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
void TableIndexMetadata::__construct_impl(String* name, ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
 TableIndexMetadata::~TableIndexMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableIndexMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableIndexMetadata", L"~TableIndexMetadata");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
}
void TableIndexMetadata::setupColumnMetadata(TableMetadata* meta, ThreadContext* ctx)
{
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* name = this->columns->get(i, ctx);
		TableColumnMetadata* col = meta->getColumnByName(name, ctx);
		if(col == nullptr)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1613()->clone(ctx)->append(name, ctx)->append(ConstStr::getCNST_STR_1614(), ctx)->append(this->name, ctx), ctx));
		}
		this->metadata->add(col, ctx);
	}
}
int TableIndexMetadata::fileSize(ThreadContext* ctx) throw() 
{
	int total = this->name->length(ctx) * 2 + 4;
	int maxLoop = this->columns->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = this->columns->get(i, ctx);
		total += col->length(ctx) * 2 + 4;
	}
	return total;
}
void TableIndexMetadata::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putString(this->name, ctx);
	int maxLoop = this->columns->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = this->columns->get(i, ctx);
		builder->putString(col, ctx);
	}
}
String* TableIndexMetadata::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void TableIndexMetadata::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
ArrayList<String>* TableIndexMetadata::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void TableIndexMetadata::setColumns(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
ArrayList<TableColumnMetadata>* TableIndexMetadata::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
TableIndexMetadata* TableIndexMetadata::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	String* name = fetcher->fetchString(ctx);
	ArrayList<String>* list = (new(ctx) ArrayList<String>(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = fetcher->fetchString(ctx);
		list->add(col, ctx);
	}
	TableIndexMetadata* meta = (new(ctx) TableIndexMetadata(name, list, ctx));
	return meta;
}
}}}

