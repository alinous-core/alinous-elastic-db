#ifndef ALINOUS_REMOTE_REGION_CLIENT_TABLEACCESSSTATUSLISTNER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_TABLEACCESSSTATUSLISTNER_H_
namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace remote {namespace region {namespace client {
class TableAccessStatus;}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;



class TableAccessStatusListner final : public virtual IObject {
public:
	TableAccessStatusListner(const TableAccessStatusListner& base) = default;
public:
	TableAccessStatusListner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableAccessStatusListner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,TableAccessStatus>* stats;
public:
	void setStatus(String* schemaName, String* TableName, int status, ThreadContext* ctx) throw() ;
	void setStatus(String* fullName, int status, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_TABLEACCESSSTATUSLISTNER_H_ */
