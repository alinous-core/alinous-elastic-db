#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool CaseStatement::__init_done = __init_static_variables();
bool CaseStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CaseStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CaseStatement::~CaseStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CaseStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CaseStatement", L"~CaseStatement");
	__e_obj1.add(this->constId, this);
	constId = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
IStatement::StatementType CaseStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::CASE_STATEMENT;
}
void CaseStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool CaseStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool CaseStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
AlinousName* CaseStatement::getConstId(ThreadContext* ctx) throw() 
{
	return constId;
}
void CaseStatement::setConstId(AlinousName* constId, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->constId), constId, AlinousName);
}
void CaseStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->constId), static_cast<AlinousName*>(el), AlinousName);
	}
}
void CaseStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__CaseStatement, ctx);
	bool isnull = (this->constId == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->constId->writeData(buff, ctx);
	}
}
}}}

