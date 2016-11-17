#ifndef ALINOUS_RUNTIME_DOM_IALINOUSVARIABLE_H_
#define ALINOUS_RUNTIME_DOM_IALINOUSVARIABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

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

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomNode;
using ::alinous::runtime::dom::typed::BigDecimalVariable;
using ::alinous::runtime::dom::typed::BoolVariable;
using ::alinous::runtime::dom::typed::ByteVariable;
using ::alinous::runtime::dom::typed::CharVariable;
using ::alinous::runtime::dom::typed::DoubleVariable;
using ::alinous::runtime::dom::typed::FloatVariable;
using ::alinous::runtime::dom::typed::IntegerVariable;
using ::alinous::runtime::dom::typed::LongVariable;
using ::alinous::runtime::dom::typed::ShortVariable;
using ::alinous::runtime::dom::typed::StringVariable;
using ::alinous::runtime::dom::typed::TimeVariable;
using ::alinous::runtime::dom::typed::TimestampVariable;
using ::alinous::runtime::dom::typed::TypedVariableArray;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class IAlinousVariable : public virtual IObject {
public:
	IAlinousVariable(const IAlinousVariable& base) = default;
public:
	IAlinousVariable(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IAlinousVariable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int CLASS_VARIANT{0};
	constexpr static const int CLASS_DOM{1};
	constexpr static const int CLASS_OBJECT{2};
	constexpr static const int CLASS_TYPED{3};
	constexpr static const int CLASS_IDENTIFIER{4};
	static String* ATTR_NAME;
public:
	virtual void outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw()  = 0;
	virtual int getVariableClass(ThreadContext* ctx) throw()  = 0;
	virtual IAlinousVariable* copy(ThreadContext* ctx) = 0;
	virtual IDomVariable* toDomVariable(ThreadContext* ctx) = 0;
	virtual bool isNull(ThreadContext* ctx) throw()  = 0;
	virtual bool isArray(ThreadContext* ctx) throw()  = 0;
	virtual BoolVariable* toBoolVariable(ThreadContext* ctx) = 0;
	virtual ByteVariable* toByteVariable(ThreadContext* ctx) = 0;
	virtual CharVariable* toCharVariable(ThreadContext* ctx) = 0;
	virtual ShortVariable* toShortVariable(ThreadContext* ctx) = 0;
	virtual IntegerVariable* toIntVariable(ThreadContext* ctx) = 0;
	virtual LongVariable* toLongVariable(ThreadContext* ctx) = 0;
	virtual StringVariable* toStringVariable(ThreadContext* ctx) = 0;
	virtual FloatVariable* toFloatVariable(ThreadContext* ctx) = 0;
	virtual DoubleVariable* toDoubleVariable(ThreadContext* ctx) = 0;
	virtual BigDecimalVariable* toBigDecimalVariable(ThreadContext* ctx) = 0;
	virtual TimeVariable* toTimeVariable(ThreadContext* ctx) = 0;
	virtual TimestampVariable* toTimestampVariable(ThreadContext* ctx) = 0;
	virtual VariantValue* toVariantValue(ThreadContext* ctx) = 0;
	virtual int getIntValue(ThreadContext* ctx) = 0;
	virtual long long getLongValue(ThreadContext* ctx) = 0;
	virtual String* getStringValue(ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* add(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* minus(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* multiply(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* div(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftLeft(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRight(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* modulo(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitOr(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitAnd(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitExor(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* bitReverse(ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual IAlinousVariable* substitute(TypedVariableArray* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(IAlinousVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(VariantValue* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(DomVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(BoolVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(ByteVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(CharVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(DoubleVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(FloatVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(IntegerVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(LongVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(ShortVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(StringVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(BigDecimalVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(TimeVariable* variable, ThreadContext* ctx) = 0;
	virtual int compareTo(TimestampVariable* variable, ThreadContext* ctx) = 0;
	virtual bool isTrue(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw();
	};
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_IALINOUSVARIABLE_H_ */
