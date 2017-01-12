#ifndef ALINOUS_COMPILE_ANALYSE_ALINOUSTYPE_H_
#define ALINOUS_COMPILE_ANALYSE_ALINOUSTYPE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class DocumentVariable;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class StringVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimeVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimestampVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BigDecimalVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BoolVariable;}}}}

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

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace numeric {
class BigDecimal;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

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

namespace alinous {namespace compile {namespace analyse {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::sql::Timestamp;
using ::java::util::ArrayList;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::expression::IExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::numeric::BigDecimal;
using ::alinous::numeric::TimeOnlyTimestamp;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::DocumentVariable;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::dom::typed::BigDecimalVariable;
using ::alinous::runtime::dom::typed::BoolVariable;
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
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class AlinousType final : public ICommandData, public virtual IObject {
public:
	AlinousType(const AlinousType& base) = default;
public:
	AlinousType(AlinousClass* clazz, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousClass* clazz, ThreadContext* ctx) throw() ;
	AlinousType(int type, int typeClass, ThreadContext* ctx) throw() ;
	void __construct_impl(int type, int typeClass, ThreadContext* ctx) throw() ;
	AlinousType(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AlinousType() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int typeClass;
	AlinousClass* clazz;
	int type;
	int dimension;
public:
	constexpr static const int TYPE_PRIMITIVE{1};
	constexpr static const int TYPE_STANDARD_OBJ{2};
	constexpr static const int TYPE_CLASS_OBJ{3};
	constexpr static const int TYPE_DOM{4};
	constexpr static const int TYPE_VOID{5};
	constexpr static const int NULL_TYPE{0};
	constexpr static const int BOOL_TYPE{1};
	constexpr static const int BYTE_TYPE{2};
	constexpr static const int SHORT_TYPE{3};
	constexpr static const int CHAR_TYPE{4};
	constexpr static const int INT_TYPE{5};
	constexpr static const int LONG_TYPE{6};
	constexpr static const int FLOAT_TYPE{7};
	constexpr static const int DOUBLE_TYPE{8};
	constexpr static const int TIME{9};
	constexpr static const int TIMESTAMP{10};
	constexpr static const int BIGDECIMAL{11};
	constexpr static const int STRING_TYPE{12};
	constexpr static const int OBJECT_TYPE{13};
public:
	int getTypeClass(ThreadContext* ctx) throw() ;
	AlinousClass* getClazz(ThreadContext* ctx) throw() ;
	int getType(ThreadContext* ctx) throw() ;
	IAlinousVariable* makeDefault(ThreadContext* ctx) throw() ;
	int getDimension(ThreadContext* ctx) throw() ;
	void setDimension(int dimension, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
private:
	IAlinousVariable* returnClasssVariable(ThreadContext* ctx) throw() ;
	IAlinousVariable* returnStandardVariable(ThreadContext* ctx) throw() ;
	IAlinousVariable* returnPrimitive(ThreadContext* ctx) throw() ;
public:
	static void fillArray(int level, ScriptMachine* machine, TypedVariableArray* parent, AlinousType* analysedType, ArrayList<IExpression>* arrayCapacity, bool debug, ThreadContext* ctx);
private:
	static TypedVariableArray* fillLeafArray(int count, TypedVariableArray* arrayVar, AlinousType* analysedType, ThreadContext* ctx);
	static ITypedVariable* newBlankVariable(AlinousType* analysedType, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_ALINOUSTYPE_H_ */
