#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/StringKey.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.db.server.commit/InsertStore.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {





bool InsertStore::__init_done = __init_static_variables();
bool InsertStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertStore::InsertStore(String* filePath, ThreadContext* ctx) throw()  : IObject(ctx), store(nullptr), baseDir(nullptr)
{
	__GC_MV(this, &(this->baseDir), filePath, String);
}
void InsertStore::__construct_impl(String* filePath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->baseDir), filePath, String);
}
 InsertStore::~InsertStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertStore", L"~InsertStore");
	__e_obj1.add(this->store, this);
	store = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	if(!prepare){
		return;
	}
}
InsertStore* InsertStore::init(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->store), (new(ctx) BTreeOnMemory(8, ctx)), IBTree);
	return this;
}
void InsertStore::add(IDatabaseTable* table, List<ClientNetworkRecord>* records, ThreadContext* ctx)
{
	String* fullName = table->getFullName(ctx);
	StringKey* key = (new(ctx) StringKey(fullName, ctx));
	IBTreeNode* node = this->store->findByKey(key, ctx);
	if(node == nullptr)
	{
		this->store->putKey(key, ctx);
		node = this->store->findByKey(key, ctx);
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ClientNetworkRecord* record = records->get(i, ctx);
		values->add(record, ctx);
	}
}
IBTree* InsertStore::getStore(ThreadContext* ctx) throw() 
{
	return store;
}
String* InsertStore::getBaseDir(ThreadContext* ctx) throw() 
{
	return baseDir;
}
void InsertStore::__cleanUp(ThreadContext* ctx){
}
}}}}}

