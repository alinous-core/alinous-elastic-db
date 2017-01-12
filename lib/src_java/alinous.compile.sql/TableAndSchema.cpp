#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool TableAndSchema::__init_done = __init_static_variables();
bool TableAndSchema::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableAndSchema", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableAndSchema::TableAndSchema(String* schema, String* table, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), schema(nullptr), toStr(nullptr)
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->table), table, String);
}
void TableAndSchema::__construct_impl(String* schema, String* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->table), table, String);
}
 TableAndSchema::~TableAndSchema() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableAndSchema::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableAndSchema", L"~TableAndSchema");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->toStr, this);
	toStr = nullptr;
	if(!prepare){
		return;
	}
}
String* TableAndSchema::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void TableAndSchema::setTable(String* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, String);
}
String* TableAndSchema::getSchema(ThreadContext* ctx) throw() 
{
	return schema;
}
void TableAndSchema::setSchema(String* schema, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
}
TableAndSchema* TableAndSchema::copy(ThreadContext* ctx) throw() 
{
	TableAndSchema* newObj = (new(ctx) TableAndSchema(this->schema, this->table, ctx));
	return newObj;
}
int TableAndSchema::getArchiveSize(ThreadContext* ctx) throw() 
{
	int total = 4;
	if(this->table != nullptr)
	{
		total += this->table->length(ctx) * 2;
	}
	total += 4;
	if(this->schema != nullptr)
	{
		total += this->schema->length(ctx) * 2;
	}
	return total;
}
void TableAndSchema::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putString(this->table, ctx);
	builder->putString(this->schema, ctx);
}
bool TableAndSchema::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	TableAndSchema* other = dynamic_cast<TableAndSchema*>(obj);
	return this->schema->equals(other->schema, ctx) && this->table->equals(other->table, ctx);
}
String* TableAndSchema::toString(ThreadContext* ctx) throw() 
{
	if(this->toStr == nullptr)
	{
		StringBuffer* buff = (new(ctx) StringBuffer(ctx));
		buff->append(this->schema, ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(this->table, ctx);
		__GC_MV(this, &(this->toStr), buff->toString(ctx), String);
	}
	return this->toStr;
}
TableAndSchema* TableAndSchema::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	String* table = fetcher->fetchString(ctx);
	String* schema = fetcher->fetchString(ctx);
	return (new(ctx) TableAndSchema(schema, table, ctx));
}
}}}

