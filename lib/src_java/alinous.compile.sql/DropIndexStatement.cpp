#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool DropIndexStatement::__init_done = __init_static_variables();
bool DropIndexStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DropIndexStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DropIndexStatement::~DropIndexStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DropIndexStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DropIndexStatement", L"~DropIndexStatement");
	__e_obj1.add(this->indexName, this);
	indexName = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
IStatement::StatementType DropIndexStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::DROP_INDEX;
}
void DropIndexStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<TableJoinTarget*>(indexName) != 0)))
	{
		validator->addError(ConstStr::getCNST_STR_1035(), this, ctx);
	}
}
bool DropIndexStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->indexName != nullptr && !this->indexName->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool DropIndexStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->indexName != nullptr)
	{
		this->indexName->analyse(context, leftValue, ctx);
	}
	return true;
}
IJoinTarget* DropIndexStatement::getIndexName(ThreadContext* ctx) throw() 
{
	return indexName;
}
void DropIndexStatement::setIndexName(IJoinTarget* indexName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->indexName), indexName, IJoinTarget);
}
void DropIndexStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw() 
{
}
void DropIndexStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoinTarget*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1030(), ctx));
		}
		__GC_MV(this, &(this->indexName), static_cast<IJoinTarget*>(el), IJoinTarget);
	}
}
void DropIndexStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__DropIndexStatement, ctx);
	bool isnull = (this->indexName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->indexName->writeData(buff, ctx);
	}
}
}}}

