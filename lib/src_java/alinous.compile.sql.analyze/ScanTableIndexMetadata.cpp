#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanTableIndexMetadata::__init_done = __init_static_variables();
bool ScanTableIndexMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanTableIndexMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanTableIndexMetadata::ScanTableIndexMetadata(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw()  : IObject(ctx), tableId(nullptr), columns(nullptr)
{
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	GCUtils<ArrayList<ScanTableColumnMetadata> >::mv(this, &(this->columns), columns, ctx);
}
void ScanTableIndexMetadata::__construct_impl(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	GCUtils<ArrayList<ScanTableColumnMetadata> >::mv(this, &(this->columns), columns, ctx);
}
 ScanTableIndexMetadata::~ScanTableIndexMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanTableIndexMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanTableIndexMetadata", L"~ScanTableIndexMetadata");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	if(!prepare){
		return;
	}
}
String* ScanTableIndexMetadata::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->tableId->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1000(), ctx);
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* col = this->columns->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(col->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_564(), ctx);
	return buff->toString(ctx);
}
void ScanTableIndexMetadata::setColumns(ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ScanTableColumnMetadata> >::mv(this, &(this->columns), columns, ctx);
}
ArrayList<ScanTableColumnMetadata>* ScanTableIndexMetadata::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
ArrayList<String>* ScanTableIndexMetadata::getColumnsStr(ThreadContext* ctx) throw() 
{
	ArrayList<String>* list = (new(ctx) ArrayList<String>(ctx));
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* meta = this->columns->get(i, ctx);
		list->add(meta->getName(ctx), ctx);
	}
	return list;
}
ArrayList<ScanTableColumnIdentifier>* ScanTableIndexMetadata::getColumnIds(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* meta = this->columns->get(i, ctx);
		list->add(meta->getColumnIdentifier(ctx), ctx);
	}
	return list;
}
bool ScanTableIndexMetadata::hasColumnsWithoutOrder(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* colId = columns->get(i, ctx);
		if(!hasColumn(colId, ctx))
		{
			return false;
		}
	}
	return true;
}
bool ScanTableIndexMetadata::hasColumn(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* colmeta = this->columns->get(i, ctx);
		if(colmeta->matchIdentigier(colId, ctx))
		{
			return true;
		}
	}
	return false;
}
ScanTableIndexMetadata* ScanTableIndexMetadata::copy(ThreadContext* ctx) throw() 
{
	ScanTableIndexMetadata* newObj = (new(ctx) ScanTableIndexMetadata(this->tableId, this->columns, ctx));
	return newObj;
}
ScanTableIdentifier* ScanTableIndexMetadata::getTableId(ThreadContext* ctx) throw() 
{
	return tableId;
}
}}}}

