#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace analyze {





bool TableMetadataUniqueCollection::__init_done = __init_static_variables();
bool TableMetadataUniqueCollection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableMetadataUniqueCollection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableMetadataUniqueCollection::~TableMetadataUniqueCollection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableMetadataUniqueCollection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableMetadataUniqueCollection", L"~TableMetadataUniqueCollection");
	__e_obj1.add(this->uniqueList, this);
	uniqueList = nullptr;
	if(!prepare){
		return;
	}
}
void TableMetadataUniqueCollection::addUnique(ScanUnique* unique, ThreadContext* ctx) throw() 
{
	this->uniqueList->add(unique, ctx);
}
ArrayList<ScanUnique>* TableMetadataUniqueCollection::getUniqueList(ThreadContext* ctx) throw() 
{
	return uniqueList;
}
}}}}

