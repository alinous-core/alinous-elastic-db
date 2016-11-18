#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace analyze {





bool SQLAnalyseContext::__init_done = __init_static_variables();
bool SQLAnalyseContext::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLAnalyseContext", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLAnalyseContext::SQLAnalyseContext(AlinousDatabase* database, ScriptMachine* machine, ThreadContext* ctx) throw()  : IObject(ctx), database(nullptr), machine(nullptr), tables(GCUtils<ArrayList<ScanTableMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), asNameMap(GCUtils<HashMap<String,ScanTableMetadata> >::ins(this, (new(ctx) HashMap<String,ScanTableMetadata>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
}
void SQLAnalyseContext::__construct_impl(AlinousDatabase* database, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
}
 SQLAnalyseContext::~SQLAnalyseContext() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLAnalyseContext::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLAnalyseContext", L"~SQLAnalyseContext");
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->machine, this);
	machine = nullptr;
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->asNameMap, this);
	asNameMap = nullptr;
	if(!prepare){
		return;
	}
}
void SQLAnalyseContext::addTable(ScanTableMetadata* table, String* asName, ThreadContext* ctx) throw() 
{
	this->tables->add(table, ctx);
	if(asName != nullptr)
	{
		this->asNameMap->put(asName, table, ctx);
	}
}
ArrayList<ScanTableMetadata>* SQLAnalyseContext::getTables(ThreadContext* ctx) throw() 
{
	return tables;
}
AlinousDatabase* SQLAnalyseContext::getDatabase(ThreadContext* ctx) throw() 
{
	return database;
}
ScanTableMetadata* SQLAnalyseContext::findTableByAsName(String* asname, ThreadContext* ctx) throw() 
{
	return this->asNameMap->get(asname, ctx);
}
ScriptMachine* SQLAnalyseContext::getMachine(ThreadContext* ctx) throw() 
{
	return machine;
}
ArrayList<ScanTableColumnIdentifier>* SQLAnalyseContext::joinList(ArrayList<ScanTableColumnIdentifier>* list, ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	if(exp == nullptr)
	{
		return list;
	}
	ArrayList<ScanTableColumnIdentifier>* sublist = exp->getColumns(ctx);
	if(sublist != nullptr)
	{
		list->addAll(sublist, ctx);
	}
	return list;
}
String* SQLAnalyseContext::findTable(SQLAnalyseContext* context, String* schema, String* column, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableMetadata>* tables = context->getTables(ctx);
	AlinousDatabase* db = context->getDatabase(ctx);
	int maxLoop = tables->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableMetadata* tbl = tables->get(i, ctx);
		if(!tbl->getSchemaName(ctx)->equals(schema, ctx))
		{
			continue;
		}
		IDatabaseTable* tableStore = db->getTable(schema, tbl->getTableName(ctx), ctx);
		if(tableStore != nullptr)
		{
			return tbl->getTableName(ctx);
		}
	}
	return nullptr;
}
}}}}

