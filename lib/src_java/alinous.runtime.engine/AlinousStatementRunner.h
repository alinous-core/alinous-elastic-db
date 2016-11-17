#ifndef ALINOUS_RUNTIME_ENGINE_ALINOUSSTATEMENTRUNNER_H_
#define ALINOUS_RUNTIME_ENGINE_ALINOUSSTATEMENTRUNNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace stmt {
class AssignmentStatement;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class IdentifierVariable;}}}}

namespace alinous {namespace system {
class AlinousNotSupportedException;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace compile {namespace stmt {
class ReturnStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class ExpressionStatement;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementBlock;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ByteVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ShortVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class CharVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class IntegerVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class LongVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class FloatVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class DoubleVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class StringVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimestampVariable;}}}}

namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimeVariable;}}}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BigDecimalVariable;}}}}

namespace alinous {namespace numeric {
class BigDecimal;}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::sql::Timestamp;
using ::java::util::ArrayList;
using ::alinous::compile::IStatement;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::expstream::IdentifierVariable;
using ::alinous::compile::stmt::AssignmentStatement;
using ::alinous::compile::stmt::ExpressionStatement;
using ::alinous::compile::stmt::ReturnStatement;
using ::alinous::compile::stmt::StatementBlock;
using ::alinous::compile::stmt::StatementList;
using ::alinous::compile::stmt::TypedVariableDeclare;
using ::alinous::db::table::DatabaseException;
using ::alinous::numeric::BigDecimal;
using ::alinous::numeric::TimeOnlyTimestamp;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::dom::typed::BigDecimalVariable;
using ::alinous::runtime::dom::typed::ByteVariable;
using ::alinous::runtime::dom::typed::CharVariable;
using ::alinous::runtime::dom::typed::DoubleVariable;
using ::alinous::runtime::dom::typed::FloatVariable;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::runtime::dom::typed::IntegerVariable;
using ::alinous::runtime::dom::typed::LongVariable;
using ::alinous::runtime::dom::typed::ShortVariable;
using ::alinous::runtime::dom::typed::StringVariable;
using ::alinous::runtime::dom::typed::TimeVariable;
using ::alinous::runtime::dom::typed::TimestampVariable;
using ::alinous::runtime::dom::typed::TypedVariableArray;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;
using ::alinous::system::AlinousNotSupportedException;



class AlinousStatementRunner final : public virtual IObject {
public:
	AlinousStatementRunner(const AlinousStatementRunner& base) = default;
public:
	AlinousStatementRunner(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousStatementRunner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool assignStatement(AssignmentStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool returnStatement(ReturnStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool expressionStatement(ExpressionStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool statementBlock(StatementBlock* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool typedVariableDeclare(TypedVariableDeclare* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool statementList(StatementList* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx);
private:
	void substituteLocalVariableByIdenifier(ScriptMachine* machine, IdentifierVariable* leftId, IAlinousVariable* value, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_ALINOUSSTATEMENTRUNNER_H_ */
