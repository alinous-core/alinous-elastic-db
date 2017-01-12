#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool NaturalJoin::__init_done = __init_static_variables();
bool NaturalJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NaturalJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NaturalJoin::~NaturalJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NaturalJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLJoin::__releaseRegerences(true, ctx);
}
void NaturalJoin::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ITableTargetScanner* NaturalJoin::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) throw() 
{
	return nullptr;
}
IStatement::StatementType NaturalJoin::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void NaturalJoin::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void NaturalJoin::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void NaturalJoin::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__NaturalJoin, ctx);
	__writeData(buff, ctx);
}
}}}}}

