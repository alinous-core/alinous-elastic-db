#include "includes.h"


namespace alinous {namespace lock {namespace unique {





bool ValueCollections::__init_done = __init_static_variables();
bool ValueCollections::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ValueCollections", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ValueCollections::ValueCollections(IDatabaseRecord* value, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), value, IDatabaseRecord);
}
void ValueCollections::__construct_impl(IDatabaseRecord* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, IDatabaseRecord);
}
 ValueCollections::~ValueCollections() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ValueCollections::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ValueCollections", L"~ValueCollections");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
int ValueCollections::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	ValueCollections* col = static_cast<ValueCollections*>(another);
	return 0;
}
void ValueCollections::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
}
int ValueCollections::size(ThreadContext* ctx)
{
	return 0;
}
int ValueCollections::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}}

