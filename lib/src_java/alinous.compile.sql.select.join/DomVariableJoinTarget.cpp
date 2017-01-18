#include "includes.h"


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
		context->getSourceValidator(ctx)->addError(ConstStr::getCNST_STR_1084(), this, ctx);
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
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1085(), ctx));
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
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1086(), ctx));
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
void DomVariableJoinTarget::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
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
}}}}}

