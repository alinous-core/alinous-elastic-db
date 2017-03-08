#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/LongKey.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.variable.util/LongArrayStore.h"

namespace alinous {namespace db {namespace variable {namespace util {





bool LongArrayStore::__init_done = __init_static_variables();
bool LongArrayStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongArrayStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongArrayStore::LongArrayStore(DiskCacheManager* diskCache, File* file, int storageCapacity, AlinousDatabase* database, ThreadContext* ctx) : IObject(ctx), tree(nullptr)
{
	__GC_MV(this, &(this->tree), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), diskCache, ctx), IBTree);
	int BLOCK_SIZE = 64;
	int nodeCapacity = 32;
	int keyType = IBTreeKey::TYPE_LONG;
	int valueType = 0;
	this->tree->initTreeStorage(nodeCapacity, keyType, valueType, (long long)storageCapacity, (long long)BLOCK_SIZE, ctx);
}
void LongArrayStore::__construct_impl(DiskCacheManager* diskCache, File* file, int storageCapacity, AlinousDatabase* database, ThreadContext* ctx)
{
	__GC_MV(this, &(this->tree), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), diskCache, ctx), IBTree);
	int BLOCK_SIZE = 64;
	int nodeCapacity = 32;
	int keyType = IBTreeKey::TYPE_LONG;
	int valueType = 0;
	this->tree->initTreeStorage(nodeCapacity, keyType, valueType, (long long)storageCapacity, (long long)BLOCK_SIZE, ctx);
}
 LongArrayStore::~LongArrayStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongArrayStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongArrayStore", L"~LongArrayStore");
	__e_obj1.add(this->tree, this);
	tree = nullptr;
	if(!prepare){
		return;
	}
}
void LongArrayStore::addLong(long long value, ThreadContext* ctx)
{
	LongKey* key = (new(ctx) LongKey(value, ctx));
	this->tree->putKey(key, ctx);
}
void LongArrayStore::__cleanUp(ThreadContext* ctx){
}
}}}}

