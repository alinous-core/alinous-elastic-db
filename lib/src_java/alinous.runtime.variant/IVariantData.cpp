#include "include/global.h"


#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/IVariantData.h"
#include "alinous.runtime.variant/StringData.h"
#include "alinous.runtime.variant/LongData.h"
#include "alinous.runtime.variant/IntData.h"
#include "alinous.runtime.variant/ShortData.h"
#include "alinous.runtime.variant/ByteData.h"
#include "alinous.runtime.variant/FloatData.h"
#include "alinous.runtime.variant/DoubleData.h"
#include "alinous.runtime.variant/BigDecimalData.h"
#include "alinous.runtime.variant/TimeData.h"
#include "alinous.runtime.variant/TimestampData.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.variant/CharData.h"
#include "alinous.runtime.variant/VariantDataFactory.h"

namespace alinous {namespace runtime {namespace variant {




constexpr const int IVariantData::TYPE_STRING;
constexpr const int IVariantData::TYPE_LONG;
constexpr const int IVariantData::TYPE_INT;
constexpr const int IVariantData::TYPE_SHORT;
constexpr const int IVariantData::TYPE_CHAR;
constexpr const int IVariantData::TYPE_BYTE;
constexpr const int IVariantData::TYPE_FLOAT;
constexpr const int IVariantData::TYPE_DOUBLE;
constexpr const int IVariantData::TYPE_BOOL;
constexpr const int IVariantData::TYPE_BIG_DECIMAL;
constexpr const int IVariantData::TYPE_TIME;
constexpr const int IVariantData::TYPE_TIMESTAMP;
constexpr const int IVariantData::TYPE_NULL;
String* IVariantData::ATTR_VALUE = ConstStr::getCNST_STR_1159();
bool IVariantData::__init_done = __init_static_variables();
bool IVariantData::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IVariantData", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IVariantData::IVariantData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx)
{
}
void IVariantData::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IVariantData::~IVariantData() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IVariantData::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ICommandData::__releaseRegerences(true, ctx);
}
void IVariantData::__cleanUp(ThreadContext* ctx){
}
}}}

