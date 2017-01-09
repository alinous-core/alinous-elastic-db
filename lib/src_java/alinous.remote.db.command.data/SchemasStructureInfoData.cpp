#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {namespace data {





bool SchemasStructureInfoData::__init_done = __init_static_variables();
bool SchemasStructureInfoData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SchemasStructureInfoData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SchemasStructureInfoData::~SchemasStructureInfoData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SchemasStructureInfoData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SchemasStructureInfoData", L"~SchemasStructureInfoData");
	__e_obj1.add(this->schemas, this);
	schemas = nullptr;
	if(!prepare){
		return;
	}
}
void SchemasStructureInfoData::addScheme(SchemaData* value, ThreadContext* ctx) throw() 
{
	this->schemas->put(value->getName(ctx), value, ctx);
}
}}}}}

