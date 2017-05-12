#ifndef ALINOUS_REMOTE_DB_SERVER_SCAN_FULLSCANSESSION_H_
#define ALINOUS_REMOTE_DB_SERVER_SCAN_FULLSCANSESSION_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace db {namespace table {
class TableIndexValue;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class AbstractStorageScanSession;}}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexScannerLockRequirement;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableIndexValue;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::scan::ScanWorkerResult;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class FullScanSession final : public AbstractStorageScanSession {
public:
	FullScanSession(const FullScanSession& base) = default;
public:
	FullScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	virtual ~FullScanSession() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	BTreeScanner* scanner;
	int lockMode;
	ArrayList<IBTreeValue>* values;
	int current;
public:
	void init(ThreadContext* ctx) final;
	ScanWorkerResult* scan(ThreadContext* ctx) final;
private:
	bool loadNextRecord(ScanWorkerResult* result, ThreadContext* ctx);
	IDatabaseRecord* loadFromStorage(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_SCAN_FULLSCANSESSION_H_ */
