#ifndef ALINOUS_COMPILE_SQL_DDL_DDLCOLUMNDESCRIPTOR_H_
#define ALINOUS_COMPILE_SQL_DDL_DDLCOLUMNDESCRIPTOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ColumnTypeDescriptor;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class CheckDefinition;}}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace ddl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IAlinousVisitorContainer;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class DdlColumnDescriptor final : public IAlinousElement, public IAlinousVisitorContainer {
public:
	DdlColumnDescriptor(const DdlColumnDescriptor& base) = default;
public:
	DdlColumnDescriptor(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousElement(ctx), IAlinousVisitorContainer(ctx), name(nullptr), typeDescriptor(nullptr), defaultValue(nullptr), notnull(0), unique(0), check(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DdlColumnDescriptor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	ColumnTypeDescriptor* typeDescriptor;
	ISQLExpression* defaultValue;
	bool notnull;
	bool unique;
	CheckDefinition* check;
public:
	TableColumnMetadata* toMetadata(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void validate(SourceValidator* validator, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	ColumnTypeDescriptor* getTypeDescriptor(ThreadContext* ctx) throw() ;
	void setTypeDescriptor(ColumnTypeDescriptor* typeDescriptor, ThreadContext* ctx) throw() ;
	ISQLExpression* getDefaultValue(ThreadContext* ctx) throw() ;
	void setDefaultValue(ISQLExpression* defaultValue, ThreadContext* ctx) throw() ;
	bool isNotnull(ThreadContext* ctx) throw() ;
	void setNotnull(bool notnull, ThreadContext* ctx) throw() ;
	bool isUnique(ThreadContext* ctx) throw() ;
	void setUnique(bool unique, ThreadContext* ctx) throw() ;
	CheckDefinition* getCheck(ThreadContext* ctx) throw() ;
	void setCheck(CheckDefinition* check, ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_DDL_DDLCOLUMNDESCRIPTOR_H_ */
