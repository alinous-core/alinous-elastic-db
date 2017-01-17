#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLNotExpression::__init_done = __init_static_variables();
bool SQLNotExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLNotExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLNotExpression::~SQLNotExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLNotExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLNotExpression", L"~SQLNotExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLNotExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLNotExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLNotExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return this->first->analyse(context, leftValue, ctx);
}
ISQLExpression* SQLNotExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void SQLNotExpression::setFirst(ISQLExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, ISQLExpression);
}
IAlinousVariable* SQLNotExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* SQLNotExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLNotExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->first != nullptr)
	{
		this->first->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLNotExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		return this->first->hasTable(table, ctx);
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLNotExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->first != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->first, ctx);
	}
	return list;
}
bool SQLNotExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLNotExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLNotExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLNotExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLNotExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->first->getColumns(ctx);
	return cols;
}
IndexColumnMatchCondition* SQLNotExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ScanTableColumnIdentifier* SQLNotExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLNotExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	if(val->isTrue(ctx))
	{
		return (new(ctx) VariantValue(((char)0), ctx));
	}
	return (new(ctx) VariantValue(((char)1), ctx));
}
bool SQLNotExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLNotExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
int SQLNotExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLNotExpression;
}
void SQLNotExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLNotExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLNotExpression, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
}
int SQLNotExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	bool isnull = (this->first == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->first->fileSize(ctx);
	}
	return total;
}
void SQLNotExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLNotExpression, ctx);
	__toFileEntry(builder, ctx);
	bool isnull = (this->first == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->toFileEntry(builder, ctx);
	}
}
void SQLNotExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
}}}}}

