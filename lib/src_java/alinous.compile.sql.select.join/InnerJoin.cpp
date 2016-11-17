#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool InnerJoin::__init_done = __init_static_variables();
bool InnerJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InnerJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InnerJoin::~InnerJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InnerJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLJoin::__releaseRegerences(true, ctx);
}
ITableTargetScanner* InnerJoin::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	if(this->crossjoin == true)
	{
		return (new(ctx) VoidScanner(ctx));
	}
	if(this->bestParts->size(ctx) == 1)
	{
		JoinStrategyPart* part = this->bestParts->get(0, ctx);
		ITableTargetScanner* scanner = getJoinStrategyScanner(trx, machine, part, true, debug, ctx);
		if(joinRequest != nullptr)
		{
			return toResultScanner(trx, scanner, joinRequest, this->scanMetadata, debug, ctx);
		}
		return scanner;
	}
	ArrayList<ITableTargetScanner>* scanners = (new(ctx) ArrayList<ITableTargetScanner>(ctx));
	int maxLoop = this->bestParts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		JoinStrategyPart* part = this->bestParts->get(i, ctx);
		ITableTargetScanner* scanner = getJoinStrategyScanner(trx, machine, part, true, debug, ctx);
		scanners->add(scanner, ctx);
	}
	JoinedCollectionScanner* collectionScanner = (new(ctx) JoinedCollectionScanner(scanners, ctx));
	if(joinRequest != nullptr)
	{
		return toResultScanner(trx, collectionScanner, joinRequest, this->scanMetadata, debug, ctx);
	}
	return collectionScanner;
}
IStatement::StatementType InnerJoin::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void InnerJoin::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
}}}}}

