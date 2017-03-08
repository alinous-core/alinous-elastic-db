#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"
#include "alinous.runtime.function/AbstractNativeFunction.h"

namespace alinous {namespace runtime {namespace function {





bool AbstractNativeFunction::__init_done = __init_static_variables();
bool AbstractNativeFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractNativeFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractNativeFunction::AbstractNativeFunction(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousNativeFunction(ctx), prefix(nullptr), name(nullptr), argumentMetadata(GCUtils<ArrayList<AlinousType> >::ins(this, (new(ctx) ArrayList<AlinousType>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void AbstractNativeFunction::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractNativeFunction::~AbstractNativeFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractNativeFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractNativeFunction", L"~AbstractNativeFunction");
	__e_obj1.add(this->prefix, this);
	prefix = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->argumentMetadata, this);
	argumentMetadata = nullptr;
	if(!prepare){
		return;
	}
}
ArrayList<AlinousType>* AbstractNativeFunction::getArgumentMetadata(ThreadContext* ctx) throw() 
{
	return this->argumentMetadata;
}
String* AbstractNativeFunction::getPrefix(ThreadContext* ctx) throw() 
{
	return prefix;
}
String* AbstractNativeFunction::getName(ThreadContext* ctx) throw() 
{
	return name;
}
AlinousType* AbstractNativeFunction::makeDomType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeByteType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::BYTE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeShortType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::SHORT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeCharType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::CHAR_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeIntType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::INT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeLongType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::LONG_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeFloatType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::FLOAT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeDoubleType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::DOUBLE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeStringType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::STRING_TYPE, AlinousType::TYPE_STANDARD_OBJ, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeTimeType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::TIME, AlinousType::TYPE_STANDARD_OBJ, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeTimestampType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::TIMESTAMP, AlinousType::TYPE_STANDARD_OBJ, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeBigDecimalType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::BIGDECIMAL, AlinousType::TYPE_STANDARD_OBJ, ctx));
	return type;
}
AlinousType* AbstractNativeFunction::makeVoidType(ThreadContext* ctx) throw() 
{
	AlinousType* type = (new(ctx) AlinousType(AlinousType::NULL_TYPE, AlinousType::TYPE_VOID, ctx));
	return type;
}
void AbstractNativeFunction::__cleanUp(ThreadContext* ctx){
}
}}}

