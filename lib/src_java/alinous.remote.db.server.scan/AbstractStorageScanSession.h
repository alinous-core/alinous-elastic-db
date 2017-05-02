#ifndef ALINOUS_REMOTE_DB_SERVER_SCAN_ABSTRACTSTORAGESCANSESSION_H_
#define ALINOUS_REMOTE_DB_SERVER_SCAN_ABSTRACTSTORAGESCANSESSION_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::scan::ScanWorkerResult;



class AbstractStorageScanSession : public virtual IObject {
public:
	AbstractStorageScanSession(const AbstractStorageScanSession& base) = default;
public:
	AbstractStorageScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	virtual ~AbstractStorageScanSession() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IDatabaseTable* table;
	ClientScanCommandData* data;
public:
	virtual void init(ThreadContext* ctx) throw()  = 0;
	virtual ScanWorkerResult* scan(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_SCAN_ABSTRACTSTORAGESCANSESSION_H_ */
