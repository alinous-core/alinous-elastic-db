#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace result {





bool AllColumnResult::__init_done = __init_static_variables();
bool AllColumnResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AllColumnResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AllColumnResult::AllColumnResult(ScanTableMetadata* metadata, ThreadContext* ctx) throw()  : IObject(ctx), AbstructSelectResult(ctx), metadata(nullptr)
{
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
}
void AllColumnResult::__construct_impl(ScanTableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
}
 AllColumnResult::~AllColumnResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AllColumnResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AllColumnResult", L"~AllColumnResult");
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
	AbstructSelectResult::__releaseRegerences(true, ctx);
}
void AllColumnResult::fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	int numColmns = srecord->numColumns(ctx);
	ArrayList<ScanTableColumnMetadata>* cols = this->metadata->getColumns(ctx);
	for(int i = 0; i != numColmns; ++i)
	{
		VariantValue* vv = srecord->get(i, ctx);
		String* name = cols->get(i, ctx)->getName(ctx);
		domVariable->setProperty(name, (new(ctx) DomVariable(vv, ctx)), ctx);
	}
}
int AllColumnResult::getType(ThreadContext* ctx) throw() 
{
	return AbstructSelectResult::ALL_COLUMNS;
}
}}}}

