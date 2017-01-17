#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLColumnIdentifier::__init_done = __init_static_variables();
bool SQLColumnIdentifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLColumnIdentifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLColumnIdentifier::SQLColumnIdentifier(AlinousName* name, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLExpression(ctx), distinct(0), id(nullptr), asName(nullptr), resolvedName(nullptr), analysedColumn(nullptr), columnOrder(-1)
{
	__GC_MV(this, &(this->id), name, AlinousName);
}
void SQLColumnIdentifier::__construct_impl(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), name, AlinousName);
}
 SQLColumnIdentifier::~SQLColumnIdentifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLColumnIdentifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLColumnIdentifier", L"~SQLColumnIdentifier");
	__e_obj1.add(this->id, this);
	id = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	__e_obj1.add(this->resolvedName, this);
	resolvedName = nullptr;
	__e_obj1.add(this->analysedColumn, this);
	analysedColumn = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLExpression::__releaseRegerences(true, ctx);
}
bool SQLColumnIdentifier::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->id != nullptr && !this->id->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLColumnIdentifier::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLColumnIdentifier::isDistinct(ThreadContext* ctx) throw() 
{
	return distinct;
}
void SQLColumnIdentifier::setDistinct(bool distinct, ThreadContext* ctx) throw() 
{
	this->distinct = distinct;
}
AlinousName* SQLColumnIdentifier::getId(ThreadContext* ctx) throw() 
{
	return id;
}
void SQLColumnIdentifier::setId(AlinousName* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, AlinousName);
}
String* SQLColumnIdentifier::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void SQLColumnIdentifier::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
IAlinousVariable* SQLColumnIdentifier::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->resolvedName == nullptr)
	{
		__GC_MV(this, &(this->resolvedName), (new(ctx) VariantValue(this->id->toString(ctx), ctx)), VariantValue);
	}
	return this->resolvedName;
}
bool SQLColumnIdentifier::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
ExpressionSourceId* SQLColumnIdentifier::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(this->id->toString(ctx), this, nullptr, ctx));
}
bool SQLColumnIdentifier::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	ArrayList<String>* segments = this->id->getSegments(ctx);
	__GC_MV(this, &(this->analysedColumn), nullptr, ScanTableColumnIdentifier);
	if(analyzeAsName(context, segments, ctx))
	{
		return true;
	}
	int size = this->id->getSegments(ctx)->size(ctx);
	String* schema = nullptr;
	String* table = nullptr;
	String* column = nullptr;
	switch(size) {
	case 1:
		schema = ConstStr::getCNST_STR_955();
		column = segments->get(0, ctx);
		table = SQLAnalyseContext::findTable(context, schema, column, ctx);
		if(table == nullptr)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1042()->clone(ctx)->append(this->id->toString(ctx), ctx), ctx));
		}
		break ;
	case 2:
		schema = ConstStr::getCNST_STR_955();
		table = segments->get(0, ctx);
		column = segments->get(1, ctx);
		break ;
	case 3:
		schema = segments->get(0, ctx);
		table = segments->get(1, ctx);
		column = segments->get(2, ctx);
		break ;
	default:
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1042()->clone(ctx)->append(this->id->toString(ctx), ctx), ctx));
		break;
	}
	IDatabaseTable* dataStore = context->getDatabase(ctx)->getTable(schema, table, ctx);
	if(dataStore == nullptr)
	{
		throw (new(ctx) DatabaseException(schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1043(), ctx), ctx));
	}
	TableAndSchema* tableSc = (new(ctx) TableAndSchema(schema, table, ctx));
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(tableSc, this->asName, dataStore->getColumnCount(ctx), ctx));
	__GC_MV(this, &(this->analysedColumn), (new(ctx) ScanTableColumnIdentifier(tableId, column, ctx)), ScanTableColumnIdentifier);
	analyseColumnOrder(tableSc, context, ctx);
	return true;
}
bool SQLColumnIdentifier::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->analysedColumn->getTable(ctx)->equals(table, ctx);
}
ArrayList<ScanTableColumnIdentifier>* SQLColumnIdentifier::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list->add(this->analysedColumn, ctx);
	return list;
}
bool SQLColumnIdentifier::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLColumnIdentifier::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLColumnIdentifier::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLColumnIdentifier::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return true;
}
ScanTableColumnIdentifier* SQLColumnIdentifier::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return this->analysedColumn;
}
VariantValue* SQLColumnIdentifier::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->columnOrder >= 0)
	{
		ScanTableIdentifier* tableId = analysedColumn->getTable(ctx);
		return record->getValueOfTable(tableId, this->columnOrder, ctx);
	}
		else 
	{
	}
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool SQLColumnIdentifier::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLColumnIdentifier::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
bool SQLColumnIdentifier::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
int SQLColumnIdentifier::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLColumnIdentifier;
}
void SQLColumnIdentifier::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->distinct = buff->getBoolean(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->id), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void SQLColumnIdentifier::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLColumnIdentifier, ctx);
	buff->putBoolean(this->distinct, ctx);
	bool isnull = (this->id == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->id->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
int SQLColumnIdentifier::fileSize(ThreadContext* ctx) throw() 
{
	int total = 4;
	total += 1;
	bool isnull = (this->id == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->id->fileSize(ctx);
	}
	isnull = (this->asName == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->asName->length(ctx) * 2 + 4;
	}
	return total;
}
void SQLColumnIdentifier::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IExpressionFactory::__SQLColumnIdentifier, ctx);
	builder->putBoolean(this->distinct, ctx);
	bool isnull = (this->id == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->id->toFileEntry(builder, ctx);
	}
	isnull = (this->asName == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->asName, ctx);
	}
}
void SQLColumnIdentifier::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	this->distinct = fetcher->fetchBoolean(ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		AlinousName* exp = AlinousName::fromFileEntry(fetcher, ctx);
		if(exp != nullptr)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->id), exp, AlinousName);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), fetcher->fetchString(ctx), String);
	}
}
void SQLColumnIdentifier::analyseColumnOrder(TableAndSchema* tableSc, SQLAnalyseContext* context, ThreadContext* ctx) throw() 
{
	int maxLoop = context->getTables(ctx)->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableMetadata* tableMetadata = context->getTables(ctx)->get(i, ctx);
		String* s = tableMetadata->getSchemaName(ctx);
		String* t = tableMetadata->getTableName(ctx);
		if(s->equals(tableSc->getSchema(ctx), ctx) && t->equals(tableSc->getTable(ctx), ctx))
		{
			this->columnOrder = tableMetadata->getColumnOrder(this->analysedColumn, ctx);
		}
	}
}
bool SQLColumnIdentifier::analyzeAsName(SQLAnalyseContext* context, ArrayList<String>* segments, ThreadContext* ctx) throw() 
{
	int size = segments->size(ctx);
	if(size != 2)
	{
		return false;
	}
	String* asname = segments->get(0, ctx);
	String* columnName = segments->get(1, ctx);
	ScanTableMetadata* meta = context->findTableByAsName(asname, ctx);
	if(meta == nullptr)
	{
		return false;
	}
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(nullptr, asname, meta->getColumns(ctx)->size(ctx), ctx));
	__GC_MV(this, &(this->analysedColumn), (new(ctx) ScanTableColumnIdentifier(tableId, columnName, ctx)), ScanTableColumnIdentifier);
	return true;
}
}}}}

