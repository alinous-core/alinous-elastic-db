#include "includes.h"


namespace alinous {namespace db {namespace table {





bool DatatableUpdateSupport::__init_done = __init_static_variables();
bool DatatableUpdateSupport::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableUpdateSupport", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableUpdateSupport::DatatableUpdateSupport(String* schema, String* name, String* baseDir, IOidPublisher* oidPublisher, ThreadContext* ctx) throw()  : IObject(ctx), DatatableDDLSupport(schema, name, baseDir, ctx), oidPublisher(nullptr)
{
	__GC_MV(this, &(this->oidPublisher), oidPublisher, IOidPublisher);
}
void DatatableUpdateSupport::__construct_impl(String* schema, String* name, String* baseDir, IOidPublisher* oidPublisher, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->oidPublisher), oidPublisher, IOidPublisher);
}
 DatatableUpdateSupport::~DatatableUpdateSupport() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableUpdateSupport::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatatableUpdateSupport", L"~DatatableUpdateSupport");
	__e_obj1.add(this->oidPublisher, this);
	oidPublisher = nullptr;
	if(!prepare){
		return;
	}
	DatatableDDLSupport::__releaseRegerences(true, ctx);
}
void DatatableUpdateSupport::updateData(IDatabaseRecord* data, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx)
{
	DatabaseRecord* lastdbrecord = getLastRecord(data->getOid(ctx), commitId, ctx);
	data->setLastUpdateCommitId(commitId, ctx);
	data->setInsertedCommitId(lastdbrecord->getInsertedCommitId(ctx), ctx);
	this->cacheEngine->updateData(this, lastdbrecord, commitId, jobs, log, ctx);
}
void DatatableUpdateSupport::insertData(IDatabaseRecord* data, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx)
{
	long long nextOid = this->dataStorage->getNextOid(ctx);
	DatabaseRecord* dbrecord = (new(ctx) DatabaseRecord(nextOid, data->getNumColumn(ctx), commitId, data, ctx));
	this->cacheEngine->insertData(this, dbrecord, commitId, jobs, log, ctx);
}
void DatatableUpdateSupport::insertData(List<IDatabaseRecord>* records, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* data = records->get(i, ctx);
		insertData(data, newCommitId, jobs, logger, ctx);
	}
}
}}}

