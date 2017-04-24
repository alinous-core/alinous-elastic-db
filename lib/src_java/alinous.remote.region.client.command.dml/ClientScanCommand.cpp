#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommand.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {





bool ClientScanCommand::__init_done = __init_static_variables();
bool ClientScanCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientScanCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientScanCommand::ClientScanCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx), data(__GC_INS(this, (new(ctx) ClientScanCommandData(ctx)), ClientScanCommandData)), hasNext(0)
{
	this->type = AbstractNodeRegionCommand::TYPE_SCAN;
	this->hasNext = false;
}
void ClientScanCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = AbstractNodeRegionCommand::TYPE_SCAN;
	this->hasNext = false;
}
 ClientScanCommand::~ClientScanCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientScanCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ClientScanCommand", L"~ClientScanCommand");
	__e_obj1.add(this->data, this);
	data = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void ClientScanCommand::executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	{
		try
		{
			this->hasNext = nodeRegionServer->scan(this->data, ctx);
		}
		catch(Throwable* e)
		{
			AlinousCore* core = nodeRegionServer->getCore(ctx);
			core->logError(e, ctx);
			handleError(e, ctx);
		}
	}
	writeByteStream(outStream, ctx);
}
void ClientScanCommand::readFromStream(InputStream* stream, int remain, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* src = ArrayAllocatorPrimitive<char>::allocatep(ctx, remain);
	stream->read(src, ctx);
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(src, ctx));
	__GC_MV(this, &(this->data), ClientScanCommandData::fromNetwork(buff, ctx), ClientScanCommandData);
	this->hasNext = buff->getBoolean(ctx);
	readErrorFromStream(buff, ctx);
}
DbVersionContext* ClientScanCommand::getVctx(ThreadContext* ctx) throw() 
{
	return this->data->getVctx(ctx);
}
void ClientScanCommand::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	this->data->setVctx(vctx, ctx);
}
TableAndSchema* ClientScanCommand::getTable(ThreadContext* ctx) throw() 
{
	return this->data->getTable(ctx);
}
void ClientScanCommand::setTable(TableAndSchema* table, ThreadContext* ctx) throw() 
{
	this->data->setTable(table, ctx);
}
int ClientScanCommand::getLockMode(ThreadContext* ctx) throw() 
{
	return this->data->getLockMode(ctx);
}
void ClientScanCommand::setLockMode(int lockMode, ThreadContext* ctx) throw() 
{
	this->data->setLockMode(lockMode, ctx);
}
bool ClientScanCommand::isPrimaryIndex(ThreadContext* ctx) throw() 
{
	return this->data->isPrimaryIndex(ctx);
}
void ClientScanCommand::setPrimaryIndex(bool primaryIndex, ThreadContext* ctx) throw() 
{
	this->data->setPrimaryIndex(primaryIndex, ctx);
}
bool ClientScanCommand::isFullscan(ThreadContext* ctx) throw() 
{
	return this->data->isFullscan(ctx);
}
void ClientScanCommand::setFullscan(bool fullscan, ThreadContext* ctx) throw() 
{
	this->data->setFullscan(fullscan, ctx);
}
ArrayList<TableColumnMetadata>* ClientScanCommand::getIndexColmns(ThreadContext* ctx) throw() 
{
	return this->data->getIndexColmns(ctx);
}
void ClientScanCommand::setIndexColmns(ArrayList<TableColumnMetadata>* indexColmns, ThreadContext* ctx) throw() 
{
	this->data->setIndexColmns(indexColmns, ctx);
}
ISQLExpression* ClientScanCommand::getExp(ThreadContext* ctx) throw() 
{
	return this->data->getExp(ctx);
}
void ClientScanCommand::setExp(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	this->data->setExp(exp, ctx);
}
IndexListScannerParam* ClientScanCommand::getListParam(ThreadContext* ctx) throw() 
{
	return this->data->getListParam(ctx);
}
void ClientScanCommand::setListParam(IndexListScannerParam* listParam, ThreadContext* ctx) throw() 
{
	this->data->setListParam(listParam, ctx);
}
ScanResultIndexKey* ClientScanCommand::getEqKey(ThreadContext* ctx) throw() 
{
	return this->data->getEqKey(ctx);
}
void ClientScanCommand::setEqKey(ScanResultIndexKey* eqKey, ThreadContext* ctx) throw() 
{
	this->data->setEqKey(eqKey, ctx);
}
IndexRangeScannerParam* ClientScanCommand::getRangeParam(ThreadContext* ctx) throw() 
{
	return this->data->getRangeParam(ctx);
}
void ClientScanCommand::setRangeParam(IndexRangeScannerParam* rangeParam, ThreadContext* ctx) throw() 
{
	this->data->setRangeParam(rangeParam, ctx);
}
bool ClientScanCommand::isHasNext(ThreadContext* ctx) throw() 
{
	return hasNext;
}
void ClientScanCommand::setHasNext(bool hasNext, ThreadContext* ctx) throw() 
{
	this->hasNext = hasNext;
}
void ClientScanCommand::writeByteStream(OutputStream* outStream, ThreadContext* ctx)
{
	NetworkBinaryBuffer* buff = (new(ctx) NetworkBinaryBuffer(32, ctx));
	buff->putInt(this->type, ctx);
	this->data->writeData(buff, ctx);
	buff->putBoolean(this->hasNext, ctx);
	writeErrorByteStream(buff, ctx);
	IArrayObjectPrimitive<char>* b = buff->toBinary(ctx);
	int pos = buff->getPutSize(ctx);
	outStream->write(b, 0, pos, ctx);
	outStream->flush(ctx);
}
void ClientScanCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}}

