#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DML_CLIENTSCANCOMMAND_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DML_CLIENTSCANCOMMAND_H_
namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionServer;}}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScannerParam;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexRangeScannerParam;}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class AbstractNodeRegionCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::util::ArrayList;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::scan::IndexListScannerParam;
using ::alinous::db::table::scan::IndexRangeScannerParam;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::remote::region::client::command::AbstractNodeRegionCommand;
using ::alinous::remote::region::server::NodeRegionServer;
using ::alinous::remote::region::server::scan::ScanWorkerResult;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class ClientScanCommand final : public AbstractNodeRegionCommand {
public:
	ClientScanCommand(const ClientScanCommand& base) = default;
public:
	ClientScanCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ClientScanCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ClientScanCommandData* data;
	ScanWorkerResult* result;
public:
	void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	DbVersionContext* getVctx(ThreadContext* ctx) throw() ;
	void setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	TableAndSchema* getTable(ThreadContext* ctx) throw() ;
	void setTable(TableAndSchema* table, ThreadContext* ctx) throw() ;
	int getLockMode(ThreadContext* ctx) throw() ;
	void setLockMode(int lockMode, ThreadContext* ctx) throw() ;
	bool isPrimaryIndex(ThreadContext* ctx) throw() ;
	void setPrimaryIndex(bool primaryIndex, ThreadContext* ctx) throw() ;
	bool isFullscan(ThreadContext* ctx) throw() ;
	void setFullscan(bool fullscan, ThreadContext* ctx) throw() ;
	ArrayList<TableColumnMetadata>* getIndexColmns(ThreadContext* ctx) throw() ;
	void setIndexColmns(ArrayList<TableColumnMetadata>* indexColmns, ThreadContext* ctx) throw() ;
	ISQLExpression* getExp(ThreadContext* ctx) throw() ;
	void setExp(ISQLExpression* exp, ThreadContext* ctx) throw() ;
	IndexListScannerParam* getListParam(ThreadContext* ctx) throw() ;
	void setListParam(IndexListScannerParam* listParam, ThreadContext* ctx) throw() ;
	ScanResultIndexKey* getEqKey(ThreadContext* ctx) throw() ;
	void setEqKey(ScanResultIndexKey* eqKey, ThreadContext* ctx) throw() ;
	IndexRangeScannerParam* getRangeParam(ThreadContext* ctx) throw() ;
	void setRangeParam(IndexRangeScannerParam* rangeParam, ThreadContext* ctx) throw() ;
	ScanWorkerResult* getResult(ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* outStream, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DML_CLIENTSCANCOMMAND_H_ */
