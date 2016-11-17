#include "includes.h"


namespace alinous {namespace btree {





bool BTreeValues::__init_done = __init_static_variables();
bool BTreeValues::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeValues", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeValues::~BTreeValues() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeValues::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeValues", L"~BTreeValues");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void BTreeValues::addValue(IBTreeValue* value, ThreadContext* ctx) throw() 
{
	this->values->add(value, ctx);
}
bool BTreeValues::contains(IBTreeValue* value, ThreadContext* ctx) throw() 
{
	ArrayList<IBTreeValue>* values = this->values;
	int maxLoop = values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(values->get(i, ctx)->equals(value, ctx))
		{
			return true;
		}
	}
	return false;
}
void BTreeValues::remove(IBTreeValue* value, ThreadContext* ctx) throw() 
{
	this->values->remove(value, ctx);
}
void BTreeValues::clearValues(ThreadContext* ctx) throw() 
{
	this->values->clear(ctx);
}
IBTreeValue* BTreeValues::get(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
int BTreeValues::numValues(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
int BTreeValues::size(ThreadContext* ctx)
{
	int total = 4;
	Iterator<IBTreeValue>* it = this->values->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IBTreeValue* val = it->next(ctx);
		total += val->diskSize(ctx);
	}
	return total;
}
void BTreeValues::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	ArrayList<IBTreeValue>* values = this->values;
	int maxLoop = values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* val = values->get(i, ctx);
		val->appendToEntry(builder, ctx);
	}
}
ArrayList<IBTreeValue>* BTreeValues::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
}}

