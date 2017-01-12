#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool CrossJoin::__init_done = __init_static_variables();
bool CrossJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CrossJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CrossJoin::~CrossJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CrossJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	InnerJoin::__releaseRegerences(true, ctx);
}
ITableTargetScanner* CrossJoin::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	if(this->crossjoin)
	{
		return getCrossJoinsScanner(trx, machine, joinRequest, debug, ctx);
	}
	return InnerJoin::getScanner(trx, machine, joinRequest, debug, ctx);
}
IStatement::StatementType CrossJoin::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void CrossJoin::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void CrossJoin::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void CrossJoin::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__CrossJoin, ctx);
	__writeData(buff, ctx);
}
}}}}}

