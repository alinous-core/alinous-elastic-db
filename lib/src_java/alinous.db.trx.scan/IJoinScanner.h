#ifndef ALINOUS_DB_TRX_SCAN_IJOINSCANNER_H_
#define ALINOUS_DB_TRX_SCAN_IJOINSCANNER_H_
namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IJoinScanner : public virtual IObject, public ITableTargetScanner {
public:
	IJoinScanner(const IJoinScanner& base) = default;
public:
	IJoinScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IJoinScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_IJOINSCANNER_H_ */
