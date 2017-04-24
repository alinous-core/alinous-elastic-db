#ifndef ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNERPARAM_H_
#define ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNERPARAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScannerParam;}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

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

namespace alinous {namespace db {namespace table {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class IndexListScannerParam final : public ICommandData, public virtual IObject {
public:
	IndexListScannerParam(const IndexListScannerParam& base) = default;
public:
	IndexListScannerParam(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IndexListScannerParam() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ScanResultIndexKey>* list;
	int current;
public:
	void addIndexKey(ScanResultIndexKey* key, ThreadContext* ctx) throw() ;
	ArrayList<ScanResultIndexKey>* getList(ThreadContext* ctx) throw() ;
	bool hasNext(ThreadContext* ctx) throw() ;
	ScanResultIndexKey* nextKey(ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static IndexListScannerParam* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNERPARAM_H_ */
