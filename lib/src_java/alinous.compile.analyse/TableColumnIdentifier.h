#ifndef ALINOUS_COMPILE_ANALYSE_TABLECOLUMNIDENTIFIER_H_
#define ALINOUS_COMPILE_ANALYSE_TABLECOLUMNIDENTIFIER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class TableColumnIdentifier final : public virtual IObject {
public:
	TableColumnIdentifier(const TableColumnIdentifier& base) = default;
public:
	TableColumnIdentifier(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TableColumnIdentifier() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* schema;
	String* table;
	String* column;
public:
	String* getSchema(ThreadContext* ctx) throw() ;
	void setSchema(String* schema, ThreadContext* ctx) throw() ;
	String* getTable(ThreadContext* ctx) throw() ;
	void setTable(String* table, ThreadContext* ctx) throw() ;
	String* getColumn(ThreadContext* ctx) throw() ;
	void setColumn(String* column, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_TABLECOLUMNIDENTIFIER_H_ */
