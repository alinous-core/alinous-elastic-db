#include "includes.h"


namespace alinous {namespace runtime {namespace variant {





bool VariantDataFactory::__init_done = __init_static_variables();
bool VariantDataFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariantDataFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariantDataFactory::~VariantDataFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariantDataFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IVariantData* VariantDataFactory::fromNetworkData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	IVariantData* data = nullptr;
	int type = buff->getInt(ctx);
	switch(type) {
	case IVariantData::TYPE_STRING:
		data = (new(ctx) StringData(ctx));
		break ;
	case IVariantData::TYPE_LONG:
		data = (new(ctx) LongData(ctx));
		break ;
	case IVariantData::TYPE_INT:
		data = (new(ctx) IntData(ctx));
		break ;
	case IVariantData::TYPE_SHORT:
		data = (new(ctx) ShortData(ctx));
		break ;
	case IVariantData::TYPE_CHAR:
		data = (new(ctx) CharData(ctx));
		break ;
	case IVariantData::TYPE_BYTE:
		data = (new(ctx) ByteData(ctx));
		break ;
	case IVariantData::TYPE_FLOAT:
		data = (new(ctx) FloatData(ctx));
		break ;
	case IVariantData::TYPE_DOUBLE:
		data = (new(ctx) DoubleData(ctx));
		break ;
	case IVariantData::TYPE_BIG_DECIMAL:
		data = (new(ctx) BigDecimalData(ctx));
		break ;
	case IVariantData::TYPE_TIME:
		data = (new(ctx) TimeData(ctx));
		break ;
	case IVariantData::TYPE_TIMESTAMP:
		data = (new(ctx) TimestampData(ctx));
		break ;
	case IVariantData::TYPE_BOOL:
	case IVariantData::TYPE_NULL:
	default:
		return nullptr;
		break;
	}
	data->readData(buff, ctx);
	return data;
}
}}}

