#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUEOPVALUE_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUEOPVALUE_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

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
using ::java::util::List;
using ::alinous::runtime::variant::VariantValue;



class UniqueOpValue final : public virtual IObject {
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
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUEOPVALUE_H_ */
