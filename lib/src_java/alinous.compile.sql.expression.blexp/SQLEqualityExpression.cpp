#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLEqualityExpression::__init_done = __init_static_variables();
bool SQLEqualityExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLEqualityExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLEqualityExpression::~SQLEqualityExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLEqualityExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLEqualityExpression", L"~SQLEqualityExpression");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLEqualityExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->left != nullptr && !this->left->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLEqualityExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && !this->left->isConstant(ctx))
	{
		return false;
	}
	if(this->right != nullptr && !this->right->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLEqualityExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr)
	{
		this->left->analyse(context, leftValue, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLEqualityExpression::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void SQLEqualityExpression::setLeft(ISQLExpression* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, ISQLExpression);
}
ISQLExpression* SQLEqualityExpression::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void SQLEqualityExpression::setRight(ISQLExpression* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, ISQLExpression);
}
ExpressionSourceId* SQLEqualityExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLEqualityExpression::isCheckEquals(ThreadContext* ctx) throw() 
{
	return checkEquals;
}
void SQLEqualityExpression::setCheckEquals(bool checkEquals, ThreadContext* ctx) throw() 
{
	this->checkEquals = checkEquals;
}
void SQLEqualityExpression::setCheckEquals(String* strEq, ThreadContext* ctx) throw() 
{
	if(strEq->equals(ConstStr::getCNST_STR_1074(), ctx))
	{
		this->checkEquals = true;
	}
		else 
	{
		this->checkEquals = false;
	}
}
VariantValue* SQLEqualityExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->left->resolveSQLExpression(record, machine, debug, ctx);
	if(this->right == nullptr)
	{
		return val;
	}
	VariantValue* rightVal = this->right->resolveSQLExpression(record, machine, debug, ctx);
	if((this->checkEquals && val->compareTo(rightVal, ctx) == 0) || (!this->checkEquals && val->compareTo(rightVal, ctx) != 0))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
IAlinousVariable* SQLEqualityExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->left->resolveExpression(machine, debug, ctx);
	if(this->right == nullptr)
	{
		return val;
	}
	IAlinousVariable* rightVal = this->right->resolveExpression(machine, debug, ctx);
	if((this->checkEquals && val->compareTo(rightVal, ctx) == 0) || (!this->checkEquals && val->compareTo(rightVal, ctx) != 0))
	{
		return (new(ctx) VariantValue(((char)1), ctx));
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
bool SQLEqualityExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->left != nullptr)
	{
		this->left->analyseSQL(context, leftValue, debug, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLEqualityExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && this->left->hasTable(table, ctx))
	{
		return true;
	}
	if(this->right != nullptr && this->right->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLEqualityExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->left != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->left, ctx);
	}
	if(this->right != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->right, ctx);
	}
	return list;
}
bool SQLEqualityExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLEqualityExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLEqualityExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return this->checkEquals && this->left->isColumnIdentifier(ctx) && this->right->isColumnIdentifier(ctx);
}
void SQLEqualityExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
ArrayList<ScanTableColumnIdentifier>* SQLEqualityExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->left->getColumns(ctx);
	return cols;
}
IndexColumnMatchCondition* SQLEqualityExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	if(isJoinCondition(ctx))
	{
		return nullptr;
	}
	if(this->left->isColumnIdentifier(ctx))
	{
		IndexColumnMatchCondition* part = (new(ctx) IndexColumnMatchCondition(this->left->toColumnIdentifier(ctx), IndexColumnMatchCondition::INDEX_EQUALS, this->right, this->right, ctx));
		return part;
	}
		else 
	{
		if(this->right->isColumnIdentifier(ctx))
		{
			IndexColumnMatchCondition* part = (new(ctx) IndexColumnMatchCondition(this->right->toColumnIdentifier(ctx), IndexColumnMatchCondition::INDEX_EQUALS, this->left, this->left, ctx));
			return part;
		}
	}
	return nullptr;
}
ScanTableColumnIdentifier* SQLEqualityExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLEqualityExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLEqualityExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
int SQLEqualityExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLEqualityExpression;
}
void SQLEqualityExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
		__GC_MV(this, &(this->left), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	this->checkEquals = buff->getBoolean(ctx);
}
void SQLEqualityExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLEqualityExpression, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->left == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->writeData(buff, ctx);
	}
	isnull = (this->right == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->writeData(buff, ctx);
	}
	buff->putBoolean(this->checkEquals, ctx);
}
int SQLEqualityExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	bool isnull = (this->left == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->left->fileSize(ctx);
	}
	isnull = (this->right == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->right->fileSize(ctx);
	}
	total += 1;
	return total;
}
void SQLEqualityExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLEqualityExpression, ctx);
	__toFileEntry(builder, ctx);
	bool isnull = (this->left == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->left->toFileEntry(builder, ctx);
	}
	isnull = (this->right == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->right->toFileEntry(builder, ctx);
	}
	builder->putBoolean(this->checkEquals, ctx);
}
void SQLEqualityExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
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
		__GC_MV(this, &(this->left), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1044(), ctx));
		}
		__GC_MV(this, &(this->right), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	this->checkEquals = fetcher->fetchBoolean(ctx);
}
}}}}}

