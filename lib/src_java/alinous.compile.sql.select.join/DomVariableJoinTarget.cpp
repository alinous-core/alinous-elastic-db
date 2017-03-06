#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze.scan/VoidScanner.h"
#include "alinous.compile.sql.select.join.scan/JoinedCollectionScanner.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.compile.sql.select.join.scan/CrossJoinScanner.h"
#include "alinous.compile.sql.select.join.scan/ReverseIndexScanner.h"
#include "alinous.compile.sql.select.join.scan/RightindexJoinScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/InnerJoin.h"
#include "alinous.compile.sql.select.join/CrossJoin.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"
#include "alinous.compile.sql.select.join/DomVariableJoinTarget.h"
#include "alinous.compile.sql.select.join/JoinSubQueryTarget.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"
#include "alinous.compile.sql.select.join/NaturalJoin.h"
#include "alinous.compile.sql.select.join/RightJoin.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.select.join/TableJoinTarget.h"
#include "alinous.compile.sql.select.join/WrappedJoinTarget.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.sql.select.join/TableList.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool DomVariableJoinTarget::__init_done = __init_static_variables();
bool DomVariableJoinTarget::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariableJoinTarget", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariableJoinTarget::DomVariableJoinTarget(ThreadContext* ctx) throw()  : IObject(ctx), AbstractJoinTarget(ctx), domDesc(nullptr), asName(nullptr), scanMeta(nullptr)
{
}
void DomVariableJoinTarget::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DomVariableJoinTarget::~DomVariableJoinTarget() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariableJoinTarget::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomVariableJoinTarget", L"~DomVariableJoinTarget");
	__e_obj1.add(this->domDesc, this);
	domDesc = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	__e_obj1.add(this->scanMeta, this);
	scanMeta = nullptr;
	if(!prepare){
		return;
	}
	AbstractJoinTarget::__releaseRegerences(true, ctx);
}
bool DomVariableJoinTarget::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->domDesc != nullptr && !this->domDesc->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool DomVariableJoinTarget::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->domDesc != nullptr)
	{
		this->domDesc->analyse(context, leftValue, ctx);
	}
	if(this->asName == nullptr)
	{
		context->addError(ConstStr::getCNST_STR_1090(), this, ctx);
	}
	return true;
}
DomVariableDescriptor* DomVariableJoinTarget::getDomDesc(ThreadContext* ctx) throw() 
{
	return domDesc;
}
void DomVariableJoinTarget::setDomDesc(DomVariableDescriptor* domDesc, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domDesc), domDesc, DomVariableDescriptor);
}
String* DomVariableJoinTarget::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void DomVariableJoinTarget::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
bool DomVariableJoinTarget::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = context->getMachine(ctx)->resolveExpression(this->domDesc, debug, ctx);
	if(val->getVariableClass(ctx) != IAlinousVariable::CLASS_DOM)
	{
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1091(), ctx));
	}
	IDomVariable* domvariable = static_cast<IDomVariable*>(val);
	if(domvariable->getDomType(ctx) == IDomVariable::TYPE_DOM)
	{
		analyseDomTable(context, static_cast<DomVariable*>(domvariable), ctx);
	}
		else 
	{
		if(domvariable->getDomType(ctx) == IDomVariable::TYPE_ARRAY)
		{
			DomArray* array = static_cast<DomArray*>(domvariable);
			if(array->size(ctx) == 0 || !((dynamic_cast<DomVariable*>(array->get(0, ctx)) != 0)))
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1092(), ctx));
			}
			analyseDomTable(context, static_cast<DomVariable*>(array->get(0, ctx)), ctx);
		}
	}
	return true;
}
void DomVariableJoinTarget::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
}
bool DomVariableJoinTarget::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
void DomVariableJoinTarget::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) throw() 
{
}
ScanTableMetadata* DomVariableJoinTarget::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return this->scanMeta;
}
bool DomVariableJoinTarget::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return false;
}
ITableTargetScanner* DomVariableJoinTarget::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) throw() 
{
	return nullptr;
}
SQLJoinCondition* DomVariableJoinTarget::getCondition(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IStatement::StatementType DomVariableJoinTarget::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void DomVariableJoinTarget::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void DomVariableJoinTarget::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<DomVariableDescriptor*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_979(), ctx));
		}
		__GC_MV(this, &(this->domDesc), static_cast<DomVariableDescriptor*>(el), DomVariableDescriptor);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void DomVariableJoinTarget::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DomVariableJoinTarget, ctx);
	bool isnull = (this->domDesc == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->domDesc->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
void DomVariableJoinTarget::analyseDomTable(SQLAnalyseContext* context, DomVariable* variable, ThreadContext* ctx) throw() 
{
	ScanTableIdentifier* tableId = (new(ctx) ScanTableIdentifier(nullptr, this->asName, variable->getColumnCount(ctx), ctx));
	__GC_MV(this, &(this->scanMeta), (new(ctx) ScanTableMetadata(tableId, ctx)), ScanTableMetadata);
	this->scanMeta->setDom(true, ctx);
	Iterator<String>* it = variable->getPropertiesIterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		ScanTableColumnMetadata* colMeta = (new(ctx) ScanTableColumnMetadata(tableId, key, ctx));
		this->scanMeta->addColumn(colMeta, ctx);
	}
	context->addTable(this->scanMeta, this->asName, ctx);
}
void DomVariableJoinTarget::__cleanUp(ThreadContext* ctx){
}
}}}}}

