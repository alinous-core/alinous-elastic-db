#ifndef ALINOUS_RUNTIME_VARIANT_BIGDECIMALDATA_H_
#define ALINOUS_RUNTIME_VARIANT_BIGDECIMALDATA_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace numeric {
class BigDecimal;}}

namespace alinous {namespace runtime {namespace variant {
class BigDecimalData;}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace numeric {
class TimeOnlyTimestamp;}}

namespace java {namespace sql {
class Timestamp;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace variant {
class IVariantData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::html::Attribute;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::numeric::BigDecimal;
using ::alinous::numeric::TimeOnlyTimestamp;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class BigDecimalData final : public IVariantData, public virtual IObject {
public:
	BigDecimalData(const BigDecimalData& base) = default;
public:
	BigDecimalData(BigDecimal* data, ThreadContext* ctx) throw() ;
	void __construct_impl(BigDecimal* data, ThreadContext* ctx) throw() ;
	BigDecimalData(ThreadContext* ctx) throw()  : IObject(ctx), IVariantData(ctx), data(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~BigDecimalData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	BigDecimal* data;
public:
	static String* TAG_NAME;
public:
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw()  final;
	int getType(ThreadContext* ctx) throw()  final;
	String* getString(ThreadContext* ctx) throw()  final;
	long long getLong(ThreadContext* ctx) throw()  final;
	int getInt(ThreadContext* ctx) throw()  final;
	short getShort(ThreadContext* ctx) throw()  final;
	wchar_t getChar(ThreadContext* ctx) throw()  final;
	char getByte(ThreadContext* ctx) throw()  final;
	float getFloat(ThreadContext* ctx) throw()  final;
	double getDouble(ThreadContext* ctx) throw()  final;
	bool getBoolean(ThreadContext* ctx) throw()  final;
	BigDecimal* getBigDecimal(ThreadContext* ctx) throw()  final;
	TimeOnlyTimestamp* getTime(ThreadContext* ctx) throw()  final;
	Timestamp* getTimestamp(ThreadContext* ctx) throw()  final;
	int bufferSize(ThreadContext* ctx) throw()  final;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	bool isNull(ThreadContext* ctx) throw()  final;
	int compareTo(VariantValue* variant, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static BigDecimalData* importFromXml(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (VariantValue* _this, VariantValue* variant, ThreadContext* ctx) const throw();
	};
};

}}}

#endif /* end of ALINOUS_RUNTIME_VARIANT_BIGDECIMALDATA_H_ */
