#ifndef ALINOUS_RUNTIME_VARIANT_VARIANTDATAFACTORY_H_
#define ALINOUS_RUNTIME_VARIANT_VARIANTDATAFACTORY_H_
namespace alinous {namespace runtime {namespace variant {
class IVariantData;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace variant {
class StringData;}}}

namespace alinous {namespace runtime {namespace variant {
class LongData;}}}

namespace alinous {namespace runtime {namespace variant {
class IntData;}}}

namespace alinous {namespace runtime {namespace variant {
class ShortData;}}}

namespace alinous {namespace runtime {namespace variant {
class CharData;}}}

namespace alinous {namespace runtime {namespace variant {
class ByteData;}}}

namespace alinous {namespace runtime {namespace variant {
class FloatData;}}}

namespace alinous {namespace runtime {namespace variant {
class DoubleData;}}}

namespace alinous {namespace runtime {namespace variant {
class BigDecimalData;}}}

namespace alinous {namespace runtime {namespace variant {
class TimeData;}}}

namespace alinous {namespace runtime {namespace variant {
class TimestampData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace variant {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class VariantDataFactory final : public virtual IObject {
public:
	VariantDataFactory(const VariantDataFactory& base) = default;
public:
	VariantDataFactory(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~VariantDataFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IVariantData* fromNetworkData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_VARIANT_VARIANTDATAFACTORY_H_ */
