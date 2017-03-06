#ifndef ALINOUS_RUNTIME_DOM_NETWORKALINOUSVARIABLEFACTORY_H_
#define ALINOUS_RUNTIME_DOM_NETWORKALINOUSVARIABLEFACTORY_H_
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class IdentifierVariable;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace runtime {namespace dom {
class DocumentVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class DomArray;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BigDecimalVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BoolVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ByteVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class CharVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class DoubleVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class FloatVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class IntegerVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class LongVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ShortVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class StringVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimestampVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimeVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::expression::expstream::IdentifierVariable;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::dom::typed::BigDecimalVariable;
using ::alinous::runtime::dom::typed::BoolVariable;
using ::alinous::runtime::dom::typed::ByteVariable;
using ::alinous::runtime::dom::typed::CharVariable;
using ::alinous::runtime::dom::typed::DoubleVariable;
using ::alinous::runtime::dom::typed::FloatVariable;
using ::alinous::runtime::dom::typed::IntegerVariable;
using ::alinous::runtime::dom::typed::LongVariable;
using ::alinous::runtime::dom::typed::ShortVariable;
using ::alinous::runtime::dom::typed::StringVariable;
using ::alinous::runtime::dom::typed::TimeVariable;
using ::alinous::runtime::dom::typed::TimestampVariable;
using ::alinous::runtime::dom::typed::TypedVariableArray;
using ::alinous::runtime::variant::VariantValue;



class NetworkAlinousVariableFactory final : public virtual IObject {
public:
	NetworkAlinousVariableFactory(const NetworkAlinousVariableFactory& base) = default;
public:
	NetworkAlinousVariableFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~NetworkAlinousVariableFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IAlinousVariable* fromNetworkData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_NETWORKALINOUSVARIABLEFACTORY_H_ */
