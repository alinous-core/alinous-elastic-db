#ifndef ALINOUS_DB_TABLE_SCAN_INDEXSCANNERLOCKREQUIREMENT_H_
#define ALINOUS_DB_TABLE_SCAN_INDEXSCANNERLOCKREQUIREMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
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



class IndexScannerLockRequirement : public virtual IObject {
public:
	IndexScannerLockRequirement(const IndexScannerLockRequirement& base) = default;
public:
	IndexScannerLockRequirement(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IndexScannerLockRequirement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int NO_LOCK{0};
	constexpr static const int INSTANT_SHARE{1};
	constexpr static const int EXPLICIT_SHARE{2};
	constexpr static const int INSTANT_UPDATE{3};
	constexpr static const int EXPLICIT_UPDATE{4};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_INDEXSCANNERLOCKREQUIREMENT_H_ */
