#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.remote.region.server.schema.strategy/UniqueOpValue.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool UniqueOpValue::__init_done = __init_static_variables();
bool UniqueOpValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueOpValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueOpValue::UniqueOpValue(List<VariantValue>* values, ThreadContext* ctx) throw()  : IObject(ctx), values(nullptr)
{
	GCUtils<List<VariantValue> >::mv(this, &(this->values), values, ctx);
}
void UniqueOpValue::__construct_impl(List<VariantValue>* values, ThreadContext* ctx) throw() 
{
	GCUtils<List<VariantValue> >::mv(this, &(this->values), values, ctx);
}
 UniqueOpValue::~UniqueOpValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueOpValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueOpValue", L"~UniqueOpValue");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
List<VariantValue>* UniqueOpValue::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
void UniqueOpValue::__cleanUp(ThreadContext* ctx){
}
}}}}}}

