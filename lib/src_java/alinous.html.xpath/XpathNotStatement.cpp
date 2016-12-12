#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool XpathNotStatement::__init_done = __init_static_variables();
bool XpathNotStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathNotStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathNotStatement::~XpathNotStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathNotStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathNotStatement", L"~XpathNotStatement");
	__e_obj1.add(this->stmt, this);
	stmt = nullptr;
	if(!prepare){
		return;
	}
}
bool XpathNotStatement::isNot(ThreadContext* ctx) throw() 
{
	return notFlag;
}
void XpathNotStatement::setNot(bool notFlag, ThreadContext* ctx) throw() 
{
	this->notFlag = notFlag;
}
IXpathBooleanCondition* XpathNotStatement::getStmt(ThreadContext* ctx) throw() 
{
	return stmt;
}
void XpathNotStatement::setStmt(IXpathBooleanCondition* stmt, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->stmt), stmt, IXpathBooleanCondition);
}
String* XpathNotStatement::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	if(notFlag)
	{
		buffer->append(ConstStr::getCNST_STR_1691(), ctx);
	}
	buffer->append(ConstStr::getCNST_STR_972(), ctx);
	buffer->append(stmt->toString(ctx), ctx);
	buffer->append(ConstStr::getCNST_STR_889(), ctx);
	return buffer->toString(ctx);
}
bool XpathNotStatement::getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	bool condition = this->stmt->getBooleanValue(document, currentNode, ctx);
	if(this->notFlag)
	{
		return !condition;
	}
	return condition;
}
}}}

