#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanTableColumnMetadata::__init_done = __init_static_variables();
bool ScanTableColumnMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanTableColumnMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanTableColumnMetadata::ScanTableColumnMetadata(ScanTableIdentifier* table, String* name, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), name(nullptr), columnIdentifier(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->table), table, ScanTableIdentifier);
	__GC_MV(this, &(this->columnIdentifier), (new(ctx) ScanTableColumnIdentifier(this->table, this->name, ctx)), ScanTableColumnIdentifier);
}
void ScanTableColumnMetadata::__construct_impl(ScanTableIdentifier* table, String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->table), table, ScanTableIdentifier);
	__GC_MV(this, &(this->columnIdentifier), (new(ctx) ScanTableColumnIdentifier(this->table, this->name, ctx)), ScanTableColumnIdentifier);
}
 ScanTableColumnMetadata::~ScanTableColumnMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanTableColumnMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanTableColumnMetadata", L"~ScanTableColumnMetadata");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->columnIdentifier, this);
	columnIdentifier = nullptr;
	if(!prepare){
		return;
	}
}
String* ScanTableColumnMetadata::getName(ThreadContext* ctx) throw() 
{
	return name;
}
bool ScanTableColumnMetadata::matchIdentigier(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	ScanTableIdentifier* tableId = colId->getTable(ctx);
	if(tableId == nullptr)
	{
		return name->equals(colId->getColumn(ctx), ctx);
	}
	return this->table != nullptr && this->table->equals(tableId, ctx) && this->name->equals(colId->getColumn(ctx), ctx);
}
ScanTableColumnIdentifier* ScanTableColumnMetadata::getColumnIdentifier(ThreadContext* ctx) throw() 
{
	return columnIdentifier;
}
bool ScanTableColumnMetadata::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	ScanTableColumnMetadata* other = dynamic_cast<ScanTableColumnMetadata*>(obj);
	return this->table->equals(other->table, ctx) && this->name->equals(other->name, ctx);
}
String* ScanTableColumnMetadata::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->table->toString(ctx), ctx)->append(ConstStr::getCNST_STR_947(), ctx)->append(this->name, ctx);
	return buff->toString(ctx);
}
}}}}

