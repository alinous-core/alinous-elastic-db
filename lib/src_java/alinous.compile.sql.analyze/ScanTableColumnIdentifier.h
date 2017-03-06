#ifndef ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLECOLUMNIDENTIFIER_H_
#define ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLECOLUMNIDENTIFIER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

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



class ScanTableColumnIdentifier final : public virtual IObject {
public:
	ScanTableColumnIdentifier(const ScanTableColumnIdentifier& base) = default;
public:
	ScanTableColumnIdentifier(ScanTableIdentifier* table, String* column, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableIdentifier* table, String* column, ThreadContext* ctx) throw() ;
	virtual ~ScanTableColumnIdentifier() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ScanTableIdentifier* table;
	String* column;
public:
	ScanTableIdentifier* getTable(ThreadContext* ctx) throw() ;
	void setTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() ;
	String* getColumn(ThreadContext* ctx) throw() ;
	void setColumn(String* column, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_ANALYZE_SCANTABLECOLUMNIDENTIFIER_H_ */
