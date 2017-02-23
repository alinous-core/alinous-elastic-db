#ifndef ALINOUS_RUNTIME_VARIANT_VARIANTVALUE_H_
#define ALINOUS_RUNTIME_VARIANT_VARIANTVALUE_H_
namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace variant {
class StringData;}}}

namespace alinous {namespace runtime {namespace variant {
class LongData;}}}

namespace alinous {namespace runtime {namespace variant {
class IntData;}}}

namespace alinous {namespace runtime {namespace variant {
class ShortData;}}}

namespace alinous {namespace runtime {namespace variant {
class CharData;}}}

namespace alinous {namespace runtime {namespace variant {
class ByteData;}}}

namespace alinous {namespace runtime {namespace variant {
class FloatData;}}}

namespace alinous {namespace runtime {namespace variant {
class DoubleData;}}}

namespace alinous {namespace numeric {
class BigDecimal;}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace runtime {namespace variant {
class BigDecimalData;}}}

namespace alinous {namespace runtime {namespace variant {
class TimeData;}}}

namespace alinous {namespace runtime {namespace variant {
class TimestampData;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace runtime {namespace engine {
class AlinousNullPointerException;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BoolVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ByteVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class CharVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class DoubleVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class FloatVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class IntegerVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ShortVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class StringVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class LongVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimestampVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TimeVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class BigDecimalVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace variant {
class IVariantData;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableOperationCaller;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace variant {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::sql::Timestamp;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::html::Attribute;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::numeric::BigDecimal;
using ::alinous::numeric::TimeOnlyTimestamp;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::VariableOperationCaller;
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
using ::alinous::runtime::engine::AlinousNullPointerException;
using ::alinous::system::AlinousException;



class VariantValue final : public IAlinousVariable, public virtual IObject {
public:
	VariantValue(const VariantValue& base) = default;
public:
	VariantValue(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	VariantValue(String* value, ThreadContext* ctx) throw() ;
	void __construct_impl(String* value, ThreadContext* ctx) throw() ;
	VariantValue(long long lvalue, ThreadContext* ctx) throw() ;
	void __construct_impl(long long lvalue, ThreadContext* ctx) throw() ;
	VariantValue(int ivalue, ThreadContext* ctx) throw() ;
	void __construct_impl(int ivalue, ThreadContext* ctx) throw() ;
	VariantValue(short svalue, ThreadContext* ctx) throw() ;
	void __construct_impl(short svalue, ThreadContext* ctx) throw() ;
	VariantValue(wchar_t cvalue, ThreadContext* ctx) throw() ;
	void __construct_impl(wchar_t cvalue, ThreadContext* ctx) throw() ;
	VariantValue(char bvalue, ThreadContext* ctx) throw() ;
	void __construct_impl(char bvalue, ThreadContext* ctx) throw() ;
	VariantValue(float fvalue, ThreadContext* ctx) throw() ;
	void __construct_impl(float fvalue, ThreadContext* ctx) throw() ;
	VariantValue(double dvalue, ThreadContext* ctx) throw() ;
	void __construct_impl(double dvalue, ThreadContext* ctx) throw() ;
	VariantValue(BigDecimal* decvalue, ThreadContext* ctx) throw() ;
	void __construct_impl(BigDecimal* decvalue, ThreadContext* ctx) throw() ;
	VariantValue(TimeOnlyTimestamp* value, ThreadContext* ctx) throw() ;
	void __construct_impl(TimeOnlyTimestamp* value, ThreadContext* ctx) throw() ;
	VariantValue(Timestamp* value, ThreadContext* ctx) throw() ;
	void __construct_impl(Timestamp* value, ThreadContext* ctx) throw() ;
	virtual ~VariantValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int vtype;
	IVariantData* data;
	char max;
public:
	constexpr static const int TYPE_STRING{1};
	constexpr static const int TYPE_LONG{2};
	constexpr static const int TYPE_INT{3};
	constexpr static const int TYPE_SHORT{4};
	constexpr static const int TYPE_CHAR{5};
	constexpr static const int TYPE_BYTE{6};
	constexpr static const int TYPE_FLOAT{7};
	constexpr static const int TYPE_DOUBLE{8};
	constexpr static const int TYPE_BOOL{9};
	constexpr static const int TYPE_BIG_DECIMAL{10};
	constexpr static const int TYPE_TIME{11};
	constexpr static const int TYPE_TIMESTAMP{12};
	constexpr static const int TYPE_NULL{13};
	static String* TAG_NAME;
	static String* ATTR_VTYPE;
	constexpr static const int MAX_VALUE{1};
	constexpr static const int MIN_VALUE{-1};
public:
	void outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw()  final;
	int getIntValue(ThreadContext* ctx) final;
	String* getStringValue(ThreadContext* ctx) final;
	VariantValue* toVariantValue(ThreadContext* ctx) final;
	IAlinousVariable* copy(ThreadContext* ctx) final;
	String* toString(ThreadContext* ctx) throw() ;
	void setString(String* value, ThreadContext* ctx) throw() ;
	void setLong(long long value, ThreadContext* ctx) throw() ;
	void setInt(int value, ThreadContext* ctx) throw() ;
	void setShort(short value, ThreadContext* ctx) throw() ;
	void setChar(wchar_t value, ThreadContext* ctx) throw() ;
	void setByte(char value, ThreadContext* ctx) throw() ;
	void setFloat(float value, ThreadContext* ctx) throw() ;
	void setDouble(double value, ThreadContext* ctx) throw() ;
	void setBigDecimal(BigDecimal* value, ThreadContext* ctx) throw() ;
	void setTime(TimeOnlyTimestamp* value, ThreadContext* ctx) throw() ;
	void setTimestamp(Timestamp* value, ThreadContext* ctx) throw() ;
	bool isMax(ThreadContext* ctx) throw() ;
	bool isMinimum(ThreadContext* ctx) throw() ;
	void setNull(ThreadContext* ctx) throw() ;
	void setValue(VariantValue* variant, ThreadContext* ctx);
	int bufferSize(ThreadContext* ctx);
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	String* getString(ThreadContext* ctx) throw() ;
	long long getLong(ThreadContext* ctx) throw() ;
	int getInt(ThreadContext* ctx) throw() ;
	short getShort(ThreadContext* ctx) throw() ;
	wchar_t getChar(ThreadContext* ctx) throw() ;
	char getByte(ThreadContext* ctx) throw() ;
	float getFloat(ThreadContext* ctx) throw() ;
	double getDouble(ThreadContext* ctx) throw() ;
	BigDecimal* getBigDecimal(ThreadContext* ctx) throw() ;
	TimeOnlyTimestamp* getTime(ThreadContext* ctx) throw() ;
	Timestamp* getTimestamp(ThreadContext* ctx) throw() ;
	int getVtype(ThreadContext* ctx) throw() ;
	bool isNull(ThreadContext* ctx) throw()  final;
	int compareTo(VariantValue* variant, ThreadContext* ctx) throw()  final;
	IAlinousVariable* add(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* minus(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* multiply(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* div(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* modulo(VariantValue* variant, ThreadContext* ctx) final;
	bool isTrue(ThreadContext* ctx) final;
	IAlinousVariable* bitOr(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(VariantValue* variant, ThreadContext* ctx) final;
	IAlinousVariable* bitReverse(ThreadContext* ctx) final;
	int getVariableClass(ThreadContext* ctx) throw()  final;
	IDomVariable* toDomVariable(ThreadContext* ctx) throw()  final;
	IAlinousVariable* add(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(DomVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(BoolVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(ByteVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(CharVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(DoubleVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(FloatVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(IntegerVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(ShortVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(StringVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(IAlinousVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(LongVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(LongVariable* variable, ThreadContext* ctx) final;
	bool isArray(ThreadContext* ctx) throw()  final;
	IAlinousVariable* shiftLeft(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	IAlinousVariable* shiftRight(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	IAlinousVariable* modulo(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	IAlinousVariable* substitute(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(TimeVariable* variable, ThreadContext* ctx) final;
	int compareTo(BigDecimalVariable* variable, ThreadContext* ctx) final;
	int compareTo(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	int compareTo(TimestampVariable* variable, ThreadContext* ctx) final;
	int compareTo(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	IAlinousVariable* bitAnd(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	IAlinousVariable* bitExor(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	IAlinousVariable* add(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(BigDecimalVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx) final;
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
	BoolVariable* toBoolVariable(ThreadContext* ctx) final;
	ByteVariable* toByteVariable(ThreadContext* ctx) final;
	CharVariable* toCharVariable(ThreadContext* ctx) final;
	ShortVariable* toShortVariable(ThreadContext* ctx) final;
	IntegerVariable* toIntVariable(ThreadContext* ctx) final;
	LongVariable* toLongVariable(ThreadContext* ctx) final;
	StringVariable* toStringVariable(ThreadContext* ctx) final;
	BigDecimalVariable* toBigDecimalVariable(ThreadContext* ctx) final;
	long long getLongValue(ThreadContext* ctx) final;
	FloatVariable* toFloatVariable(ThreadContext* ctx) final;
	DoubleVariable* toDoubleVariable(ThreadContext* ctx) final;
	TimeVariable* toTimeVariable(ThreadContext* ctx) final;
	TimestampVariable* toTimestampVariable(ThreadContext* ctx) final;
	IAlinousVariable* add(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* add(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* minus(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* multiply(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* div(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftLeft(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRight(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* modulo(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitOr(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitAnd(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(TimeVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* bitExor(TimestampVariable* variable, ThreadContext* ctx) final;
	IAlinousVariable* substitute(TypedVariableArray* variable, ThreadContext* ctx) final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
private:
	int nullCompare(VariantValue* variant, ThreadContext* ctx) throw() ;
	int compareMinMax(VariantValue* variable, ThreadContext* ctx) throw() ;
public:
	static VariantValue* createMaxValue(int type, ThreadContext* ctx) throw() ;
	static VariantValue* createMinValue(int type, ThreadContext* ctx) throw() ;
	static VariantValue* importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() ;
	static VariantValue* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<String>::dec(nullptr, VariantValue::TAG_NAME, ctx, __FILEW__, __LINE__, L"String");
		GCUtils<String>::dec(nullptr, VariantValue::ATTR_VTYPE, ctx, __FILEW__, __LINE__, L"String");
	}
	class ValueCompare {
	public:
		int operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw();
	};
};

}}}

#endif /* end of ALINOUS_RUNTIME_VARIANT_VARIANTVALUE_H_ */
