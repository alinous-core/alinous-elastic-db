#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_
namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {namespace table {
class TableMetadataUnique;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableMetadataUnique;
using ::alinous::db::table::TablePartitionKey;



class ScanUnique final : public TableMetadataUnique {
public:
	ScanUnique(const ScanUnique& base) = default;
public:
	ScanUnique(ThreadContext* ctx) throw()  : IObject(ctx), TableMetadataUnique(ctx), coveredKey(nullptr), matchLength(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ScanUnique() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TablePartitionKey* coveredKey;
	int matchLength;
public:
	TablePartitionKey* getCoveredKey(ThreadContext* ctx) throw() ;
	void setCoveredKey(TablePartitionKey* coveredKey, ThreadContext* ctx) throw() ;
	bool isCovered(ThreadContext* ctx) throw() ;
	int getMatchLength(ThreadContext* ctx) throw() ;
	void calcCoverage(TablePartitionKey* key, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANUNIQUE_H_ */
