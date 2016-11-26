#include "includes.h"


namespace alinous {namespace db {





bool TableSchemaCollection::__init_done = __init_static_variables();
bool TableSchemaCollection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableSchemaCollection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableSchemaCollection::~TableSchemaCollection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableSchemaCollection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableSchemaCollection", L"~TableSchemaCollection");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void TableSchemaCollection::addScheme(TableSchema* sc, ThreadContext* ctx) throw() 
{
	this->list->add(sc, ctx);
}
IDatabaseTable* TableSchemaCollection::getTableStore(String* tableName, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableSchema* sc = this->list->get(i, ctx);
		IDatabaseTable* tbl = sc->getTableStore(tableName, ctx);
		if(tbl != nullptr)
		{
			return tbl;
		}
	}
	return nullptr;
}
TableMetadata* TableSchemaCollection::getDableMetadata(String* tableName, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableSchema* sc = this->list->get(i, ctx);
		IDatabaseTable* tbl = sc->getTableStore(tableName, ctx);
		if(tbl != nullptr)
		{
			return tbl->getMetadata(ctx);
		}
	}
	return nullptr;
}
}}

