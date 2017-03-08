#include "include/global.h"


#include "alinous.db.trx.cache/CulumnOrder.h"

namespace alinous {namespace db {namespace trx {namespace cache {





bool CulumnOrder::__init_done = __init_static_variables();
bool CulumnOrder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CulumnOrder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CulumnOrder::CulumnOrder(ThreadContext* ctx) throw()  : IObject(ctx), valuesOrder(0), columnOrder(0), columnName(nullptr)
{
}
void CulumnOrder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CulumnOrder::~CulumnOrder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CulumnOrder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CulumnOrder", L"~CulumnOrder");
	__e_obj1.add(this->columnName, this);
	columnName = nullptr;
	if(!prepare){
		return;
	}
}
String* CulumnOrder::getColumnName(ThreadContext* ctx) throw() 
{
	return columnName;
}
void CulumnOrder::setColumnName(String* columnName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->columnName), columnName, String);
}
void CulumnOrder::setValuesOrder(int valuesOrder, ThreadContext* ctx) throw() 
{
	this->valuesOrder = valuesOrder;
}
void CulumnOrder::setColumnOrder(int columnOrder, ThreadContext* ctx) throw() 
{
	this->columnOrder = columnOrder;
}
int CulumnOrder::getValuesOrder(ThreadContext* ctx) throw() 
{
	return valuesOrder;
}
int CulumnOrder::getColumnOrder(ThreadContext* ctx) throw() 
{
	return columnOrder;
}
void CulumnOrder::__cleanUp(ThreadContext* ctx){
}
}}}}

