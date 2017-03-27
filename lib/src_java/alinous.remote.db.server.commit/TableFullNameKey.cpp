#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.remote.db.server.commit/TableFullNameKey.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {





bool TableFullNameKey::__init_done = __init_static_variables();
bool TableFullNameKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableFullNameKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableFullNameKey::TableFullNameKey(String* schema, String* table, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), schema(nullptr), table(nullptr)
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->table), table, String);
}
void TableFullNameKey::__construct_impl(String* schema, String* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->table), table, String);
}
 TableFullNameKey::~TableFullNameKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableFullNameKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableFullNameKey", L"~TableFullNameKey");
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	if(!prepare){
		return;
	}
}
int TableFullNameKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	TableFullNameKey* anotherKey = static_cast<TableFullNameKey*>(another);
	int result = this->schema->compareTo(anotherKey->schema, ctx);
	if(result != 0)
	{
		return result;
	}
	result = this->table->compareTo(anotherKey->table, ctx);
	return result;
}
void TableFullNameKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IBTreeKey::TYPE_TABLE_FULL_NAME_KEY, ctx);
	builder->putString(this->schema, ctx);
	builder->putString(this->table, ctx);
}
int TableFullNameKey::size(ThreadContext* ctx)
{
	int total = 4;
	total += (this->schema->length(ctx) * 2) + 4;
	total += (this->table->length(ctx) * 2) + 4;
	return total;
}
String* TableFullNameKey::getSchema(ThreadContext* ctx) throw() 
{
	return schema;
}
String* TableFullNameKey::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
IBTreeKey* TableFullNameKey::fetchFromEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	String* schema = fetcher->fetchString(ctx);
	String* table = fetcher->fetchString(ctx);
	return (new(ctx) TableFullNameKey(schema, table, ctx));
}
void TableFullNameKey::__cleanUp(ThreadContext* ctx){
}
int TableFullNameKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}}}}

