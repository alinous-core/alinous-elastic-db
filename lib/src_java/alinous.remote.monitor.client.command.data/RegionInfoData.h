#ifndef ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_DATA_REGIONINFODATA_H_
#define ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_DATA_REGIONINFODATA_H_
namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::remote::monitor::RegionNodeInfo;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;



class RegionInfoData final : public ICommandData, public virtual IObject {
public:
	RegionInfoData(const RegionInfoData& base) = default;
public:
	RegionInfoData(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RegionInfoData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	RegionNodeInfo* nodeInfo;
public:
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	RegionNodeInfo* getNodeInfo(ThreadContext* ctx) throw() ;
	void setNodeInfo(RegionNodeInfo* nodeInfo, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_DATA_REGIONINFODATA_H_ */
