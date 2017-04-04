#ifndef ALINOUS_REMOTE_MONITOR_TABLEOIDHOLDER_H_
#define ALINOUS_REMOTE_MONITOR_TABLEOIDHOLDER_H_
namespace alinous {namespace remote {namespace monitor {
class OidHolder;}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::lock::LockObject;



class TableOidHolder final : public virtual IObject {
public:
	TableOidHolder(const TableOidHolder& base) = default;
public:
	TableOidHolder(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableOidHolder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,OidHolder>* tableOids;
	LockObject* lock;
public:
	void setNextOid(String* tableFullName, long long nextOid, ThreadContext* ctx) throw() ;
	long long getNextOid(String* tableFullName, int length, ThreadContext* ctx) throw() ;
	void syncNextOid(String* tableFullName, long long nextOid, ThreadContext* ctx) throw() ;
private:
	OidHolder* getOidHolder(String* tableFullName, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_TABLEOIDHOLDER_H_ */
