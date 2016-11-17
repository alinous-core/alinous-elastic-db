#ifndef ALINOUS_DB_TABLE_SCAN_INDEXRANGESCANNERPARAM_H_
#define ALINOUS_DB_TABLE_SCAN_INDEXRANGESCANNERPARAM_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

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



class IndexRangeScannerParam final : public virtual IObject {
public:
	IndexRangeScannerParam(const IndexRangeScannerParam& base) = default;
public:
	IndexRangeScannerParam(ThreadContext* ctx) throw()  : IObject(ctx), start(nullptr), startEq(0), end(nullptr), endEq(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
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
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_INDEXRANGESCANNERPARAM_H_ */
