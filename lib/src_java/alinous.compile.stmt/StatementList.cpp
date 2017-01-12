#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool StatementList::__init_done = __init_static_variables();
bool StatementList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StatementList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StatementList::~StatementList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StatementList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StatementList", L"~StatementList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
IStatement* StatementList::getFirstStatement(ThreadContext* ctx) throw() 
{
	if(list->isEmpty(ctx))
	{
		return nullptr;
	}
	return this->list->get(0, ctx);
}
bool StatementList::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->list != nullptr)
	{
		int maxLoop = this->list->size(ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			if(!this->list->get(i, ctx)->visit(visitor, this, ctx))
			{
				return false;
			}
		}
	}
	return true;
}
bool StatementList::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->list != nullptr)
	{
		int maxLoop = this->list->size(ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			this->list->get(i, ctx)->analyse(context, leftValue, ctx);
		}
	}
	return true;
}
void StatementList::add(IStatement* stmt, ThreadContext* ctx) throw() 
{
	this->list->add(stmt, ctx);
}
ArrayList<IStatement>* StatementList::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void StatementList::setList(ArrayList<IStatement>* list, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<IStatement> >::mv(this, &(this->list), list, ctx);
}
IStatement::StatementType StatementList::getType(ThreadContext* ctx) throw() 
{
	return StatementType::STMT_LIST;
}
void StatementList::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void StatementList::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* element = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(element == nullptr || !((dynamic_cast<IStatement*>(element) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1089(), ctx));
		}
		this->list->add(static_cast<IStatement*>(element), ctx);
	}
}
void StatementList::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__StatementList, ctx);
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IStatement* stmt = this->list->get(i, ctx);
		stmt->writeData(buff, ctx);
	}
}
}}}

