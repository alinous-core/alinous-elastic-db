#ifndef ALINOUS_COMPILE_SQL_ANALYZE_TABLEMETADATAUNIQUECOLLECTION_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_TABLEMETADATAUNIQUECOLLECTION_H_
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace analyze {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;



class TableMetadataUniqueCollection final : public virtual IObject {
public:
	TableMetadataUniqueCollection(const TableMetadataUniqueCollection& base) = default;
public:
	TableMetadataUniqueCollection(ThreadContext* ctx) throw()  : IObject(ctx), uniqueList(GCUtils<ArrayList<ScanUnique> >::ins(this, (new(ctx) ArrayList<ScanUnique>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableMetadataUniqueCollection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ScanUnique>* uniqueList;
public:
	void addUnique(ScanUnique* unique, ThreadContext* ctx) throw() ;
	ArrayList<ScanUnique>* getUniqueList(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_TABLEMETADATAUNIQUECOLLECTION_H_ */
