#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEINDEXMETADATA_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEINDEXMETADATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnMetadata;}}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIndexMetadata;}}}}

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



class ScanTableIndexMetadata final : public virtual IObject {
public:
	ScanTableIndexMetadata(const ScanTableIndexMetadata& base) = default;
public:
	ScanTableIndexMetadata(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableIdentifier* tableId, ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw() ;
	virtual ~ScanTableIndexMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ScanTableIdentifier* tableId;
	ArrayList<ScanTableColumnMetadata>* columns;
public:
	String* toString(ThreadContext* ctx) throw() ;
	void setColumns(ArrayList<ScanTableColumnMetadata>* columns, ThreadContext* ctx) throw() ;
	ArrayList<ScanTableColumnMetadata>* getColumns(ThreadContext* ctx) throw() ;
	ArrayList<String>* getColumnsStr(ThreadContext* ctx) throw() ;
	ArrayList<ScanTableColumnIdentifier>* getColumnIds(ThreadContext* ctx) throw() ;
	bool hasColumnsWithoutOrder(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	bool hasColumn(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() ;
	ScanTableIndexMetadata* copy(ThreadContext* ctx) throw() ;
	ScanTableIdentifier* getTableId(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLEINDEXMETADATA_H_ */
