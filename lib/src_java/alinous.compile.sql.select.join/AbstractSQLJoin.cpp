#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool AbstractSQLJoin::__init_done = __init_static_variables();
bool AbstractSQLJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractSQLJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractSQLJoin::~AbstractSQLJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractSQLJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractSQLJoin", L"~AbstractSQLJoin");
	__e_obj1.add(this->left, this);
	left = nullptr;
	__e_obj1.add(this->right, this);
	right = nullptr;
	__e_obj1.add(this->condition, this);
	condition = nullptr;
	__e_obj1.add(this->joinStrategy, this);
	joinStrategy = nullptr;
	__e_obj1.add(this->bestParts, this);
	bestParts = nullptr;
	__e_obj1.add(this->scanMetadata, this);
	scanMetadata = nullptr;
	if(!prepare){
		return;
	}
	IJoin::__releaseRegerences(true, ctx);
}
bool AbstractSQLJoin::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
	if(this->condition != nullptr && !this->condition->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool AbstractSQLJoin::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr)
	{
		this->left->analyse(context, leftValue, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyse(context, leftValue, ctx);
	}
	if(this->condition != nullptr)
	{
		this->condition->analyse(context, leftValue, ctx);
	}
	return true;
}
void AbstractSQLJoin::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	__GC_MV(this, &(this->joinStrategy), (new(ctx) JoinStrategy(false, ctx)), JoinStrategy);
	ISQLExpression* joinExp = nullptr;
	if(this->condition != nullptr)
	{
		joinExp = this->condition->getCondition(ctx);
	}
	this->joinStrategy->setJoinCondition(joinExp, ctx);
	if(where != nullptr)
	{
		this->joinStrategy->setWhereCondition(where->getCondition(ctx), ctx);
	}
	ScanTableMetadata* leftMetadata = this->left->getScanTableMetadata(ctx);
	ScanTableMetadata* rightMetadata = this->right->getScanTableMetadata(ctx);
	this->joinStrategy->analyze(context, leftMetadata, rightMetadata, ctx);
	GCUtils<ArrayList<JoinStrategyPart> >::mv(this, &(this->bestParts), this->joinStrategy->getBestParts(ctx), ctx);
	if(this->bestParts == nullptr)
	{
		this->crossjoin = true;
		this->left->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		this->right->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		return;
	}
	JoinStrategyPart* part = this->bestParts->get(0, ctx);
	JoinMatchExpression* exp = part->getBestExp(ctx);
	int indexStatus = exp->getIndexStatus(ctx);
	ScanTableIndexMetadata* leftIndex = nullptr;
	ScanTableIndexMetadata* rightIndex = nullptr;
	switch(indexStatus) {
	case JoinMatchExpression::NO_INDEX:
		{
			this->left->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
			this->right->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
			ArrayList<ScanTableColumnMetadata>* rightCols = (new(ctx) ArrayList<ScanTableColumnMetadata>(ctx));
			rightCols->add(exp->getRightMetadata(ctx)->getColumn(exp->getRightColumn(ctx), ctx), ctx);
			ScanTableIndexMetadata* rightIndexMeta = (new(ctx) ScanTableIndexMetadata(exp->getRightMetadata(ctx)->getFirstTableId(ctx), rightCols, ctx));
			exp->setRightIndex(rightIndexMeta, ctx);
			break ;
		}
	case JoinMatchExpression::LEFT_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		this->left->optimizeScan(context, where, groupby, limit, leftIndex->getColumnIds(ctx), debug, ctx);
		this->right->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		break ;
	case JoinMatchExpression::RIGHT_INDEX:
		this->left->optimizeScan(context, where, groupby, limit, nullptr, debug, ctx);
		rightIndex = exp->getRightIndex(ctx);
		this->right->optimizeScan(context, where, groupby, limit, rightIndex->getColumnIds(ctx), debug, ctx);
		break ;
	case JoinMatchExpression::BOTH_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		this->left->optimizeScan(context, where, groupby, limit, leftIndex->getColumnIds(ctx), debug, ctx);
		rightIndex = exp->getRightIndex(ctx);
		this->right->optimizeScan(context, where, groupby, limit, rightIndex->getColumnIds(ctx), debug, ctx);
		break ;
	}
}
IJoin* AbstractSQLJoin::getLeft(ThreadContext* ctx) throw() 
{
	return left;
}
void AbstractSQLJoin::setLeft(IJoin* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), left, IJoin);
}
IJoin* AbstractSQLJoin::getRight(ThreadContext* ctx) throw() 
{
	return right;
}
void AbstractSQLJoin::setRight(IJoin* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), right, IJoin);
}
SQLJoinCondition* AbstractSQLJoin::getCondition(ThreadContext* ctx) throw() 
{
	return condition;
}
void AbstractSQLJoin::setCondition(SQLJoinCondition* condition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->condition), condition, SQLJoinCondition);
}
bool AbstractSQLJoin::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->left != nullptr)
	{
		this->left->analyseSQLTables(context, leftValue, debug, ctx);
	}
	if(this->right != nullptr)
	{
		this->left->analyseSQLTables(context, leftValue, debug, ctx);
	}
	return true;
}
void AbstractSQLJoin::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	if(this->left != nullptr)
	{
		this->left->analyseSQLTables(context, false, debug, ctx);
		this->left->analyzeSQL(context, debug, ctx);
	}
	if(this->right != nullptr)
	{
		this->right->analyseSQLTables(context, false, debug, ctx);
		this->right->analyzeSQL(context, debug, ctx);
	}
	if(this->condition != nullptr)
	{
		this->condition->analyseSQL(context, false, debug, ctx);
	}
	__GC_MV(this, &(this->scanMetadata), this->left->getScanTableMetadata(ctx)->copy(ctx), ScanTableMetadata);
	ScanTableMetadata* rightData = this->right->getScanTableMetadata(ctx);
	this->scanMetadata->join(rightData, ctx);
}
bool AbstractSQLJoin::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->left != nullptr && this->left->hasTable(table, ctx))
	{
		return true;
	}
	if(this->right != nullptr && this->right->hasTable(table, ctx))
	{
		return true;
	}
	if(this->condition != nullptr && this->condition->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ScanTableMetadata* AbstractSQLJoin::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return this->scanMetadata;
}
bool AbstractSQLJoin::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return this->left->isOptimizerCacheable(ctx) && this->right->isOptimizerCacheable(ctx);
}
int AbstractSQLJoin::getLine(ThreadContext* ctx) throw() 
{
	return IJoin::getLine(ctx);
}
int AbstractSQLJoin::getStartPosition(ThreadContext* ctx) throw() 
{
	return IJoin::getStartPosition(ctx);
}
int AbstractSQLJoin::getEndLine(ThreadContext* ctx) throw() 
{
	return IJoin::getEndLine(ctx);
}
int AbstractSQLJoin::getEndPosition(ThreadContext* ctx) throw() 
{
	return IJoin::getEndPosition(ctx);
}
AbstractSrcElement* AbstractSQLJoin::getParent(ThreadContext* ctx) throw() 
{
	return IJoin::getParent(ctx);
}
void AbstractSQLJoin::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IJoin::setParent(parent, ctx);
}
ITableTargetScanner* AbstractSQLJoin::getCrossJoinsScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ITableTargetScanner* leftScanner = this->left->getScanner(trx, machine, nullptr, debug, ctx);
	ITableTargetScanner* rightScanner = this->right->getScanner(trx, machine, nullptr, debug, ctx);
	CrossJoinScanner* scanner = (new(ctx) CrossJoinScanner(trx, leftScanner, rightScanner, this->left->getScanTableMetadata(ctx), this->right->getScanTableMetadata(ctx), machine, ctx));
	if(joinRequest == nullptr)
	{
		return scanner;
	}
	return toResultScanner(trx, scanner, joinRequest, this->scanMetadata, debug, ctx);
}
ScannedResultIndexScanner* AbstractSQLJoin::toResultScanner(DbTransaction* trx, ITableTargetScanner* scanner, ArrayList<ScanTableColumnIdentifier>* joinRequest, ScanTableMetadata* tableMeta, bool debug, ThreadContext* ctx)
{
	ScanResult* result = trx->newResult(tableMeta, ctx);
	result->addIndex(joinRequest, ctx);
	{
		try
		{
			scanner->startScan(nullptr, ctx);
			while(scanner->hasNext(debug, ctx))
			{
				ScanResultRecord* record = scanner->next(debug, ctx);
				{
					try
					{
						result->addRecord(record, trx, ctx);
					}
					catch(Throwable* e)
					{
						throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1041(), ctx));
					}
				}
			}
			scanner->endScan(ctx);
		}
		catch(Throwable* e)
		{
			scanner->dispose(trx->getLogger(ctx), ctx);
			throw e;
		}
	}
	scanner->dispose(trx->getLogger(ctx), ctx);
	ScannedResultIndexScanner* resultScanner = (new(ctx) ScannedResultIndexScanner(result, joinRequest, ctx));
	return resultScanner;
}
ITableTargetScanner* AbstractSQLJoin::getJoinStrategyScanner(DbTransaction* trx, ScriptMachine* machine, JoinStrategyPart* part, bool inner, bool debug, ThreadContext* ctx)
{
	JoinMatchExpression* exp = part->getBestExp(ctx);
	int indexStatus = exp->getIndexStatus(ctx);
	ITableTargetScanner* leftScanner = nullptr;
	ITableTargetScanner* rightScanner = nullptr;
	ScanTableIndexMetadata* leftIndex = nullptr;
	ScanTableIndexMetadata* rightIndex = nullptr;
	ArrayList<ScanTableColumnIdentifier>* rightCols = nullptr;
	switch(indexStatus) {
	case JoinMatchExpression::NO_INDEX:
		{
			leftScanner = this->left->getScanner(trx, machine, nullptr, debug, ctx);
			rightCols = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
			rightCols->add(exp->getRightColumn(ctx), ctx);
			rightScanner = this->right->getScanner(trx, machine, rightCols, debug, ctx);
			return (new(ctx) RightindexJoinScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx));
		}
	case JoinMatchExpression::LEFT_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		leftScanner = this->left->getScanner(trx, machine, leftIndex->getColumnIds(ctx), debug, ctx);
		rightScanner = this->right->getScanner(trx, machine, nullptr, debug, ctx);
		return (new(ctx) ReverseIndexScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx));
	case JoinMatchExpression::RIGHT_INDEX:
		leftScanner = this->left->getScanner(trx, machine, nullptr, debug, ctx);
		rightIndex = exp->getRightIndex(ctx);
		rightScanner = this->right->getScanner(trx, machine, rightIndex->getColumnIds(ctx), debug, ctx);
		return (new(ctx) RightindexJoinScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx));
	case JoinMatchExpression::BOTH_INDEX:
		leftIndex = exp->getLeftIndex(ctx);
		leftScanner = this->left->getScanner(trx, machine, leftIndex->getColumnIds(ctx), debug, ctx);
		rightScanner = this->right->getScanner(trx, machine, nullptr, debug, ctx);
		return (new(ctx) ReverseIndexScanner(trx, leftScanner, rightScanner, left->getScanTableMetadata(ctx), right->getScanTableMetadata(ctx), inner, exp, this->condition, machine, ctx));
	}
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1042(), ctx));
}
}}}}}

