#ifndef ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNERPARAM_H_
#define ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNERPARAM_H_
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
using ::java::util::ArrayList;
using ::alinous::db::trx::scan::ScanResultIndexKey;



class IndexListScannerParam final : public virtual IObject {
public:
	IndexListScannerParam(const IndexListScannerParam& base) = default;
public:
	IndexListScannerParam(ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<ScanResultIndexKey> >::ins(this, (new(ctx) ArrayList<ScanResultIndexKey>(ctx)), ctx, __FILEW__, __LINE__, L"")), current(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
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
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_INDEXLISTSCANNERPARAM_H_ */
