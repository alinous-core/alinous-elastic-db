#ifndef ALINOUS_REMOTE_REGION_CLIENT_STORAGENODEREGIONCLIENT_H_
#define ALINOUS_REMOTE_REGION_CLIENT_STORAGENODEREGIONCLIENT_H_
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



class StorageNodeRegionClient final : public virtual IObject {
public:
	StorageNodeRegionClient(const StorageNodeRegionClient& base) = default;
public:
	StorageNodeRegionClient(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~StorageNodeRegionClient() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_STORAGENODEREGIONCLIENT_H_ */
