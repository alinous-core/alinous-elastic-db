#ifndef ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_
#define ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class RemoteTableStorageServer final : public virtual IObject {
public:
	RemoteTableStorageServer(const RemoteTableStorageServer& base) = default;
public:
	RemoteTableStorageServer(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RemoteTableStorageServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_DB_REMOTETABLESTORAGESERVER_H_ */
