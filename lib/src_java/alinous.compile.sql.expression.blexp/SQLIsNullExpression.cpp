#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLIsNullExpression::__init_done = __init_static_variables();
bool SQLIsNullExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLIsNullExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLIsNullExpression::~SQLIsNullExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLIsNullExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLIsNullExpression", L"~SQLIsNullExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLIsNullExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(!this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLIsNullExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(!this->first->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLIsNullExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	this->first->analyse(context, leftValue, ctx);
	return true;
}
ISQLExpression* SQLIsNullExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void SQLIsNullExpression::setFirst(ISQLExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, ISQLExpression);
}
bool SQLIsNullExpression::isNotNull(ThreadContext* ctx) throw() 
{
	return notNull;
}
void SQLIsNullExpression::setNotNull(bool notNull, ThreadContext* ctx) throw() 
{
	this->notNull = notNull;
}
IAlinousVariable* SQLIsNullExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->first->resolveExpression(machine, debug, ctx);
	if((this->notNull && !val->isNull(ctx)) || (!this->notNull && val->isNull(ctx)))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
VariantValue* SQLIsNullExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	if((this->notNull && !val->isNull(ctx)) || (!this->notNull && val->isNull(ctx)))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
ExpressionSourceId* SQLIsNullExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLIsNullExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->first != nullptr)
	{
		this->first->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLIsNullExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		return this->first->hasTable(table, ctx);
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLIsNullExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->first != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->first, ctx);
	}
	return list;
}
bool SQLIsNullExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLIsNullExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLIsNullExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLIsNullExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLIsNullExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->first->getColumns(ctx);
	return cols;
}
IndexColumnMatchCondition* SQLIsNullExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	if(isJoinCondition(ctx) || this->notNull)
	{
		return nullptr;
	}
	if(this->first->isColumnIdentifier(ctx))
	{
		SQLLiteral* nullLit = (new(ctx) SQLLiteral(SQLLiteral::sqlliteralType::NULL_LITERAL, ctx));
		IndexColumnMatchCondition* part = (new(ctx) IndexColumnMatchCondition(this->first->toColumnIdentifier(ctx), IndexColumnMatchCondition::INDEX_EQUALS, nullLit, nullLit, ctx));
		return part;
	}
	return nullptr;
}
ScanTableColumnIdentifier* SQLIsNullExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLIsNullExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLIsNullExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
int SQLIsNullExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLIsNullExpression;
}
void SQLIsNullExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	this->notNull = buff->getBoolean(ctx);
}
void SQLIsNullExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLIsNullExpression, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	buff->putBoolean(this->notNull, ctx);
}
int SQLIsNullExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	bool isnull = (this->first == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->first->fileSize(ctx);
	}
	total += 1;
	return total;
}
void SQLIsNullExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLIsNullExpression, ctx);
	__toFileEntry(builder, ctx);
	bool isnull = (this->first == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->toFileEntry(builder, ctx);
	}
	builder->putBoolean(this->notNull, ctx);
}
void SQLIsNullExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	this->notNull = fetcher->fetchBoolean(ctx);
}
}}}}}

