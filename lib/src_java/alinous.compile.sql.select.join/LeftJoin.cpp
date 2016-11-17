#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool LeftJoin::__init_done = __init_static_variables();
bool LeftJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LeftJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LeftJoin::~LeftJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LeftJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLJoin::__releaseRegerences(true, ctx);
}
ITableTargetScanner* LeftJoin::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	if(this->crossjoin)
	{
		return getCrossJoinsScanner(trx, machine, joinRequest, debug, ctx);
	}
	if(this->bestParts->size(ctx) == 1)
	{
		JoinStrategyPart* part = this->bestParts->get(0, ctx);
		ITableTargetScanner* scanner = getJoinStrategyScanner(trx, machine, part, this->joinStrategy->isInner(ctx), debug, ctx);
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
		ITableTargetScanner* scanner = getJoinStrategyScanner(trx, machine, part, this->joinStrategy->isInner(ctx), debug, ctx);
		scanners->add(scanner, ctx);
	}
	JoinedCollectionScanner* collectionScanner = (new(ctx) JoinedCollectionScanner(scanners, ctx));
	if(joinRequest != nullptr)
	{
		return toResultScanner(trx, collectionScanner, joinRequest, this->scanMetadata, debug, ctx);
	}
	return collectionScanner;
}
IStatement::StatementType LeftJoin::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void LeftJoin::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
}}}}}

