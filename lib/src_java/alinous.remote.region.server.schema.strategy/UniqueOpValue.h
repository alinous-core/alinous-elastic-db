#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUEOPVALUE_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUEOPVALUE_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueOpValue;}}}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class NetworkAlinousVariableFactory;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::NetworkAlinousVariableFactory;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;



class UniqueOpValue final : public ICommandData, public virtual IObject {
public:
	UniqueOpValue(const UniqueOpValue& base) = default;
public:
	UniqueOpValue(List<VariantValue>* values, ThreadContext* ctx) throw() ;
	void __construct_impl(List<VariantValue>* values, ThreadContext* ctx) throw() ;
	virtual ~UniqueOpValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<VariantValue>* values;
public:
	List<VariantValue>* getValues(ThreadContext* ctx) throw() ;
	String* getLockStr(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static UniqueOpValue* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUEOPVALUE_H_ */
