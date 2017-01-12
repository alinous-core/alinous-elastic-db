#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool UpdateSet::__init_done = __init_static_variables();
bool UpdateSet::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UpdateSet", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UpdateSet::~UpdateSet() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UpdateSet::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UpdateSet", L"~UpdateSet");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->value, this);
	value = nullptr;
	__e_obj1.add(this->analysedColumn, this);
	analysedColumn = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* UpdateSet::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* UpdateSet::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool UpdateSet::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->value != nullptr && !this->value->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool UpdateSet::isConstant(ThreadContext* ctx) throw() 
{
	if(this->value != nullptr && !this->value->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool UpdateSet::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->name != nullptr)
	{
		this->name->analyse(context, leftValue, ctx);
	}
	if(this->value != nullptr)
	{
		this->value->analyse(context, leftValue, ctx);
	}
	return true;
}
AlinousName* UpdateSet::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void UpdateSet::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
ISQLExpression* UpdateSet::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void UpdateSet::setValue(ISQLExpression* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, ISQLExpression);
}
bool UpdateSet::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	ArrayList<String>* segments = this->name->getSegments(ctx);
	__GC_MV(this, &(this->analysedColumn), nullptr, ScanTableColumnIdentifier);
	int size = this->name->getSegments(ctx)->size(ctx);
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
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1042()->clone(ctx)->append(this->name->toString(ctx), ctx), ctx));
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
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1042()->clone(ctx)->append(this->name->toString(ctx), ctx), ctx));
		break;
	}
	IDatabaseTable* dataStore = context->getDatabase(ctx)->getTable(schema, table, ctx);
	if(dataStore == nullptr)
	{
		throw (new(ctx) DatabaseException(schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1043(), ctx), ctx));
	}
	TableAndSchema* tableSc = (new(ctx) TableAndSchema(schema, table, ctx));
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(tableSc, nullptr, dataStore->getColumnCount(ctx), ctx));
	__GC_MV(this, &(this->analysedColumn), (new(ctx) ScanTableColumnIdentifier(tableId, column, ctx)), ScanTableColumnIdentifier);
	if(this->value != nullptr)
	{
		this->value->analyseSQL(context, leftValue, debug, ctx);
	}
	analyseColumnOrder(tableSc, context, ctx);
	return true;
}
bool UpdateSet::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->analysedColumn->getTable(ctx)->equals(table, ctx);
}
ArrayList<ScanTableColumnIdentifier>* UpdateSet::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list->add(this->analysedColumn, ctx);
	return list;
}
bool UpdateSet::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool UpdateSet::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void UpdateSet::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool UpdateSet::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* UpdateSet::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* UpdateSet::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
int UpdateSet::getColumnOrder(ThreadContext* ctx) throw() 
{
	return columnOrder;
}
int UpdateSet::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int UpdateSet::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int UpdateSet::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int UpdateSet::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* UpdateSet::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void UpdateSet::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool UpdateSet::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* UpdateSet::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
bool UpdateSet::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* UpdateSet::getAsName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void UpdateSet::setAsName(String* name, ThreadContext* ctx) throw() 
{
}
int UpdateSet::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::updateSet;
}
void UpdateSet::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->name), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->value), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void UpdateSet::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__UpdateSet, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->value == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->value->writeData(buff, ctx);
	}
}
void UpdateSet::analyseColumnOrder(TableAndSchema* tableSc, SQLAnalyseContext* context, ThreadContext* ctx) throw() 
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
}}}

