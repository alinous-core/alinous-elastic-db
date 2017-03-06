#ifndef ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLEARRAY_H_
#define ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLEARRAY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class DomArray;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BoolVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ByteVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class CharVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ShortVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class IntegerVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class LongVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class StringVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class FloatVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class DoubleVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BigDecimalVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimeVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimestampVariable;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class AbstractTypedVariable;}}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class NetworkAlinousVariableFactory;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {namespace typed {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::html::Attribute;
using ::alinous::html::DomNode;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::DomArray;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::NetworkAlinousVariableFactory;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class TypedVariableArray final : public AbstractTypedVariable {
public:
	TypedVariableArray(const TypedVariableArray& base) = default;
public:
	TypedVariableArray(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TypedVariableArray() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<ITypedVariable>* array;
public:
	static String* VAL_TYPE;
public:
	void outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw()  final;
	void addElement(ITypedVariable* element, ThreadContext* ctx) throw() ;
	ITypedVariable* get(int index, ThreadContext* ctx) throw() ;
	IAlinousVariable* substitute(TypedVariableArray* variable, ThreadContext* ctx) final;
	VariantValue* toVariantValue(ThreadContext* ctx) final;
	int getVariableClass(ThreadContext* ctx) throw()  final;
	int getTypedType(ThreadContext* ctx) throw()  final;
	bool isTrue(ThreadContext* ctx) final;
	IAlinousVariable* copy(ThreadContext* ctx) final;
	IDomVariable* toDomVariable(ThreadContext* ctx) final;
	bool isNull(ThreadContext* ctx) throw()  final;
	bool isArray(ThreadContext* ctx) throw()  final;
	BoolVariable* toBoolVariable(ThreadContext* ctx) final;
	ByteVariable* toByteVariable(ThreadContext* ctx) final;
	CharVariable* toCharVariable(ThreadContext* ctx) final;
	ShortVariable* toShortVariable(ThreadContext* ctx) final;
	IntegerVariable* toIntVariable(ThreadContext* ctx) final;
	LongVariable* toLongVariable(ThreadContext* ctx) final;
	StringVariable* toStringVariable(ThreadContext* ctx) final;
	FloatVariable* toFloatVariable(ThreadContext* ctx) final;
	DoubleVariable* toDoubleVariable(ThreadContext* ctx) final;
	BigDecimalVariable* toBigDecimalVariable(ThreadContext* ctx) final;
	TimeVariable* toTimeVariable(ThreadContext* ctx) final;
	TimestampVariable* toTimestampVariable(ThreadContext* ctx) final;
	int getIntValue(ThreadContext* ctx) final;
	long long getLongValue(ThreadContext* ctx) final;
	String* getStringValue(ThreadContext* ctx) final;
	IAlinousVariable* add(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitReverse(ThreadContext* ctx) final;
	IAlinousVariable* substitute(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(VariantValue* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(TimestampVariable* variable, ThreadContext* ctx) final;
	int compareTo(IAlinousVariable* variable, ThreadContext* ctx) final;
	int compareTo(VariantValue* variable, ThreadContext* ctx) final;
	int compareTo(DomVariable* variable, ThreadContext* ctx) final;
	int compareTo(BoolVariable* variable, ThreadContext* ctx) final;
	int compareTo(ByteVariable* variable, ThreadContext* ctx) final;
	int compareTo(CharVariable* variable, ThreadContext* ctx) final;
	int compareTo(DoubleVariable* variable, ThreadContext* ctx) final;
	int compareTo(FloatVariable* variable, ThreadContext* ctx) final;
	int compareTo(IntegerVariable* variable, ThreadContext* ctx) final;
	int compareTo(LongVariable* variable, ThreadContext* ctx) final;
	int compareTo(ShortVariable* variable, ThreadContext* ctx) final;
	int compareTo(StringVariable* variable, ThreadContext* ctx) final;
	int compareTo(BigDecimalVariable* variable, ThreadContext* ctx) final;
	int compareTo(TimeVariable* variable, ThreadContext* ctx) final;
	int compareTo(TimestampVariable* variable, ThreadContext* ctx) final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static TypedVariableArray* fromDebugXml(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
	class ValueCompare {
	public:
		int operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw();
	};
};

}}}}

#endif /* end of ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLEARRAY_H_ */
