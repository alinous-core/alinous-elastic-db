#ifndef ALINOUS_REMOTE_DB_CLIENT_REMOTETABLESTORAGECLIENT_H_
#define ALINOUS_REMOTE_DB_CLIENT_REMOTETABLESTORAGECLIENT_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class RemoteTableStorageClient final : public virtual IObject {
public:
	RemoteTableStorageClient(const RemoteTableStorageClient& base) = default;
public:
	RemoteTableStorageClient(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RemoteTableStorageClient() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_REMOTETABLESTORAGECLIENT_H_ */
