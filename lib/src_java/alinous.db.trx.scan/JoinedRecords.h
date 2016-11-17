#ifndef ALINOUS_DB_TRX_SCAN_JOINEDRECORDS_H_
#define ALINOUS_DB_TRX_SCAN_JOINEDRECORDS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class JoinedRecords;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::runtime::dom::VariableException;



class JoinedRecords final : public virtual IObject {
public:
	JoinedRecords(const JoinedRecords& base) = default;
public:
	JoinedRecords(ThreadContext* ctx) throw()  : IObject(ctx), oid(0), lockingMode(0), tableId(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	JoinedRecords(ScanTableIdentifier* tableId, long long oid, int lockingMode, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableIdentifier* tableId, long long oid, int lockingMode, ThreadContext* ctx) throw() ;
	virtual ~JoinedRecords() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long oid;
	int lockingMode;
	ScanTableIdentifier* tableId;
public:
	JoinedRecords* copy(ThreadContext* ctx) throw() ;
	int getArchiveSize(ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	long long getOid(ThreadContext* ctx) throw() ;
	void setOid(long long oid, ThreadContext* ctx) throw() ;
	int getLockingMode(ThreadContext* ctx) throw() ;
	void setLockingMode(int lockingMode, ThreadContext* ctx) throw() ;
	ScanTableIdentifier* getTableId(ThreadContext* ctx) throw() ;
public:
	static JoinedRecords* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_JOINEDRECORDS_H_ */
