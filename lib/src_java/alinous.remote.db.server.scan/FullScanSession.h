#ifndef ALINOUS_REMOTE_DB_SERVER_SCAN_FULLSCANSESSION_H_
#define ALINOUS_REMOTE_DB_SERVER_SCAN_FULLSCANSESSION_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class AbstractStorageScanSession;}}}}}

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



class FullScanSession final : public AbstractStorageScanSession {
public:
	FullScanSession(const FullScanSession& base) = default;
public:
	FullScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	virtual ~FullScanSession() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ScanWorkerResult* scan(ThreadContext* ctx) throw()  final;
	void init(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_SCAN_FULLSCANSESSION_H_ */
