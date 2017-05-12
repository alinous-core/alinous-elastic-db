#ifndef ALINOUS_REMOTE_REGION_CLIENT_TABLEACCESSSTATUS_H_
#define ALINOUS_REMOTE_REGION_CLIENT_TABLEACCESSSTATUS_H_
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



class TableAccessStatus final : public virtual IObject {
public:
	TableAccessStatus(const TableAccessStatus& base) = default;
public:
	TableAccessStatus(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableAccessStatus() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int status;
public:
	constexpr static const int STAT_COMMITTED_DONE{0};
	constexpr static const int STAT_COMMITTED_NEEDED{1};
public:
	int getStatus(ThreadContext* ctx) throw() ;
	void setStatus(int status, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_TABLEACCESSSTATUS_H_ */
