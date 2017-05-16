#ifndef ALINOUS_REMOTE_REGION_CLIENT_SCAN_RESULTHOLDER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_SCAN_RESULTHOLDER_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::List;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;



class ResultHolder final : public virtual IObject {
public:
	ResultHolder(const ResultHolder& base) = default;
public:
	ResultHolder(List<ClientNetworkRecord>* resultList, ThreadContext* ctx) throw() ;
	void __construct_impl(List<ClientNetworkRecord>* resultList, ThreadContext* ctx) throw() ;
	virtual ~ResultHolder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<ClientNetworkRecord>* resultList;
	int index;
public:
	ClientNetworkRecord* getNextRecord(ThreadContext* ctx) throw() ;
	bool hasNext(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_SCAN_RESULTHOLDER_H_ */
