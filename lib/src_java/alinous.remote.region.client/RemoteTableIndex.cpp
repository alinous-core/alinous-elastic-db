#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.region.client/RemoteTableIndex.h"

namespace alinous {namespace remote {namespace region {namespace client {





bool RemoteTableIndex::__init_done = __init_static_variables();
bool RemoteTableIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableIndex::RemoteTableIndex(String* name, ArrayList<TableColumnMetadata>* keys, bool primary, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw()  : IObject(ctx), IScannableIndex(ctx), name(nullptr), primary(0), keys(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	this->primary = primary;
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->keys), keys, ctx);
}
void RemoteTableIndex::__construct_impl(String* name, ArrayList<TableColumnMetadata>* keys, bool primary, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	this->primary = primary;
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->keys), keys, ctx);
}
 RemoteTableIndex::~RemoteTableIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableIndex", L"~RemoteTableIndex");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->keys, this);
	keys = nullptr;
	if(!prepare){
		return;
	}
}
ArrayList<TableColumnMetadata>* RemoteTableIndex::getColumns(ThreadContext* ctx) throw() 
{
	return this->keys;
}
BTree* RemoteTableIndex::getStorage(ThreadContext* ctx) throw() 
{
	return nullptr;
}
String* RemoteTableIndex::getName(ThreadContext* ctx) throw() 
{
	return this->name;
}
bool RemoteTableIndex::isPrimary(ThreadContext* ctx) throw() 
{
	return this->primary;
}
void RemoteTableIndex::addIndexValue(IDatabaseRecord* record, ThreadContext* ctx)
{
}
void RemoteTableIndex::createIndex(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
bool RemoteTableIndex::isAvailableByScanId(ArrayList<ScanTableColumnIdentifier>* columnIds, ThreadContext* ctx) throw() 
{
	int maxLoop = columnIds->size(ctx);
	if(maxLoop > this->keys->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = columnIds->get(i, ctx)->getColumn(ctx);
		TableColumnMetadata* colMeta = this->keys->get(i, ctx);
		if(!key->equals(colMeta->name, ctx))
		{
			return false;
		}
	}
	return true;
}
bool RemoteTableIndex::isAvailable(ArrayList<String>* columnsStr, ThreadContext* ctx) throw() 
{
	int maxLoop = columnsStr->size(ctx);
	if(maxLoop > this->keys->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = columnsStr->get(i, ctx);
		TableColumnMetadata* colMeta = this->keys->get(i, ctx);
		if(!key->equals(colMeta->name, ctx))
		{
			return false;
		}
	}
	return true;
}
bool RemoteTableIndex::isOpened(ThreadContext* ctx) throw() 
{
	return true;
}
void RemoteTableIndex::open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void RemoteTableIndex::close(ThreadContext* ctx)
{
}
void RemoteTableIndex::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
}
int RemoteTableIndex::archiveSize(ThreadContext* ctx)
{
	return -1;
}
void RemoteTableIndex::__cleanUp(ThreadContext* ctx){
}
}}}}

