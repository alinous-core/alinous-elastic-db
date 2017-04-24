#ifndef ALINOUS_DB_TABLE_SCAN_INDEXRANGESCANNERPARAM_H_
#define ALINOUS_DB_TABLE_SCAN_INDEXRANGESCANNERPARAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexRangeScannerParam;}}}}

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
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class IndexRangeScannerParam final : public ICommandData, public virtual IObject {
public:
	IndexRangeScannerParam(const IndexRangeScannerParam& base) = default;
public:
	IndexRangeScannerParam(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IndexRangeScannerParam() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ScanResultIndexKey* start;
	bool startEq;
	ScanResultIndexKey* end;
	bool endEq;
public:
	ScanResultIndexKey* getStart(ThreadContext* ctx) throw() ;
	void setStart(ScanResultIndexKey* start, ThreadContext* ctx) throw() ;
	bool isStartEq(ThreadContext* ctx) throw() ;
	void setStartEq(bool startEq, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static IndexRangeScannerParam* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_INDEXRANGESCANNERPARAM_H_ */
