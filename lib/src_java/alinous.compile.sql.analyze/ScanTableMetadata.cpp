#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanTableMetadata::__init_done = __init_static_variables();
bool ScanTableMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanTableMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanTableMetadata::ScanTableMetadata(ThreadContext* ctx) throw()  : IObject(ctx), table(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), columns(GCUtils<ArrayList<ScanTableColumnMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), indexes(GCUtils<ArrayList<ScanTableIndexMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableIndexMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), dom(0)
{
}
void ScanTableMetadata::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanTableMetadata::ScanTableMetadata(ScanTableIdentifier* table, ThreadContext* ctx) throw()  : IObject(ctx), table(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), columns(GCUtils<ArrayList<ScanTableColumnMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), indexes(GCUtils<ArrayList<ScanTableIndexMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableIndexMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), dom(0)
{
	this->table->add(table, ctx);
	this->dom = false;
}
void ScanTableMetadata::__construct_impl(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	this->table->add(table, ctx);
	this->dom = false;
}
 ScanTableMetadata::ScanTableMetadata(TableMetadata* metadata, String* asName, ThreadContext* ctx) throw()  : IObject(ctx), table(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), columns(GCUtils<ArrayList<ScanTableColumnMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), indexes(GCUtils<ArrayList<ScanTableIndexMetadata> >::ins(this, (new(ctx) ArrayList<ScanTableIndexMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), dom(0)
{
	this->dom = false;
	TableAndSchema* tableAndSchema = (new(ctx) TableAndSchema(metadata->getSchema(ctx), metadata->getTableName(ctx), ctx));
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(tableAndSchema, asName, metadata->getColumnCount(ctx), ctx));
	this->table->add(tableId, ctx);
	ArrayList<TableColumnMetadata>* list = metadata->getColumnsList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* colMeta = list->get(i, ctx);
		ScanTableColumnMetadata* col = (new(ctx) ScanTableColumnMetadata(tableId, colMeta->name, ctx));
		addColumn(col, ctx);
	}
	ArrayList<ScanTableColumnIdentifier>* indexList = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list = metadata->getPrimaryKeys(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* colMeta = list->get(i, ctx);
		ScanTableColumnIdentifier* colId = (new(ctx) ScanTableColumnIdentifier(tableId, colMeta->name, ctx));
		indexList->add(colId, ctx);
	}
	addindex(tableId, indexList, ctx);
	ArrayList<TableIndexMetadata>* indexes = metadata->getIndexes(ctx);
	maxLoop = indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* indexMeta = indexes->get(i, ctx);
		ArrayList<ScanTableColumnIdentifier>* colList = getColumnIdsFromIndex(tableId, indexMeta, ctx);
		addindex(tableId, colList, ctx);
	}
}
void ScanTableMetadata::__construct_impl(TableMetadata* metadata, String* asName, ThreadContext* ctx) throw() 
{
	this->dom = false;
	TableAndSchema* tableAndSchema = (new(ctx) TableAndSchema(metadata->getSchema(ctx), metadata->getTableName(ctx), ctx));
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(tableAndSchema, asName, metadata->getColumnCount(ctx), ctx));
	this->table->add(tableId, ctx);
	ArrayList<TableColumnMetadata>* list = metadata->getColumnsList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* colMeta = list->get(i, ctx);
		ScanTableColumnMetadata* col = (new(ctx) ScanTableColumnMetadata(tableId, colMeta->name, ctx));
		addColumn(col, ctx);
	}
	ArrayList<ScanTableColumnIdentifier>* indexList = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list = metadata->getPrimaryKeys(ctx);
	maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* colMeta = list->get(i, ctx);
		ScanTableColumnIdentifier* colId = (new(ctx) ScanTableColumnIdentifier(tableId, colMeta->name, ctx));
		indexList->add(colId, ctx);
	}
	addindex(tableId, indexList, ctx);
	ArrayList<TableIndexMetadata>* indexes = metadata->getIndexes(ctx);
	maxLoop = indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* indexMeta = indexes->get(i, ctx);
		ArrayList<ScanTableColumnIdentifier>* colList = getColumnIdsFromIndex(tableId, indexMeta, ctx);
		addindex(tableId, colList, ctx);
	}
}
 ScanTableMetadata::~ScanTableMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanTableMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanTableMetadata", L"~ScanTableMetadata");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->indexes, this);
	indexes = nullptr;
	if(!prepare){
		return;
	}
}
ScanTableMetadata* ScanTableMetadata::copy(ThreadContext* ctx) throw() 
{
	ScanTableMetadata* meta = (new(ctx) ScanTableMetadata(ctx));
	int maxLoop = this->table->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tbl = this->table->get(i, ctx);
		meta->table->add(tbl, ctx);
	}
	maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* col = this->columns->get(i, ctx);
		meta->columns->add(col, ctx);
	}
	maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIndexMetadata* idx = this->indexes->get(i, ctx);
		meta->indexes->add(idx, ctx);
	}
	meta->dom = this->dom;
	return meta;
}
bool ScanTableMetadata::hasTableColumn(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	int maxLoop = this->table->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = this->table->get(i, ctx);
		if(!exp->hasTable(tableId, ctx))
		{
			return false;
		}
	}
	return false;
}
ScanTableIdentifier* ScanTableMetadata::getRelevantTableId(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	int maxLoop = this->table->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = this->table->get(i, ctx);
		if(exp->hasTable(tableId, ctx))
		{
		}
	}
	return nullptr;
}
int ScanTableMetadata::getColumnOrder(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* col = this->columns->get(i, ctx);
		if(col->matchIdentigier(colId, ctx))
		{
			return i;
		}
	}
	return -1;
}
ArrayList<ScanTableIndexMetadata>* ScanTableMetadata::getAbailableIndexes(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	if(columns == nullptr)
	{
		return nullptr;
	}
	ArrayList<ScanTableIndexMetadata>* list = (new(ctx) ArrayList<ScanTableIndexMetadata>(ctx));
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIndexMetadata* index = this->indexes->get(i, ctx);
		if(!tableId->equals(index->getTableId(ctx), ctx))
		{
			continue;
		}
		if(index->hasColumnsWithoutOrder(columns, ctx))
		{
			list->add(index, ctx);
		}
	}
	return list;
}
void ScanTableMetadata::join(ScanTableMetadata* meta, ThreadContext* ctx) throw() 
{
	this->table->addAll(meta->table, ctx);
	int maxLoop = meta->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* col = meta->columns->get(i, ctx);
		addColumn(col, ctx);
	}
	this->indexes->addAll(meta->indexes, ctx);
}
bool ScanTableMetadata::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	int maxLoop = this->table->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = this->table->get(i, ctx);
		if(table->equals(tableId, ctx))
		{
			return true;
		}
	}
	return false;
}
bool ScanTableMetadata::hasTable(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	int maxLoop = this->table->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableIdentifier* tableId = this->table->get(i, ctx);
		if(exp->hasTable(tableId, ctx))
		{
			return true;
		}
	}
	return false;
}
void ScanTableMetadata::addColumn(ScanTableColumnMetadata* col, ThreadContext* ctx) throw() 
{
	this->columns->add(col, ctx);
}
void ScanTableMetadata::addindex(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnMetadata>* list = (new(ctx) ArrayList<ScanTableColumnMetadata>(ctx));
	int maxLoop = columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* colId = columns->get(i, ctx);
		ScanTableColumnMetadata* cl = getColumn(colId, ctx);
		list->add(cl, ctx);
	}
	ScanTableIndexMetadata* index = (new(ctx) ScanTableIndexMetadata(tableId, list, ctx));
	this->indexes->add(index, ctx);
}
ArrayList<ScanTableColumnMetadata>* ScanTableMetadata::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
ScanTableColumnMetadata* ScanTableMetadata::getColumn(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* colMeta = this->columns->get(i, ctx);
		ScanTableColumnIdentifier* id = colMeta->getColumnIdentifier(ctx);
		if(id->equals(colId, ctx))
		{
			return colMeta;
		}
	}
	return nullptr;
}
ScanTableIdentifier* ScanTableMetadata::getFirstTableId(ThreadContext* ctx) throw() 
{
	return this->table->get(0, ctx);
}
String* ScanTableMetadata::getSchemaName(ThreadContext* ctx) throw() 
{
	return this->table->get(0, ctx)->getTable(ctx)->getSchema(ctx);
}
String* ScanTableMetadata::getTableName(ThreadContext* ctx) throw() 
{
	return this->table->get(0, ctx)->getTable(ctx)->getTable(ctx);
}
bool ScanTableMetadata::isDom(ThreadContext* ctx) throw() 
{
	return dom;
}
void ScanTableMetadata::setDom(bool dom, ThreadContext* ctx) throw() 
{
	this->dom = dom;
}
ArrayList<ScanTableColumnIdentifier>* ScanTableMetadata::getColumnIdsFromIndex(ScanTableIdentifier* tableId, TableIndexMetadata* indexMeta, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	ArrayList<String>* clsStrs = indexMeta->getColumns(ctx);
	int maxLoop = clsStrs->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* strCol = clsStrs->get(i, ctx);
		ScanTableColumnIdentifier* colId = (new(ctx) ScanTableColumnIdentifier(tableId, strCol, ctx));
		list->add(colId, ctx);
	}
	return list;
}
void ScanTableMetadata::__cleanUp(ThreadContext* ctx){
}
}}}}

