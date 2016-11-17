#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace result {





bool ColumnResult::__init_done = __init_static_variables();
bool ColumnResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ColumnResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ColumnResult::ColumnResult(int colOrder, ISQLExpression* sqlexp, ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw()  : IObject(ctx), AbstructSelectResult(ctx), colId(nullptr), colOrder(0)
{
	this->colOrder = colOrder;
	__GC_MV(this, &(this->colId), colId, ScanTableColumnIdentifier);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), colId->getColumn(ctx), String);
	}
}
void ColumnResult::__construct_impl(int colOrder, ISQLExpression* sqlexp, ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	this->colOrder = colOrder;
	__GC_MV(this, &(this->colId), colId, ScanTableColumnIdentifier);
	String* asName = sqlexp->getAsName(ctx);
	if(asName != nullptr)
	{
		__GC_MV(this, &(this->outputName), asName, String);
	}
		else 
	{
		__GC_MV(this, &(this->outputName), colId->getColumn(ctx), String);
	}
}
 ColumnResult::~ColumnResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ColumnResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ColumnResult", L"~ColumnResult");
	__e_obj1.add(this->colId, this);
	colId = nullptr;
	if(!prepare){
		return;
	}
	AbstructSelectResult::__releaseRegerences(true, ctx);
}
void ColumnResult::fetchFromRecord(DomVariable* domVariable, ScanResultRecord* srecord, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw() 
{
	VariantValue* value = srecord->get(this->colOrder, ctx);
	domVariable->setProperty(this->outputName, (new(ctx) DomVariable(value, ctx)), ctx);
}
int ColumnResult::getType(ThreadContext* ctx) throw() 
{
	return AbstructSelectResult::COLUMN;
}
}}}}

