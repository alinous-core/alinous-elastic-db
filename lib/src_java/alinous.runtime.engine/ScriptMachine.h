#ifndef ALINOUS_RUNTIME_ENGINE_SCRIPTMACHINE_H_
#define ALINOUS_RUNTIME_ENGINE_SCRIPTMACHINE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseConnection;}}}

namespace alinous {namespace runtime {namespace engine {
class DatabaseHandle;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace server {namespace http {namespace params {
class AbstractHttpParameter;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpParameter;}}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpArrayParameter;}}}}

namespace alinous {namespace server {namespace http {namespace params {
class HttpUploadParameter;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace stmt {
class StatementBlock;}}}

namespace alinous {namespace runtime {namespace engine {
class IStackFrame;}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace runtime {namespace engine {
class AlinousStatementRunner;}}}

namespace alinous {namespace runtime {namespace engine {
class SQLStatementRunner;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace runtime {namespace engine {
class ExpressionStreamBuffer;}}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

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
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Stack;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::expression::DomNameSegment;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::stmt::StatementBlock;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::html::DomNode;
using ::alinous::runtime::AlinousModule;
using ::alinous::runtime::dbif::IDatabaseConnection;
using ::alinous::runtime::dbif::IDatabaseDriver;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::server::http::params::AbstractHttpParameter;
using ::alinous::server::http::params::HttpArrayParameter;
using ::alinous::server::http::params::HttpParameter;
using ::alinous::server::http::params::HttpUploadParameter;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class ScriptMachine final : public virtual IObject {
public:
	ScriptMachine(const ScriptMachine& base) = default;
public:
	ScriptMachine(AlinousModule* module, AlinousCore* core, ThreadContext* ctx);
	void __construct_impl(AlinousModule* module, AlinousCore* core, ThreadContext* ctx);
	virtual ~ScriptMachine() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousCore* core;
	Stack<MainStackFrame>* stackFrames;
	AlinousModule* module;
	ArrayList<DatabaseHandle>* dbHandles;
	DatabaseHandle* currentDbHandle;
	AlinousStatementRunner* alinousStmtRunner;
	SQLStatementRunner* sqlRunner;
	long long stackIdSerial;
	IAlinousVariable* returnedValue;
	Stack<ExpressionStreamBuffer>* expStreamStack;
	bool leftValue;
public:
	void importParams(HashMap<String,AbstractHttpParameter>* params, ThreadContext* ctx);
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() ;
	IAlinousVariable* resolveExpression(IExpression* exp, bool debug, ThreadContext* ctx);
	AlinousFunction* findSourceFunction(String* name, ThreadContext* ctx) throw() ;
	void newStackFrame(AlinousFunction* func, ThreadContext* ctx) throw() ;
	void newStackFrame(StatementBlock* block, ThreadContext* ctx) throw() ;
	void popStackFrame(ThreadContext* ctx) throw() ;
	IStackFrame* peek(ThreadContext* ctx) throw() ;
	MainStackFrame* getFrame(ThreadContext* ctx) throw() ;
	MainStackFrame* getLastFrame(ThreadContext* ctx) throw() ;
	Stack<MainStackFrame>* getStackFrames(ThreadContext* ctx) throw() ;
	AlinousCore* getCore(ThreadContext* ctx) throw() ;
	ArrayList<DatabaseHandle>* getDbHandles(ThreadContext* ctx) throw() ;
	DatabaseHandle* getCurrentDbHandle(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	AlinousStatementRunner* getAlinousStmtRunner(ThreadContext* ctx) throw() ;
	void setAlinousStmtRunner(AlinousStatementRunner* alinousStmtRunner, ThreadContext* ctx) throw() ;
	SQLStatementRunner* getSqlRunner(ThreadContext* ctx) throw() ;
	void setSqlRunner(SQLStatementRunner* sqlRunner, ThreadContext* ctx) throw() ;
	void putVariable(DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx);
	IDomVariable* getByDescriptor(DomVariableDescriptor* domVariableDescriptor, bool debug, ThreadContext* ctx);
	ITypedVariable* getTypedVariable(String* name, ThreadContext* ctx) throw() ;
	void putTypedVariable(String* name, ITypedVariable* variable, ThreadContext* ctx);
	IAlinousVariable* getReturnedValue(ThreadContext* ctx) throw() ;
	void setReturnedValue(IAlinousVariable* returnedValue, ThreadContext* ctx) throw() ;
	void newExpressionStream(ThreadContext* ctx) throw() ;
	void endExpressionStream(ThreadContext* ctx) throw() ;
	IAlinousVariable* getStreamLastValue(ThreadContext* ctx) throw() ;
	void setStreamLastValue(IAlinousVariable* streamLastValue, ThreadContext* ctx) throw() ;
	bool isLeftValue(ThreadContext* ctx) throw() ;
	void setLeftValue(bool leftValue, ThreadContext* ctx) throw() ;
	AlinousClassVariable* getThisPtr(ThreadContext* ctx) throw() ;
	void setThisPtr(AlinousClassVariable* thisPtr, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_SCRIPTMACHINE_H_ */
