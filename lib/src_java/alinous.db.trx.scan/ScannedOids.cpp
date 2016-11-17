#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace scan {





bool ScannedOids::__init_done = __init_static_variables();
bool ScannedOids::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannedOids", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannedOids::ScannedOids(ThreadContext* ctx) throw()  : IObject(ctx), numHash(256 * 256), numHashMask((256 * 256) - 1), hasheddArray(nullptr)
{
	__GC_MV(this, &(this->hasheddArray), ArrayAllocator<OidsArray>::allocate(ctx, this->numHash), IArrayObject<OidsArray>);
	int maxLoop = this->numHash;
	for(int i = 0; i != maxLoop; ++i)
	{
		this->hasheddArray->set(nullptr,i, ctx);
	}
}
void ScannedOids::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->hasheddArray), ArrayAllocator<OidsArray>::allocate(ctx, this->numHash), IArrayObject<OidsArray>);
	int maxLoop = this->numHash;
	for(int i = 0; i != maxLoop; ++i)
	{
		this->hasheddArray->set(nullptr,i, ctx);
	}
}
 ScannedOids::~ScannedOids() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannedOids::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScannedOids", L"~ScannedOids");
	__e_obj1.add(this->hasheddArray, this);
	hasheddArray = nullptr;
	if(!prepare){
		return;
	}
}
void ScannedOids::dispose(ThreadContext* ctx) throw() 
{
	int maxLoop = this->numHash;
	for(int i = 0; i != maxLoop; ++i)
	{
		this->hasheddArray->set(nullptr,i, ctx);
	}
}
void ScannedOids::addOid(ScanResultRecord* record, ThreadContext* ctx) throw() 
{
	ScannedOids::Oids* oid = (new(ctx) ScannedOids::Oids(record, ctx));
	ScannedOids::OidsArray* array = getHashedArray(oid, ctx);
	array->addOid(oid, ctx);
}
bool ScannedOids::contains(ScanResultRecord* record, ThreadContext* ctx) throw() 
{
	ScannedOids::Oids* oid = (new(ctx) ScannedOids::Oids(record, ctx));
	ScannedOids::OidsArray* array = getHashedArray(oid, ctx);
	return array != nullptr ? array->contains(oid, ctx) : false;
}
ScannedOids::OidsArray* ScannedOids::getHashedArray(ScannedOids::Oids* oid, ThreadContext* ctx) throw() 
{
	int code = ((int)(oid->getHash(ctx) & this->numHashMask));
	ScannedOids::OidsArray* array = this->hasheddArray->get(code);
	if(array == nullptr)
	{
		array = (new(ctx) ScannedOids::OidsArray(ctx));
		this->hasheddArray->set(array,code, ctx);
	}
	return array;
}
}}}}

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScannedOids::Oids::__init_done = __init_static_variables();
bool ScannedOids::Oids::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannedOids::Oids", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannedOids::Oids::Oids(ScanResultRecord* record, ThreadContext* ctx) throw()  : IObject(ctx), oids(nullptr)
{
	ArrayList<IDatabaseRecord>* list = record->getRecords(ctx);
	int maxLoop = list->size(ctx);
	__GC_MV(this, &(this->oids), ArrayAllocatorPrimitive<long long>::allocatep(ctx, maxLoop), IArrayObjectPrimitive<long long>);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->oids->set(list->get(i, ctx)->getOid(ctx),i, ctx);
	}
}
void ScannedOids::Oids::__construct_impl(ScanResultRecord* record, ThreadContext* ctx) throw() 
{
	ArrayList<IDatabaseRecord>* list = record->getRecords(ctx);
	int maxLoop = list->size(ctx);
	__GC_MV(this, &(this->oids), ArrayAllocatorPrimitive<long long>::allocatep(ctx, maxLoop), IArrayObjectPrimitive<long long>);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->oids->set(list->get(i, ctx)->getOid(ctx),i, ctx);
	}
}
 ScannedOids::Oids::~Oids() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannedOids::Oids::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Oids", L"~Oids");
	__e_obj1.add(this->oids, this);
	oids = nullptr;
	if(!prepare){
		return;
	}
}
bool ScannedOids::Oids::equals(IObject* other, ThreadContext* ctx) throw() 
{
	ScannedOids::Oids* otherOids = dynamic_cast<ScannedOids::Oids*>(other);
	if(this->oids->length != otherOids->oids->length)
	{
		return false;
	}
	int maxLoop = this->oids->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		if(this->oids->get(i) != otherOids->oids->get(i))
		{
			return false;
		}
	}
	return true;
}
long long ScannedOids::Oids::getHash(ThreadContext* ctx) throw() 
{
	int maxLoop = this->oids->length;
	long long hash = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		hash = hash | this->oids->get(i);
	}
	return hash;
}
}}}}

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScannedOids::OidsArray::__init_done = __init_static_variables();
bool ScannedOids::OidsArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScannedOids::OidsArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScannedOids::OidsArray::~OidsArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScannedOids::OidsArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"OidsArray", L"~OidsArray");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void ScannedOids::OidsArray::addOid(ScannedOids::Oids* oid, ThreadContext* ctx) throw() 
{
	this->list->add(oid, ctx);
}
bool ScannedOids::OidsArray::contains(ScannedOids::Oids* oid, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScannedOids::Oids* lobj = this->list->get(i, ctx);
		if(lobj->equals(oid, ctx))
		{
			return true;
		}
	}
	return false;
}
}}}}

