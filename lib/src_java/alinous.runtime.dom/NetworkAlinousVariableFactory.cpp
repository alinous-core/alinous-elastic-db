#include "includes.h"


namespace alinous {namespace runtime {namespace dom {





bool NetworkAlinousVariableFactory::__init_done = __init_static_variables();
bool NetworkAlinousVariableFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NetworkAlinousVariableFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NetworkAlinousVariableFactory::~NetworkAlinousVariableFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NetworkAlinousVariableFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* NetworkAlinousVariableFactory::fromNetworkData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	IAlinousVariable* val = nullptr;
	int type = buff->getInt(ctx);
	switch(type) {
	case ICommandData::__IdentifierVariable:
		val = (new(ctx) IdentifierVariable(ctx));
		break ;
	case ICommandData::__VariantValue:
		val = (new(ctx) VariantValue(ctx));
		break ;
	case ICommandData::__DocumentVariable:
		val = (new(ctx) DocumentVariable(ctx));
		break ;
	case ICommandData::__DomArray:
		val = (new(ctx) DomArray(ctx));
		break ;
	case ICommandData::__DomVariable:
		val = (new(ctx) DomVariable(ctx));
		break ;
	case ICommandData::__BigDecimalVariable:
		val = (new(ctx) BigDecimalVariable(ctx));
		break ;
	case ICommandData::__BoolVariable:
		val = (new(ctx) BoolVariable(ctx));
		break ;
	case ICommandData::__ByteVariable:
		val = (new(ctx) ByteVariable(ctx));
		break ;
	case ICommandData::__CharVariable:
		val = (new(ctx) CharVariable(ctx));
		break ;
	case ICommandData::__DoubleVariable:
		val = (new(ctx) DoubleVariable(ctx));
		break ;
	case ICommandData::__FloatVariable:
		val = (new(ctx) FloatVariable(ctx));
		break ;
	case ICommandData::__IntegerVariable:
		val = (new(ctx) IntegerVariable(ctx));
		break ;
	case ICommandData::__LongVariable:
		val = (new(ctx) LongVariable(ctx));
		break ;
	case ICommandData::__ShortVariable:
		val = (new(ctx) ShortVariable(ctx));
		break ;
	case ICommandData::__StringVariable:
		val = (new(ctx) StringVariable(ctx));
		break ;
	case ICommandData::__TimestampVariable:
		val = (new(ctx) TimestampVariable(ctx));
		break ;
	case ICommandData::__TimeVariable:
		val = (new(ctx) TimeVariable(ctx));
		break ;
	case ICommandData::__TypedVariableArray:
		val = (new(ctx) TypedVariableArray(ctx));
		break ;
	case ICommandData::__AlinousClassVariable:
		val = (new(ctx) AlinousClassVariable(ctx));
		break ;
	default:
		return nullptr;
		break;
	}
	return val;
}
}}}

