#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUECHECKOPERATION_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUECHECKOPERATION_H_
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



class UniqueCheckOperation final : public virtual IObject {
public:
	UniqueCheckOperation(const UniqueCheckOperation& base) = default;
public:
	UniqueCheckOperation(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~UniqueCheckOperation() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUECHECKOPERATION_H_ */
