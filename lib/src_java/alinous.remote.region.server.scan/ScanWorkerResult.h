#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_SCANWORKERRESULT_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_SCANWORKERRESULT_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class ScanWorkerResult final : public ICommandData, public virtual IObject {
public:
	ScanWorkerResult(const ScanWorkerResult& base) = default;
public:
	ScanWorkerResult(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ScanWorkerResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool finished;
	List<ClientNetworkRecord>* records;
public:
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	bool isFinished(ThreadContext* ctx) throw() ;
	void setFinished(bool finished, ThreadContext* ctx) throw() ;
	void setRecords(List<ClientNetworkRecord>* records, ThreadContext* ctx) throw() ;
	List<ClientNetworkRecord>* getRecords(ThreadContext* ctx) throw() ;
	void addRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() ;
public:
	static ScanWorkerResult* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_SCANWORKERRESULT_H_ */
