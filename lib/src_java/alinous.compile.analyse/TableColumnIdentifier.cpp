#include "include/global.h"


#include "alinous.compile.analyse/TableColumnIdentifier.h"

namespace alinous {namespace compile {namespace analyse {





bool TableColumnIdentifier::__init_done = __init_static_variables();
bool TableColumnIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableColumnIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableColumnIdentifier::TableColumnIdentifier(ThreadContext* ctx) throw()  : IObject(ctx), schema(nullptr), table(nullptr), column(nullptr)
{
}
void TableColumnIdentifier::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableColumnIdentifier::~TableColumnIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableColumnIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableColumnIdentifier", L"~TableColumnIdentifier");
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->column, this);
	column = nullptr;
	if(!prepare){
		return;
	}
}
String* TableColumnIdentifier::getSchema(ThreadContext* ctx) throw() 
{
	return schema;
}
void TableColumnIdentifier::setSchema(String* schema, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
}
String* TableColumnIdentifier::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void TableColumnIdentifier::setTable(String* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, String);
}
String* TableColumnIdentifier::getColumn(ThreadContext* ctx) throw() 
{
	return column;
}
void TableColumnIdentifier::setColumn(String* column, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->column), column, String);
}
void TableColumnIdentifier::__cleanUp(ThreadContext* ctx){
}
}}}

