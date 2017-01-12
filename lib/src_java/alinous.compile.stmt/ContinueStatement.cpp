#include "includes.h"


namespace alinous {namespace compile {namespace stmt {





bool ContinueStatement::__init_done = __init_static_variables();
bool ContinueStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ContinueStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ContinueStatement::~ContinueStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ContinueStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ContinueStatement", L"~ContinueStatement");
	__e_obj1.add(this->label, this);
	label = nullptr;
	if(!prepare){
		return;
	}
	AbstractAlinousStatement::__releaseRegerences(true, ctx);
}
void ContinueStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool ContinueStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool ContinueStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IStatement::StatementType ContinueStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::CONTINUE_STATEMENT;
}
String* ContinueStatement::getLabel(ThreadContext* ctx) throw() 
{
	return label;
}
void ContinueStatement::setLabel(String* label, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->label), label, String);
}
void ContinueStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->label), buff->getString(ctx), String);
	}
}
void ContinueStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ContinueStatement, ctx);
	bool isnull = (this->label == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->label, ctx);
	}
}
}}}

