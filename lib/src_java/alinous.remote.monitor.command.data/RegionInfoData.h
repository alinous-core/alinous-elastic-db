#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_DATA_REGIONINFODATA_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_DATA_REGIONINFODATA_H_
namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::remote::monitor::RegionNodeInfo;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;



class RegionInfoData final : public ICommandData, public virtual IObject {
public:
	RegionInfoData(const RegionInfoData& base) = default;
public:
	RegionInfoData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), regionsMap(GCUtils<Map<String,RegionNodeInfo> >::ins(this, (new(ctx) HashMap<String,RegionNodeInfo>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RegionInfoData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,RegionNodeInfo>* regionsMap;
public:
	void putNodeInfo(String* key, RegionNodeInfo* info, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_DATA_REGIONINFODATA_H_ */
