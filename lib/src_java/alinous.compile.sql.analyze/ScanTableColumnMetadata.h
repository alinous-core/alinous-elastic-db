#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLECOLUMNMETADATA_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLECOLUMNMETADATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnMetadata;}}}}

namespace java {namespace lang {
class StringBuffer;}}

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



class ScanTableColumnMetadata final : public virtual IObject {
public:
	ScanTableColumnMetadata(const ScanTableColumnMetadata& base) = default;
public:
	ScanTableColumnMetadata(ScanTableIdentifier* table, String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableIdentifier* table, String* name, ThreadContext* ctx) throw() ;
	virtual ~ScanTableColumnMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ScanTableIdentifier* table;
	String* name;
	ScanTableColumnIdentifier* columnIdentifier;
public:
	String* getName(ThreadContext* ctx) throw() ;
	bool matchIdentigier(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() ;
	ScanTableColumnIdentifier* getColumnIdentifier(ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLECOLUMNMETADATA_H_ */
