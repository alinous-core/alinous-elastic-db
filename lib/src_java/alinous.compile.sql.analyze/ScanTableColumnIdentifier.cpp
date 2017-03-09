#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanTableColumnIdentifier::__init_done = __init_static_variables();
bool ScanTableColumnIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanTableColumnIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanTableColumnIdentifier::ScanTableColumnIdentifier(ScanTableIdentifier* table, String* column, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), column(nullptr)
{
	__GC_MV(this, &(this->table), table, ScanTableIdentifier);
	__GC_MV(this, &(this->column), column, String);
}
void ScanTableColumnIdentifier::__construct_impl(ScanTableIdentifier* table, String* column, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, ScanTableIdentifier);
	__GC_MV(this, &(this->column), column, String);
}
 ScanTableColumnIdentifier::~ScanTableColumnIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanTableColumnIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanTableColumnIdentifier", L"~ScanTableColumnIdentifier");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->column, this);
	column = nullptr;
	if(!prepare){
		return;
	}
}
ScanTableIdentifier* ScanTableColumnIdentifier::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void ScanTableColumnIdentifier::setTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, ScanTableIdentifier);
}
String* ScanTableColumnIdentifier::getColumn(ThreadContext* ctx) throw() 
{
	return column;
}
void ScanTableColumnIdentifier::setColumn(String* column, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->column), column, String);
}
bool ScanTableColumnIdentifier::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	ScanTableColumnIdentifier* otherColId = dynamic_cast<ScanTableColumnIdentifier*>(obj);
	return this->table->equals(otherColId->table, ctx) && this->column->equals(otherColId->column, ctx);
}
String* ScanTableColumnIdentifier::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->table->toString(ctx), ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(this->column, ctx);
	return buff->toString(ctx);
}
void ScanTableColumnIdentifier::__cleanUp(ThreadContext* ctx){
}
}}}}

