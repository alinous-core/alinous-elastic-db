#include "include/global.h"


#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.db.trx/CreateIndexMetadata.h"

namespace alinous {namespace db {namespace trx {





bool CreateIndexMetadata::__init_done = __init_static_variables();
bool CreateIndexMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CreateIndexMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CreateIndexMetadata::CreateIndexMetadata(String* indexName, TableAndSchema* tas, ArrayList<String>* columns, ThreadContext* ctx) throw()  : IObject(ctx), indexName(nullptr), tas(nullptr), columns(nullptr)
{
	__GC_MV(this, &(this->indexName), indexName, String);
	__GC_MV(this, &(this->tas), tas, TableAndSchema);
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
void CreateIndexMetadata::__construct_impl(String* indexName, TableAndSchema* tas, ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->indexName), indexName, String);
	__GC_MV(this, &(this->tas), tas, TableAndSchema);
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
 CreateIndexMetadata::~CreateIndexMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CreateIndexMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CreateIndexMetadata", L"~CreateIndexMetadata");
	__e_obj1.add(this->indexName, this);
	indexName = nullptr;
	__e_obj1.add(this->tas, this);
	tas = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	if(!prepare){
		return;
	}
}
String* CreateIndexMetadata::getindexName(ThreadContext* ctx) throw() 
{
	return indexName;
}
TableAndSchema* CreateIndexMetadata::getTas(ThreadContext* ctx) throw() 
{
	return tas;
}
ArrayList<String>* CreateIndexMetadata::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void CreateIndexMetadata::__cleanUp(ThreadContext* ctx){
}
}}}

