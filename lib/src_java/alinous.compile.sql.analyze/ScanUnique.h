#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_
namespace alinous {namespace db {namespace table {
class TableMetadataUnique;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::TableMetadataUnique;



class ScanUnique final : public TableMetadataUnique {
public:
	ScanUnique(const ScanUnique& base) = default;
public:
	ScanUnique(ThreadContext* ctx) throw()  : IObject(ctx), TableMetadataUnique(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ScanUnique() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_ */
