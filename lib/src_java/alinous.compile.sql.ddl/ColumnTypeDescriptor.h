#ifndef ALINOUS_COMPILE_SQL_DDL_COLUMNTYPEDESCRIPTOR_H_
#define ALINOUS_COMPILE_SQL_DDL_COLUMNTYPEDESCRIPTOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {
class IAlinousVisitorContainer;}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace ddl {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IAlinousVisitorContainer;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class ColumnTypeDescriptor final : public IAlinousElement, public IAlinousVisitorContainer {
public:
	ColumnTypeDescriptor(const ColumnTypeDescriptor& base) = default;
public:
	ColumnTypeDescriptor(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ColumnTypeDescriptor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ISQLExpression* length;
	String* typeName;
	int typeNum;
public:
	constexpr static const int INT{0};
	constexpr static const int LONG{1};
	constexpr static const int VARCHAR{2};
	constexpr static const int TEXT{3};
	constexpr static const int DOUBLE{4};
	constexpr static const int DATE{5};
	constexpr static const int TIME{6};
	constexpr static const int TIMESTAMP{7};
	constexpr static const int BLOB{8};
	constexpr static const int BIG_DECIMAL{9};
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	ISQLExpression* getLength(ThreadContext* ctx) throw() ;
	void setLength(ISQLExpression* length, ThreadContext* ctx) throw() ;
	String* getTypeName(ThreadContext* ctx) throw() ;
	void setTypeName(String* typeName, ThreadContext* ctx) throw() ;
	int getTypeNum(ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
private:
	int toTypeNum(String* str, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_DDL_COLUMNTYPEDESCRIPTOR_H_ */
