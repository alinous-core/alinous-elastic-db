#ifndef ALINOUS_COMPILE_EXPRESSION_BLEXP_ANDEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_BLEXP_ANDEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class AbstractBooleanCollectionExpression;}}}}

namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {namespace blexp {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::IExpressionFactory;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class AndExpression final : public AbstractBooleanCollectionExpression {
public:
	AndExpression(const AndExpression& base) = default;
public:
	AndExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractBooleanCollectionExpression(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AndExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_BLEXP_ANDEXPRESSION_H_ */
