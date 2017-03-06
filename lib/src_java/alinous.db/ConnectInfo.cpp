#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"

namespace alinous {namespace db {





bool ConnectInfo::__init_done = __init_static_variables();
bool ConnectInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConnectInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConnectInfo::ConnectInfo(ThreadContext* ctx) throw()  : IObject(ctx), user(nullptr), pass(nullptr)
{
}
void ConnectInfo::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ConnectInfo::~ConnectInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConnectInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConnectInfo", L"~ConnectInfo");
	__e_obj1.add(this->user, this);
	user = nullptr;
	__e_obj1.add(this->pass, this);
	pass = nullptr;
	if(!prepare){
		return;
	}
}
String* ConnectInfo::getUser(ThreadContext* ctx) throw() 
{
	return user;
}
void ConnectInfo::setUser(String* user, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->user), user, String);
}
String* ConnectInfo::getPass(ThreadContext* ctx) throw() 
{
	return pass;
}
void ConnectInfo::setPass(String* pass, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pass), pass, String);
}
void ConnectInfo::__cleanUp(ThreadContext* ctx){
}
}}

