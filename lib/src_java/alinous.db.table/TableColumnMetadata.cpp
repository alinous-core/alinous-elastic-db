#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TableColumnMetadata::__init_done = __init_static_variables();
bool TableColumnMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableColumnMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableColumnMetadata::TableColumnMetadata(String* name, int type, int length, ThreadContext* ctx) throw()  : IObject(ctx), name(nullptr), notnull(0), unique(0), primaryKey(0), defaultValue(nullptr), columnOrder(0), type(0), length(0), check(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	this->type = type;
	this->length = length;
}
void TableColumnMetadata::__construct_impl(String* name, int type, int length, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	this->type = type;
	this->length = length;
}
 TableColumnMetadata::~TableColumnMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableColumnMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableColumnMetadata", L"~TableColumnMetadata");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->defaultValue, this);
	defaultValue = nullptr;
	__e_obj1.add(this->check, this);
	check = nullptr;
	if(!prepare){
		return;
	}
}
int TableColumnMetadata::fileSize(ThreadContext* ctx) throw() 
{
	int total = 4 + 4;
	total += name->length(ctx) * 2 + 4;
	total += 1 * 3;
	total += 4;
	return total;
}
void TableColumnMetadata::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(this->type, ctx);
	builder->putInt(this->length, ctx);
	builder->putString(this->name, ctx);
	char bl = ((char)(this->notnull ? 1 : 0));
	builder->putByte(bl, ctx);
	bl = ((char)(this->unique ? 1 : 0));
	builder->putByte(bl, ctx);
	bl = ((char)(this->primaryKey ? 1 : 0));
	builder->putByte(bl, ctx);
	builder->putInt(this->columnOrder, ctx);
}
CheckDefinition* TableColumnMetadata::getCheck(ThreadContext* ctx) throw() 
{
	return check;
}
void TableColumnMetadata::setCheck(CheckDefinition* check, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->check), check, CheckDefinition);
}
bool TableColumnMetadata::isPrimaryKey(ThreadContext* ctx) throw() 
{
	return primaryKey;
}
void TableColumnMetadata::setPrimaryKey(bool primaryKey, ThreadContext* ctx) throw() 
{
	this->primaryKey = primaryKey;
}
TableColumnMetadata* TableColumnMetadata::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	int type = fetcher->fetchInt(ctx);
	int length = fetcher->fetchInt(ctx);
	String* name = fetcher->fetchString(ctx);
	TableColumnMetadata* col = (new(ctx) TableColumnMetadata(name, type, length, ctx));
	char bl = fetcher->fetchByte(ctx);
	col->notnull = (bl > (char)0 ? true : false);
	bl = fetcher->fetchByte(ctx);
	col->unique = (bl > (char)0 ? true : false);
	bl = fetcher->fetchByte(ctx);
	col->setPrimaryKey(bl > (char)0 ? true : false, ctx);
	col->columnOrder = fetcher->fetchInt(ctx);
	return col;
}
}}}

